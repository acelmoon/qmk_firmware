/* Copyright 2018 Alexander Fougner <fougner89 at gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define TOG_NKR MAGIC_TOGGLE_NKRO

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  AYAYA = SAFE_RANGE,
  QMKURL,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
  //Base Layer
  [0] = LAYOUT_tkl_ansi(
      KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,            KC_PSCR, KC_SLCK, MO(2), //KC_PAUS
      KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
      KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
      KC_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT,
      KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,                    KC_UP,
      KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT,KC_RGUI,TG(1),  KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT),
	  
  //Numpad
  [1] = LAYOUT_tkl_ansi(
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,           KC_P7, KC_P8, KC_P9,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   KC_P4, KC_P5, KC_P6,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   KC_P1, KC_P2, KC_P3,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,                    _______,
      _______,_______,_______,                _______,                                _______,_______,_______,_______,   _______, _______, _______),
	  
  //Extra Controls
  [2] = LAYOUT_tkl_ansi(
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,           KC_VOLD, KC_VOLU, _______,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______, _______, _______,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______, _______, _______,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,                    _______,
      _______,_______,_______,                _______,                                _______,_______,MO(3),  _______,   _______, _______, _______),

  //Settings  
  [3] = LAYOUT_tkl_ansi(
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,           _______, _______, _______,
      RGB_TOG,RGB_M_P,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______, _______, _______,
      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______, _______, _______,
      _______,AYAYA  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,
      _______,BL_DEC, BL_TOGG,BL_INC, _______,_______,TOG_NKR,_______,_______,_______,_______,        _______,                    _______,
      _______,_______,_______,                _______,                                _______,_______,_______,RESET,     _______, _______, _______),
};

void matrix_init_user(void) {
	rgblight_setrgb(52, 35, 50);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AYAYA:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING("AYAYA");
      } else {
        // when keycode is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {
	rgblight_setrgb(52, 35, 50);
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        // Turn capslock on
        PORTE &= ~(1 << 2);
    } else {
        // Turn capslock off
        PORTE |= (1 << 2);
    }
}

#define rgblight_set_led0		 rgblight_setrgb(52, 35, 50);//GMK Olivia Rose Gold: 232,196,184
#define rgblight_set_led1        rgblight_setrgb(25, 25, 25);
#define rgblight_set_led2        rgblight_setrgb(10, 50, 10);
#define rgblight_set_led3        rgblight_setrgb(0, 55, 40);
//#define rgblight_set_led4        rgblight_setrgb_at(100, 100, 100, 10);

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  switch (biton32(state)) {
    case 1:
      rgblight_set_led1;
      break;
	case 2:
      rgblight_set_led2;
      break;
	case 3:
      rgblight_set_led3;
      break;
    default: //for any other layers, or the default layer
      rgblight_set_led0;
      break;}
#endif
  return state;
}