#include "flirre.h"

/*
Copyright 2021 Jakob Hærvig <jakob.haervig@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// These indicate if left and right shift are physically pressed
bool lshift = false;
bool rshift = false;

// Interrupt and times for space cadet shift
bool     lshiftp      = false;
bool     rshiftp      = false;
uint16_t lshift_timer = 0;
uint16_t rshift_timer = 0;

// Number of items that are saved in prev_kcs
uint8_t prev_indx = 0;
// Used to save the last 6 actual keycodes activated by frankenkeycodes
uint16_t prev_kcs[6] = {0, 0, 0, 0, 0, 0};

// If true the deadkey characters grave and circonflexe are not automatically escaped
bool esct = false;

/*
Used to add a keycode to a prev_kcs to remember it.
When full the last code gets discarded and replaced by
the new one.
*/
void add_to_prev(uint16_t kc) {
    for (int i = 0; i < prev_indx; i++) {
        if (kc == prev_kcs[i]) return;
    }
    if (prev_indx == 6) {
        for (int i = 5; i > 0; i--) {
            prev_kcs[i] = prev_kcs[i - 1];
        }
        prev_kcs[0] = kc;
    } else {
        prev_kcs[prev_indx] = kc;
        prev_indx++;
    }
}

/*
Unregisters all codes saved in prev_kcs and resets prev_indx.
gets called on multiple occasions mainly when shift is released
and when frankenkeycodes are pressed. Prevents output of
wrong characters when really specific key combinations
that would never occur during normal usage are pressed.
*/
void unreg_prev(void) {
    if (prev_indx == 0) return;
    for (int i = 0; i < prev_indx; i++) {
        unregister_code(prev_kcs[i]);
    }
    prev_indx = 0;
}

// Interrupt and times for Nav/Esc
bool     navesc       = false;
uint16_t navesc_timer = 0;

// Interrupts all timers
void timer_timeout(void) {
    lshiftp = false;
    rshiftp = false;
    navesc  = false;
    timer_timeout_keymap();
}

__attribute__((weak)) void timer_timeout_keymap(void) {}

void toggle_osx_mode(void) {
    keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
    keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;

    if (!keymap_config.swap_lctl_lgui) {
        layer_on(_QWERTY);
        layer_off(_MAC_QWERTY);
        default_layer_set(_QWERTY);
    } else {
        layer_on(_MAC_QWERTY);
        layer_off(_QWERTY);
        default_layer_set(_MAC_QWERTY);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_MAC_LOWER:
            if (record->event.pressed) {
                layer_on(_MAC_LOWER);
                update_tri_layer(_MAC_LOWER, _MAC_RAISE, _MAC_ADJUST);
            } else {
                layer_off(_MAC_LOWER);
                update_tri_layer(_MAC_LOWER, _MAC_RAISE, _MAC_ADJUST);
            }
            return false;
        case KC_MAC_RAISE:
            if (record->event.pressed) {
                layer_on(_MAC_RAISE);
                update_tri_layer(_MAC_LOWER, _MAC_RAISE, _MAC_ADJUST);
            } else {
                layer_off(_MAC_RAISE);
                update_tri_layer(_MAC_LOWER, _MAC_RAISE, _MAC_ADJUST);
            }
            return false;
        case KC_MAC_ADJUST:
            if (record->event.pressed) {
                layer_on(_MAC_ADJUST);
            } else {
                layer_off(_MAC_ADJUST);
            }
            return false;
        case OS_TOGG:
            if (record->event.pressed) {
                toggle_osx_mode();
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
            break;
        case KC_LGUI:
        case KC_RGUI:
            if (record->event.pressed) timer_timeout();
            return true;
        case CU_LSFT:
            if (record->event.pressed) {
                lshiftp      = true;
                lshift_timer = timer_read();
                unregister_code(KC_LSFT);
                register_code(KC_LSFT);
                lshift = true;
            } else {
                if (timer_elapsed(lshift_timer) < TAPPING_TERM && lshiftp) {
                    register_code(KC_LSFT);
                    unregister_code(KC_LSFT);
                }
                unreg_prev();
                if (!rshift) unregister_code(KC_LSFT);
                lshift = false;
            }
            return false;
        case CU_RSFT:
            if (record->event.pressed) {
                rshiftp      = true;
                rshift_timer = timer_read();
                unregister_code(KC_LSFT);
                register_code(KC_LSFT);
                rshift = true;
            } else {
                if (timer_elapsed(rshift_timer) < TAPPING_TERM && rshiftp) {
                    register_code(KC_LSFT);
                    unregister_code(KC_LSFT);
                }
                unreg_prev();
                if (!lshift) unregister_code(KC_LSFT);
                rshift = false;
            }
            return false;
        case CU_GRV:
            DEAD_NORM_ALGR(SE_GRV, SE_DIAE);
        case CU_COMM:
            SHIFT_NO(SE_COMM, SE_LABK)
        case CU_DOT:
            SHIFT_NORM(SE_DOT, SE_LABK)
        case CU_SLSH:
            SHIFT_ALL(SE_7, KC_MINS)
        case CU_SCLN:
            SHIFT_ALL(SE_COMM, SE_DOT)
        case CU_QUOT:
            SHIFT_NORM(SE_QUOT, SE_2)
        case CU_2:
            NORM_ALGR(SE_2, SE_2)
        case CU_4:
            NORM_ALGR(SE_4, SE_4);
        case CU_6:
            SHIFT_NORM(SE_6, KC_RBRC)
        case CU_7:
            SHIFT_NORM(SE_7, SE_6)
        case CU_8:
            SHIFT_NORM(SE_8, KC_NUHS)
        case CU_9:
            SHIFT_NORM(SE_9, SE_8)
        case CU_0:
            SHIFT_NORM(SE_0, SE_9)
        case CU_MINS:
            SHIFT_NORM(KC_SLSH, KC_SLSH)
        case CU_EQL:
            SHIFT_SWITCH(SE_0, SE_PLUS)
        case CU_BSPC:
            SHIFT_NO(KC_BSPC, KC_DEL)
        case CU_LBRC:
            NORM_ALGRSHIFT(SE_8, SE_8)
        case CU_RBRC:
            NORM_ALGRSHIFT(SE_9, SE_9)
        case CU_BSLS:
            SHIFT_ALGR(SE_PLUS, SE_LABK)
        case CA_BSLS:
            if (record->event.pressed) {
                timer_timeout();
                if (lshift || rshift) {
                    register_code(KC_LSFT);
                    register_code(KC_ALGR);
                    unregister_code(AE_7);
                    tap_code(AE_7);
                    unregister_code(AE_7);
                } else {
                    register_code(KC_ALGR);
                    unregister_code(AE_7);
                    tap_code(AE_7);
                }
                unregister_code(KC_ALGR);
                unregister_code(KC_LSFT);
            }
            return false;
        case CA_COMM:
            SHIFT_NO(AE_COMM, AE_LABK);
        case CA_DOT:
            SHIFT_NORM(AE_DOT, AE_LABK);
        case CA_GRV:
            DEAD_NORM_ALGR(AE_GRV, AE_DIAE);
        case KC_LCTL:
        case KC_RCTL:
            if (!record->event.pressed) {
                timer_timeout();
                unregister_code(KC_Z);
                unregister_code(KC_Y);
            }
            return true;

        default:
            if (record->event.pressed) {
                timer_timeout();

                if (lshift || rshift)
                    register_code(KC_LSFT);
                else
                    unregister_code(KC_LSFT);
            }
            return process_record_keymap(keycode, record);
    }
    return false;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
