/*Brumar Florin - Ilie
File name: push_button.h
Date:8/5/2016
Description: push_button.c header file
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

bool read_button_status(); // read the status of the push buttons

#endif /* PUSH_BUTTON_H_ */
