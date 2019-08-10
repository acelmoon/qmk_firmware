#include QMK_KEYBOARD_H
#include "acemoon.h"

#define _FN0 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define _FN5 5
#define _FN6 6
#define _FN7 7

#define TAB_ESC TD(TABESC)
#define QUO_LT3 TD(QUOT_LAYER)
#define ESC_LT1 TD(ESC_LAYER)
#define SPC_LT1 TD(SPC_LAYER)
#define SLS_LT2 TD(SLSH_LAYER)
#define SFT_DOT TD(RSHIFT_DOT)

#define _______ KC_TRNS
#define LT3_QUO LT(3,KC_QUOT)
#define GUI_SLS LGUI_T(KC_SLSH)
#define LT1_DEL LT(1,KC_DEL)
#define TOG_NKR MAGIC_TOGGLE_NKRO

#define LT7_SLS LT(7,KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	//0: Base Layer
	[_FN0] = LAYOUT(
	  //_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		TAB_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT3_QUO,//QUO_LT3
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, SFT_DOT, MO(1),
		ESC_LT1, MO(2),   KC_LALT, _______, KC_SPC,  _______, SLS_LT2, LT1_DEL),
	
	//1: Number & Extra Keys
	[_FN1] = LAYOUT(
		KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		_______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, KC_GRV,  KC_SCLN, KC_ENT,
		_______, _______, _______, _______, _______, KC_BSPC, _______, KC_DOT,  KC_SLSH, KC_RSFT, _______,
		_______, KC_NO,   KC_APP,  _______, _______, _______, KC_BSPC, _______),

	//2: F-Keys & Functions
    [_FN2] = LAYOUT(
		KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
		_______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, _______, _______, _______,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, BL_TOGG, _______, KC_MUTE, _______, _______, _______,
		MO(4),   KC_NO,   KC_MUTE, _______, MO(6),   _______, KC_VOLD, KC_VOLU),

	//3: Home-Row Arrows & Extra Keys
	[_FN3] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
		_______, _______, _______, _______, _______, _______, _______, F(0),    _______, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_PSCR, _______),
	
	//4: Lighting & Settings
	[_FN4] = LAYOUT(
		TG(5),   RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, KC_SLEP, KC_PWR,
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_P, _______, _______, _______, _______, _______, _______,
		_______, BL_DEC,  BL_TOGG, BL_INC,  RGB_TOG, _______, TOG_NKR, _______, _______, _______, _______,
		KC_NO,   KC_NO,   _______, _______, _______, _______, _______, RESET),
	
	//5: Dedicated Arrows
	[_FN5] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_RGHT,
		_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN),
	
	//6: Mouse Controls
	[_FN6] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
		_______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),
	/*
	//7: Blank
	[_FN7] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),
	*/
};

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_KANA)) {
	} else {
	}
}

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
