#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define MOVE 3 // movement keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Grv   |   1  |   2  |   3  |   4  |   5  | ESC  |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L1  |           | [/{  |   Y  |   U  |   I  |   O  |   P  |  ]/}   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   L3   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '"   |
 * |--------+------+------+------+------+------| Hyper|           |  L1  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  '"  | \/|  | =/+  | LGui |                                       | Left | Down |  Up  | Right| LGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Backsp|Delete|------|       |------| Enter  |Space |
 *                                 |   ace|      | End  |       | LGui |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,    KC_1,         KC_2,      KC_3,   KC_4,     KC_5,   KC_ESC,
        KC_TAB,    KC_Q,         KC_W,      KC_E,   KC_R,     KC_T,   TG(SYMB),
        MO(MOVE),  KC_A,         KC_S,      KC_D,   KC_F,     KC_G,
        KC_LSFT,   CTL_T(KC_Z),  KC_X,      KC_C,   KC_V,     KC_B,   ALL_T(KC_NO),
        KC_LCTRL,  KC_QUOT,      KC_BSLASH, KC_EQUAL, KC_LGUI,
                                              ALT_T(KC_APP),    KC_LGUI,
                                                                KC_HOME,
                                              KC_BSPC,KC_DEL,   KC_END,
        // right hand
             KC_CAPS,     KC_6,   KC_7,    KC_8,    KC_9,   KC_0,             KC_MINS,
             KC_LBRACKET, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,             KC_RBRACKET,
                          KC_H,   KC_J,    KC_K,    KC_L,   LT(MDIA, KC_SCLN),KC_QUOTE,
             MO(SYMB),    KC_N,   KC_M,    KC_COMM, KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,         KC_LGUI,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_LGUI,KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,-----------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |           |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |        |   {  |   }  |   [  |   ]  |      |      |           |      |      |   7  |   8  |   9  |   *  | Volume Up |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|      |   4  |   (  |   )  |   +  | Volume Dn |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |   1  |   2  |   3  |   \  |   Mute    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______,
       _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
       _______, _______, _______, _______, _______,
                                        _______, _______,
                                                 _______,
                               _______, _______, _______,
       // right hand
       KC_F12,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  _______,
       _______, _______, KC_7,   KC_8,    KC_9,    KC_ASTR, KC_VOLU,
                _______, KC_4,   KC_LPRN, KC_RPRN, KC_PLUS, KC_VOLD,
       _______, _______, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_MUTE,
                         _______,KC_DOT,  KC_0,    KC_EQL,  _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       RESET  , _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),


/* Keymap 3: Movement keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left |  Up  | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOVEMENT KEYS
[MOVE] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______,  _______, _______,
       _______,  _______, _______, _______, _______,  _______, _______,
                 KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______,
       _______,  _______, _______, _______, _______,  _______, _______,
                          _______, _______, _______,  _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//   // MACRODOWN only works in this function
//   switch(id) {
//     case 0:
//       if (record->event.pressed) {
//         register_code(KC_RSFT);
//       } else {
//         unregister_code(KC_RSFT);
//       }
//       break;
//   }
//   return MACRO_NONE;
// };

bool left_shift = false;
bool right_shift = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed) {
    switch(keycode) {
      case KC_LSHIFT:
        left_shift = true;
        break;
      case KC_RSHIFT:
        right_shift = true;
        break;
    }
  }
  if (!record->event.pressed) {
    switch(keycode) {
      case KC_LSHIFT:
        left_shift = false;
        break;
      case KC_RSHIFT:
        right_shift = false;
        break;
    }
  }
  if (left_shift && right_shift) {
    SEND_STRING(SS_TAP(X_LOCKING_CAPS));
    left_shift = false;
    right_shift = false;
    return true;
  } else {
    return true;
  }
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
