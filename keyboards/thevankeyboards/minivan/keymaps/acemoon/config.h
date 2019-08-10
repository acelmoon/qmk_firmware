#pragma once
// place overrides here

//#define IGNORE_MOD_TAP_INTERRUPT
//#define TAPPING_TERM_PER_KEY

// Selection of RGBLIGHT MODE to use.
#if defined(LED_ANIMATIONS)
   //#define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   //#define RGBLIGHT_EFFECT_SNAKE
   #define RGBLIGHT_EFFECT_KNIGHT
   //#define RGBLIGHT_EFFECT_CHRISTMAS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   //#define RGBLIGHT_EFFECT_RGB_TEST
   //#define RGBLIGHT_EFFECT_ALTERNATING
#endif

// LED Setting: if you have KUMO you can use RGBLIGHT_ENABLE = yes
#ifdef RGBLIGHT_ENABLE
  #define RGB_DI_PIN D0
  #define RGBLIGHT_TIMER
  #define RGBLED_NUM 3
#endif
