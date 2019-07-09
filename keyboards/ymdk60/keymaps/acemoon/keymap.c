#include QMK_KEYBOARD_H
#include "acemoon.h"

#define _FN0 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define _FN5 5
#define _FN6 6

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
#define LT5_DEL LT(5,KC_DEL)
#define TOG_NKR MAGIC_TOGGLE_NKRO

#define LT7_SLS LT(7,KC_SLSH)
#define LT3_SCN LT(3,KC_SCLN)
#define SFT_SLH RSFT_T(KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //0: Base Layer
  [_FN0] = LAYOUT_all(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT3_SCN, QUO_LT3, KC_NO,            KC_ENT,//TD(QUOT_LAYER)
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, SFT_DOT, SFT_SLH, KC_NO,   KC_RSFT, KC_NO,
      ESC_LT1, MO(2),   KC_LALT, KC_NO,                       KC_SPC,                  KC_NO,   SLS_LT2, _______, KC_NO,   MO(5), LT1_DEL),

  //1: Numbers & F-keys
  [_FN1] = LAYOUT_all(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
      KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSLS,
      _______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, KC_GRV,  KC_SCLN, _______, _______, KC_NO,            _______,
      _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, KC_APP,  _______,                _______,                      _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU),
	  
  //2: Functions
  [_FN2] = LAYOUT_all(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
      KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           _______,
	  KC_CAPS, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, _______, _______, _______, _______, KC_NO,            _______,
	  _______, KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, BL_TOGG, _______, KC_MUTE, _______, _______, _______, _______, _______, _______,
      MO(4),   _______, KC_MUTE, _______,                _______,                      _______, _______, _______, _______, KC_VOLD, KC_VOLU),
	  
  //3: Home-Row Arrowsxx
  [_FN3] = LAYOUT_all(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS, _______,          _______,
      _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_NO,            _______,
      _______, KC_NO,   _______, _______, _______, _______, _______, _______, F(1),    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,                _______,                      _______, _______, _______, _______, _______, _______),
	  
  //4: Lighting
  [_FN4] = LAYOUT_all(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP, _______, KC_PWR,
	  _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_P, _______, _______, _______, _______, _______, _______, _______, KC_NO,            _______,
      _______, KC_NO,   BL_DEC , BL_STEP, BL_INC , RGB_TOG, _______, TOG_NKR, _______, _______, _______, _______, _______, _______, _______,
      KC_NO  , KC_NO  , _______, _______,                _______,                      _______, _______, _______, _______, _______, RESET),
	  
  //5: Mouse Controls
  [_FN5] = LAYOUT_all(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO,   _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______, _______, _______,          _______,
      _______, _______, _______, _______, _______, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______, KC_NO,            _______,
      _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO,   _______, KC_NO,
      _______, _______, _______, KC_NO,                _______,                        KC_NO,   _______, _______, KC_NO,   _______, _______),
	  
  //6: Blank
  [_FN6] = LAYOUT_all(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,            KC_TRNS,
      KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_NO,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                KC_TRNS,                        KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS),
  
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
	rgblight_setrgb(0, 55, 40);
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

//#define rgblight_set_led0        rgblight_setrgb_at(0, 55, 40, 10);rgblight_setrgb_at(0, 55, 40, 9);rgblight_setrgb_at(0, 55, 40, 8);rgblight_setrgb_at(0, 55, 40, 7);
#define rgblight_set_led0		 rgblight_setrgb(0, 55, 40);
#define rgblight_set_led1        rgblight_setrgb_at(0, 100, 85, 10);
#define rgblight_set_led2        rgblight_setrgb_at(50, 0, 100, 10);
#define rgblight_set_led3        rgblight_setrgb_at(0, 55, 40, 10);
#define rgblight_set_led4        rgblight_setrgb_at(100, 100, 100, 10);
#define rgblight_set_led5        rgblight_setrgb_at(0, 100, 0, 10);
#define rgblight_set_led6        rgblight_setrgb_at(0, 0, 0, 9);rgblight_setrgb_at(0, 0, 0, 8);rgblight_setrgb_at(0, 0, 0, 7);

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  switch (biton32(state)) {
	 /*
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
	  */
    default: //for any other layers, or the default layer
      rgblight_set_led0;
      break;}
#endif
  return state;
}

enum function_id {
	APO_M,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(APO_M),
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
