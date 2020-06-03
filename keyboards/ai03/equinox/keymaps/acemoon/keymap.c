#include QMK_KEYBOARD_H
#include "acemoon.h" //User Space Include

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
  APO_M_3 = SAFE_RANGE,
  UwU,
  AYAYA,
};


/*
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
    K300, K301, K302,     K304,       K306,       K308,   K309, K310, K311  \
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //0: Base Layer
  [0] = LAYOUT_all(
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    _______, QUO_LT3,
	KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, SFT_DOT, MO(1),
    ESC_LT1, MO(2),   KC_LALT,          KC_SPC,           KC_SPC,       KC_SPC,      SLS_LT2, MO(7),   LT2_DEL),

  //1: Number & Extra Keys
  [1] = LAYOUT_all(
	KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
	_______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, KC_GRV,  KC_SCLN, _______, KC_ENT,
	_______, _______, _______, _______, _______, _______, KC_BSPC, _______, KC_BSLS, KC_SLSH, KC_RSFT, _______,
    _______, KC_NO,   KC_APP,           _______,          _______,     _______,      KC_BSPC, _______, _______),

  //2: F-Keys & Functions
  [2] = LAYOUT_all(
	KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
	UwU    , KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, _______, _______, _______, _______,
	AYAYA  , _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, BL_TOGG, _______, KC_MUTE, _______, _______, _______,
    MO(4),   KC_NO,   KC_MUTE,          MO(7),            MO(7),         MO(7),      _______, KC_VOLD, KC_VOLU),

  //3: Home-Row Arrows & Extra Keys
  [3] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
	_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, APO_M_3, _______, _______, _______,
	_______, _______, _______,          _______,          _______,     _______,      KC_PSCR, _______, _______),

  //4: Lighting & Settings
  [4] = LAYOUT_all(
	TG(5),   RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, KC_SLEP, KC_PWR,
	RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_P, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, BL_DEC,  BL_TOGG, BL_INC,  RGB_TOG, _______, TOG_NKR, _______, _______, _______, _______,
	KC_NO,   KC_NO,   TG(6),            _______,          _______,     _______,      _______, _______, RESET),

  //5: Dedicated Arrows
  [5] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
	_______, _______, _______,          _______,          _______,     _______,      KC_LEFT, KC_DOWN, KC_RGHT),

  //6: Func Space
  [6] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,          LT1_SPC,          LT1_SPC,     LT1_SPC,      _______, _______, _______),

  //7: Mouse Keys
  [7] = LAYOUT_all(
	_______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
	_______, _______, _______, _______, _______, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_BTN1,
	_______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______,
	_______, _______, _______,          _______,          _______,     _______,      _______, _______, _______),

/*
  //Blank
  [] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,          _______,          _______,     _______,      _______, _______, _______),
*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case APO_M_3:
	  if (record->event.pressed) {
		// when keycode is pressed
		add_key(KC_QUOT); send_keyboard_report();
		add_key(KC_M); send_keyboard_report();
	  } else {
		// when keycode is released
		del_key(KC_QUOT); send_keyboard_report();
		del_key(KC_M); send_keyboard_report();
	  }
	  break;	
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
};
