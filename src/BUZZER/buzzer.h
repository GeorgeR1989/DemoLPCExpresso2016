/*Bobar Ioan
File name: buzzer.h
Date:8/9/2016
Description: Buzzer header file
*/


#include "mcu_regs.h"
#include "type.h"
#include "stdio.h"
#include "timer32.h"
#include "gpio.h"

//High state of the duty cycle
#define P1_2_HIGH() (LPC_GPIO1->DATA |= (0x1<<2))
//Low state of the duty cycle
#define P1_2_LOW()  (LPC_GPIO1->DATA &= ~(0x1<<2))

//Frequencies of notes
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

void delayMS(uint16_t ); //delay to setup the duty cycle of PWM
void playNote(uint16_t, uint16_t, uint16_t); //function control the buzzer


