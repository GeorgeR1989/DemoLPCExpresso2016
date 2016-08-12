/*
===============================================================================
 Name        : rgbLED.c
 Author      : Dorin-Stefan Deac
 Version     : 1.0
 Date        : 8/5/2016
 Description : RGB module implementation
===============================================================================
*/

#include "rgbLED.h"



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

	LPC_TMR16B0->PR = ((SystemCoreClock/100000));
    LPC_TMR16B0->TC = 1;

	LPC_TMR16B0->MR0 = DEFAULT_INTENSITY;   /* Default intensity RED   */
	LPC_TMR16B0->MR1 = DEFAULT_INTENSITY;	/* Default intensity GREEN   */
	LPC_TMR16B0->MR2 = DEFAULT_INTENSITY;   /* Default intensity BLUE   */
	LPC_TMR16B0->MR3 = RGB_TIMING;   /* Timing  */

	LPC_TMR16B0->MCR = TIMER_INT_ON_MATCH(0)+		/* Interrupt MR0 */
			TIMER_INT_ON_MATCH(1) +		/* Interrupt MR1 */
			TIMER_INT_ON_MATCH(2) +		/* Interrupt MR2 */
			TIMER_INT_ON_MATCH(3) +		/* Interrupt MR3 */
			TIMER_RESET_ON_MATCH(3);	/* Reset on interrupt MR3 */

	/*Enable the TIMER0 */

	/* Enable the TIMER0 Interrupt */
	NVIC_EnableIRQ(TIMER_16_0_IRQn);
}


/*****************************************************************************
** Function name:		init_rgbLED
**
** Descriptions:		Activate the RGB module
**
** parameters:			None
**
** Returned value:		None
**
*****************************************************************************/
void init_rgbLED(void)
{
    rgb_init();                   /* Initialize pins as output */
    setTimer16();                 /* Set timer for controlling the intensity of the leds with a PWM signal*/

    GPIOSetValue( PORT1, 9, 1 );  /* RED    - HIGH */
    GPIOSetValue( PORT1, 10, 1 ); /* GREEN  - HIGH */
    GPIOSetValue( PORT1, 2, 1 );  /* BLUE   - HIGH */

    Chip_TIMER_Enable(LPC_TMR16B0);
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
		GPIOSetValue( PORT1, 9, 0 );  /* RED    - LOW */
	}
	if(Chip_TIMER_MatchPending(LPC_TMR16B0, 1))
	{
		Chip_TIMER_ClearMatch(LPC_TMR16B0, 1);
		GPIOSetValue( PORT1, 10, 0 ); /* GREEN  - LOW */
	}
	if(Chip_TIMER_MatchPending(LPC_TMR16B0, 2))
	{
		Chip_TIMER_ClearMatch(LPC_TMR16B0, 2);
		GPIOSetValue( PORT1, 2, 0 );  /* BLUE    - LOW */
	}
	if(Chip_TIMER_MatchPending(LPC_TMR16B0, 3))
	{
		Chip_TIMER_ClearMatch(LPC_TMR16B0, 3);  /* HIGH all pins */
		GPIOSetValue( PORT1, 9, 1 );  /* RED    - HIGH */
		GPIOSetValue( PORT1, 10, 1 ); /* GREEN  - HIGH */
		GPIOSetValue( PORT1, 2, 1 );  /* BLUE   - HIGH */
	}

}

/*****************************************************************************
** Function name:		setColor_rgb
**
** Descriptions:		Sets the new comparation values ( intensity of LED) for timer registers
**
** parameters:			uint8_t red (intensity of red LED)
** 						uint8_t green (intensity of green LED)
** 						uint8_t blue (intensity of blue LED)
**
** Returned value:		None
**
*****************************************************************************/
void setColor_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	Chip_TIMER_Disable(LPC_TMR16B0);

	LPC_TMR16B0->MR0 = red;       /* SET intensity RED   */
	LPC_TMR16B0->MR1 = green;	  /* SET intensity GREEN   */
	LPC_TMR16B0->MR2 = blue;      /* SET intensity BLUE   */

	Chip_TIMER_Enable(LPC_TMR16B0);
}

/*****************************************************************************
** Function name:		rgbRainbow
**
** Descriptions:		Demo functionality of RGB modula
**
** parameters:			None
**
** Returned value:		None
**
*****************************************************************************/
void rgbRainbow(void)
{
	uint8_t red = 50;          /* SET initial intensity RED   */
	uint8_t green = 100;       /* SET initial intensity GREEN   */
	uint8_t blue = 150;        /* SET initial intensity BLUE   */

	init_timer32(1, 10);
	init_rgbLED();             /* Set module RGB */


	while(1)
    {
		/* This variables are used to set a pseudo-rainbow */
		red += 5;
		green += 7;
	    blue += 10;
	    setColor_rgb(red, green, blue);  /* SET new color */
	    delay32Ms(1,200);                /* Delay 200 ms */
	}

}
