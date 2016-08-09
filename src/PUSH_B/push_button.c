/*Brumar Florin - Ilie
File name: push_button.c
Date:8/5/2016
Description: return true if the push button was pressed
*/

#include "push_button.h"


                 /*           Local variables                     */


volatile uint32_t button_1 = 0;     // port 1 pin 4

/*......................................................................*/

/*the related function read the value from button_1
  and return true or false if the button is pressed or not*/

bool read_button_status()
{

	button_1=ADCRead(5);


	if ((button_1== 10)||(button_1==9)||(button_1==11))   //if the button is pressed from the ADC channel 5 we will receive a value witch can be 9, 10 or 11
	{
		return TRUE;
	}

    else
    {
    return FALSE;
    }
}
