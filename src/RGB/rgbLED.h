/*
===============================================================================
 Name        : rgbLED.h
 Author      : Dorin-Stefan Deac
 Version     : 1.0
 Date        : 8/5/2016
 Description : RGB module - functions for controlling the RGB module
===============================================================================
*/


#ifndef RGBLEDS_H_
#define RGBLEDS_H_

#include "type.h"
#include "rgb.h"
#include "timer16.h"
#include "timer32.h"
#include "mcu_regs.h"
#include "gpio.h"


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
/** Bit location for stop on MRx match, n = 0 to 3 */
#define TIMER_STOP_ON_MATCH(n)  (_BIT((((n) * 3) + 2)))


#define DEFAULT_INTENSITY (255)
#define RGB_TIMING (255)

void init_rgbLED(void); /* Set pins as output */
void setTimer16(void);  /* Set timer for PWM functionality */
void setColor_rgb(uint8_t, uint8_t, uint8_t); /* set a new color from the combination of red, green blue */
void rgbRainbow(void);  /* Examplying the functionality */

#endif /* RGBLEDS_H_ */
