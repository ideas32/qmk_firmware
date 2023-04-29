// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _RAISE
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                 KC_P7,   KC_P8,   KC_P9  ,
                 KC_P4,   KC_P5,   KC_P6  ,
                 KC_P1,   KC_P2,   KC_P3  ,
        MO(1) ,  KC_P0,   KC_PDOT, KC_PENT),
    [_RAISE] = LAYOUT(
                 RGB_MOD, RGB_VAI, _______,
                 RGB_TOG, RGB_VAD, _______,
                 _______, _______, _______,
        _______, _______, _______, _______)
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = {ENCODER_CCW_CW(KC_UP, KC_DOWN)},
        [_RAISE] = {ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}
    };
#endif
