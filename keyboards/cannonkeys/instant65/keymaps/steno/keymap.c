#include QMK_KEYBOARD_H
#include "keymap_steno.h"

// tap dance declarations
enum {
    TD_RSFT_CW,
    TD_LCTL_CAPS,
    TD_HOME_END,
};

// tap dance def

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTL_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};

enum layers {
    _qwerty,
    _steno,
    // _lower,
    _raise,
};


// initialize backlight to 0
void keyboard_post_init_user(void){
    backlight_level(5);
    backlight_disable();
    breathing_disable();
};

// set backlight based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _raise:
        backlight_toggle();
        break;
    //case _lower:
        //backlight_toggle();
        //break;
    case _steno:
        backlight_enable();
        backlight_level(6);
        break;
    default: //  for any other layers, or the default layer
        backlight_disable();
        break;
    }
  return state;
};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_BSPC:
        if (record->event.pressed) {
            for(size_t i=0; i<KEYBOARD_REPORT_KEYS; i++) {
                if (keyboard_report->keys[i]==KC_LSFT) {
                    register_code(KC_LGUI);
                    register_code(KC_BSPC);
                    unregister_code(KC_BSPC);
                    unregister_code(KC_LGUI);
                    return false;
                } else{
                    return true;
                }
            };
        };
        return true;
    default:
        return true; // Process all other keycodes normally
  }
}*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_qwerty] = LAYOUT_default(QK_GESC /*esc*/, KC_1 /*1!*/, KC_2 /*2@*/, KC_3 /*3#*/, KC_4 /*4$*/, KC_5 /*5%*/, KC_6 /*6^*/, KC_7 /*7&*/, KC_8 /*8*/, KC_9 /*9(*/, KC_0 /*0)*/, KC_MINS /*-_*/, KC_EQL /*=+*/, KC_BSPC /*bksp*/, KC_DEL /*del, row 1 end*/, KC_TAB /*tab*/, KC_Q /*q*/, KC_W /*w*/, KC_E /*e*/, KC_R /*r*/, KC_T /*t*/, KC_Y /*y*/, KC_U /*u*/, KC_I /*i*/, KC_O /*o*/, KC_P /*p*/, KC_LBRC /*[{*/, KC_RBRC /*]}*/, KC_BSLS/*\|*/, TD(TD_HOME_END) /*end, row 2 end*/, LM(2, MOD_LGUI) /*caps*/ , KC_A /*a*/, KC_S /*s*/, KC_D /*d*/, KC_F /*f*/, KC_G /*g*/, KC_H /*h*/, KC_J /*j*/, KC_K /*k*/, KC_L /*l*/, KC_SCLN /*;*/, KC_QUOT /*"'*/, KC_ENT /*ent*/ , KC_PGUP /*pgup, row 3 end*/, KC_LSFT /*lsft*/, KC_Z /*z*/, KC_X /*x*/, KC_C /*c*/, KC_V /*v*/, KC_B /*b*/, KC_N /*n*/, KC_M /*m*/, KC_COMM /*,<*/, KC_DOT /*.>*/, KC_SLSH /*/?*/, KC_RSFT /*rsft*/, KC_UP /*up*/, KC_PGDN /*pgdn*/, TD(TD_LCTL_CAPS) /*lctl*/, KC_LGUI /*lalt*/, MO(2) /*lcmd*/, KC_SPC /*spc*/, KC_RGUI /*rcmd*/, KC_RCTL /*rctl*/, KC_LEFT /*left*/, KC_DOWN /*down*/, KC_RGHT /*right*/),

	[_steno] = LAYOUT_default(QK_GESC, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5, STN_N6, STN_N7, STN_N8, STN_N9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, KC_RBRC, KC_BSLS, KC_END, MO(2), STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR, KC_ENT, KC_PGUP, KC_LSFT, KC_NO, KC_NO, STN_A, STN_O, KC_NO, STN_E, STN_U, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, TD(TD_LCTL_CAPS), KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT),

    //[_lower] = LAYOUT_default(_______ /*esc*/, _______/*1!*/, _______/*2@*/, _______/*3#*/, _______/*4$*/, _______/*5%*/, _______/*6^*/, _______/*7&*/, _______/*8*/, _______/*9(*/, _______ /*0)*/, _______ /*-_*/, _______/*=+*/, _______/*bksp*/, _______/*del, row 1 end*/, _______/*tab*/, _______/*q*/, _______/*w*/, _______/*e*/, _______/*r*/, _______/*t*/, _______/*y*/, _______/*u*/, _______/*i*/, _______/*o*/, _______/*p*/, _______/*[{*/, _______/*]}*/, _______/*\|*/, G(A(KC_ESCAPE)) /*end, row 2 end*/, _______/*caps*/ ,_______ /*a*/, _______/*s*/, _______/*d*/,_______ /*f*/,_______ /*g*/,_______ /*h*/,_______ /*j*/, _______/*k*/, _______/*l*/,_______ /*;*/,_______ /*'*/, _______/*ent*/, _______/*pgup, row 3 end*/, _______/*lsft*/, _______/*z*/,_______ /*x*/,_______ /*c*/, _______/*v*/,_______ /*b*/,_______ /*n*/,_______ /*m*/, _______/*,<*/, _______/*.>*/, _______/*/?*/, _______/*rsft*/, _______/*left*/, _______/*pgdn*/, _______/*lctl*/, _______/*lalt*/,_______ /*lcmd*/, _______/*spc*/, QK_BOOT /*rcmd*/,_______ /*rctl*/, _______/*left*/, _______/*down*/,_______ /*right*/),

    [_raise] = LAYOUT_default(C(KC_Q) /*esc*/, KC_F1 /*1!*/, KC_F2 /*2@*/, KC_F3 /*3#*/, KC_F4 /*4$*/, KC_F5 /*5%*/, KC_F6 /*6^*/, KC_F7 /*7&*/, KC_F8 /*8*/, KC_F9 /*9(*/, KC_F10 /*0)*/, KC_F11 /*-_*/, KC_F12 /*=+*/, _______ /*bksp*/, _______ /*del, row 1 end*/, _______ /*tab*/, _______ /*q*/, _______ /*w*/, _______ /*e*/, _______ /*r*/, _______ /*t*/, _______ /*y*/, _______ /*u*/, _______ /*i*/, _______ /*o*/, _______ /*p*/, _______ /*[{*/, _______ /*]}*/, _______ /*\|*/, _______ /*end, row 2 end*/, _______ /*caps*/ , _______ /*a*/, _______ /*s*/, _______ /*d*/, _______ /*f*/, _______ /*g*/, _______ /*h*/, _______ /*j*/, _______ /*k*/, _______ /*l*/, _______ /*;*/, _______ /*'*/, TG(_steno) /*ent*/ , _______ /*pgup, row 3 end*/, _______ /*lsft*/, G(KC_Z) /*z*/, _______ /*x*/, _______ /*c*/, _______ /*v*/, _______ /*b*/, _______ /*n*/, _______ /*m*/, _______ /*,<*/, _______ /*.>*/, _______ /*/?*/, _______ /*rsft*/, _______ /*left*/, S(KC_4) /*pgdn*/, _______ /*lctl*/, _______ /*lalt*/, _______ /*lcmd*/, _______ /*spc*/, _______ /*rcmd*/, QK_BOOT /*rctl*/, _______ /*left*/, _______ /*down*/, _______ /*right*/),
};

// for additional layers: LAYOUT_default(/*esc*/, /*1!*/, /*2@*/, /*3#*/, /*4$*/, /*5%*/, /*6^*/, /*7&*/, /*8*/, /*9(*/, /*0)*/, /*-_*/, /*=+*/, /*bksp*/, /*del, row 1 end*/, /*tab*/, /*q*/, /*w*/, /*e*/, /*r*/, /*t*/, /*y*/, /*u*/, /*i*/, /*o*/, /*p*/, /*[{*/, /*]}*/, /*\|*/, /*end, row 2 end*/, /*caps*/ , /*a*/, /*s*/, /*d*/, /*f*/, /*g*/, /*h*/, /*j*/, /*k*/, /*l*/, /*;*/, /*'*/, /*ent*/ , /*pgup, row 3 end*/, /*lsft*/, /*z*/, /*x*/, /*c*/, /*v*/, /*b*/, /*n*/, /*m*/, /*,<*/, /*.>*/, /*/?*/, /*rsft*/, /*left*/, /*pgdn*/, /*lctl*/, /*lalt*/, /*lcmd*/, /*spc*/, /*rcmd*/, /*rctl*/, /*left*/, /*down*/, /*right*/)
