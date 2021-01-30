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
#define _FN8 8

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
		ESC_LT1, MO(2),   KC_LALT, KC_SPC,  MO(1),   SLS_LT2, LT7_SLS, LT1_DEL),
	
	//1: Number & Extra Keys
	[_FN1] = LAYOUT(
		KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		_______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, KC_GRV,  KC_SCLN, KC_ENT,
		_______, _______, _______, _______, _______, KC_BSPC, _______, KC_DOT,  KC_SLSH, KC_RSFT, MO(5),
		MO(5),   KC_NO,   KC_APP,  _______, _______, KC_BSPC, KC_NO,   MO(5)),

	//2: F-Keys & Functions
    [_FN2] = LAYOUT(
		KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
		_______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, _______, _______, _______,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, BL_TOGG, _______, KC_MUTE, _______, _______, _______,
		MO(4),   KC_NO,   KC_MUTE, _______, _______, KC_NO,   KC_VOLD, KC_VOLU),

	//3: Home-Row Arrows & Extra Keys
	[_FN3] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
		_______, _______, _______, _______, _______, _______, _______, F(1),    _______, _______, _______,
		_______, _______, _______, _______, _______, KC_PSCR, KC_PSCR, _______),
	
	//4: Lighting
	[_FN4] = LAYOUT(
		TG(6),   RGB_HUI, RGB_SAI, RGB_VAI, F(0),    _______, _______, _______, KC_MS_U, _______, KC_SLEP, KC_PWR,
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_P, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
		_______, BL_DEC,  BL_TOGG, BL_INC,  RGB_TOG, _______, TOG_NKR, _______, _______, _______, _______,
		KC_NO,   KC_NO,   _______, _______, _______, _______, _______, RESET),
	
	//5: Shifted Keys
	[_FN5] = LAYOUT(
		KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
		_______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_TILD, KC_COLN, KC_ENT,
		_______, _______, _______, _______, _______, _______, _______, KC_RABK, KC_QUES, _______, KC_NO,
		KC_NO,   _______, _______, _______, _______, _______, _______, KC_NO),
	
	//6: Dedicated Arrows
	[_FN6] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_RGHT,
		_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN),
	
	//7: Mouse Controls
	[_FN7] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
		_______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),
		
	//8: Blank
	[_FN8] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),
	
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

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

#define rgblight_set_led0        rgblight_setrgb_at(0, 55, 40, 10);
#define rgblight_set_led1        rgblight_setrgb_at(0, 100, 85, 10);
#define rgblight_set_led2        rgblight_setrgb_at(50, 0, 100, 10);
#define rgblight_set_led3        rgblight_setrgb_at(100, 100, 100, 10);
#define rgblight_set_led4        rgblight_setrgb_at(0, 55, 40, 10);
#define rgblight_set_led5        rgblight_setrgb_at(0, 100, 0, 10);
#define rgblight_set_led6        rgblight_setrgb_at(0, 0, 0, 9);rgblight_setrgb_at(0, 0, 0, 8);rgblight_setrgb_at(0, 0, 0, 7);

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
	case 4:
      rgblight_set_led4;
      break;
	case 5:
      rgblight_set_led5;
      break;
	case 6:
      rgblight_set_led6;
      break;
    default: //for any other layers, or the default layer
      rgblight_set_led0;
      break;}
#endif
  return state;
}

enum function_id {
	RGB_CYAN,
	APO_M,
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(RGB_CYAN),
  [1]  = ACTION_FUNCTION(APO_M),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id){
	case RGB_CYAN:
	  rgblight_setrgb(0, 55, 40);
	  break;
  }
  switch(id){
	case APO_M:
	  if(record->event.pressed){
	    add_key(KC_QUOT);
        add_key(KC_M);
        send_keyboard_report();
	  }else{
		del_key(KC_QUOT);
        del_key(KC_M);
        send_keyboard_report();
	  }
  }
}
