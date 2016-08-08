/*
 * buzzer.c
 *
 *  Created on: Aug 2, 2016
 *      Author: ioan.bobar
 */


#include "mcu_regs.h"
#include "type.h"
#include "stdio.h"
#include "timer32.h"
#include "gpio.h"
#include "buzzer.h"


volatile uint32_t timer32_0_counter = 0;


/******************************************************************************
** Function name:		TIMER32_0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**						executes each 10ms @ 60 MHz CPU Clock
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER32_0_IRQHandler(void)
{
  LPC_TMR32B0->IR = 1;			/* clear interrupt flag */
  timer32_0_counter++;
  return;
}
/*****************************************************************************
 * ** Function name: delayMS **
 * ** Descriptions: Start the timer delay in milliseconds until elapsed
 * ** 32-bit timer #0 is used **
 * ** Parameters: Delay value in millisecond **
 * ** Returned value: None **
 * *****************************************************************************/
void delayMS(uint16_t BUZZER_u16DelayInMs)
{
	//setup timer #0 for delay
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9); /* Enable 32-bit timer #0 clock */
	LPC_TMR32B0->TCR = 0x02; /* reset timer */
	LPC_TMR32B0->PR = 0x00; /* set prescaler to zero */
	//(SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV) = 48000000 => Timer clock is 48MHz
	LPC_TMR32B0->MR0 = BUZZER_u16DelayInMs * ((SystemCoreClock/LPC_SYSCON->SYSAHBCLKDIV)/ 1000000);
	LPC_TMR32B0->IR = 0xff; /* reset all interrupts (not needed) */
	LPC_TMR32B0->MCR = 0x04; /* stop timer on match */
	LPC_TMR32B0->TCR = 0x01; /* start timer */
	/* wait until delay time has elapsed */
	while (LPC_TMR32B0->TCR & 0x01);
}
/*****************************************************************************
** Function name: playNote
**
** Descriptions: Initialize 32-bit timer #0 for PWM generation
**
** Parameters: noteInUs: Period time (in microseconds) for tone
** 			   durationMs: Length of tone (in milliseconds)
** 			   volume:the duty cycle of the PWM
** Returned value: None
**
*******************************************************************************/
void playNote(uint16_t BUZZER_u16Note, uint16_t BUZZER_u16DurationMs,uint16_t BUZZER_u16Volume) {

    uint16_t BUZZER_u16TimeActive = 0;

    if (BUZZER_u16Note > 0) {

        while (BUZZER_u16TimeActive < (BUZZER_u16DurationMs*1000)) {
            P1_2_HIGH();
            delayMS(0);

            P1_2_LOW();
            delayMs(BUZZER_u16Volume);

            BUZZER_u16TimeActive += BUZZER_u16Note;
        }

    }
    else {
        delay32Ms(0, BUZZER_u16DurationMs);
    }
}





