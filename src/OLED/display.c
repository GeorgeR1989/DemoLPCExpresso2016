/*Bradescu Tudor-Ioan
File name: display.c
Date:8/2/2016
Description: OLED temperature display resource file
*/
#include "display.h"

static uint32_t msTicks = 0;
static uint8_t buf[10];
int32_t t = 0;

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
    }



    oled_clearScreen(OLED_COLOR_WHITE);

    oled_putString(1,1,  (uint8_t*)"Temp   : ", OLED_COLOR_BLACK, OLED_COLOR_WHITE);
}
void temp_display(void)
{

        /* Temperature */
        t = temp_read();

        /* output values to OLED display */

        intToString(t, buf, 10, 10);
        oled_fillRect((1+9*6),1, 80, 8, OLED_COLOR_WHITE);
        oled_putString((1+9*6),1, buf, OLED_COLOR_BLACK, OLED_COLOR_WHITE);


        /* delay */
        delay32Ms(0, 200);
    }
    void display_temperature_circle(void)
{
	oled_circle(31, 26, 3, OLED_COLOR_BLACK);
}

void display_celsius(void)
{
	oled_fillRect(36,28,50,30,OLED_COLOR_BLACK);
	oled_fillRect(36,31,39,54,OLED_COLOR_BLACK);
	oled_fillRect(48,31,50,33,OLED_COLOR_BLACK);
	oled_fillRect(48,49,50,51,OLED_COLOR_BLACK);
	oled_fillRect(40,52,50,54,OLED_COLOR_BLACK);
}
void display_Fahrenheit(void)
{
	oled_fillRect(36,28,50,30,OLED_COLOR_BLACK);
	oled_fillRect(36,31,39,54,OLED_COLOR_BLACK);
	oled_fillRect(40,37,45,40,OLED_COLOR_BLACK);
}
