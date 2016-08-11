/*****************************************************************************
 *  Rosian Rad
 *  File name: DemoLPCExpresso2016.c
 *  Date: 8/10/2016
 *	Description: Resource file of the init files for the final project
 ******************************************************************************/

#include "DemoLPCExpresso2016.h"

void DemoLPCExpresso2016_init()
{
	 /*joystick initialization*/
	joystick_init();

	 /*display initialization*/
	GPIOInit();
	init_timer32(0, 10);

	UARTInit(115200);
	UARTSendString((uint8_t*)"OLED - Peripherals\r\n");

	I2CInit( (uint32_t)I2CMASTER, 0 );
	SSPInit();
	ADCInit( ADC_CLK );

	oled_init();


	/*rotary encoder initialization*/
	rotary_init();

	/*seven segment display initialization*/
	led7seg_init();
}
