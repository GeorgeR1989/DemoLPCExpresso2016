/*Brumar Florin - Ilie
File name: temperature.h
Date:8/5/2016
Description:  temperature module header file
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

uint32_t temp_conversion (bool change_unit);  // make a conversion from Celsius ti Fahreinheit or Fahreinheit to Celsius

#endif /* TEMPERATURE_H_ */
