#include QMK_KEYBOARD_H
#include "acemoon.h" //User Space Include

//Layer Defines
#define _FN0 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define _FN5 5
#define _FN6 6
#define _FN7 7
#define _FN8 8

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
#define LT3_QUO LT(3,KC_QUOT)
#define LT2_DEL LT(2,KC_DEL)
#define LT1_SPC LT(1,KC_SPC)
#define TOG_NKR MAGIC_TOGGLE_NKRO

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  UwU = SAFE_RANGE,
  AYAYA,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	//0: Base Layer
	[_FN0] = LAYOUT_625_space(
	  //_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,//TAB_ESC
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT3_QUO,//QUO_LT3
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, SFT_DOT, MO(1),
	  //ESC_LT1, MO(2),   KC_LALT,                   LT1_SPC,                            SLS_LT2, DEL_LT1),//SPC_LT1 GUI_SLS
		ESC_LT1, MO(2),   KC_LALT,                   KC_SPC,                             SLS_LT2, LT2_DEL),

	//1: Number & Extra Keys
	[_FN1] = LAYOUT_625_space(
		KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		_______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, KC_GRV,  KC_SCLN, KC_ENT,
		_______, _______, _______, _______, _______, KC_BSPC, _______, KC_BSLS, KC_SLSH, KC_RSFT, _______,
		_______, KC_NO,   KC_APP,                    _______,                            KC_BSPC, _______),

	//2: F-Keys & Functions
    [_FN2] = LAYOUT_625_space(
		KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
		UwU    , KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, _______, _______, _______,
		AYAYA  , KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, BL_TOGG, _______, KC_MUTE, _______, _______, _______,
		MO(4),   KC_NO,   KC_MUTE,                   MO(7),                              KC_VOLD, KC_VOLU),

	//3: Home-Row Arrows & Extra Keys
	[_FN3] = LAYOUT_625_space(
		_______, _______, _______, _______, _______, _______, _______, _______, KC_UP, KC_LBRC, KC_RBRC, KC_BSLS,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
		_______, _______, _______, _______, _______, _______, _______, F(0),    _______, _______, _______,
		_______, _______, _______,                   _______,                           KC_PSCR, _______),
		
	//4: Lighting
	[_FN4] = LAYOUT_625_space(
		TG(5),   RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, KC_SLEP, KC_PWR,
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_P, _______, _______, _______, _______, _______, _______,
		_______, BL_DEC,  BL_TOGG, BL_INC,  RGB_TOG, _______, TOG_NKR, _______, _______, _______, _______,
		KC_NO,   KC_NO,   TG(6),                     _______,                            _______, RESET),
	
	//5: Dedicated Arrows
	[_FN5] = LAYOUT_625_space(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_RGHT,
		_______, _______, _______,                   _______,                            KC_LEFT, KC_DOWN),
	
	//6: Func Space
	[_FN6] = LAYOUT_625_space(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                   LT1_SPC,                            _______, _______),
		
	//7: Mouse Keys
	[_FN7] = LAYOUT_625_space(
		_______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
		_______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______,
		_______, _______, _______,                   _______,                            _______, _______),
	/*
	//8: Blank
	[_FN8] = LAYOUT_625_space(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                   _______,                            _______, _______),
	*/
};

void matrix_init_user(void) {
	rgblight_setrgb(0, 55, 40);
}

void keyboard_post_init_user(void) {
	rgblight_setrgb(0, 55, 40);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UwU:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING("UwU");
      } else {
        // when keycode is released
      }
      break;
	case AYAYA:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING("AYAYA");
      } else {
        // when keycode is released
      }
      break;
  }
  return true;
}

//#define rgblight_set_led0        rgblight_setrgb_at(0, 55, 40, 10);rgblight_setrgb_at(0, 55, 40, 9);rgblight_setrgb_at(0, 55, 40, 8);rgblight_setrgb_at(0, 55, 40, 7);
#define rgblight_set_led0		 rgblight_setrgb(0, 55, 40);
#define rgblight_set_led1        rgblight_setrgb_at(0, 100, 85, 10);
#define rgblight_set_led2        rgblight_setrgb_at(50, 0, 100, 10);
#define rgblight_set_led3        rgblight_setrgb_at(0, 55, 40, 10);
#define rgblight_set_led4        rgblight_setrgb_at(100, 100, 100, 10);
#define rgblight_set_led5        rgblight_setrgb_at(0, 55, 40, 10);rgblight_setrgb_at(0, 0, 0, 9);rgblight_setrgb_at(0, 0, 0, 8);rgblight_setrgb_at(0, 0, 0, 7);
#define rgblight_set_led6        rgblight_setrgb_at(0, 0, 0, 11);rgblight_setrgb_at(0, 0, 0, 10);rgblight_setrgb_at(0, 0, 0, 9);
#define rgblight_set_led7        rgblight_setrgb_at(0, 55, 40, 10);rgblight_setrgb_at(50, 0, 100, 7);rgblight_setrgb_at(50, 0, 100, 6);rgblight_setrgb_at(50, 0, 100, 5);

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
	case 7:
      rgblight_set_led7;
      break;
    default: //for any other layers, or the default layer
      rgblight_set_led0;
      break;}
#endif
  return state;
}

enum function_id {
	APO_M,
	//RGB_CYAN,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(APO_M),
  //[1]  = ACTION_FUNCTION(RGB_CYAN),
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
  /*
  switch(id){
	case RGB_CYAN:
	  rgblight_setrgb(0, 55, 40);
	  break;
  }
  */
}