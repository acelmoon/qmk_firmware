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
#define LT1_SPC LT(1,KC_SPC)
#define TOG_NKR MAGIC_TOGGLE_NKRO
//Long Keycode Defines Set 2
#define LT3_ENT LT(3,KC_ENT)
#define LT7_SPC LT(7,KC_SPC)

enum custom_keycodes {
	KC_PASTA = SAFE_RANGE,
	
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT( //Base Layer
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, GUI_T(KC_ESC), //KC_GESC
		KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(3,KC_QUOT), LT(3, KC_ENT), 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_SPC, LT(2,KC_B), KC_N, KC_M, KC_COMM, SFT_DOT, SFT_SLS, DEL_LT1),//LT(1,  LT(1,KC_SLSH)

	[1] = LAYOUT( //Number & Extra Keys
		KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_SCLN, _______, 
		_______, _______, _______, _______, KC_APP, _______, KC_BSPC, _______, _______, _______, _______, SFT_SLS, _______),//KC_PSCR

	[2] = LAYOUT( //F-Keys & Functions
		_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
		_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, _______, 
		MO(4), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

	[3] = LAYOUT( //Home-Row Arrows & Extra Keys
		_______, _______, _______, _______, _______, _______, _______, _______, KC_UP, KC_LBRC, KC_RBRC, KC_BSLS, KC_PSCR,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, 
		_______, _______, _______, _______, KC_LALT, _______, _______, SLS_LT2, _______, _______, _______, _______, _______),
	
	[4] = LAYOUT( //Settings
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET),
	
	[5] = LAYOUT( //Mouse Keys
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	/*
	[6] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
    switch (keycode) {
            case KC_PASTA:
                if (record->event.pressed) {
                    SEND_STRING("You better not be fucking thinking about flipping this board. I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed trades on /r/mm.  I am trained in gorilla warfare and I'm the top typist in the entire US armed forces at over 600 wpm. If you flip this board, you are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with flipping this board over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You're fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with this PCB. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little clever sale was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn't, you didn't, and now you're paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You're fucking dead, kiddo.");
                } else {}
                break;
           
        }
    }
    return true;
}	

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set NumLock LED to output and low
  setPinOutput(B6);
  writePinLow(B6);
  
}

void matrix_scan_user(void) {

}
	
	
uint32_t layer_state_set_user(uint32_t state)
{
    if (state & (1<<1)) {
    writePinHigh(B2);
    } else if (state & (1<<2)) {
        writePinLow(B2);
        writePinHigh(B6);
    } else if (state & (1<<3)) {
        writePinHigh(B2);
        writePinHigh(B6);
    } else {
        writePinLow(B2);
        writePinLow(B6);
    }
    return state;
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