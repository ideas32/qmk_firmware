// Copyright 2023 Kean Li (@ideas32)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define FORCE_NKRO

#define I2C_DRIVER I2CD0
#define I2C1_SCL_PIN GP13
#define I2C1_SDA_PIN GP12

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 2000U //
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1 // press top left key while plugging in board to jump to bootloader

#define ENCODER_MAP_ENABLE


#define RGB_MATRIX_LED_COUNT 16
#define RGB_DI_PIN GP11

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE

#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE

