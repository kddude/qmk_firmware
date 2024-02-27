/* Copyright 2023 Moritz Plattner
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

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

//ALT TAB Encoder Timer
void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* base layer - ctrl escape */
    [0] = LAYOUT_all(
        C_MPLY,         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,        KC_EQL,  KC_BSPC, KC_TRNS, KC_HOME,
                        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,        KC_RBRC, KC_BSLS,          KC_PGUP,
                        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_NUHS, KC_ENT,  KC_ENT,  KC_PGDN,
                        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,        KC_RSFT, KC_UP,            MO(2),
                        MT(MOD_LCTL,KC_ESC), KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,  KC_SPC,        KC_RALT, KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* 2nd layer - escape escape */
    [1] = LAYOUT_all(
        C_MPLY, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,        KC_EQL,  KC_BSPC, KC_TRNS, KC_HOME,
                        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,        KC_RBRC, KC_BSLS,          KC_PGUP,
                        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_NUHS, KC_ENT,  KC_ENT,  KC_PGDN,
                        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,        KC_RSFT, KC_UP,            MO(3),
                        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,           KC_RALT, KC_MPLY,        KC_MPRV, KC_DOWN, KC_MNXT
    ),
    /* transition to escpescp layer */
    [2] = LAYOUT_all(
        KC_MPLY,        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS, KC_DEL,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_ON,   NK_OFF,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(1),            TT(0),
                        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          MO(2),   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
    ),
    /* transition to base layer */
    [3] = LAYOUT_all(
        KC_MPLY,        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS, KC_DEL,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_ON,   NK_OFF,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),            TT(0),
                        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS  KC_MPLY,          KC_MPRV, KC_DOWN, KC_MNXT
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    register_code(KC_LALT);
    is_alt_tab_active = true;
    if (clockwise) {            
        tap_code(KC_TAB);
    } else {
        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT); // this fixes the getting stuck problem
    }
    alt_tab_timer = timer_read();
    return false;
};        

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//     [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [1] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
//     [2] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
// };
// #endif