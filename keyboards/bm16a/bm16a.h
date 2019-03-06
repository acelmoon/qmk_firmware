#ifndef BM16A_H
#define BM16A_H

#include "quantum.h"
#include "led.h"

/* BM16A LEDs
 *   GPIO pads
 *   0 __ not connected
 *   1 E2 RGB PWM Underglow
 *   2 B6 Backlight LED
 *   3 __ not connected
 *   __ Capslock LED
 *   __ not connected
 */
inline void caps_led_on(void)    { DDRF |=  (1<<4); PORTF &= ~(1<<4); }
inline void bl_led_on(void)      { DDRB |=  (1<<7); PORTB &= ~(1<<7); }
inline void rgb_led_on(void)     { DDRE |=  (1<<2); PORTE &= ~(1<<2); }

inline void caps_led_off(void)   { DDRF &= ~(1<<4); PORTF &= ~(1<<4); }
inline void bl_led_off(void)     { DDRB &= ~(1<<7); PORTB &= ~(1<<7); }
inline void rgb_led_off(void)     { DDRE |=  (1<<2); PORTE &= ~(1<<2); }


/* BM16A Keymap Definition Macro */ //This is the wiring
#define LAYOUT_4x4( \
	K01, K02, K03, K04, \
	K11, K12, K13, K14, \
	K21, K22, K23, K24, \
	K31, K32, K33, K34 \
) \
{ \
  { K01, K02, K03, K04 }, \
  { K11, K12, K13, K14 }, \
  { K21, K22, K23, K24 }, \
  { K31, K32, K33, K34 } \
}

#endif
