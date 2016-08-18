/*Bobar Ioan
File name: buzzer.h
Date:8/9/2016
Description: Buzzer header file
*/


#include "mcu_regs.h"
#include "type.h"
#include "stdio.h"
#include "timer32.h"
#include "gpio.h"

//High state of the duty cycle
#define P1_2_HIGH() (LPC_GPIO1->DATA |= (0x1<<2))
//Low state of the duty cycle
#define P1_2_LOW()  (LPC_GPIO1->DATA &= ~(0x1<<2))

//Frequencies of notes
 static	uint16_t notes[] = {
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
void playNote(uint32_t, uint32_t, uint32_t); //function control the buzzer

void setTimer16(void);
void setNote(uint16_t);
void setIntensity(uint8_t);
void startMusic();
void stopMusic();


