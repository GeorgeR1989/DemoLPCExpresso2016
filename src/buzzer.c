/*Bobar Ioan
File name: buzzer.c
Date:8/9/2016
Description: Buzzer resource file
*/

#include "DemoLPCExpresso2016.h"

volatile uint32_t timer16_0_counter = 0;
volatile uint32_t timer16_1_counter = 0;

/******************************************************************************
** Function name:		TIMER32_0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**						executes each 10ms @ 60 MHz CPU Clock
**
** parameters:			None
** Returned value:		None
**
******************************************************************************
/*****************************************************************************
 * ** Function name: BUZZER_u16DelayInMs **
 * ** Descriptions: Start the timer delay in milliseconds until elapsed
 * ** 32-bit timer #0 is used **
 * ** Parameters: Delay value in millisecond **
 * ** Returned value: None **
 * *****************************************************************************/
/*****************************************************************************
** Function name: playNote
**
** Descriptions: Initialize 32-bit timer #0 for PWM generation
**
** Parameters: BUZZER_u16Note: Period time (in microseconds) for tone
** 			   BUZZER_u16DurationMs: Length of tone (in milliseconds)
** 			   BUZZER_u16Volume:the duty cycle of the PWM
** Returned value: None
**
*******************************************************************************/
/*
static void playNote(uint32_t note, uint32_t durationMs) {
    uint32_t t = 0;
    if (note > 0) {
        while (t < (durationMs*1000)) {
            P1_2_HIGH();
            delay32Us(0, note / 2);
            P1_2_LOW();
            delay32Us(0, note / 2);
            t += note;
        }
    }
    else {
        delay32Ms(0, durationMs);
    }
}
*/






/*TIMER FUNCTIONS*/
/*===============================================================================*/
/**
 * @brief	Determine if a match interrupt is pending
 * @param	pTMR		: Pointer to timer IP register address
 * @param	matchnum	: Match interrupt number to check
 * @return	false if the interrupt is not pending, otherwise true
 * @note	Determine if the match interrupt for the passed timer and match
 * counter is pending.
 */
STATIC INLINE uint8_t Chip_TIMER_MatchPending(LPC_TMR_TypeDef *pTMR, int8_t matchnum)
{
	return (uint8_t) ((pTMR->IR & TIMER_MATCH_INT(matchnum)) != 0);
}

/**
 * @brief	Clears a (pending) match interrupt
 * @param	pTMR		: Pointer to timer IP register address
 * @param	matchnum	: Match interrupt number to clear
 * @return	Nothing
 * @note	Clears a pending timer match interrupt.
 */
STATIC INLINE void Chip_TIMER_ClearMatch(LPC_TMR_TypeDef *pTMR, int8_t matchnum)
{
	pTMR->IR = TIMER_IR_CLR(matchnum);
}


/**
 * @brief	Enables the timer (starts count)
 * @param	pTMR	: Pointer to timer IP register address
 * @return	Nothing
 * @note	Enables the timer to start counting.
 */
STATIC INLINE void Chip_TIMER_Enable(LPC_TMR_TypeDef *pTMR)
{
	pTMR->TCR |= TIMER_ENABLE;
}

/**
 * @brief	Disables the timer (stops count)
 * @param	pTMR	: Pointer to timer IP register address
 * @return	Nothing
 * @note	Disables the timer to stop counting.
 */
STATIC INLINE void Chip_TIMER_Disable(LPC_TMR_TypeDef *pTMR)
{
	pTMR->TCR &= ~TIMER_ENABLE;
}

/**
 * @brief	Resets the timer terminal and prescale counts to 0
 * @return	Nothing
 */
/**
 * @brief	Resets the timer terminal and prescale counts to 0
 * @return	Nothing
 */


/*===============================================================================*/

/*****************************************************************************
** Function name:		setTimer16
**
** Descriptions:		Set TIMER for PWM functionality
**
** parameters:			None
**
** Returned value:		None
**
*****************************************************************************/




/*****************************************************************************
** Function name:		TIMER16_0_IRQHandler
**
** Descriptions:		Handles the interrupts from TIMER16B0 and modulates the PWM signals
**
** parameters:			None
**
** Returned value:		None
**
*****************************************************************************/


void setNote(uint16_t note)
{
	Chip_TIMER_Disable(LPC_TMR16B0);

	LPC_TMR16B0->MR0 = note;

	Chip_TIMER_Enable(LPC_TMR16B0);
}
void setIntensity(uint8_t pwmValue)
{
	Chip_TIMER_Disable(LPC_TMR16B0);

	LPC_TMR16B0->MR1 = LPC_TMR16B0->MR0 * pwmValue / 100;

	Chip_TIMER_Enable(LPC_TMR16B0);
}
void startMusic()
{
	Chip_TIMER_Enable(LPC_TMR16B0);
}
void stopMusic()
{
	Chip_TIMER_Disable(LPC_TMR16B0);
}
