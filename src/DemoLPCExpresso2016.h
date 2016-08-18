/*****************************************************************************
 *  Rosian Rad
 *  File name: DemoLPCExpresso2016.c
 *  Date: 8/10/2016
 *	Description: Header file of the main function for the final project
 ******************************************************************************/

#ifndef DEMOLPCEXPRESSO2016_H_
#define DEMOLPCEXPRESSO2016_H_

/*Header files*/

#include "type.h"
#include "gpio.h"
#include "joystick.h"
#include "mcu_regs.h"
#include "timer32.h"
#include "timer16.h"
#include "rgb.h"
#include "type.h"
#include "uart.h"
#include "i2c.h"
#include "ssp.h"
#include "adc.h"
#include "oled.h"
#include "temp.h"
#include "stdbool.h"
#include "rotary.h"
#include "led7seg.h"



/*Defines*/

#define ASCII_Val_0 (48)
#define MIN_VALUE (0)     /* MIN_VALUE */
#define MAX_VALUE (3)     /* and MAX_VALUE represents the limits of the set which will be returned */
#define OVERFLOW  (255)   /* Use OVERFLOW when the set includes 0 */
#define ADC_CHANNEL (5)   /* we will use channel 5 to read the button statusb */
#define P1_2_HIGH() (LPC_GPIO1->DATA |= (0x1<<2))   //High state of the duty cycle
#define P1_2_LOW()  (LPC_GPIO1->DATA &= ~(0x1<<2))  //Low state of the duty cycle



#define STATIC static
#define INLINE inline

/* Set bit macro */
#define _BIT(n) (1 << (n))

/** Timer/counter enable bit */
#define TIMER_ENABLE            ((uint32_t) (1 << 0))
/** Timer/counter reset bit */
#define TIMER_RESET             ((uint32_t) (1 << 1))


/** Macro to clear interrupt pending */
#define TIMER_IR_CLR(n)         _BIT(n)

/** Macro for getting a timer match interrupt bit */
#define TIMER_MATCH_INT(n)      (_BIT((n) & 0x0F))
/** Macro for getting a capture event interrupt bit */
#define TIMER_CAP_INT(n)        (_BIT((((n) & 0x0F) + 4)))


/** Bit location for interrupt on MRx match, n = 0 to 3 */
#define TIMER_INT_ON_MATCH(n)   (_BIT(((n) * 3)))
/** Bit location for reset on MRx match, n = 0 to 3 */
#define TIMER_RESET_ON_MATCH(n) (_BIT((((n) * 3) + 1)))


#define DEFAULT_INTENSITY (255)
#define RGB_TIMING (255)


/*Main functions*/
void init_buzzer(void);
void DemoLPCExpresso2016_init(void);
void ledSet(uint8_t value);
void init_display (void);
void temp_display(int32_t);
void delayMS(uint16_t );
void playNote(uint16_t, uint16_t, uint16_t);

char joystickPosition(void);
uint8_t rotary_encoder(void);
uint32_t temp_conversion (uint32_t change_unit);
void joystick_buzzer(void);



uint32_t read_button_status(); // read the status of the push button





void DemoLPCExpresso2016_init();

void init_rgbLED(void); /* Set pins as output */
void setTimer16(void);  /* Set timer for PWM functionality */
void setColor_rgb(uint8_t, uint8_t, uint8_t); /* set a new color from the combination of red, green blue */
void rgbRainbow(void);  /*  Special functionality for module presentation */
void rgb_stop(void); /* Stop the RGB module */

/*Variables*/
static uint16_t notes[] = {
        2272, // A - 440 Hz
        2024, // B - 494 Hz
        3816, // C - 262 Hz
        3401, // D - 294 Hz
        3030, // E - 330 Hz
        2865, // F - 349 Hz
        2551, // G - 392 Hz
        1136, // a - 880 Hz
        1012, // b - 988 Hz
        1912, // c - 523 Hz
        1703, // d - 587 Hz
        1517, // e - 659 Hz
        1432, // f - 698 Hz
        1275, // g - 784 Hz
};
typedef struct {
	 uint8_t high_time;
	 uint8_t low_time;
} note_ctr;

note_ctr Buzzer_u8NoteControl;

#define STATIC static
#define INLINE inline

/* Set bit macro */
#define _BIT(n) (1 << (n))

/** Timer/counter enable bit */
#define TIMER_ENABLE            ((uint32_t) (1 << 0))
/** Timer/counter reset bit */
#define TIMER_RESET             ((uint32_t) (1 << 1))


/** Macro to clear interrupt pending */
#define TIMER_IR_CLR(n)         _BIT(n)

/** Macro for getting a timer match interrupt bit */
#define TIMER_MATCH_INT(n)      (_BIT((n) & 0x0F))
/** Macro for getting a capture event interrupt bit */
#define TIMER_CAP_INT(n)        (_BIT((((n) & 0x0F) + 4)))


/** Bit location for interrupt on MRx match, n = 0 to 3 */
#define TIMER_INT_ON_MATCH(n)   (_BIT(((n) * 3)))
/** Bit location for reset on MRx match, n = 0 to 3 */
#define TIMER_RESET_ON_MATCH(n) (_BIT((((n) * 3) + 1)))


#define DEFAULT_INTENSITY (255)
#define RGB_TIMING (255)
void delayMS_High(uint32_t); //delay to setup the duty cycle of PWM
void delayMS_Low(uint16_t); //delay to setup the duty cycle of PWM


void setTimer16(void);
void setNote(uint16_t);
void setIntensity(uint8_t);
void startMusic();
void stopMusic();




#endif /* DEMOLPCEXPRESSO2016_H_ */
