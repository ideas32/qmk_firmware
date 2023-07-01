// Copyright 2023 Kean Li (@ideas32)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                 KC_7   , KC_8   , KC_9   ,
                 KC_4   , KC_5   , KC_6   ,
                 KC_1   , KC_2   , KC_3   ,
    MO(_RAISE),  KC_0   , KC_DOT , KC_ENT ),
    [_RAISE] = LAYOUT(
                 RGB_M_B, RGB_VAI, RGB_MOD,
                 RGB_TOG, RGB_VAD, VK_TOGG,
                 _______, _______, _______,
        _______, _______, _______, _______)
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = {ENCODER_CCW_CW(KC_UP, KC_DOWN)},
        [_RAISE] = {ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}
    };
#endif
