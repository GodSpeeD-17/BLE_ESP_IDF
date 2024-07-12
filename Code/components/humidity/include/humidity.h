#ifndef __HUMIDITY_H
#define __HUMIDITY_H

#include <stdio.h>
#include <stdlib.h>

// Humidity Value Lower Limit
#define HUMID_LOW       (50)
// Humidity Value Higher Limit
#define HUMID_HIGH      (100)
// Decimal Point Lower Limit
#define DEC_LOW_LIM     (0)
// Decimal Point Higher Limit
#define DEC_HIGH_LIM    (99)

/**
 * @brief - Dummy Humidity Function
 * @brief - Uses rand() function to generate values 
 * @brief - The range specified by (`HUMID_LOW`, `HUMID_HIGH`)
 * @return - (float) => Current humidity value (%)
*/
float get_humidity(void);

#endif