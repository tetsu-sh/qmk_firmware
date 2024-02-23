// Copyright 2023 YMGWorks (@YMGWorks)
// SPDX-License-Identifier: MIT

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

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS \
    { D4, C6, D7, E6 ,B4 }

// wiring of each half
#define MATRIX_COL_PINS \
    { F4, F5, F6, F7, B1, B3, B2, B6 }

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6

#define ENCODERS_PAD_A { D0,B4 }
#define ENCODERS_PAD_B { D1,B5 }

#define ENCODER_RESOLUTIONS {3,3}

#define SPLT_USB_DETECT
#define SPLT_USB_TIMEOUT_POOL 500

#define WS2812_DI_PIN D3
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LAYERS
#define RGBLED_NUM 20
#define RGBLED_SPLIT {10, 10}
#define RGBLIGHT_SPLIT
#endif

#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
#    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255