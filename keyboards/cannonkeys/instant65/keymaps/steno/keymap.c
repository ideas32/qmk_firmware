#include QMK_KEYBOARD_H
#include "keymap_steno.h"

// tap dance declarations
enum {
    TD_LCTL_CAPS,
};

// tap dance def

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LCTL_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
};

enum layers {
    _qwerty,
    _steno,
    _raise,
};


// initialize backlight to 0
void keyboard_post_init_user(void){
    backlight_level(5);
    backlight_disable();
    breathing_disable();
}

// set backlight based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _raise:
        backlight_toggle();
        break;
    case _steno:
        backlight_enable();
        backlight_level(6);
        break;
    default: //  for any other layers, or the default layer
        backlight_disable();
        break;
    }
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_qwerty] = LAYOUT_default(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, MO(2), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, TD(TD_LCTL_CAPS), KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

	[_steno] = LAYOUT_default(QK_GESC, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5, STN_N6, STN_N7, STN_N8, STN_N9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, KC_RBRC, KC_BSLS, KC_END, MO(2), STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR, KC_ENT, KC_PGUP, KC_LSFT, KC_NO, KC_NO, STN_A, STN_O, KC_NO, STN_E, STN_U, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, TD(TD_LCTL_CAPS), KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT),

	[_raise] = LAYOUT_default(KC_LSFT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_steno), GUI_ON, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_INC, GUI_OFF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, BL_TOGG, BL_DEC, KC_MPLY),

};