/*****************************************************************************
 *  Rosian Rad
 *  File name: joystickPosition_test.c
 *  Date: 8/5/2016
 *	Description: Resource file used to test the joystick module
 ******************************************************************************/

#include "DemoLPCExpresso2016.h"

void init_buzzer()
{
	GPIOInit();
	    uint8_t i;
	    init_timer32(0, 10);
	    joystick_init();

	    uint8_t ij=0;

	    UARTInit(115200);
	    UARTSendString((uint8_t*)"Speaker - Tone\r\n");

	    GPIOSetDir( PORT1, 9, 1 );
	    GPIOSetDir( PORT1, 10, 1 );

	    GPIOSetDir( PORT3, 0, 1 );
	    GPIOSetDir( PORT3, 1, 1 );
	    GPIOSetDir( PORT3, 2, 1 );
	    GPIOSetDir( PORT1, 2, 1 );

	    LPC_IOCON->JTAG_nTRST_PIO1_2 = (LPC_IOCON->JTAG_nTRST_PIO1_2 & ~0x7) | 0x01;

	    GPIOSetValue( PORT3, 0, 0 );  //LM4811-clk
	    GPIOSetValue( PORT3, 1, 0 );  //LM4811-up/dn
	    GPIOSetValue( PORT3, 2, 0 );  //LM4811-shutdn

}

void joystick_buzzer()
{

    uint8_t ij = 0;
    uint8_t n = 0;

	uint8_t BUZZER_u16DirectionRight=0;
	uint8_t BUZZER_u16DirectionLeft=0;


		switch(joystickPosition())
		{
		case 1:
			BUZZER_u16DirectionRight=1;
			BUZZER_u16DirectionLeft=0;
			break;
		case 2:
			if ((n>=0)&&(n<=20))
					n+=2;
			break;
		case 3:
			BUZZER_u16DirectionRight=0;
			BUZZER_u16DirectionLeft=1;
			break;
		case 4:
			if ((n>=0)&&(n<=20))
					n-=2;
			break;
		default:
			break;
		}

		   P1_2_HIGH();

		      setTimer16();
		      startMusic();


		if(BUZZER_u16DirectionRight)
			{for(ij=0;ij<14;ij++)
		    	{
		    		setNote(notes[ij]);
		    		setIntensity(50);
		    		delay32Ms(0,1000);
		    	}

			}
		else if (BUZZER_u16DirectionLeft)
			 {
			for(ij=13;ij>=0;ij--)
		    	{
		    		setNote(notes[ij]);
		    		setIntensity(50);
		    		delay32Ms(0,1000);
		    	}

			 }

}
