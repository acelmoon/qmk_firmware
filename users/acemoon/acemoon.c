#include "acemoon.h"
#include "quantum.h"
#include "action.h"

#define tap_held (state->interrupted || state->pressed)
#define tap_tap (state->interrupted || !state->pressed)

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

/*
//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_X); break;
    case SINGLE_HOLD: register_code(KC_LCTRL); break;
    case DOUBLE_TAP: register_code(KC_ESC); break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_X); break;
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
    case DOUBLE_TAP: unregister_code(KC_ESC); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  xtap_state.state = 0;
}
*/

static tap tabesctap_state = {
  .is_press_action = true,
  .state = 0
};

void tabesc_finished (qk_tap_dance_state_t *state, void *user_data) {
  tabesctap_state.state = cur_dance(state);
  switch (tabesctap_state.state) {
    case SINGLE_TAP: register_code(KC_TAB); break;
    case SINGLE_HOLD: register_code(KC_TAB); break;
    case DOUBLE_TAP: register_code(KC_ESC); break;
    case DOUBLE_HOLD: register_code(KC_ESC); break;
  }
}

void tabesc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (tabesctap_state.state) {
    case SINGLE_TAP: unregister_code(KC_TAB); break;
    case SINGLE_HOLD: unregister_code(KC_TAB); break;
    case DOUBLE_TAP: unregister_code(KC_ESC); break;
    case DOUBLE_HOLD: unregister_code(KC_ESC); break;
  }
  tabesctap_state.state = 0;
}

void quotlayer_start (qk_tap_dance_state_t *state, void *user_data) {
	if(!IS_LAYER_ON(3)){layer_on(3);}
	if(state->interrupted)
	{
		register_code (KC_QUOT);
	}
}

void quotlayer_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (!state->pressed) {
	//key has not been held, send finds the count and send tap
	if(IS_LAYER_ON(3)){layer_off(3);}
	if (state->count == 1) {register_code (KC_QUOT);}
	if (state->count == 2) {register_code (KC_ENT);}
  }
}

void quotlayer_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(IS_LAYER_ON(3)){layer_off(3);}
  if (state->count == 1) {unregister_code (KC_QUOT);}
  else {unregister_code (KC_ENT);}
}

void esclayer_start (qk_tap_dance_state_t *state, void *user_data) {
}

void esclayer_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (tap_held) layer_on(1);
    //key has not been interrupted, but the key is not held. Means you want to send a 'TAP'.
    else register_code (KC_ESC);
  }else {
	register_code (KC_ESC);
  }
}

void esclayer_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(IS_LAYER_ON(1))layer_off(1);
  else unregister_code (KC_ESC);
}

void spclayer_start (qk_tap_dance_state_t *state, void *user_data) {
}

void spclayer_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (tap_tap) register_code (KC_SPC);
    //key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
    else layer_on(1);
  }else {
	register_code (KC_SPC);
  }
}

void spclayer_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(IS_LAYER_ON(1))layer_off(1);
  else unregister_code (KC_SPC);
}

static tap slshlayertap_state = {
  .is_press_action = true,
  .state = 0
};

void slshlayer_finished (qk_tap_dance_state_t *state, void *user_data) {
  slshlayertap_state.state = cur_dance(state);
  switch (slshlayertap_state.state) {
    case SINGLE_TAP: register_code(KC_SLSH); break;
    case SINGLE_HOLD: register_code(KC_LGUI); break;
    case DOUBLE_TAP: register_code(KC_SLSH); unregister_code(KC_SLSH); register_code(KC_SLSH); break;
    case DOUBLE_HOLD: layer_on(2); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_SLSH); unregister_code(KC_SLSH); register_code(KC_SLSH); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void slshlayer_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (slshlayertap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SLSH); break;
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
    case DOUBLE_TAP: unregister_code(KC_SLSH); break;
    case DOUBLE_HOLD: layer_off(2); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_SLSH); break;
  }
  slshlayertap_state.state = 0;
}

void rshiftdot_start(qk_tap_dance_state_t *state, void *user_data) {
	register_code (KC_RSFT);
}

void rshiftdot_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (!state->pressed) {
	unregister_code (KC_RSFT);
	if (state->count == 1) {
		register_code (KC_DOT);
	}
	if (state->count == 2) {
		register_code (KC_DOT);
		unregister_code (KC_DOT);
		register_code (KC_DOT);
	}
  }
}

void rshiftdot_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code (KC_RSFT);
  unregister_code (KC_DOT);
}

void dellayer_start (qk_tap_dance_state_t *state, void *user_data) {
}

void dellayer_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (tap_held) layer_on(1);
    //key has not been interrupted, but the key is not held. Means you want to send a 'TAP'.
    else register_code (KC_DEL);
  }else {
	register_code (KC_DEL);
  }
}

void dellayer_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(IS_LAYER_ON(1))layer_off(1);
  else unregister_code (KC_DEL);
}

void enterlayer_start (qk_tap_dance_state_t *state, void *user_data) {
	if(!IS_LAYER_ON(3)){layer_on(3);}
	if(state->interrupted)
	{
		register_code (KC_ENT);
	}
}

void enterlayer_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (!state->pressed) {
	//key has not been held, send finds the count and send tap
	if(IS_LAYER_ON(3)){layer_off(3);}
	if (state->count == 1) {register_code (KC_ENT);}
	if (state->count == 2) {register_code (KC_ENT);}
  }
}

void enterlayer_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(IS_LAYER_ON(3)){layer_off(3);}
  if (state->count == 1) {unregister_code (KC_ENT);}
  else {unregister_code (KC_ENT);}
}

void rshiftslsh_start(qk_tap_dance_state_t *state, void *user_data) {
	register_code (KC_RSFT);
}

void rshiftslsh_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (!state->pressed) {
	unregister_code (KC_RSFT);
	if (state->count == 1) {
		register_code (KC_SLSH);
	}
	if (state->count == 2) {
		register_code (KC_SLSH);
		unregister_code (KC_SLSH);
		register_code (KC_SLSH);
	}
  }
}

void rshiftslsh_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code (KC_RSFT);
  unregister_code (KC_SLSH);
}

void sclnlayer_start (qk_tap_dance_state_t *state, void *user_data) {
	if(!IS_LAYER_ON(3)){layer_on(3);}
	if(state->interrupted)
	{
		register_code (KC_SCLN);
	}
}

void sclnlayer_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (!state->pressed) {
	//key has not been held, send finds the count and send tap
	if(IS_LAYER_ON(3)){layer_off(3);}
	if (state->count == 1) {register_code (KC_SCLN);}
	if (state->count == 2) {register_code (KC_ENT);}
  }
}

void sclnlayer_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(IS_LAYER_ON(3)){layer_off(3);}
  if (state->count == 1) {unregister_code (KC_SCLN);}
  else {unregister_code (KC_ENT);}
}

//All tap dance functions go here.
qk_tap_dance_action_t tap_dance_actions[] = {
 //[X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset),
 //Tap once for tab, tap twice for escape
 [TABESC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, tabesc_finished, tabesc_reset, 150),
 //Hold for layer 3, tap once for quote, tap twice for enter
 [QUOT_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(quotlayer_start, quotlayer_finished, quotlayer_reset, 130),
 //Hold for layer 1, tap for escape
 [ESC_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(esclayer_start, esclayer_finished, esclayer_reset, 150),
 //Hold for layer 1, tap for space
 [SPC_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(spclayer_start, spclayer_finished, spclayer_reset, 130),
 //Hold for Left GUI, tap for slash, tap hold for layer 2, double tap for slash
 [SLSH_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, slshlayer_finished, slshlayer_reset, 150),
 //Hold for Right Shift, tap for dot
 [RSHIFT_DOT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(rshiftdot_start, rshiftdot_finished, rshiftdot_reset, 100),
 //Hold for layer 1, tap for delete
 [DEL_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dellayer_start, dellayer_finished, dellayer_reset, 150),
 //Hold for layer 3, tap once or twice for enter
 [ENTER_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(enterlayer_start, enterlayer_finished, enterlayer_reset, 130),
 //Hold for Right Shift, tap for slash
 [RSHIFT_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(rshiftslsh_start, rshiftslsh_finished, rshiftslsh_reset, 100),
 //Hold for layer 3, tap once for semicolon, tap twice for enter
 [SCLN_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(sclnlayer_start, sclnlayer_finished, sclnlayer_reset, 130),
 //Other declarations go here, separated by commas
};