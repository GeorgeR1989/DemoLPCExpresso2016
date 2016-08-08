/*Bradescu Tudor-Ioan
File name: display.h
Date:8/2/2016
Description: OLED temperature display header file
*/
#include "mcu_regs.h"
#include "type.h"
#include "uart.h"
#include "stdio.h"
#include "timer32.h"
#include "i2c.h"
#include "gpio.h"
#include "ssp.h"
#include "adc.h"
#include "oled.h"
#include "temp.h"

void init_display (void); //initializes the oled display on the board(setup function)
void temp_display(void);  //displays the current temperature from the temperature sensor (while(1) function)
void init_temp(void); //test function
