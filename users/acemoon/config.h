#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO

/* Debounce reduces chatter (unintended double-presses) - Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/* sets delay between tapping and holding */
#define TAPPING_TERM 150

/* number of backlight levels */
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 4
#endif

/* RGB Underglow settings */
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 135
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#endif

/* Mouse key settings */
#define MOUSEKEY_DELAY             75	//Define the delay between that button press and the mouse cursor moving
#define MOUSEKEY_INTERVAL          50	//Specifies how long to wait between each movement report. Lower settings mean higher mouse speed.
#define MOUSEKEY_MAX_SPEED         4	//When movement key is held down, speed of the mouse cursor will increase until it reaches MOUSEKEY_MAX_SPEED.
#define MOUSEKEY_TIME_TO_MAX       1	//How long you want to hold down a movement key until MOUSEKEY_MAX_SPEED is reached. This controls how quickly your cursor will accelerate.
#define MOUSEKEY_WHEEL_MAX_SPEED   4	//The top speed for scrolling movements.
#define MOUSEKEY_WHEEL_TIME_TO_MAX 1	//How long you want to hold down a scroll key until MOUSEKEY_WHEEL_MAX_SPEED is reached. This controls how quickly your scrolling will accelerate.1

#endif
