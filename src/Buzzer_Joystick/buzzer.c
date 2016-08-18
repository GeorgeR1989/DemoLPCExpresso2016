/*Bobar Ioan
File name: buzzer.c
Date:8/9/2016
Description: Buzzer resource file
*/

#include "buzzer.h"

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


void playNote(uint32_t BUZZER_u16Note, uint32_t BUZZER_u16DurationMs,uint32_t BUZZER_u16VolumeUp) {

    uint32_t BUZZER_u16TimeActive = 0;

    if (BUZZER_u16Note > 0) {
// In the while loop buzzer functionality is controlled by frequency and volume.
// The volume control is depending to how long time the duty cycle is on high state or low state.

    	while (BUZZER_u16TimeActive < (BUZZER_u16DurationMs*1000)) {
            P1_2_HIGH();
            delayMS_High(BUZZER_u16VolumeUp/4);

            P1_2_LOW();
            delay32Us(0,3*BUZZER_u16VolumeUp/4);


            BUZZER_u16TimeActive += BUZZER_u16Note;
        }

    }
    else {
        delay32Ms(0, BUZZER_u16DurationMs);
    }
}



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
void Chip_TIMER_Reset(LPC_TMR_TypeDef *pTMR)
{
	uint32_t reg;

	/* Disable timer, set terminal count to non-0 */
	reg = pTMR->TCR;
	pTMR->TCR = 0;
	pTMR->TC = 1;

	/* Reset timer counter */
	pTMR->TCR = TIMER_RESET;

	/* Wait for terminal count to clear */
	while (pTMR->TC != 0) {}

	/* Restore timer state */
	pTMR->TCR = reg;
}

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
void setTimer16(void)
{
	Chip_TIMER_Reset(LPC_TMR16B0);
	/*Activate TIMER */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);

	LPC_TMR16B0->PR = ((SystemCoreClock/1000000));
    LPC_TMR16B0->TC = 1;

	LPC_TMR16B0->MR0 = 2272;   /* Frequencies note  */
	LPC_TMR16B0->MR1 = 500;	/* Intensity  */

	LPC_TMR16B0->MCR = TIMER_INT_ON_MATCH(0) +		/* Interrupt MR0 */
			TIMER_RESET_ON_MATCH(0) +    /* Reset on interrupt MR0 */
			TIMER_INT_ON_MATCH(1);		/* Interrupt MR1 */


	/*Enable the TIMER0 */

	/* Enable the TIMER0 Interrupt */
	NVIC_EnableIRQ(TIMER_16_0_IRQn);
}



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
void TIMER16_0_IRQHandler(void)
{
	if(Chip_TIMER_MatchPending(LPC_TMR16B0, 0))
	{
		Chip_TIMER_ClearMatch(LPC_TMR16B0, 0);
		P1_2_HIGH();  /* RED    - LOW */
	}
	if(Chip_TIMER_MatchPending(LPC_TMR16B0, 1))
	{
		Chip_TIMER_ClearMatch(LPC_TMR16B0, 1);
		P1_2_LOW(); /* GREEN  - LOW */
	}
}

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
