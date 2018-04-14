#include "foldkb.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define qwerty 0
#define game 1
#define nav 2
#define system 3



enum custom_keycodes {
	KC_screenshot = SAFE_RANGE,
	KC_wat,
	QWERTY,
	GAME,
	NAV,
	SYSTEM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* BL
 * ,---------------------------------------------------------------------------------------------------------.
 * |  pause | esc |  ~ |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |--------+------+---+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |vol up  |   tab    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |--------+------++------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |vol dwn | control  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |--------+------++------+------+------+------+------+------|------+------+------+------+------+------+------|
 * |med next| shift    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |--------+------++------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |med prev| ctrl  | Alt  | GUI  |Lower |    backspace   |     space      | alt | RGUI |  FN2  |  ctl  |
 * `---------------------------------------------------------------------------------------------------------'
 */
	[qwerty] = KEYMAP(
		KC_MPLY, KC_ESC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQL, KC_DEL,
		KC_VOLU, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_VOLD, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_PGUP, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT, NAV,
		KC_PGDN, KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, KC_BSPC, KC_SPC, KC_RALT, KC_RGUI, SYSTEM, KC_RCTL
	),
	
	[game] = KEYMAP(
		KC_screenshot, KC_ESC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQL, KC_DEL,
		KC_VOLU, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_VOLD, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_PGUP, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT, NAV,
		KC_PGDN, KC_LCTL, KC_LCTL, KC_LALT, KC_LALT, KC_BSPC, KC_SPC, KC_RALT, KC_RGUI, SYSTEM, KC_RCTL
	),


	[nav] = KEYMAP(
		QWERTY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS,
		GAME, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, 
		KC_screenshot, KC_TRNS,KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),


	[system] = KEYMAP(
		KC_PGUP, KC_HOME, KC_END, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
		KC_PGDN, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

};

void press_key(uint16_t key) {
	register_code(key);
	unregister_code(key);
};

void press_two_keys(uint16_t key1, uint16_t key2) {
	register_code(key1);
	register_code(key2);
	unregister_code(key2);
	unregister_code(key1);
 };
  
  void press_three_keys(uint16_t key1, uint16_t key2, uint16_t key3) {
	register_code(key1);
	register_code(key2);
	register_code(key3);
	unregister_code(key3);
	unregister_code(key2);
	unregister_code(key1);
 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case KC_screenshot:
			if(record->event.pressed) {
				press_three_keys(KC_RCTL, KC_RALT, KC_PSCR);
			}

			return false;
			break;
			
		case QWERTY:
			if(record->event.pressed) {
				set_single_persistent_default_layer(qwerty);
			}
			return false;
			break;
			
		case GAME:
			if(record->event.pressed) {
				set_single_persistent_default_layer(game);
			}
			return false;
			break;
		case NAV:
			if (record->event.pressed) {
				layer_on(nav);
			} else {
				layer_off(nav);
			}
			return false;
			break;
			
		case SYSTEM:
			if (record->event.pressed) {
				layer_on(system);
			} else {
				layer_off(system);
			}
			return false;
			break;
			
	}		
	return true;
};
