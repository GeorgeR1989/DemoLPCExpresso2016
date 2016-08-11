/*Brumar Florin - Ilie
File name: push_button.h
Date:8/5/2016
Description:  push button module header file
 */

#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

#include "mcu_regs.h"
#include "type.h"
#include "stdio.h"
#include "timer32.h"
#include "gpio.h"
#include "stdbool.h"
#include "adc.h"

#define ADC_CHANNEL (5)  /* we will use channel 5 to read the button statusb */

uint32_t read_button_status(); // read the status of the push button

#endif /* PUSH_BUTTON_H_ */
