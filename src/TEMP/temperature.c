/*
Author: Brumar Florin - Ilie
File name: temperature.c
Date:8/4/2016
Description: Changing the unit for the displayed temperature (Celsius or Fahreinheit)
*/

#include "temperature.h"

/*..............................................................................................................*/


                 /*           Local variables           */

volatile uint32_t previous_state ='C';

/*..............................................................................................................*/

/* Funcion name: temp_conversion */

/* Description: temp_conversion function make the conversion of temperature unit from Celsius to Fahreinheit or */
/* Fahreinheit to Celsius, depends on previous state, if a button is pressed */

/*..............................................................................................................*/

uint32_t temp_conversion (uint32_t change_unit)

{

	uint32_t t_unit=0;

	  /*  Read temperature  */

	switch(change_unit)
	{
		case  (1):
		{
/* if change_unit value is 1(true), we have to change the temperature unit, if it was in Celsius degrees we will change it in Fahreinheit degrees */
			if (previous_state == 'C')
				 {
				           t_unit = temp_read();
				           t_unit = t_unit / 10;
						   t_unit = (t_unit * 9 / 5 + 32 );
	 /*  Celsius to Fahreinheit transformation; 0 degrees Celsius is equal to 32 degrees Fahrenheit*/
     /*  The temperature T in degrees Fahrenheit (°F) is equal to the temperature T in degrees Celsius (°C) times 9/5 plus 32:  */
				           previous_state = 'F';
				           break;
				 }
/* in the same case if it was in Fahreinheit degrees we will change it in Celsius degrees */
	         if (previous_state == 'F')
	        	 {
						   t_unit = temp_read();
						   t_unit = t_unit / 10;
						   previous_state = 'C';

						   break;
	        	 }

		}
		case (0):
		{
/* if change_unit value is 0(false) we no need to change the previous temperature unit */
			if (previous_state == 'C')
				{
						   t_unit = temp_read();
						   t_unit = t_unit / 10;
				}
			if (previous_state == 'F')
				{
					       t_unit = temp_read();
					       t_unit = t_unit / 10;
						   t_unit = (t_unit * 9 / 5 + 32 );
				}
		}
		default  :
			{
				break;
			}
	}

	   return t_unit;

}

/*.................................................................................................*/
