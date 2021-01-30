#ifndef YMDK60_H
#define YMDK60_H

#include "quantum.h"
#include "led.h"

/* YMDK60 LEDs
 *   GPIO pads
 *   0 __ not connected
 *   1 E2 RGB PWM Underglow
 *   2 B7 Backlight LED
 *   3 __ not connected
 *   F4 Capslock LED
 *   __ not connected
 */
inline void caps_led_on(void)    { DDRF |=  (1<<4); PORTF &= ~(1<<4); }
inline void bl_led_on(void)      { DDRB |=  (1<<7); PORTB &= ~(1<<7); }
inline void rgb_led_on(void)     { DDRE |=  (1<<2); PORTE &= ~(1<<2); }

inline void caps_led_off(void)   { DDRF &= ~(1<<4); PORTF &= ~(1<<4); }
inline void bl_led_off(void)     { DDRB &= ~(1<<7); PORTB &= ~(1<<7); }
inline void rgb_led_off(void)     { DDRE |=  (1<<2); PORTE &= ~(1<<2); }


/* YMDK60 Keymap Definition Macro */ //This is the wiring
#define LAYOUT_all( \
      K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E, \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1D,       \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,       \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D,  K3E, \
      K40,  K41,  K42,  K43,                 K47,     K48,  K49,  K4A,  K4B,  K4C,  K4D  \
) { \
    { K00,  K01,  K02,  K03,   K04,   K05,  K06,   K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D, K0E }, \
    { K10,  K11,  K12,  K13,   K14,   K15,  K16,   K17,  K18,  K19,  K1A,  K1B,  K1C,  K1D }, \
    { K20,  K21,  K22,  K23,   K24,   K25,  K26,   K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D }, \
    { K30,  K31,  K32,  K33,   K34,   K35,  K36,   K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D, K3E }, \
    { K40,  K41,  K42,  K43,   KC_NO, KC_NO,KC_NO, K47,  K48,  K49,  K4A,  K4B,  K4C,  K4D }  \
}

#endif
