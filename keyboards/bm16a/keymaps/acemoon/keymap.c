#include QMK_KEYBOARD_H

//Layer Defines
#define _FN0 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define _FN5 5

//Long Keycode Defines
#define _______ KC_TRNS
#define TOG_NKR MAGIC_TOGGLE_NKRO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,---------------------------.
 * |   7  |   8  |   9  | BKSP |
 * +------+------+------+------|
 * |   4  |   5  |   6  |  -   |
 * +------+------+------+------|
 * |   1  |   2  |   3  |  +   |
 * +------+------+------+------|
 * | LT1,0|   0  |   .  | ENT  |
 * ----------------------------'
 */
 
	//Numpad
	[_FN0] = LAYOUT_ortho_4x4(
		KC_7,    KC_8,    KC_9,   KC_BSPC,
		KC_4,    KC_5,    KC_6,   KC_MINS,
		KC_1,    KC_2,    KC_3,   KC_PLUS,
		LT(1,KC_0), KC_0, KC_DOT, LT(1,KC_ENT)),
		
	//Arrows & Extra keys
	[_FN1] = LAYOUT_ortho_4x4(
		_______, KC_UP,   _______, TG(2),
		KC_LEFT, KC_DOWN, KC_RGHT, KC_SLSH,
		_______, _______, _______, KC_ASTR,
		LT(4,KC_0), _______, KC_COMM, LT(4,KC_ENT)),
		
	//Nav Cluster
	[_FN2] = LAYOUT_ortho_4x4(
		KC_INS,  KC_HOME, KC_PGUP, TG(2),
		KC_DEL,  KC_END,  KC_PGDN, _______,
		KC_NO,   KC_UP,   KC_NO,   _______,
		KC_LEFT, KC_DOWN, KC_RGHT, _______),
		
	//Undecided, likely mouse controls
	[_FN3] = LAYOUT_ortho_4x4(
		_______, _______, _______, _______,
		_______, _______, _______, TG(3),
		_______, _______, _______, _______,
		_______, _______, _______, _______),
		
	//
	[_FN4] = LAYOUT_ortho_4x4(
		//RGB_HUI, RGB_SAI, RGB_VAI, RESET,
		//RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD,
		_______, _______, _______, RESET,
		_______, _______, _______, RGB_MOD,
		KC_MPRV, KC_MPLY, KC_MNXT, RGB_TOG,
		KC_NO,   KC_VOLD, KC_VOLU, KC_NO),
		
	//Blank
	[_FN5] = LAYOUT_ortho_4x4(
		_______, _______, _______, _______,
		_______, _______, _______, _______,
		_______, _______, _______, _______,
		_______, _______, _______, _______)
};

#define rgblight_set_led0		 rgblight_setrgb(0, 55, 40);
#define rgblight_set_led1        rgblight_setrgb(0, 0, 100);
#define rgblight_set_led2        rgblight_setrgb(100, 100, 100);
#define rgblight_set_led3        rgblight_setrgb(50, 0, 100);
#define rgblight_set_led4        rgblight_setrgb(0, 100, 0);
#define rgblight_set_led5        rgblight_setrgb(0, 55, 40);

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
    default: //for any other layers, or the default layer
      rgblight_set_led0;
      break;}
#endif
  return state;
};

/*
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
};
*/