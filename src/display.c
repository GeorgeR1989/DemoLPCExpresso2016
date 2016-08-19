/*Bradescu Tudor-Ioan
File name: display.c
Date:8/2/2016
Description: OLED temperature display resource file
*/

#include "DemoLPCExpresso2016.h"

static uint32_t msTicks = 0;
static uint8_t buf[10];


static void intToString(int value, uint8_t* pBuf, uint32_t len, uint32_t base)  //converts to string an integer value

{
    static const char* pAscii = "0123456789abcdefghijklmnopqrstuvwxyz";
    int pos = 0;
    int tmpValue = value;

    // the buffer must not be null and at least have a length of 2 to handle one
    // digit and null-terminator
    if (pBuf == NULL || len < 2)
    {
        return;
    }

    // a valid base cannot be less than 2 or larger than 36
    // a base value of 2 means binary representation. A value of 1 would mean only zeros
    // a base larger than 36 can only be used if a larger alphabet were used.
    if (base < 2 || base > 36)
    {
        return;
    }

    // negative value
    if (value < 0)
    {
        tmpValue = -tmpValue;
        value    = -value;
        pBuf[pos++] = '-';
    }

    // calculate the required length of the buffer
    do {
        pos++;
        tmpValue /= base;
    } while(tmpValue > 0);


    if (pos > len)
    {
        // the len parameter is invalid.
        return;
    }

    pBuf[pos] = '\0';

    do {
        pBuf[--pos] = pAscii[value % base];
        value /= base;
    } while(value > 0);

    return;

}
void SysTick_Handler(void) {  //counts the number of clock ticks
    msTicks++;
}
static uint32_t getTicks(void) //return the number of clock ticks
{
    return msTicks;
}
void init_display (void)
{

<<<<<<< HEAD
	/* GPIOInit();
=======
	 GPIOInit();
>>>>>>> 8fbbc685ff1ec4b9acdc28c5a667f79e2cfc6dff
	    init_timer32(0, 10);

	    UARTInit(115200);
	    UARTSendString((uint8_t*)"OLED - Peripherals\r\n");

	    I2CInit( (uint32_t)I2CMASTER, 0 );
	    SSPInit();
	    ADCInit( ADC_CLK );
<<<<<<< HEAD
*/
	   /*  oled_init();*/
=======

	     oled_init();
>>>>>>> 8fbbc685ff1ec4b9acdc28c5a667f79e2cfc6dff
	     temp_init (&getTicks);
    /* setup sys Tick. Elapsed time is e.g. needed by temperature sensor */



   /* oled_clearScreen(OLED_COLOR_WHITE);

    oled_putString(1,1,  (uint8_t*)"Temp   : ", OLED_COLOR_BLACK, OLED_COLOR_WHITE);*/
}
void temp_display(int32_t t)
{

        /* Temperature */
     //   t = temp_conversion (read_button_status());

        /* output values to OLED display */

        intToString(t, buf, 10, 10);
        oled_fillRect((1+9*6),1, 80, 8, OLED_COLOR_WHITE);
        oled_putString((1+9*6),1, buf, OLED_COLOR_BLACK, OLED_COLOR_WHITE);


        /* delay */
        //delay32Ms(0, 200);
    }