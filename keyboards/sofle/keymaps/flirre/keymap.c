#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum sofle_layers {
    _QWERTY,
   _SHIFTED,
    _LOWER,
    _LOWERSHIFT,
    _RAISE,
    _RAISESHIFT,
    _ADJUST,
};

enum custom_keycodes { KC_QWERTY = SAFE_RANGE, KC_LOWER, KC_RAISE, KC_ADJUST, KC_SHIFT, KC_PRVWD, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /SPACE  /       \ ENTER\  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_QWERTY] = LAYOUT(SE_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, SE_BSLS,
                       KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
                       LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SE_SCLN, SE_QUOT,
                       KC_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, SE_COMM, SE_DOT, SE_SLSH, KC_SHIFT,
                       KC_LGUI, KC_LALT, KC_LCTRL, KC_LOWER, KC_SPC, KC_ENT, KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI),

    /*
     * Shifted
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  |   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   :  |  "   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   <  |   >  |   ?  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /SPACE  /       \ ENTER\  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_SHIFTED] = LAYOUT(SE_TILD, SE_EXLM, SE_AT, SE_HASH, SE_DLR, SE_PERC, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN, SE_RPRN, SE_PIPE,
                       KC_ESC, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), KC_BSPC,
                       LCTL_T(KC_TAB), S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), SE_COLN, SE_DQUO,
                       KC_SHIFT, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), KC_MUTE, XXXXXXX, S(KC_N), S(KC_M), SE_LABK, SE_RABK, SE_QUES, KC_SHIFT,
                       KC_LGUI, KC_LALT, KC_LCTRL, KC_LOWER, KC_SPC, KC_ENT, KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI),


    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ´   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |WRK_SPC|------+------+------+------+------+------|
     * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /SPACE  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(SE_ACUT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                      SE_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
                      _______, SE_EXLM, SE_AT, SE_HASH, SE_DLR, SE_PERC, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN, SE_RPRN, SE_PIPE,
                      _______, SE_EQL, SE_MINS, SE_PLUS, SE_LCBR, SE_RCBR, _______, _______, SE_LBRC, SE_RBRC, SE_SCLN, SE_COLN, SE_BSLS,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* LOWER Shifted
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ´    |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |WRK_SPC|------+------+------+------+------+------|
     * | Shift|  =   |  _  |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /SPACE  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWERSHIFT] = LAYOUT(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                      SE_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
                      _______, SE_EXLM, SE_AT, SE_HASH, SE_DLR, SE_PERC, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN, SE_RPRN, SE_PIPE,
                      _______, SE_EQL, SE_UNDS, SE_PLUS, SE_LCBR, SE_RCBR, _______, _______, SE_LBRC, SE_RBRC, SE_SCLN, SE_COLN, SE_BSLS,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),


    /* RAISE
     * ,----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      | DLine| Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd |   å  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Right|   ö  | ä    |
     * |------+------+------+------+------+------|  MUTE  |    |      |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /SPACE  /       \ENTER \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DLINE, KC_DEL,
                      _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, KC_PGUP, KC_PRVWD, KC_UP, KC_NXTWD, SE_ARNG, KC_BSPC,
                      _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, SE_ODIA, SE_ADIA,
                      _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* RAISE Shifted
     * ,----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      | DLine| Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd |   Å  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Right|   Ö  | Ä    |
     * |------+------+------+------+------+------|  MUTE  |    |      |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /SPACE  /       \ENTER \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISESHIFT] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DLINE, KC_DEL,
                      _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, KC_PGUP, KC_PRVWD, KC_UP, KC_NXTWD, S(SE_ARNG), KC_BSPC,
                      _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, S(SE_ODIA), S(SE_ADIA),
                      _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       RESET, XXXXXXX, KC_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};
// clang-format on
#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MacOS"), false);
    } else {
        oled_write_ln_P(PSTR("Linux"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _SHIFTED:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
        case _RAISESHIFT:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
        case _LOWERSHIFT:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n\n\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _RAISE:
        case _LOWER:
        case _ADJUST:
            oled_write_ln_P(PSTR("SHIFT"), false);
            break;
        case _SHIFTED:
        case _RAISESHIFT:
        case _LOWERSHIFT:
        default:
            oled_write_ln_P(PSTR("SHIFT"), true);
    }
    //led_t led_usb_state = host_keyboard_led_state();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif


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
                update_tri_layer(_LOWER, _SHIFTED, _LOWERSHIFT);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                update_tri_layer(_LOWER, _SHIFTED, _LOWERSHIFT);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                update_tri_layer(_RAISE, _SHIFTED, _RAISESHIFT);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_SHIFT:
            if (record->event.pressed) {
                layer_on(_SHIFTED);
                update_tri_layer(_SHIFTED, _LOWER, _LOWERSHIFT);
                update_tri_layer(_SHIFTED, _RAISE, _RAISESHIFT);
            } else {
                layer_off(_SHIFTED);
                update_tri_layer(_SHIFTED, _LOWER, _LOWERSHIFT);
                update_tri_layer(_SHIFTED, _RAISE, _RAISESHIFT);
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
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            register_mods(mod_config(MOD_LCTL));
            register_mods(mod_config(MOD_LGUI));
            register_code(KC_UP);
            unregister_mods(mod_config(MOD_LCTL));
            unregister_mods(mod_config(MOD_LGUI));
            unregister_code(KC_UP);
        } else {
            register_mods(mod_config(MOD_LCTL));
            register_mods(mod_config(MOD_LGUI));
            register_code(KC_DOWN);
            unregister_mods(mod_config(MOD_LCTL));
            unregister_mods(mod_config(MOD_LGUI));
            unregister_code(KC_DOWN);
        }
    }
    return true;
}

#endif
