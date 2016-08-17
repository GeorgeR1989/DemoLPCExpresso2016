#include "display.h"
#include "push_button.h"

uint32_t value = 0;
static uint32_t msTicks = 0;

void SysTick_Handler(void) {  //counts the number of clock ticks
    msTicks++;
}
static uint32_t getTicks(void) //return the number of clock ticks
{
    return msTicks;
}
void init_display (void)
{


    GPIOInit();
    init_timer32(0, 10);

    UARTInit(115200);
    UARTSendString((uint8_t*)"OLED - Peripherals\r\n");

    I2CInit( (uint32_t)I2CMASTER, 0 );
    SSPInit();
    ADCInit( ADC_CLK );

     oled_init();
     temp_init (&getTicks);


    /* setup sys Tick. Elapsed time is e.g. needed by temperature sensor */
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
      oled_clearScreen(OLED_COLOR_WHITE);
    }
}

void display(void)
{

	value = read_button_status();
	  if(1==value)
	  {
	    oled_clearScreen(OLED_COLOR_WHITE);
	    oled_putString(1,1,  (uint8_t*)"Pressed", OLED_COLOR_BLACK, OLED_COLOR_WHITE);
	    delay32Ms(0,100);
	  }
	 if(0==value)
	 {

		  oled_putString(1,1,  (uint8_t*)"Not pressed", OLED_COLOR_BLACK, OLED_COLOR_WHITE);
	  }
}



int main()
{
	  ADCInit( ADC_CLK );
	  init_display();

while(1)
{
	display();
}

}



