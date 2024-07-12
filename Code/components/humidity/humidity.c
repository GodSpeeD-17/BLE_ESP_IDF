#include "humidity.h"

/**
 * @brief - Dummy Humidity Function
 * @brief - Uses rand() function to generate values 
 * @brief - The range specified by (`HUMID_LOW`, `HUMID_HIGH`)
 * @return - (float) => Current humidity value (%)
*/
float get_humidity(void){
    return ((float)HUMID_LOW + (float)(rand() % (HUMID_HIGH - HUMID_LOW + 1)) + (float)((rand() % (DEC_HIGH_LIM - DEC_LOW_LIM + 1))/100.0));
}
