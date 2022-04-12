#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_SPC, TO(3), MO(2), KC_LBRC, KC_RBRC, KC_END, 
		KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_HOME, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, 
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, 
		KC_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, 
		KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_SPC, KC_LSFT),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 
		KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
		KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_PGUP, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_INS, 
		KC_TRNS, KC_TRNS, KC_SLCK, KC_PAUS, KC_PSCR, KC_DEL, 
		KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, 
		KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, 
		KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP( //toggle layer
		KC_SPC, TO(0), TT(2), KC_LEFT, KC_DOWN, KC_RIGHT, 
		KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_HOME, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, 
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, 
		KC_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, 
		KC_LCTL, KC_LGUI, KC_LALT, TT(1), KC_SPC, KC_LSFT),

};


bool encoder_update_user(uint8_t index, bool clockwise) {
	if(index == 0){ //VOL
		if (IS_LAYER_ON(1)) {
			/*hold Fn*/
        	if (clockwise) {
            	tap_code(KC_BRIU);
        	} else {
            	tap_code(KC_BRID);
        	}
    	}else{
    		/*default*/
    		if (clockwise) {
      			tap_code(KC_VOLU);
    		} else {
      			tap_code(KC_VOLD);
    		}
   		}
   }else if(index == 1){ //ARROW
		if (IS_LAYER_ON(1)) {
			/*hold Fn*/
        	if (clockwise) {
            	tap_code(KC_DOWN);
        	} else {
            	tap_code(KC_UP);
        	}
    	}else{
    		/*default*/
    		if (clockwise) {
      			tap_code(KC_RIGHT);
    		} else {
      			tap_code(KC_LEFT);
    		}
   		}
   }
   return true;
}