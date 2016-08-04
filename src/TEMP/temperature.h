/*
 * temperature.h
 *
 *  Created on: Aug 3, 2016
 *      Author: florin.brumar
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_


#include "stdio.h"
#include "gpio.h"
#include "core_cm0.h"
#include "type.h"
#include "stdio.h"
#include "stdint.h"
#include "temp.h"
#include "stdbool.h"
#include "timer32.h"

bool read_button_status(void);
uint32_t temp_conversion (bool change_unit);

#endif /* TEMPERATURE_H_ */
