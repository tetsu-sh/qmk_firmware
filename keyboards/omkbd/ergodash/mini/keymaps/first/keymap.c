#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  KANA
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  Bksp|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | ALT  |                    | Enter|   N  |   M  |   ,  |   .  |   /  | Space|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| GUI  |Space |||||||| SHift | Ctrl| Raise|||||||| Left | ＼   |  -    | "    |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_BTN2 , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_BTN1, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KANA ,                        KC_LGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LOWER,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LALT,             KC_SPC,   LOWER , KC_LSFT,        KC_LGUI,KC_LCTL , RAISE,            KC_QUOT, KC_BSLS, KC_TILD,   KC_DEL
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_GRV , KC_F1, KC_F2,   KC_F3, KC_F4,  KC_F5, KC_F6,                        KC_F6, KC_F6, KC_F7, KC_F8, KC_F9, KC_F12, KC_PIPE,
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LCBR,                        KC_RCBR, KC_6, KC_7, KC_8  , KC_9, KC_0, KC_TILD ,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC ,                        KC_ENT , KC_LBRC,    KC_RBRC,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KANA,             KC_SPC,   LOWER , KC_LSFT,        KC_LGUI,KC_LCTL , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* Raise
  * 
  * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * | Ctrl |  F11 |  F12 | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_GRV , KC_1,   KC_F,   KC_3,   KC_4,   KC_5,   KC_F6,                        KC_F6, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
    KC_TAB, KC_F1,   KC_J,   KC_LCTL,   KC_LGUI,   KC_K,   KC_F6,                        KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_MINS, KC_EQL ,
    KC_LSFT, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,  KC_LALT ,                        KC_ENT , KC_LCBR,    KC_RCBR,    KC_LPRN,   KC_RPRN,   KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI , KC_LALT,  KANA,             KC_LSFT,   LOWER , KC_LSFT,        KC_LGUI,KC_LCTL , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR , KC_PERC ,_______,                       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, KC_VOLD, KC_VOLU,KC_MUTE, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};


#define SCROLL_THRESHOLD 20
bool        is_scrolling = false;
int         cnt_mouse_y  = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (is_scrolling) {
        cnt_mouse_y += mouse_report.y;
        int scrolling_y = 0;

        if (cnt_mouse_y > SCROLL_THRESHOLD) {
            scrolling_y = 1;
            cnt_mouse_y = 0;
        } else if (cnt_mouse_y < SCROLL_THRESHOLD * (-1)) {
            scrolling_y = -1;
            cnt_mouse_y = 0;
        }

      

        mouse_report.h = 0;
        mouse_report.v = scrolling_y * (-1);
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        is_scrolling=true;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        is_scrolling=false;
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
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
