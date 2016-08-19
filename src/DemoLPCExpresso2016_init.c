/*****************************************************************************
 *  Rosian Rad
 *  File name: DemoLPCExpresso2016.c
 *  Date: 8/10/2016
 *	Description: Resource file of the init files for the final project
 ******************************************************************************/

#include "DemoLPCExpresso2016.h"


void DemoLPCExpresso2016_init()
{
	 //joystick initialization
	joystick_init();

	// display initialization
	GPIOInit();
	init_timer32(0, 10);

	UARTInit(115200);
	UARTSendString((uint8_t*)"OLED - Peripherals\r\n");

	I2CInit( (uint32_t)I2CMASTER, 0 );
	SSPInit();
	ADCInit( ADC_CLK );

<<<<<<< HEAD
	 SysTick_Config(SystemCoreClock / 1000);
	    if ( !(SysTick->CTRL & (1<<SysTick_CTRL_CLKSOURCE_Msk)) )
	    {
	      /* When external reference clock is used(CLKSOURCE in
	      Systick Control and register bit 2 is set to 0), the
	      SYSTICKCLKDIV must be a non-zero value and 2.5 times
	      faster than the reference clock.
	      When core clock, or system AHB clock, is used(CLKSOURCE
	      in Systick Control and register bit 2 is set to 1), the
	      SYSTICKCLKDIV has no effect to the SYSTICK frequency. See
	      more on Systick clock and status register in Cortex-M3
	      technical Reference Manual. */
	      LPC_SYSCON->SYSTICKCLKDIV = 0x08;
	    }



	init_display();
	//oled_init();
	//init_buzzer();
=======
	oled_init();
	init_display();
	init_buzzer();
>>>>>>> 8fbbc685ff1ec4b9acdc28c5a667f79e2cfc6dff

	rgb_init();


	/*rotary encoder initialization*/
	rotary_init();

	/*seven segment display initialization*/
	led7seg_init();

}
