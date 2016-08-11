/*****************************************************************************
 *  Rosian Rad
 *  File name: DemoLPCExpresso2016.c
 *  Date: 8/10/2016
 *	Description: Header file of the main function for the final project
 ******************************************************************************/

#ifndef DEMOLPCEXPRESSO2016_H_
#define DEMOLPCEXPRESSO2016_H_

/*Header files*/

#include "type.h"
#include "gpio.h"
#include "joystick.h"
#include "mcu_regs.h"
#include "timer32.h"
#include "type.h"
#include "uart.h"
#include "i2c.h"
#include "ssp.h"
#include "adc.h"
#include "oled.h"
#include "temp.h"
#include "stdbool.h"
#include "rotary.h"
#include "led7seg.h"



/*Defines*/

#define ASCII_Val_0 (48)
#define MIN_VALUE (0)     /* MIN_VALUE */
#define MAX_VALUE (3)     /* and MAX_VALUE represents the limits of the set which will be returned */
#define OVERFLOW  (255)   /* Use OVERFLOW when the set includes 0 */
#define ADC_CHANNEL (5)   /* we will use channel 5 to read the button statusb */
#define P1_2_HIGH() (LPC_GPIO1->DATA |= (0x1<<2))   //High state of the duty cycle
#define P1_2_LOW()  (LPC_GPIO1->DATA &= ~(0x1<<2))  //Low state of the duty cycle



/*Main functions*/
void DemoLPCExpresso2016_init(void);
void ledSet(uint8_t value);
void init_display (void);
void temp_display(void);
void delayMS(uint16_t );
void playNote(uint16_t, uint16_t, uint16_t);

char joystickPosition(void);
uint8_t rotary_encoder(void);
uint32_t temp_conversion (bool change_unit);

bool read_button_status();

void DemoLPCExpresso2016_init();


/*Variables*/
static uint16_t notes[] = {
        2272, // A - 440 Hz
        2024, // B - 494 Hz
        3816, // C - 262 Hz
        3401, // D - 294 Hz
        3030, // E - 330 Hz
        2865, // F - 349 Hz
        2551, // G - 392 Hz
        1136, // a - 880 Hz
        1012, // b - 988 Hz
        1912, // c - 523 Hz
        1703, // d - 587 Hz
        1517, // e - 659 Hz
        1432, // f - 698 Hz
        1275, // g - 784 Hz
};

#endif /* DEMOLPCEXPRESSO2016_H_ */
