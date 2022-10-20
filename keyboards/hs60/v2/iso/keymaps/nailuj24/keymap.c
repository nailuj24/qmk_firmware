/* Copyright 2018 Yiancar
 * Copyright 2022 Julian Aloofi
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
#include QMK_KEYBOARD_H

#include "keyboards/wilba_tech/wt_rgb_backlight.h"

// LAYERS
#define _BASE_MACOS 0
#define _BASE_WINDOWS 1
#define _FN 2
#define _KEY_EMU 3
#define _WIN_SPCL 4

enum custom_keycodes {
  MACOS = SAFE_RANGE,
  WINDOWS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE_MACOS] = LAYOUT_60_iso( /* Base - macOS ISO */
    KC_ESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
    KC_TAB,       KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,
    KC_LCTL,      KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS, KC_ENT,
    KC_LSFT,      KC_NUBS,  KC_Z,     KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,
    TT(_KEY_EMU), KC_LALT,  KC_LGUI,                       KC_SPC,                          DM_PLY1,  KC_RALT,  MO(_FN), KC_RCTL),

[_BASE_WINDOWS] = LAYOUT_60_iso( /* Base - Windows ISO */
    KC_ESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,     KC_0,     KC_MINS,       KC_EQL,  KC_BSPC,
    KC_TAB,       KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,     KC_LBRC,       KC_RBRC,
    KC_LCTL,      KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,  KC_QUOT,       KC_NUHS, KC_ENT,
    KC_LSFT,      KC_NUBS,  KC_Z,     KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,                KC_RSFT,
    TT(_KEY_EMU), KC_LGUI,  KC_LALT,                       KC_SPC,                          DM_PLY1,  MO(_WIN_SPCL), MO(_FN), KC_RCTL),

[_FN] = LAYOUT_60_iso( /* Keyboard Functions - Fn */
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,
    KC_TRNS,  KC_TRNS,  WINDOWS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
    KC_TRNS,  EF_DEC,   EF_INC,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MACOS,    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_MNXT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[_KEY_EMU] = LAYOUT_60_iso( /* Key Emulation - Fn2 */
    KC_GRV,       KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
    LCTL(KC_TAB), KC_TRNS,  KC_TRNS,  KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,
    KC_TRNS,      KC_HOME,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_INS,
    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,      KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[_WIN_SPCL] = LAYOUT_60_iso( /* Special Character Input for Windows - Mimic OSX - Fn3 */
    KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  RALT(KC_8), RALT(KC_9),  RALT(KC_NUBS),  RALT(KC_7), RALT(KC_0), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,           KC_TRNS,  KC_TRNS,  RALT(KC_E), KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,    RALT(KC_Q), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,     RALT(KC_RBRC),  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,           KC_TRNS,  KC_TRNS,                                    KC_TRNS,                                             KC_RALT,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case MACOS:
    if (record->event.pressed)
      set_single_persistent_default_layer(_BASE_MACOS);
    return false;
  case WINDOWS:
    if (record->event.pressed)
      set_single_persistent_default_layer(_BASE_WINDOWS);
    return false;
  }
  return true;
}
