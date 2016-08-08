/*****************************************************************************
 * Bradescu Tudor-Ioan
 * File name: test.c
 * Date:8/8/2016
 * Description: OLED temperature display testing file
 ******************************************************************************/


#include "display.h"







int main (void)
{
	init_display();
	init_temp();  // temp=-99


    while(1) {




    temp_display();
    }

}
