// Main Header File
#include "bluetooth.h"

// Custom logging
const char* BLE_TAG = "BLE_CONFIG";

// Service UUID: 00000002-0000-0000-FDFD-FDFDFDFDFDFD (LSB --> MSB) {Provided}
const uint8_t my_service_uuid[16] = {
    0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
};

// Advertising parameters
esp_ble_adv_params_t my_adv_params = {
    .adv_int_min       = 0x20,                                  // 32*0.625ms= 20ms
    .adv_int_max       = 0x40,                                  // 64*0.625ms = 40ms
    .adv_type          = ADV_TYPE_IND,                          // Indefinite advertising
    .own_addr_type     = BLE_ADDR_TYPE_PUBLIC,                  // Public Address for BLE
    .channel_map       = ADV_CHNL_ALL,                          // Advertise over all channels
    .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,     // Allow any scan/connection
};

// Advertising data
esp_ble_adv_data_t my_adv_data = {
    .set_scan_rsp        = false,                               // Disable scan response data
    .include_name        = true,                                // Include name set
    .include_txpower     = true,                                // Include TX Power              
    .min_interval        = 0x20,                                // 32*0.625ms= 20ms
    .max_interval        = 0x40,                                // 64*0.625ms = 40ms
    .appearance          = 0x00,                                // Appearance (unused in this case)
    .manufacturer_len    = 0,                                   // Length of manufacturer specific data (no data included)
    .p_manufacturer_data = NULL,                                // Pointer to manufacturer specific data (null)
    .service_data_len    = 0,                                   // Length of service data (no data included)
    .p_service_data      = NULL,                                // Pointer to service data (null)
    .service_uuid_len    = sizeof(my_service_uuid),             // Length of service UUID (128-bit)
    .p_service_uuid      = (uint8_t*)my_service_uuid,           // Pointer to service UUID
    .flag                = (ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT),    // Advertising flag (General discoverable | BLE advertisement flag & BR/EDR (Classic Bluetooth) not supported)
};

// BLE Temperature Value (°C)
float temp_value_C = 0.0f; 
// BLE Humidity Value (%)
float humid_value = 0.0f; 

// GATTS Variable
uint16_t my_gatts_if = ESP_GATT_IF_NONE;    /*!< Gatt interface type, different application on GATT client use different gatt_if */
// Service ID
esp_gatt_srvc_id_t my_service_id;

// Add Temperature Characteristic
esp_bt_uuid_t my_temp_char_uuid;
// Add Humidity Characteristic
esp_bt_uuid_t my_hum_char_uuid;

#ifdef BLE_DESC
    uint8_t cccd_value[2] = {0x01, 0x00}; 
    // Add Temperature Description
    esp_bt_uuid_t my_temp_descr_uuid = {
        .len = ESP_UUID_LEN_16,
        .uuid.uuid16 = ESP_GATT_UUID_CHAR_CLIENT_CONFIG,
    };
    // Add Humidity Description
    esp_bt_uuid_t my_hum_descr_uuid = {
        .len = ESP_UUID_LEN_16,
        .uuid.uuid16 = ESP_GATT_UUID_CHAR_CLIENT_CONFIG,
    };
#endif

// Temperature Service Handler
uint16_t temp_char_handle;
// Humidity Service Handler
uint16_t humid_char_handle;

/**
 * @brief - Temperature Meta Data 
 * @brief - Includes Temperature Data Max Length, Default Length 
 * @brief - Includes Temperature Data Variable Address 
*/
esp_attr_value_t gatts_temp_char_val = {
    .attr_max_len = sizeof(temp_value_C),
    .attr_len = sizeof(temp_value_C),
    .attr_value = (uint8_t*)&temp_value_C,
};

/**
 * @brief - Humidity Meta Data 
 * @brief - Includes Humidity Data Max Length, Default Length 
 * @brief - Includes Humidity Data Variable Address 
*/
esp_attr_value_t gatts_humid_char_val = {
    .attr_max_len = sizeof(humid_value),
    .attr_len = sizeof(humid_value),
    .attr_value = (uint8_t*)&humid_value,
};

#ifdef BLE_DESC

#endif


/**
 * @brief - Initialises the BLE Stack on ESP-32 with default configuration
 * @note - The Bluetooth stack is up and running at this point in the program flow
 * @note - However, the functionality of the application has not been defined yet
 */
void init_BLE(void) {
    // Error Debugging
    esp_err_t ret;

    // Step 1: Initialize NVS (Because some data is stored in NVS by BLE)
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Step 2: BT Controller Configuration (Hardware Properties Configuration)
    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ret = esp_bt_controller_init(&bt_cfg);
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s initialize controller failed", __func__);
        return;
    }

    // Step 3: BT Controller enable BLE Mode (Enable Controller Configuration set in Step 2)
    ret = esp_bt_controller_enable(ESP_BT_MODE_BLE);
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s enable controller failed", __func__);
        return;
    }

    // Step 4: Initialise Bluedroid (Software Stack -> Host)
    ret = esp_bluedroid_init();
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s init bluetooth failed", __func__);
        return;
    }

    // Step 5: Enable Bluedroid (Host)
    ret = esp_bluedroid_enable();
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s enable bluetooth failed", __func__);
        return;
    }
    
    // Step 6: Set Device Name {DEVICE_NAME}
    ret = esp_ble_gap_set_device_name(DEVICE_NAME);
    if (ret) {
        ESP_LOGE(BLE_TAG, "Device Name Allocation Failed, Code: %X", ret);
        return;
    }
    ESP_LOGI(BLE_TAG, "Device name set to: %s", DEVICE_NAME);

    // Step 7: Register GAP Event Handler (Basically providing a callback function)
    ret = esp_ble_gap_register_callback(my_gap_event_handler);
    if (ret) {
        ESP_LOGE(BLE_TAG, "GAP Register Callback Failed, Code: %X", ret);
        return;
    }

    // Step 8: Register GATT Event Handler (Basically providing a callback function)
    ret = esp_ble_gatts_register_callback(my_gatts_profile_event_handler);
    if (ret) {
        ESP_LOGE(BLE_TAG, "GATT Register Callback Failed, Code: %X", ret);
        return;
    }

    // Step 9: Register the application using {ESP_APP_ID} with BLE GATT server
    ret = esp_ble_gatts_app_register(ESP_APP_ID);
    if (ret) {
        ESP_LOGE(BLE_TAG, "GATT Register App Failed, Code: %X", ret);
        return;
    }

    // Step 10: Setup Maximum Transmission Unit (MTU) 
    esp_err_t local_mtu_ret = esp_ble_gatt_set_local_mtu(500);
    if (local_mtu_ret) {
        ESP_LOGE(BLE_TAG, "Set local MTU failed, error code = %X", local_mtu_ret);
    }

    // Step 11: Configure advertising data
    ret = esp_ble_gap_config_adv_data(&my_adv_data);
    if (ret) {
        ESP_LOGE(BLE_TAG, "Failed to configure Advertisement Data, Code: %X", ret);
        return;
    }

    ESP_LOGW(BLE_TAG, "\nBluetooth initialization complete. Device name: %s\n", DEVICE_NAME);
}


/**
 * @brief - BLE GAP Event Handler
 * @brief - Advertisement phase events
*/
void my_gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param) {
    switch (event) {

        case ESP_GAP_BLE_ADV_DATA_SET_COMPLETE_EVT:
            ESP_LOGI(BLE_TAG, "Advertising data set successfully.");
            // Start advertising
            esp_ble_gap_start_advertising(&my_adv_params);
            break;

        case ESP_GAP_BLE_ADV_START_COMPLETE_EVT:
            if (param->adv_start_cmpl.status != ESP_BT_STATUS_SUCCESS) {
                ESP_LOGE(BLE_TAG, "Advertising start failed");
            } 
            else {
                ESP_LOGI(BLE_TAG, "Advertising start successfully");
            }
            break;

        case ESP_GAP_BLE_ADV_STOP_COMPLETE_EVT:
            if (param->adv_stop_cmpl.status != ESP_BT_STATUS_SUCCESS) {
                ESP_LOGE(BLE_TAG, "Advertising stop failed");
            } 
            else {
                ESP_LOGI(BLE_TAG, "Advertising stop successfully");
            }
            break;

        default:
            // Start advertising
            esp_ble_gap_start_advertising(&my_adv_params);
            break;
    }
}


/**
 * @brief - GATTs Profile Event Handler
 * @brief - Deals with `ESP_GATTS_CREATE_EVT` (Description)
 * @brief - Deals with `ESP_GATTS_READ_EVT` (Data Sent)
*/
void my_gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param) {
    // Main situation handling based upon events
    switch (event) {

        // Application registers with the BLE GATT server
        case ESP_GATTS_REG_EVT:
            ESP_LOGI(BLE_TAG, "REGISTER_APP_EVT, status %d, app_id %d", param->reg.status, param->reg.app_id);
            // Setup service ID
            my_service_id.is_primary = true;
            my_service_id.id.inst_id = 0x00;
            my_service_id.id.uuid.len = ESP_UUID_LEN_128;
            memcpy(my_service_id.id.uuid.uuid.uuid128, my_service_uuid, sizeof(my_service_uuid));
            esp_ble_gatts_create_service(gatts_if, &my_service_id, 6);
        break;

        // Service creation completed
        case ESP_GATTS_CREATE_EVT:
            ESP_LOGI(BLE_TAG, "CREATE_SERVICE_EVT, status %d, service_handle %d", param->create.status, param->create.service_handle);
            // Start the service
            esp_ble_gatts_start_service(param->create.service_handle);
            
            // Add Temperature Characteristic
            my_temp_char_uuid.uuid.uuid16 = GATTS_CHAR_UUID_TEMP;
            my_temp_char_uuid.len = ESP_UUID_LEN_16;
            esp_ble_gatts_add_char(
                param->create.service_handle,
                &my_temp_char_uuid,
                ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
                ESP_GATT_CHAR_PROP_BIT_READ | ESP_GATT_CHAR_PROP_BIT_NOTIFY,
                &gatts_temp_char_val,
                NULL
            );

            // Add Humidity Characteristic
            my_hum_char_uuid.len = ESP_UUID_LEN_16;
            my_hum_char_uuid.uuid.uuid16 = GATTS_CHAR_UUID_HUMID;
            esp_ble_gatts_add_char(
                param->create.service_handle,
                &my_hum_char_uuid,
                ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
                ESP_GATT_CHAR_PROP_BIT_READ | ESP_GATT_CHAR_PROP_BIT_NOTIFY,
                &gatts_humid_char_val,
                NULL
            );
        break;


        // Description added to services  
        case ESP_GATTS_ADD_CHAR_EVT:
            // Add Descriptor to Temperature Characteristic
            if (param->add_char.char_uuid.uuid.uuid16 == GATTS_CHAR_UUID_TEMP) {
                temp_char_handle = param->add_char.attr_handle;
                // Enable description
                #ifdef BLE_DESC
                    esp_ble_gatts_add_char_descr(
                        param->add_char.service_handle,
                        &my_temp_descr_uuid,
                        ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
                        &(esp_attr_value_t){
                            .attr_len = sizeof(cccd_value), 
                            .attr_max_len = sizeof(cccd_value), 
                            .attr_value = cccd_value, 
                        },
                        NULL
                    );
            #endif
            }
            // Add Descriptor to Humidity Characteristic
            else if (param->add_char.char_uuid.uuid.uuid16 == GATTS_CHAR_UUID_HUMID) {
                humid_char_handle = param->add_char.attr_handle;
                #ifdef BLE_DESC
                esp_ble_gatts_add_char_descr(
                        param->add_char.service_handle,
                        &my_hum_descr_uuid,
                        ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE,
                        &(esp_attr_value_t){
                            .attr_len = sizeof(cccd_value), 
                            .attr_max_len = sizeof(cccd_value), 
                            .attr_value = cccd_value, 
                        },
                        NULL
                    );
            #endif
            }
        break;

        // Remote device requests to read the value of a characteristic
        case ESP_GATTS_READ_EVT:
            // Initialize the response structure with zeros
            esp_gatt_rsp_t my_rsp = {0};
            // Clear the array before transmission upto CLEAN_ARRAY_LEN
            memset(my_rsp.attr_value.value, 0x00, CLEAN_ARRAY_LEN);
            // Read request for temperature
            if (param->read.handle == temp_char_handle) {
                my_rsp.attr_value.handle = temp_char_handle;    
                // Convert the float value to int after multiply by factor based upon UUID
                float_to_uint8_arr(&temp_value_C, my_rsp.attr_value.value, TEMP_UUID_SCALE_FACTOR); 
            }
            // Read request for humidity
            else if (param->read.handle == humid_char_handle) {
                my_rsp.attr_value.handle = humid_char_handle;
                // Convert the float value to int after multiply by factor based upon UUID
                float_to_uint8_arr(&humid_value, my_rsp.attr_value.value, HUM_UUID_SCALE_FACTOR);
            }
            // Define length of data to be transmitted 
            my_rsp.attr_value.len = TX_DATA_LEN;
            // Define a custom offset to be skipped while decoding at receiver's end
            my_rsp.attr_value.offset = 0;
            // Define authorization mode
            my_rsp.attr_value.auth_req = ESP_GATT_AUTH_REQ_NONE;
            // Send this scaled value
            esp_err_t ret = esp_ble_gatts_send_response(my_gatts_if, param->read.conn_id, param->read.trans_id,
                                                        ESP_GATT_OK, &my_rsp);
            // Check for valid transmission
            if (ret != ESP_OK) {
                ESP_LOGE(BLE_TAG, "Send Response failed, error code = 0x%X", ret);
            }
            // Display temperature value on the serial monitor
            else if (param->read.handle == temp_char_handle) {
                ESP_LOGI(BLE_TAG, "Temperature Read: %.2f °C (0x%2X%2X)", temp_value_C, my_rsp.attr_value.value[0], my_rsp.attr_value.value[1]);
            }
            // Display humidity value on the serial monitor
            else if (param->read.handle == humid_char_handle){
                ESP_LOGI(BLE_TAG, "Humidity Read: %.2f %% (0x%2X%2X)", humid_value, my_rsp.attr_value.value[0], my_rsp.attr_value.value[1]);
            }
        break;

        // Device connected successfully to ESP-32 
        case ESP_GATTS_CONNECT_EVT:
            my_gatts_if = gatts_if;
            ESP_LOGI(BLE_TAG, "Connection Established! gatts_if = %d", gatts_if);
            break;

        // Device disconnected from ESP-32, start advertisement
        case ESP_GATTS_DISCONNECT_EVT:
            my_gatts_if = ESP_GATT_IF_NONE;
            ESP_LOGE(BLE_TAG, "Disconnected, gatts_if reset! Started advertisement!");
            esp_ble_gap_start_advertising(&my_adv_params);
            break;

        default:
            break;
    }
}

/**
 * @brief - BLE function for updating temperature value
 * @brief - Also notifies client(s)
 * @param[in] new_value (const float) => new temperature value
*/
void update_temperature(const float new_value) {
    temp_value_C = new_value;
    // Indicates a valid connection with a remote device
    if (my_gatts_if != ESP_GATT_IF_NONE) {
        // Updates the temperature value
        esp_ble_gatts_set_attr_value(temp_char_handle, sizeof(temp_value_C), (uint8_t*)&temp_value_C);
        // Sends a notification to subscribed clients about the updated temperature
        esp_ble_gatts_send_indicate(my_gatts_if, 0, temp_char_handle, sizeof(temp_value_C), (uint8_t*)&temp_value_C, false);
    } 
    else {
        ESP_LOGW(BLE_TAG, "\nCannot indicate temperature, no valid connection!\n");
    }
}

/**
 * @brief - BLE function for updating humidity value
 * @brief - Also notifies client(s)
 * @param[in] new_value (const float) => new humidity value
*/
void update_humidity(const float new_value) {
    humid_value = new_value;
    // Indicates a valid connection with a remote device
    if (my_gatts_if != ESP_GATT_IF_NONE) {
        // Updates the humidity value
        esp_ble_gatts_set_attr_value(humid_char_handle, sizeof(humid_value), (uint8_t*)&humid_value);
        // Sends a notification to subscribed clients about the updated humidity
        esp_ble_gatts_send_indicate(my_gatts_if, 0, humid_char_handle, sizeof(humid_value), (uint8_t*)&humid_value, false);
    } 
    else {
        ESP_LOGW(BLE_TAG, "\nCannot indicate humidity, no valid connection!\n");
    }
}

/**
 * @brief - Converts the float value to it's equivalent uint8_t representation
 * @param[in] float_value (const float*) => Pointer to the value
 * @param[out] arr (uint8_t*) => Pointer to the uint8_t array
 * @param[in] factor (uint8_t) => Scaling factor as per UUID
 * @note - Assumed length for array = `TX_DATA_LEN`
*/
void float_to_uint8_arr(const float* float_value, uint8_t* arr, uint8_t factor){
    uint16_t temp = (int16_t) (*float_value * factor);
    // Copy float to it's uint8_t val
    memcpy(arr, &temp, TX_DATA_LEN);
}