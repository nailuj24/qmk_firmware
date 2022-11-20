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

// Layers
#define _BASE_MACOS 0
#define _BASE_WINDOWS 1
#define _GAMES 2
#define _FN 3
#define _KEY_EMU 4
#define _WIN_SPCL 5
#define _MORPH 6

// QMK can only send basic keycodes via Mod-Tap, hijack some
#define JK_MSHF KC_F22
#define JK_WSHL KC_F23
#define JK_WSHR KC_F24

enum custom_keycodes {
  MACOS = SAFE_RANGE,
  WINDOWS,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE_MACOS] = LAYOUT_60_iso( /* Base - macOS ISO */
    KC_ESC,          KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
    KC_TAB,          KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,
    KC_LCTL,         KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS, KC_ENT,
    LSFT_T(JK_MSHF), KC_NUBS,  KC_Z,     KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,           RSFT_T(JK_MSHF),
    MO(_KEY_EMU),    KC_LALT,  KC_LGUI,                       KC_SPC,                          KC_RGUI,  KC_RALT,  MO(_FN), KC_RCTL),

[_BASE_WINDOWS] = LAYOUT_60_iso( /* Base - Windows ISO */
    KC_ESC,          KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,     KC_0,     KC_MINS,       KC_EQL,  KC_BSPC,
    KC_TAB,          KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,     KC_LBRC,       KC_RBRC,
    KC_LCTL,         KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,  KC_QUOT,       KC_NUHS, KC_ENT,
    LSFT_T(JK_WSHL), KC_NUBS,  KC_Z,     KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,                RSFT_T(JK_WSHR),
    MO(_KEY_EMU),    KC_LGUI,  KC_LALT,                       KC_SPC,                          KC_LALT,  LT(_WIN_SPCL, KC_RGUI), MO(_FN), KC_RCTL),

[_GAMES] = LAYOUT_60_iso( /* Disable features that are annoying in Games */
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,            KC_RSFT,
    KC_LCTL,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                MO(_KEY_EMU), KC_TRNS,  KC_TRNS,  KC_TRNS),

[_FN] = LAYOUT_60_iso( /* Keyboard Functions - Fn */
    KC_MUTE, KC_VOLD,  KC_VOLU,  DM_REC1,  DM_PLY1,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,
    KC_TRNS, KC_TRNS,  WINDOWS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,
    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TG(_GAMES), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
    KC_TRNS, EF_DEC,   EF_INC,   KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  MACOS,    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_MNXT,
    KC_TRNS, KC_TRNS,  KC_TRNS,                                  KC_TRNS,                                KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS),

[_KEY_EMU] = LAYOUT_60_iso( /* Key Emulation - Fn2 */
    KC_GRV,       KC_F1,     KC_F2,      KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
    LCTL(KC_TAB), KC_TRNS,   KC_TRNS,    KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,      KC_HOME,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_INS,
    KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_UP,
    KC_TRNS,      KC_TRNS,   MO(_MORPH),                               KC_TRNS,                                KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT),

[_WIN_SPCL] = LAYOUT_60_iso( /* Special Character Input for Windows - Mimic OSX - Fn3 */
    KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  RALT(KC_8), RALT(KC_9),  RALT(KC_NUBS),  RALT(KC_7)/*8*/, RALT(KC_0), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,             KC_TRNS,  KC_TRNS,  RALT(KC_E), KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,         KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,        KC_TRNS,         RALT(KC_Q), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    LT(_MORPH, JK_WSHL), KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,     RALT(KC_RBRC),  KC_TRNS,         KC_TRNS,    KC_TRNS,  KC_TRNS,            LT(_MORPH, JK_WSHR),
    KC_TRNS,             KC_TRNS,  KC_TRNS,                                    KC_TRNS,                                                  KC_RALT,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[_MORPH] = LAYOUT_60_iso( /* QMK does not have Mod-Morph, emulate with a layer */
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RALT(KC_MINS),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  LCA(KC_DEL),
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,                                KC_TRNS,                                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
  case KC_A ... KC_Z:
  case KC_SLSH:
    add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
    return true;

    // Keycodes that continue Caps Word, without shifting.
  case KC_1 ... KC_0:
  case KC_BSPC:
  case KC_DEL:
  case S(KC_SLSH):
    return true;

  default:
    return false;  // Deactivate Caps Word.
  }
}

uint8_t _mods;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  _mods = get_mods();
  switch(keycode) {
    // OS support
  case MACOS:
    if (record->event.pressed)
      set_single_persistent_default_layer(_BASE_MACOS);
    return false;
  case WINDOWS:
    if (record->event.pressed)
      set_single_persistent_default_layer(_BASE_WINDOWS);
    return false;
    // Mac Shift Braces Tap
  case LSFT_T(JK_MSHF):
    if (record->tap.count && record->event.pressed) {
      clear_mods();
      if (_mods & MOD_MASK_CTRL)
        tap_code16(RALT(KC_8));
      else if (_mods & MOD_BIT(KC_RALT))
        tap_code16(RALT(KC_5));
      else
        tap_code16(S(KC_8));
      set_mods(_mods);
      return false;
    }
    break;
  case RSFT_T(JK_MSHF):
    if (record->tap.count && record->event.pressed) {
      if (_mods & MOD_MASK_SHIFT)
        process_record_user(LSFT_T(JK_MSHF), record);
      clear_mods();
      if (_mods & MOD_MASK_CTRL)
        tap_code16(RALT(KC_9));
      else if (_mods & MOD_BIT(KC_RALT))
        tap_code16(RALT(KC_6));
      else
        tap_code16(S(KC_9));
      set_mods(_mods);
      return false;
    }
    break;
    // Windows Shift Braces Tap
  case LSFT_T(JK_WSHL):
    if (record->tap.count && record->event.pressed) {
      clear_mods();
      if (_mods & MOD_MASK_CTRL)
        tap_code16(RALT(KC_7));
      else
        tap_code16(S(KC_8));
      set_mods(_mods);
      return false;
    }
    break;
  case LT(_MORPH, JK_WSHL):
    // HOLD_ON_OTHER_KEY_PRESS does not apply to LT(), so check for interrupt manually
    if ((record->tap.interrupted) || (record->tap.count && record->event.pressed)) {
      clear_mods();
      tap_code16(RALT(KC_8));
      set_mods(_mods);
      return false;
    }
    break;
  case RSFT_T(JK_WSHR):
    if (record->tap.count && record->event.pressed) {
      if (_mods & MOD_MASK_SHIFT)
        process_record_user(LSFT_T(JK_WSHL), record);
      clear_mods();
      if (_mods & MOD_MASK_CTRL)
        tap_code16(RALT(KC_0));
      else
        tap_code16(S(KC_9));
      set_mods(_mods);
      return false;
    }
    break;
  case LT(_MORPH, JK_WSHR):
    if (record->tap.count && record->event.pressed) {
      if (IS_LAYER_ON(_MORPH))
        process_record_user(LT(_MORPH, JK_WSHL), record);
      clear_mods();
      tap_code16(RALT(KC_9));
      set_mods(_mods);
      return false;
    }
    break;
    // add modifiers to arrows if morphing
  case KC_UP:
  case KC_DOWN:
  case KC_LEFT:
  case KC_RIGHT:
    if (IS_LAYER_ON(_MORPH) && IS_LAYER_ON(_KEY_EMU)) {
      if (IS_LAYER_ON_STATE(default_layer_state, _BASE_MACOS)) {
        if (record->event.pressed)
          register_code16(G(keycode));
        else
          unregister_code16(G(keycode));
      } else {
        if (record->event.pressed)
          register_code16(A(keycode));
        else
          unregister_code16(A(keycode));
      }
      return false;
    }
    break;
  }
  return true;
}
