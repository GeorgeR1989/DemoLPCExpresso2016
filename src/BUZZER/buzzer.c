/*
 * buzzer.c
 *
 *  Created on: Aug 2, 2016
 *      Author: ioan.bobar
 */


#include "mcu_regs.h"
#include "type.h"
#include "uart.h"
#include "stdio.h"
#include "timer32.h"
#include "gpio.h"
#include "buzzer.h"
#include "pca9532.h"
//#include "LPC11xx.h"


volatile uint32_t timer32_0_counter = 0;



void TIMER32_0_IRQHandler(void)
{
  LPC_TMR32B0->IR = 1;			/* clear interrupt flag */
  timer32_0_counter++;
  return;
}



void delayMS(uint32_t delayInMs)
{
	//setup timer #0 for delay
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9); /* Enable 32-bit timer #0 clock */
	LPC_TMR32B0->TCR = 0x02; /* reset timer */
	LPC_TMR32B0->PR = 0x00; /* set prescaler to zero */
	//(SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV) = 48000000 => Timer clock is 48MHz
	LPC_TMR32B0->MR0 = delayInMs * ((SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV)/ 1000000);
	LPC_TMR32B0->IR = 0xff; /* reset all interrupts (not needed) */
	LPC_TMR32B0->MCR = 0x04; /* stop timer on match */
	LPC_TMR32B0->TCR = 0x01; /* start timer */
	/* wait until delay time has elapsed */
	while (LPC_TMR32B0->TCR & 0x01);
}




/*****************************************************************************
** Function name: initPWM
**
** Descriptions: Initialize 16-bit timer #1 for PWM generation
** **
** Parameters: cycleLength: set PWM cycle length in microseconds
**
** Returned value: None
**
*****************************************************************************/


void initPWM(uint16_t cycleLengthInUs)
{
	CLKOUT_Setup(LPC_CT32B0_BASE);
	CLKOUT_Setup(LPC_CT32B1_BASE);
 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<8); /* Enable timer #1 (enable clock to block) */


 GPIOSetDir( PORT1, 9, 1 );
 GPIOSetDir( PORT1, 10, 1 );


 GPIOSetDir( PORT3, 0, 1 );
 GPIOSetDir( PORT3, 1, 1 );
 GPIOSetDir( PORT3, 2, 1 );
 GPIOSetDir( PORT1, 2, 1 );

 LPC_IOCON->JTAG_nTRST_PIO1_2 = (LPC_IOCON->JTAG_nTRST_PIO1_2 & ~0x7) | 0x01;

    GPIOSetValue( PORT3, 0, 0 );  //LM4811-clk
    GPIOSetValue( PORT3, 1, 0 );  //LM4811-up/dn
    GPIOSetValue( PORT3, 2, 0 );  //LM4811-shutdn


 LPC_IOCON->PIO1_9= (LPC_IOCON->PIO1_9 & ~(0x3FF)) | 0x2;
 LPC_IOCON->PIO1_10= (LPC_IOCON->PIO1_10 & ~(0x3FF)) | 0x2;
 //setup I/O pins to be MAT-outputs

 LPC_TMR32B0->TCR = 0x02; /* reset timer */
 /* Set prescaler so that timer counts in us-steps */
 /*(SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV) = 48000000 => Timer clock is 48MHz */
 LPC_TMR32B0->PR = ((SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV) / 1000000) - 1;
 LPC_TMR32B0->MR2 = cycleLengthInUs;
 //Setup match registers to generate a PWM signal with 0% duty = constant low
 LPC_TMR32B0->MR0 = LPC_TMR32B0->MR2;
 LPC_TMR32B0->MR1 = LPC_TMR32B0->MR2;
 LPC_TMR32B0->IR = 0xff; /* reset all interrupts (not needed) */
 LPC_TMR32B0->MCR = (1<<7); /* reset timer on MR2 match */
 LPC_TMR32B0->PWMC = (1<<0) | (1<<1); /* Enable PWM mode for MAT0 and MAT1 */
}

/*****************************************************************************
** Function name: startPWM
**
** Descriptions: Start 16-bit timer #1
**
** Parameters: None
**
** Returned value: None
**
*****************************************************************************/
void startPWM(void)
{
	LPC_TMR32B0->TCR = 0x01; /* start timer (16B1) = start generating PWM signal(s) */
}

/*****************************************************************************
** Function name: stopPWM
**
** Descriptions: Stop 32-bit timer #1
**
** Parameters: None
**
** Returned value: None
**
*****************************************************************************/
void stopPWM(void)
{
	LPC_TMR32B0->TCR = 0x00; /* stop timer (16B1) = stop generating PWM signal(s) */
}

/*****************************************************************************
** Function name: updatePWM
**
** Descriptions: Update the PWM output setting
**
** Parameters: channel: selects with PWM signals to update (0 or 1)
** value: set duty cycle (a value between 0 and 100)
**
** Returned value: None
**
*****************************************************************************/

void updatePWM( uint8_t channel, uint8_t value)
{
uint32_t matchValue;
matchValue = ((LPC_TMR32B0->MR2 * (100 - value)) / 100);
if (channel == 0)
	LPC_TMR32B0->MR0 = matchValue;
else if (channel == 1)
	LPC_TMR32B0->MR1 = matchValue;
}


void playNote(uint32_t note, uint32_t durationMs) {

    uint32_t t = 0;

    if (note > 0) {

        while (t < (durationMs*1000)) {
            P1_2_HIGH();
            delayMS(note/4);

            P1_2_LOW();
            delayMs(3*note/4);

            t += note;
        }

    }
    else {
        delay32Ms(0, durationMs);
    }
}


void playNote2(uint32_t note, uint32_t durationMs) {

    uint32_t t = 0;

    if (note > 0) {

        while (t < (durationMs*1000)) {
            P1_2_HIGH();
            delay32Ms(0,3*note/4 );

            P1_2_LOW();
            delay32Ms(0, note/4);

            t += note;
        }

    }
    else {
        delay32Ms(0, durationMs);
    }
}



