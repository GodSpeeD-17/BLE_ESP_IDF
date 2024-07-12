// Custom Libraries
#include "bluetooth.h"
#include "temperature.h"
#include "humidity.h"

// MAIN INFINITE LOOP DELAY
#define LOOP_DELAY_MS   (1000)       
// Repeat Time for character           
#define SEP_LEN         (75)             
// Custom Display       
#define DEFAULT_SEP     (sep('-', SEP_LEN))     

// DEBUGGING MACROS
#define DISPLAY_VALUES

/**
 * @brief - Custom Display Function
 * @param character (char) => Character to be displayed
 * @param len (uint8_t) => Repeat length
*/
static void sep(char, uint8_t);

// Main Entry Point
void app_main(void)
{
    #ifdef DISPLAY_VALUES
        extern float temp_value_C ;
        extern float humid_value;
    #endif

    // Initialise BLE
    init_BLE();

    // Infinite Loop
    while(true){
        // Indicator for loop start
        DEFAULT_SEP;

        // Update the BLE characteristics with the new values
        #ifdef DISPLAY_VALUES
            temp_value_C = get_temp_C();
            humid_value = get_humidity();
            update_temperature(temp_value_C);
            update_humidity(humid_value);
            printf("Temperature = %.2f °C\t Humidity = %.2f %%\n", temp_value_C, humid_value);
        #else
            update_temperature(get_temp_C());
            update_humidity(get_humidity());
        #endif

        // Loop delay for relaxation
        vTaskDelay(pdMS_TO_TICKS(LOOP_DELAY_MS));
    }

}

/**
 * @brief - Custom Display Function
 * @param character (char) => Character to be displayed
 * @param len (uint8_t) => Repeat length
*/
static void sep(char character, uint8_t len){
    for (uint8_t i = 0; i < len; i++)
            printf("%c", character);
        printf("\n");
}