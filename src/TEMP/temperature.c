/*
===============================================================================
 Name        : temperature.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "temperature.h"

/*..........................................................................................*/


                  /*           Local variables                     */


volatile bool button_press = FALSE;
volatile bool button_1  = TRUE;
volatile bool button_2 =TRUE;
volatile bool previous_state =TRUE;
static uint32_t msTicks = 0;


/*..........................................................................................*/



void SysTick_Handler(void)
{
    msTicks++;
}


static uint32_t getTicks(void)
{
    return msTicks;
}

/*...............................................................................................*/

/* the related function read the value from pins 0.1 and 1.4, where the push buttons are connected
 * and return true or false in button_press variable if one of those buttons are pressed or not*/

bool read_button_status()
{

	button_1 = GPIOGetValue (0, 1);
	button_2 = GPIOGetValue (1, 4);

	if((button_1==FALSE)||(button_2==FALSE))
	{
		button_press = TRUE;
	}
}

/*................................................................................................*/
/* temp_conversion function make the conversion of temperature unit from Celsius to Fahreinheit or
 * Fahreinheit to Celsius, depends on previous state, if a button is pressed */

uint32_t temp_conversion (bool change_unit)

{
	int32_t t = 0;
	int32_t t_unit = 0;

	    /* Read temperature */

	        t = temp_read();

	   if((change_unit == TRUE) && (previous_state == TRUE))
	   {
		   t_unit = (t * 9 / 5 + 32 ) * 10;
             previous_state = FALSE;
	   }
       	if((change_unit == TRUE) && (previous_state == FALSE))
	   {
		   t_unit = t;
		   previous_state = TRUE;
	   }

       /* delay */

     delay32Ms(0, 200);

	   return t_unit;
}
/*.................................................................................................*/

int main (void)
{

    GPIOInit();

    init_timer32(0, 10);

    temp_init(&getTicks);

    /* setup sys Tick. Elapsed time is e.g. needed by temperature sensor */

    SysTick_Config(SystemCoreClock / 1000);

    if ( !(SysTick->CTRL & (1<<SysTick_CTRL_CLKSOURCE_Msk)) )
    {

      LPC_SYSCON->SYSTICKCLKDIV = 0x08;
    }

  while(1)
  {
	  read_button_status();
	  temp_conversion (button_press);
	  delay32Ms(0, 500);

  }
  }

