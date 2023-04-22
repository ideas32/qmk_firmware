/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#undef SPLIT_HAND_PIN
#define SPLIT_HAND_PIN F5

#undef ENCODER_PAD_A
#undef ENCODER_PAD_B
#undef ENCODER_PAD_A_RIGHT
#undef ENCODER_PAD_B_RIGHT
#undef ENCODER_RESOLUTIONS_RIGHT

#define ENCODER_PAD_A {}
#define ENCODER_PAD_B {}
#define ENCODER_PAD_A_RIGHT {F7}
#define ENCODER_PAD_B_RIGHT {F6}
#define ENCODER_RESOLUTIONS_RIGHT {1}

#undef OLED_ENABLE

#define OLED_ENABLE

#define I2C1_SCL_PIN D0
#define I2C1_SDA_PIN D1

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS_RIGHT
#undef MATRIX_COL_PINS_RIGHT

#define MATRIX_ROW_PINS {F4, F6, D7, E6, B4}
#define MATRIX_COL_PINS {B5, F7, B1, B3, B2, B6}
#define MATRIX_ROW_PINS_RIGHT {F4, D4, B3, B2, B6}
#define MATRIX_COL_PINS_RIGHT {B1, C6, D7, E6, B4, B5}

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE

#define FORCE_NKRO

#undef RGBLIGHT_ENABLE
#define RGBLIGHT_ENABLE

#undef RGB_DI_PIN
#define RGB_DI_PIN 25
#undef RGBLED_NUM
#define RGBLED_NUM 2
#undef RGBLED_SPLIT
#define RGBLED_SPLIT {1, 1}

#define OLED_BRIGHTNESS 255
#define SPLIT_USB_DETECT
#define SPLIT_HAND_PIN F5
#define SOFT_SERIAL_PIN D2
