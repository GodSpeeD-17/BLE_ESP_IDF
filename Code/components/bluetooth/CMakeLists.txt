idf_component_register(SRCS "bluetooth.c"
                    INCLUDE_DIRS "include"
                    REQUIRES "bt" "freertos" "esp_system" "log" "nvs_flash")