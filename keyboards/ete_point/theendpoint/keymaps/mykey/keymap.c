// Copyright 2023 YMGWorks (@YMGWorks)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdio.h>

enum ETE_keycodes {
    ETE_SAFE_RANGE = SAFE_RANGE,
    REC_RST, // ETE configuration: reset to default
    REC_SAVE, // ETE configuration: save to EEPROM

    CPI_I100, // CPI +100 CPI
    CPI_D100, // CPI -100 CPI
    CPI_I1K, // CPI +1000 CPI
    CPI_D1K, // CPI -1000 CPI

    // In scroll mode, motion from primary trackball is treated as scroll
    // wheel.
    SCRL_TO, // Toggle scroll mode
    SCRL_MO, // Momentary scroll mode
    SCRL_DVI, // Increment scroll divider
    SCRL_DVD, // Decrement scroll divider
    KANA,
};

#define REC_RST QK_KB_0
#define REC_SAVE QK_KB_1
#define CPI_I100 QK_KB_2
#define CPI_D100 QK_KB_3
#define CPI_I1K QK_KB_4
#define CPI_D1K QK_KB_5
#define SCRL_TO QK_KB_6
#define SCRL_MO QK_KB_7
#define SCRL_DVI QK_KB_8
#define SCRL_DVD QK_KB_9



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
   //,---------------------------------------------------------------------.     ,-----------------------------------------------------------------------.
      KC_ESC,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_MUTE, MO(1),       KC_RGUI,  KC_BTN2,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
      KC_TAB, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    SCRL_MO,   KC_LALT,      KC_RGUI,  KC_BTN1,  KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
      KC_LGUI, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    SCRL_MO,   KC_LSFT,     KC_LEFT, KC_RCTL, KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KANA,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
      KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,         KC_SPC,   KC_LSFT,  KC_LALT,      KC_END,  KC_DOWN, MO(2) ,          SCRL_MO,  KC_LSFT, KC_RALT,  KC_SPC,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
      KC_PGUP,KC_PGDN,                                                                                                                  KC_LEFT, KC_RIGHT
  ),
    [1] = LAYOUT(
  //,----------------------------------------------------------------------.     ,-----------------------------------------------------------------------.
      KC_ESC,  KC_F1,    KC_F2,  KC_F3,    KC_F4,   KC_F5,   KC_TRNS, KC_TRNS,     KC_RGUI, KC_TRNS,  KC_F6,   KC_F7,  KC_F8,   KC_F10, KC_F12,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
      KC_TILD,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_SPC, KC_LALT,      KC_RGUI, KC_TRNS,  KC_6,   KC_7,    KC_8,    KC_9,     KC_0,   KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
      KC_LGUI,KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_LALT, KC_LSFT,     KC_TRNS, KC_RCTL,  KC_LBRC,KC_RBRC, KC_LT,   KC_GT,   KC_PMNS, KC_PEQL,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
      KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,          KC_SPC, KC_LSFT, KC_LALT,     KC_TRNS, KC_TRNS,  MO(3),           SCRL_MO,  KC_LSFT, KC_RALT,  KC_SPC,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
     KC_TRNS, KC_TRNS,                                                                                                                  KC_UP,   KC_DOWN 
  //|--------+--------+--------+--------+--------+--------+--------+---------.  ,--------+-------+--------+--------+--------+---------+--------+---------'
  ),

    [2] = LAYOUT(
  //,------------------------------------------------------------------------.    ,----------------------------------------------------------------------.
     KC_ESC,  KC_F1,    KC_F2,  KC_F3,    KC_F4,   KC_F5,   KC_TRNS, MO(3),    KC_RGUI, KC_TRNS, KC_F6,   KC_F7,  KC_QUOT,   KC_BSLS, KC_TILD, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+-------+--------+--------+--------+---------|
     KC_LSFT, KC_AT,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_SPC, KC_LALT,      KC_RGUI, KC_TRNS, KC_LEFT, KC_DOWN,KC_UP,   KC_RIGHT,KC_MINS, KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+-------+--------+--------+--------+---------|
     KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_LALT, KC_LSFT,    KC_TRNS, KC_RCTL, KC_LCBR, KC_RCBR,KC_LPRN, KC_RPRN, KANA,    KANA,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+-------+--------+--------+--------+---------|
     KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,            KC_SPC,  KC_LSFT,   KC_LALT,    KC_TRNS, KC_TRNS, KC_TRNS,         SCRL_MO,  KC_LSFT, KC_RALT,  KC_SPC,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+-------+--------+--------+--------+---------|
     KC_MS_WH_LEFT,KC_MS_WH_RIGHT,                                                                                                    KC_BSPC, KC_DEL  
  //|--------+--------+--------+--------+--------+--------+--------+---------.  ,---------+-------+--------+-------+--------+--------+--------+---------'
  ),
   [3] = LAYOUT(
//,-------------------------------------------------------------------------.    ,-----------------------------------------------------------------------.
     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, REC_RST, KC_TRNS, SCRL_DVI, SCRL_MO,    KC_RGUI, KC_TRNS, CPI_I100,CPI_D100,SCRL_DVD,SCRL_DVI,REC_SAVE,KC_MS_BTN2,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
     KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,   KC_PERC, KC_SPC, KC_LALT,      KC_RGUI, KC_TRNS, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,KC_RPRN, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
     KC_LGUI, KC_TRNS,CPI_I100,CPI_D100,KC_TRNS,  KC_MS_BTN2, KC_LALT,KC_LSFT,   KC_TRNS,KC_MS_BTN1,KC_BTN5,KC_BTN1, KC_VOLD, KC_VOLU,KC_MUTE,KC_MS_WH_DOWN,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
     KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,           KC_SPC,  KC_LSFT, KC_LALT,    KC_MS_BTN1,KC_TRNS,KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------+---------|
     KC_TRNS, KC_TRNS,                                                                                                         KC_MS_WH_UP,KC_MS_WH_DOWN
  //|--------+--------+--------+--------+--------+--------+-------+----------.   ,-------+--------+--------+--------+--------+--------+--------+---------'
 )
};
// clang-format on


#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 3:
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            break;
        default:
            set_auto_mouse_enable(true);
            break;
    }
    return state;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;
    if(index == 0){
     if(clockwise){
         key.row = 4;
         key.col = 0;
       } else {
         key.row = 4;
         key.col = 1;
       }
      
       uint8_t layer = layer_switch_get_layer(key);
       uint8_t keycode = keymap_key_to_keycode(layer,key);
       tap_code16(keycode);
    
    }else if(index == 1){
      if(clockwise){
         key.row = 9;
         key.col = 0;
       } else {
         key.row = 9;
         key.col = 1;
       }
      
       uint8_t layer = layer_switch_get_layer(key);
       uint8_t keycode = keymap_key_to_keycode(layer,key);
       tap_code16(keycode);
}
return false; 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KANA:
      if (record->event.pressed){
        // tap_code(KC_LCTL);
        // tap_code(KC_SPC);
        register_code(KC_LCTL);
        register_code(KC_SPC);
        unregister_code(KC_LCTL);
        unregister_code(KC_SPC);
      }
      return false;
      }
  return true;
}