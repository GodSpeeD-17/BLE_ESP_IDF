/*
    => Reference UUID structure for Temperature: https://github.com/atc1441/ATC_MiThermometer/issues/150
        - Just multiply the float value by UUID_FACTOR (because UUID has default precision of pre-defined decimals) to int16_t
        - For eg: 
            UUID = 0x2A6E -> UUID_FACTOR = 100 (0.01 °C) [Used] {GATTS_CHAR_UUID_TEMP}
            UUID = 0x2A1F -> UUID_FACTOR = 10 (0.1 °C)
            UUID = 0x2A1C -> UUID_FACTOR = ? (float °C) [Could not find anything]
        - Convert it to equivalent uint8_t array representation (refer function float_to_uint8()) 

    => Reference UUID structure for Humidity: 
        - Just multiply the float value by UUID_FACTOR (because UUID has default precision of 2 decimals) to int16_t
        - Only one case: UUID = 0x2A6F -> UUID_FACTOR = 100 [Used] {GATTS_CHAR_UUID_HUMID}
        - Convert it to equivalent uint8_t array representation (refer function float_to_uint8()) 
 */

// Header Guards
#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

// Basic C Library 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Generic Library
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gatt_common_api.h"

// MACROS

// ESP32 Discoverable Device Name
#define DEVICE_NAME                 ((const char*) "ESP32_TEMP_HUM")
#define GATTS_SERVICE_UUID          (0x00FF)
// Number of connections
#define GATTS_NUM_HANDLE              (10)
#define PROFILE_NUM                   (1)
#define PROFILE_APP_IDX               (0)
#define ESP_APP_ID                    (0x55)

// Temperature (0.01 °C) -> UUID: 0x2A6E
#define GATTS_CHAR_UUID_TEMP        ((uint16_t)0x2A6E)
// Depends upon UUID (UUID: 0x2A6E -> Scale Factor: 100)  
#define TEMP_UUID_SCALE_FACTOR      ((uint8_t)100)      

// Humidity: (0.01 %) -> UUID: 0x2A6F
#define GATTS_CHAR_UUID_HUMID       ((uint16_t)0x2A6F)      
// Depends upon UUID (UUID: 0x2A6F -> Scale Factor: 100)  
#define HUM_UUID_SCALE_FACTOR       ((uint8_t)100)          

// Number of array indices to be set to 0 before transmission {ESP_GATTS_READ_EVT}
#define CLEAN_ARRAY_LEN               (10)
// Transmission Data Length {ESP_GATTS_READ_EVT}
#define TX_DATA_LEN                   ((uint8_t)2)

// DEBUG MACROS
// #define BLE_DESC


/**
 * @brief - Initialises the Bluetooth Stack on ESP-32 with default configuration
 * @note - The Bluetooth stack is up and running at this point in the program flow
 * @note - However the functionality of the application has not been defined yet
*/
void init_BLE(void);

/**
 * @brief - GAP Event Handler
 * @brief - Advertisement phase
*/
void my_gap_event_handler(esp_gap_ble_cb_event_t, esp_ble_gap_cb_param_t *);

/**
 * @brief - GATTs Profile Event Handler
 * @brief - Deals with `ESP_GATTS_CREATE_EVT` (Description for Service)
 * @brief - Deals with `ESP_GATTS_READ_EVT` (Response when requested)
*/
void my_gatts_profile_event_handler(esp_gatts_cb_event_t, esp_gatt_if_t, esp_ble_gatts_cb_param_t *);

/**
 * @brief - BLE function for updating temperature value
 * @brief - Also notifies client(s)
 * @param[in] new_value (const float) => new temperature value
*/
void update_temperature(const float);

/**
 * @brief - BLE function for updating humidity value
 * @brief - Also notifies client(s)
 * @param[in] new_value (float) => new humidity value
*/
void update_humidity(const float);

/**
 * @brief - Converts the float value to it's equivalent uint8_t representation
 * @param[in] float_value (const float*) => Pointer to the value
 * @param[out] arr (uint8_t*) => Pointer to the uint8_t array
 * @param[in] factor (uint8_t) => Scaling factor as per UUID
 * @note - Assumed length for array = `TX_DATA_LEN`
*/
void float_to_uint8_arr(const float*, uint8_t*, uint8_t);

#endif