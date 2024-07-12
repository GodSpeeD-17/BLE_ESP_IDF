#include "temperature.h"

/**
 * @brief - Dummy Temperature Function
 * @brief - Uses rand() function to generate values 
 * @brief - The range specified by (`TEMP_LOW`, `TEMP_HIGH`)
 * @return - (float) => Current temperature (°C)
*/
float get_temp_C(void){
    return ((float)TEMP_LOW + (float)(rand() % (TEMP_HIGH - TEMP_LOW + 1)) + (float)((rand() % (DEC_HIGH_LIM - DEC_LOW_LIM + 1))/100.0));
}