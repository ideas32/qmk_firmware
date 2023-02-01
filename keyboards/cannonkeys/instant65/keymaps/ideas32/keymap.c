#include QMK_KEYBOARD_H

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

enum custom_keycodes {  //custom keycodes def
    QMKFLASH = SAFE_RANGE,
    QMKMAKE,
};

enum layers { //def layers
    _qwerty,
    _raise,
    _lower,
    _adjust,
};


// initialize backlight to 0
void keyboard_post_init_user(void){
    backlight_level(6);
    backlight_disable();
    breathing_disable();
};

// set backlight based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _raise, _lower, _adjust);
    switch (get_highest_layer(state)) {
    case _raise:
        backlight_toggle();
        break;
    case _lower:
        backlight_toggle();
        break;
    case _adjust:
        backlight_toggle();
        break;
    default: //  for any other layers, or the default layer
        backlight_disable();
        break;
    };
  return state;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QMKFLASH: // send cli flash command and put keyboard into bootloader
        if (record->event.pressed) {
            // when keycode QMKFLASH is pressed
            clear_keyboard();
            SEND_STRING("qmk flash -kb cannonkeys/instant65 -km ideas32 -j 0");
            SEND_STRING(SS_TAP(X_ENT));
            reset_keyboard();
        };
        break;
    case QMKMAKE: // send cli make command
        if (record->event.pressed) {
            clear_keyboard();
            SEND_STRING("qmk compile -kb cannonkeys/instant65 -km ideas32 -j 0");
            SEND_STRING(SS_TAP(X_ENT));
        };
    };
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_qwerty] = LAYOUT_default(QK_GESC /*esc*/, KC_1 /*1!*/, KC_2 /*2@*/, KC_3 /*3#*/, KC_4 /*4$*/, KC_5 /*5%*/, KC_6 /*6^*/, KC_7 /*7&*/, KC_8 /*8*/, KC_9 /*9(*/, KC_0 /*0)*/, KC_MINS /*-_*/, KC_EQL /*=+*/, KC_BSPC /*bksp*/, KC_DEL /*del, row 1 end*/, KC_TAB /*tab*/, KC_Q /*q*/, KC_W /*w*/, KC_E /*e*/, KC_R /*r*/, KC_T /*t*/, KC_Y /*y*/, KC_U /*u*/, KC_I /*i*/, KC_O /*o*/, KC_P /*p*/, KC_LBRC /*[{*/, KC_RBRC /*]}*/, KC_BSLS/*\|*/, TD(TD_HOME_END) /*end, row 2 end*/, LM(_raise, MOD_LGUI) /*caps*/ , KC_A /*a*/, KC_S /*s*/, KC_D /*d*/, KC_F /*f*/, KC_G /*g*/, KC_H /*h*/, KC_J /*j*/, KC_K /*k*/, KC_L /*l*/, KC_SCLN /*;*/, KC_QUOT /*"'*/, KC_ENT /*ent*/ , KC_PGUP /*pgup, row 3 end*/, KC_LSFT /*lsft*/, KC_Z /*z*/, KC_X /*x*/, KC_C /*c*/, KC_V /*v*/, KC_B /*b*/, KC_N /*n*/, KC_M /*m*/, KC_COMM /*,<*/, KC_DOT /*.>*/, KC_SLSH /*/?*/, KC_RSFT /*rsft*/, KC_UP /*up*/, KC_PGDN /*pgdn*/, TD(TD_LCTL_CAPS) /*lctl*/, KC_LGUI /*lalt*/, MO(_lower) /*lcmd*/, KC_SPC /*spc*/, KC_RGUI /*rcmd*/, KC_RCTL /*rctl*/, KC_LEFT /*left*/, KC_DOWN /*down*/, KC_RGHT /*right*/),

    [_raise] = LAYOUT_default(C(KC_Q) /*esc*/, _______ /*1!*/, _______ /*2@*/, _______ /*3#*/, _______ /*4$*/, _______ /*5%*/, _______ /*6^*/, _______ /*7&*/, _______ /*8*/, _______ /*9(*/, _______ /*0)*/, _______ /*-_*/, _______ /*=+*/, _______ /*bksp*/, _______ /*del, row 1 end*/, _______ /*tab*/, _______ /*q*/, _______ /*w*/, _______ /*e*/, _______ /*r*/, _______ /*t*/, _______ /*y*/, _______ /*u*/, _______ /*i*/, _______ /*o*/, _______ /*p*/, _______ /*[{*/, _______ /*]}*/, _______ /*\|*/, _______ /*end, row 2 end*/, _______ /*caps*/ , _______ /*a*/, _______ /*s*/, _______ /*d*/, _______ /*f*/, _______ /*g*/, _______ /*h*/, _______ /*j*/, _______ /*k*/, _______ /*l*/, _______ /*;*/, _______ /*'*/, _______ /*ent*/ , _______ /*pgup, row 3 end*/, _______ /*lsft*/, _______ /*z*/, _______ /*x*/, _______ /*c*/, _______ /*v*/, _______ /*b*/, _______ /*n*/, _______ /*m*/, _______ /*,<*/, _______ /*.>*/, _______ /*/?*/, _______ /*rsft*/, _______ /*left*/, _______ /*pgdn*/, _______ /*lctl*/, _______ /*lalt*/, _______ /*lcmd*/, _______ /*spc*/, _______ /*rcmd*/, _______ /*rctl*/, _______ /*left*/, _______ /*down*/, _______ /*right*/),

    [_lower] = LAYOUT_default(A(G(KC_ESC)) /*esc*/, KC_F1 /*1!*/, KC_F2 /*2@*/, KC_F3 /*3#*/, KC_F4 /*4$*/, KC_F5 /*5%*/, KC_F6 /*6^*/, KC_F7 /*7&*/, KC_F8 /*8*/, KC_F9 /*9(*/, KC_F10 /*0)*/, KC_F11 /*-_*/, KC_F12 /*=+*/, KC_DEL /*bksp*/, _______ /*del, row 1 end*/, G(KC_TAB) /*tab*/, _______ /*q*/, KC_VOLU /*w*/, _______ /*e*/, _______ /*r*/, _______ /*t*/, _______ /*y*/, _______ /*u*/, _______ /*i*/, _______ /*o*/, _______ /*p*/, _______ /*[{*/, _______ /*]}*/, _______ /*\|*/, _______ /*end, row 2 end*/, _______ /*caps*/, KC_MPRV /*a*/, KC_VOLD /*s*/, KC_MNXT /*d*/, _______ /*f*/, _______ /*g*/, _______ /*h*/, _______ /*j*/, _______ /*k*/, _______ /*l*/, _______ /*;*/, _______ /*'*/, _______ /*ent*/ , _______ /*pgup, row 3 end*/, _______ /*lsft*/, _______ /*z*/, _______ /*x*/, _______ /*c*/, _______ /*v*/, _______ /*b*/, _______ /*n*/, _______ /*m*/, _______ /*,<*/, _______ /*.>*/, _______ /*/?*/, _______ /*rsft*/, _______ /*left*/, _______ /*pgdn*/, _______ /*lctl*/, _______ /*lalt*/, _______ /*lcmd*/, KC_MPLY /*spc*/, _______ /*rcmd*/, _______ /*rctl*/, _______ /*left*/, _______ /*down*/, _______ /*right*/),

    [_adjust] = LAYOUT_default(QMKMAKE /*esc*/, _______ /*1!*/, _______ /*2@*/, _______ /*3#*/, _______ /*4$*/, _______ /*5%*/, _______ /*6^*/, _______ /*7&*/, _______ /*8*/, _______ /*9(*/, _______ /*0)*/, _______ /*-_*/, _______ /*=+*/, _______ /*bksp*/, _______ /*del, row 1 end*/, _______ /*tab*/, _______ /*q*/, _______ /*w*/, _______ /*e*/, _______ /*r*/, _______ /*t*/, _______ /*y*/, _______ /*u*/, _______ /*i*/, _______ /*o*/, _______ /*p*/, _______ /*[{*/, _______ /*]}*/, _______ /*\|*/, _______ /*end, row 2 end*/, _______ /*caps*/, _______ /*a*/, _______ /*s*/, _______ /*d*/, _______ /*f*/, _______ /*g*/, _______ /*h*/, _______ /*j*/, _______ /*k*/, _______ /*l*/, _______ /*;*/, _______ /*'*/, QMKFLASH /*ent*/ , _______ /*pgup, row 3 end*/, _______ /*lsft*/, _______ /*z*/, _______ /*x*/, _______ /*c*/, _______ /*v*/, _______ /*b*/, _______ /*n*/, _______ /*m*/, _______ /*,<*/, _______ /*.>*/, _______ /*/?*/, _______ /*rsft*/, _______ /*left*/, _______ /*pgdn*/, _______ /*lctl*/, _______ /*lalt*/, _______ /*lcmd*/, _______ /*spc*/, _______ /*rcmd*/, _______ /*rctl*/, _______ /*left*/, _______ /*down*/, _______ /*right*/),
};







// for additional layers: [] = LAYOUT_default(_______ /*esc*/, _______ /*1!*/, _______ /*2@*/, _______ /*3#*/, _______ /*4$*/, _______ /*5%*/, _______ /*6^*/, _______ /*7&*/, _______ /*8*/, _______ /*9(*/, _______ /*0)*/, _______ /*-_*/, _______ /*=+*/, _______ /*bksp*/, _______ /*del, row 1 end*/, _______ /*tab*/, _______ /*q*/, _______ /*w*/, _______ /*e*/, _______ /*r*/, _______ /*t*/, _______ /*y*/, _______ /*u*/, _______ /*i*/, _______ /*o*/, _______ /*p*/, _______ /*[{*/, _______ /*]}*/, _______ /*\|*/, _______ /*end, row 2 end*/, _______ /*caps*/, _______ /*a*/, _______ /*s*/, _______ /*d*/, _______ /*f*/, _______ /*g*/, _______ /*h*/, _______ /*j*/, _______ /*k*/, _______ /*l*/, _______ /*;*/, _______ /*'*/, _______ /*ent*/ , _______ /*pgup, row 3 end*/, _______ /*lsft*/, _______ /*z*/, _______ /*x*/, _______ /*c*/, _______ /*v*/, _______ /*b*/, _______ /*n*/, _______ /*m*/, _______ /*,<*/, _______ /*.>*/, _______ /*/?*/, _______ /*rsft*/, _______ /*left*/, _______ /*pgdn*/, _______ /*lctl*/, _______ /*lalt*/, _______ /*lcmd*/, _______ /*spc*/, _______ /*rcmd*/, _______ /*rctl*/, _______ /*left*/, _______ /*down*/, _______ /*right*/),
