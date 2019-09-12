/* Copyright 2018 Carlos Filoteo
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
#include "acemoon.h" //User Space Include
#ifdef LED_ENABLE
  #include "protocol/serial.h"
#endif

//Layer Defines
#define _FN0 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define _FN5 5
#define _FN6 6
#define _FN7 7

//User Specific Tap Dance Defines
#define TAB_ESC TD(TABESC)
#define QUO_LT3 TD(QUOT_LAYER)
#define ESC_LT1 TD(ESC_LAYER)
#define SPC_LT1 TD(SPC_LAYER)
#define SLS_LT2 TD(SLSH_LAYER)
#define SFT_DOT TD(RSHIFT_DOT)
#define DEL_LT1 TD(DEL_LAYER)
#define ENT_LT3 TD(ENTER_LAYER)
#define SFT_SLS TD(RSHIFT_SLSH)
#define SCN_LT3 TD(SCLN_LAYER)

//Long Keycode Defines
#define _______ KC_TRNS
#define TOG_NKR MAGIC_TOGGLE_NKRO
//Long Keycode Defines Set 2
#define LT1_SPC LT(1,KC_SPC)
#define LT7_SPC LT(7,KC_SPC)

//LED Custom Keycodes
enum custom_keycodes {
  LED_TOG = SAFE_RANGE,
  LED_INC,
  LED_DEC,
  LED_MOD,
  LED_DEF,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * | Ctrl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  '  |  Ent |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  L1 |
   * |-------------------------------------------------------------------------+
   * | Esc | L2 |   | Alt | Space |    Space    | L6 |  SlsGui  |   | L2 | Del |
   * `-------------------------------------------------------------------------'
   */
	//0: Base Layer
	[_FN0] = LAYOUT(
	  //KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		TAB_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    QUO_LT3, ENT_LT3,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, SFT_DOT, SFT_SLS, MO(1),
		ESC_LT1, MO(2),   _______, KC_LALT, KC_SPC,      LT1_SPC,      MO(6),   SLS_LT2, _______, MO(2),   DEL_LT1),
		
	  //ESC_LT1, MO(2),   KC_LALT, KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   SLS_LT2, MO(6),   LT1_DEL),
	  
	//1: Number & Extra Keys
	[_FN1] = LAYOUT(
		KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		_______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, KC_GRV,  KC_SCLN, KC_ENT,  KC_ENT,
		_______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, KC_SLSH, KC_RSFT, _______,
		_______, KC_NO,   _______, KC_APP,  _______,     _______,      _______, KC_QUES, _______, _______, _______),

	//2: F-Keys & Functions
    [_FN2] = LAYOUT(
		KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
		_______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, _______, _______, _______, _______,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, _______, KC_MUTE, _______, _______, _______, _______,
		MO(4),   KC_NO,   _______, KC_MUTE, _______,     _______,      _______, _______, _______, KC_VOLD, KC_VOLU),

	//3: Home-Row Arrows & Extra Keys
	[_FN3] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, F(0),    _______, _______, _______, _______,
		_______, _______, _______, _______, _______,     _______,      _______, _______, KC_PSCR, _______, _______),
	
	//4: Lighting
	[_FN4] = LAYOUT(
		TG(5),   KC_BRIU, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_L), KC_SLEP, KC_PWR,
		LED_MOD, KC_BRID, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, LED_DEC, LED_TOG, LED_INC, LED_DEF, _______, TOG_NKR, _______, _______, _______, _______, _______,
		KC_NO,   KC_NO,   _______, _______, _______,     _______,      _______, _______, _______, _______, RESET),
	
	//5: Dedicated Arrows
	[_FN5] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
		_______, _______, _______, _______, _______,     _______,      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT),
		
	//6: Mouse Controls
	[_FN6] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN1,
		_______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______, _______,
		_______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______),
	/*
	//7: Blank
	[_FN7] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______),
	*/
};

void matrix_init_user(void) {
	#ifdef LED_ENABLE
		serial_init(); //Serial Init for LED_ENABLE
	#endif
}

//LED keymap functions
#ifdef LED_ENABLE
	void led_tog(void){serial_send(100);} //LED On/Off Toggle
	void led_inc(void){serial_send(101);} //LED brightness increase
	void led_dec(void){serial_send(99);} //LED brightness decrease
	void led_mod(void) {serial_send(111);} //LED mode change
	void led_default(void){serial_send(135);} //LED Default mode set
	
	//void (void){serial_send();} //serial send function

	bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		if (record->event.pressed) {
			switch(keycode) {
				case LED_TOG:
					led_tog();
					return false;
				case LED_INC:
					led_inc();
					return false;
				case LED_DEC:
					led_dec();
					return false;
				case LED_MOD:
					led_mod();
					return false;
				case LED_DEF:
					led_default();
					return false;
				/*
				case : //custom keycode here
					//input function here
					return false;
				*/
			}
		}
		return true;
	};
#endif

enum function_id {
	APO_M,
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(APO_M),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id){
	case APO_M:
	  if(record->event.pressed){
	    add_key(KC_QUOT);
		send_keyboard_report();
        add_key(KC_M);
        send_keyboard_report();
	  }else{
		del_key(KC_QUOT);
		send_keyboard_report();
        del_key(KC_M);
        send_keyboard_report();
	  }
  }
}
