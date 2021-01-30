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
  [_FN0] = LAYOUT_all(
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    LT(3,KC_SCLN), LT(3,KC_QUOT),KC_NO,    KC_ENT,//TD(QUOT_LAYER)
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM,TD(RSHIFT_DOT),RSFT_T(KC_SLSH),KC_RSFT,KC_UP,KC_DEL,
      TD(ESC_LAYER), MO(2), KC_LALT,                          KC_SPC,                     TD(SLSH_LAYER),MO(1),       KC_LEFT,KC_DOWN,KC_RGHT),

  //1: Numbers & F-keys
  [_FN1] = LAYOUT_all(
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12, KC_TRNS, KC_TRNS,
      KC_EQL,  KC_1,     KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,      KC_BSLS,
      KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_NUBS,KC_NUHS,KC_GRV, KC_SCLN, KC_TRNS, KC_TRNS,  KC_NO,       KC_TRNS,
      KC_TRNS, KC_NO,    KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,KC_VOLU, KC_TRNS,
      KC_TRNS, KC_TRNS,  KC_APP,                          KC_TRNS,                          KC_TRNS, KC_TRNS,  KC_MUTE,KC_VOLD, KC_TRNS),
	  
  //2: Functions
  [_FN2] = LAYOUT_all(
      KC_GRV,  KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12, KC_TRNS,  KC_TRNS,
      KC_F12,  KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,           KC_TRNS,
	  KC_CAPS, KC_HOME, KC_END,   KC_PGUP,  KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,            KC_TRNS,
	  KC_TRNS, KC_NO,   KC_MPRV,  KC_MPLY,  KC_MNXT, KC_MSTP, BL_TOGG, KC_TRNS, KC_MUTE, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
      MO(4),   KC_TRNS, KC_MUTE,                          KC_TRNS,                                 KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),
	  
  //3: Home-Row Arrowsxx
  [_FN3] = LAYOUT_all(
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,  KC_TRNS,           KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,  KC_NO,             KC_TRNS,
      KC_TRNS, KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                                 KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS),
	  
  //4: Lighting
  [_FN4] = LAYOUT_all(
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_SLEP,  KC_PWR,  KC_TRNS,
	  KC_TRNS, RGB_HUI, RGB_SAI,  RGB_VAI,  F(0),    KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,           KC_TRNS,
	  RGB_MOD, RGB_HUD, RGB_SAD,  RGB_VAD,  RGB_M_P, KC_TRNS,  KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_TRNS,  KC_NO,             KC_TRNS,
      KC_TRNS, KC_NO,   BL_DEC ,  BL_STEP,  BL_INC , RGB_TOG , KC_TRNS,MAGIC_TOGGLE_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_NO  , KC_NO  , KC_TRNS,                          KC_TRNS,                                 KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  RESET),
	  
  //5: Blank
  [_FN5] = LAYOUT_all(
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,           KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO,             KC_TRNS,
      KC_TRNS, KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                                 KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS),
	  
  //6: Blank
  [_FN6] = LAYOUT_all(
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,           KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO,             KC_TRNS,
      KC_TRNS, KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                                 KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS),
	  
  //7: Blank
  [_FN7] = LAYOUT_all(
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,           KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO,             KC_TRNS,
      KC_TRNS, KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS,                                 KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS),
  
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

enum function_id {
	RGB_CYAN,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(RGB_CYAN),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id){
	case RGB_CYAN:
	  rgblight_setrgb(0, 55, 40);
	  break;
  }
}
