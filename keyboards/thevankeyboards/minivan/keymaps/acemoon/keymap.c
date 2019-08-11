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
#define _FN9 9

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
#define LT1_SPC LT(1,KC_SPC)
#define TOG_NKR MAGIC_TOGGLE_NKRO
//Long Keycode Defines Set 2
#define LT3_ENT LT(3,KC_ENT)
#define LT7_SPC LT(7,KC_SPC)

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	//0: Base Layer
	[_FN0] = LAYOUT_arrow_command(
		TAB_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    QUO_LT3, ENT_LT3,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, SFT_DOT, SFT_SLS, MO(1),
		ESC_LT1, MO(2),   _______, KC_LALT,      KC_SPC,          MO(6),        SLS_LT2, _______, MO(2),   DEL_LT1),
	  //ESC_LT1, MO(2),   MO(2),   KC_LALT,      KC_SPC,          MO(6),        SLS_LT2, SLS_LT2, MO(2),   LT1_DEL),

	//1: Number & Extra Keys
	[_FN1] = LAYOUT_arrow_command(
		KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		_______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, KC_GRV,  KC_SCLN, KC_ENT,  KC_ENT,
		_______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, KC_SLSH, KC_RSFT, _______,
		_______, KC_NO,   _______, KC_APP,      _______,         _______,      KC_QUES, _______, _______,  _______),

	//2: F-Keys & Functions
    [_FN2] = LAYOUT_arrow_command(
		KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
		_______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_PAUS, KC_PSCR, _______, _______, _______, _______,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, _______, KC_MUTE, _______, _______, _______, _______,
		MO(4),   KC_NO,   _______, KC_MUTE,      _______,         _______,      _______, _______, KC_VOLD, KC_VOLU),

	//3: Home-Row Arrows & Extra Keys
	[_FN3] = LAYOUT_arrow_command(
		_______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, F(0),    _______, _______, _______, _______,
		_______, _______, _______, _______,      _______,         _______,      _______, KC_PSCR, _______, _______),
	
	//4: Lighting
	[_FN4] = LAYOUT_arrow_command(
		TG(5),   RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, KC_SLEP, KC_PWR,
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_P, _______, _______, _______, _______, _______, _______, _______,
		_______, BL_DEC,  BL_TOGG, BL_INC,  RGB_TOG, _______, TOG_NKR, _______, _______, _______, _______, _______,
		KC_NO,   KC_NO,   _______, _______,      _______,         _______,      _______, _______, _______, RESET),
		
	//5: Dedicated Arrows
	[_FN5] = LAYOUT_arrow_command(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
		_______, _______, _______, _______,      _______,         _______,      _______, KC_LEFT, KC_DOWN, KC_RGHT),
		
	//6: Mouse Controls
	[_FN6] = LAYOUT_arrow_command(
		_______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN1,
		_______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______, _______,		
		_______, _______, _______, _______,      _______,         _______,      _______, _______, _______, _______),
	/*
	//7: Blank
	[_FN7] = LAYOUT_arrow_command(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______,      _______,         _______,      _______, _______, _______, _______),
	*/
	//_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

};

#define rgblight_set_led0		 rgblight_setrgb(0, 0, 0);rgblight_setrgb_at(0, 55, 40, 0);
#define rgblight_set_led1        rgblight_setrgb_at(0, 100, 85, 1);
#define rgblight_set_led2        rgblight_setrgb_at(50, 0, 100, 1);
#define rgblight_set_led3        rgblight_setrgb_at(0, 55, 40, 1);
#define rgblight_set_led4        rgblight_setrgb_at(100, 100, 100, 1);
#define rgblight_set_led5        rgblight_setrgb_at(0, 100, 0, 1);
#define rgblight_set_led6        rgblight_setrgb_at(0, 0, 0, 0);rgblight_setrgb_at(0, 0, 0, 1);rgblight_setrgb_at(0, 0, 0, 2);

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

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
	/*
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LANG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      break;
	*/
    #ifdef RGBLIGHT_ENABLE
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
	/*
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
	*/
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
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