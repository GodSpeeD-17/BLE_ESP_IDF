#ifndef __TEMPERATURE_H
#define __TEMPERATURE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Temperature Value Lower Limit
#define TEMP_LOW        (20)   
// Temperature Value Higher Limit
#define TEMP_HIGH       (40)
// Decimal Point Lower Limit
#define DEC_LOW_LIM     (0)
// Decimal Point Higher Limit
#define DEC_HIGH_LIM    (99)

/**
 * @brief - Dummy Temperature Function
 * @brief - Uses rand() function to generate values 
 * @brief - The range specified by (`TEMP_LOW`, `TEMP_HIGH`)
 * @return - (float) => Current temperature (°C)
*/
float get_temp_C(void);

#endif
