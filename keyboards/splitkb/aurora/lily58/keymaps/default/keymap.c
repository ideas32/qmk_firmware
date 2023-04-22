#include QMK_KEYBOARD_H

#define LOWER MO(_lower) // layer macros
#define RAISE MO(_raise) // layer macros
#define TRANS _______ // nesscesary transparent keycodes for layer switching

#define POWER_LED_ON writePinLow(24)
#define POWER_LED_OFF writePinHigh(24)

#define MASTER_LEFT
// layer defs
enum layers{
    _qwerty,
    _lower,
    _raise,
    _adjust,
};

// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_qwerty] = LAYOUT(QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8    , KC_9  , KC_0   , KC_EQL ,
                       KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I    , KC_O  , KC_P   , KC_MINS,
                       KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K    , KC_L  , KC_SCLN, KC_QUOT,
                       KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC, KC_RBRC, KC_N   , KC_M   , KC_COMM , KC_DOT, KC_SLSH, KC_RSFT,
                                                  KC_LALT, LOWER  , KC_LGUI, KC_ENT , KC_SPC , KC_BSPC, RAISE  , KC_RGUI ),

	[_lower] = LAYOUT(_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_MPLY,
                      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
                      KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
                      _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                                 _______, TRANS  , _______, _______, _______, _______, TRANS  , _______),

	[_raise] = LAYOUT(_______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
                      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
                      KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, KC_PLUS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
                                                 _______, _______, _______, _______, _______, _______, _______, _______),

	[_adjust] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                  XXXXXXX, TRANS  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TRANS  , XXXXXXX)
};

// encoders
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state) == _qwerty){ // qwerty
        if (clockwise) {
            tap_code16_delay(KC_RGHT, 10);
        } else {
            tap_code16_delay(KC_LEFT, 10);
        };
    } else if (get_highest_layer(layer_state) == _lower) { //lower
        if (clockwise) {
            tap_code16_delay(KC_VOLU, 10);
        } else {
            tap_code16_delay(KC_VOLD, 10);
        };
    } else if (get_highest_layer(layer_state) == _raise) { //raise
        if (clockwise) {
            tap_code16_delay(KC_DOWN, 10);
        } else {
            tap_code16_delay(KC_UP, 10);
        };
    } else { // adjust
        if (clockwise) {
            tap_code16_delay(KC_VOLU, 10);
        } else {
            tap_code16_delay(KC_VOLD, 10);
        };
    };
    return false;
};

void keyboard_pre_init_user(void) {
    // set power led and turn it on
    setPinOutput(24);
    POWER_LED_ON;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_at(HSV_WHITE, 0);
    rgblight_sethsv_at(HSV_RED, 1);


}

// TODO: keycode stuffs
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        /*case FOO:
            if (record->event.pressed){
                something when pressed
            } else {
                something else when released
            };*/
    };
    return true; // all other keycodes processed normally
};

// layer stuffs
layer_state_t layer_state_set_user(layer_state_t state){
    // when lower and raise activate adjust
    state = update_tri_layer_state(state, _lower, _raise, _adjust);
    // TODO: when layer
    switch (get_highest_layer(state)) {
    case _qwerty:
        break;
    case _lower:
        break;
    case _raise:
        break;
    case _adjust:
        break;
    default:
        break;
    };
    return state;
};

/*static void render_logo(void) {
    static const char logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_clear();
    oled_write(logo, false);
}*/

static void render_layer(void) {
    oled_write_P(PSTR("Layer\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _qwerty:
        oled_write_P(PSTR("QWRTY\n"), false);
        break;
        case _raise:
        oled_write_P(PSTR("RAISE\n"), false);
        break;
        case _lower:
        oled_write_P(PSTR("LOWER\n"), false);
        break;
        case _adjust:
        oled_write_P(PSTR("ADJST\n"), false);
        break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        // Host Keyboard Layer Status
        oled_on();
        render_layer();
    } else {
        oled_on();
        render_layer();
    }
    return false;
}
