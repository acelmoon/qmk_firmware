/*
Copyright 2018 by AceMoon (acemoon_da@outlook.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once
#define CONFIG_USER_H

#include "config_common.h"

//Space Saving defines
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//#define DISABLE_LEADER

/* Debounce reduces chatter (unintended double-presses) - Set 0 if debouncing isn't needed */
//#define DEBOUNCING_DELAY 0

/* sets delay between tapping and holding */
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 150
#endif

/* number of backlight levels */
#ifdef BACKLIGHT_PIN
/*
#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 4
*/
#endif

/* RGB Underglow settings */
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 135
#undef RGBLIGHT_HUE_STEP
#undef RGBLIGHT_SAT_STEP
#undef RGBLIGHT_VAL_STEP
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
