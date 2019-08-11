#pragma once

#include "quantum.h"

#define td_variables qk_tap_dance_state_t *state, void *user_data

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

//Tap dance enums
enum {
  //X_CTL = 0,
  TABESC = 0,//1=tab 2=esc
  QUOT_LAYER,//LT(3,KC_QUOT),enter
  ESC_LAYER,//LT(1,KC_ESC)
  SPC_LAYER,//LT(1,KC_SPC)
  SLSH_LAYER,//LGUI_T(KC_SLSH),layer2/slash
  RSHIFT_DOT,//RSFT_T(KC_DOT)
  DEL_LAYER,//LT(1,KC_DEL)
  ENTER_LAYER,//LT(3,KC_ENT)
  RSHIFT_SLSH,//RSFT_T(KC_SLSH)

};

int cur_dance (qk_tap_dance_state_t *state);

//Function declaration for the tap dances. Put it here so it can be used in any keymap
//void x_finished (qk_tap_dance_state_t *state, void *user_data);
//void x_reset (qk_tap_dance_state_t *state, void *user_data);

void tabesc_finished (td_variables);
void tabesc_reset (td_variables);

void quotlayer_start (td_variables);
void quotlayer_finished (td_variables);
void quotlayer_reset (td_variables);

void esclayer_start (td_variables);
void esclayer_finished (td_variables);
void esclayer_reset (td_variables);

void spclayer_start (td_variables);
void spclayer_finished (td_variables);
void spclayer_reset (td_variables);

void slshlayer_finished (td_variables);
void slshlayer_reset (td_variables);

void rshiftdot_start (td_variables);
void rshiftdot_finished (td_variables);
void rshiftdot_reset (td_variables);

void dellayer_start (td_variables);
void dellayer_finished (td_variables);
void dellayer_reset (td_variables);

void enterlayer_start (td_variables);
void enterlayer_finished (td_variables);
void enterlayer_reset (td_variables);

void rshiftslsh_start(td_variables);
void rshiftslsh_finished (td_variables);
void rshiftslsh_reset (td_variables);
