#include "config.h"
#include QMK_KEYBOARD_H
#include "flirre.h"

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

    [_QWERTY] = LAYOUT( \
    CU_GRV,           KC_1,   CU_2,   KC_3,   CU_4,   KC_5,                                    CU_6,    CU_7,        CU_8,      CU_9,     CU_0,      CU_BSLS, \
    KC_ESC,           KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                    KC_Y,    KC_U,        KC_I,      KC_O,     KC_P,      KC_BSPC, \
    LCTL_T(KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                    KC_H,    KC_J,        KC_K,      KC_L,     CU_SCLN,   CU_QUOT, \
    CU_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_MUTE,             XXXXXXX,KC_N,    KC_M,        CU_COMM,   CU_DOT,   CU_SLSH,   CU_RSFT,\
                        KC_LGUI, KC_LALT, KC_LCTRL, KC_LOWER, KC_SPC,              KC_ENT, KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI
),

    [_MAC_QWERTY] = LAYOUT( \
    CA_GRV,           KC_1,   CU_2,   KC_3,   CU_4,   KC_5,                                    CU_6,    CU_7,        CU_8,      CU_9,     CU_0,      CA_BSLS, \
    KC_ESC,           KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                    KC_Y,    KC_U,        KC_I,      KC_O,     KC_P,      KC_BSPC, \
    LCTL_T(KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                    KC_H,    KC_J,        KC_K,      KC_L,     CU_SCLN,   CU_QUOT, \
    CU_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_MUTE,             XXXXXXX,KC_N,    KC_M,        CA_COMM,   CA_DOT,   CU_SLSH,   CU_RSFT,\
                        KC_LGUI, KC_LALT, KC_LCTRL, KC_MAC_LOWER, KC_SPC,              KC_ENT, KC_MAC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI
),


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
                      CU_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
                      _______, SE_EXLM, SE_AT, SE_HASH, SE_DLR, SE_PERC, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN, SE_RPRN, SE_PIPE,
                      _______, SE_EQL, SE_MINS, SE_PLUS, SE_LCBR, SE_RCBR, _______, _______, SE_LBRC, SE_RBRC, SE_SCLN, SE_COLN, SE_BSLS,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_MAC_LOWER] = LAYOUT(AE_ACUT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
                      CA_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
                      _______, AE_EXLM, AE_AT, AE_HASH, AE_DLR, AE_PERC, AE_CIRC, AE_AMPR, AE_ASTR, AE_LPRN, AE_RPRN, AE_PIPE,
                      _______, AE_EQL, AE_MINS, AE_PLUS, AE_LCBR, AE_RCBR, _______, _______, AE_LBRC, AE_RBRC, AE_SCLN, AE_COLN, AE_BSLS,
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
    [_RAISE] = LAYOUT(SE_ACUT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DLINE, KC_DEL,
                      _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, KC_PGUP, KC_PRVWD, KC_UP, KC_NXTWD, SE_ARNG, KC_BSPC,
                      _______, KC_LALT, KC_LCTL, CU_LSFT, XXXXXXX, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, SE_ODIA, SE_ADIA,
                      _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),


    [_MAC_RAISE] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DLINE, KC_DEL,
                      _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, KC_PGUP, KC_PRVWD, KC_UP, KC_NXTWD, AE_ARNG, KC_BSPC,
                      _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, AE_ODIA, AE_ADIA,
                      _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),





    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
     * |------+------+------+------+------+------|  MUTE |    | XX    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] =     LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       RESET, XXXXXXX, KC_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, OS_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),


    [_MAC_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       RESET, XXXXXXX, KC_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, OS_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};
/* END MACOS */
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
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _MAC_QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _MAC_RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _MAC_LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _MAC_ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n\n\n\n"), false);
    oled_write_ln_P(PSTR("SHIFT"), lshift || rshift);
    // led_t led_usb_state = host_keyboard_led_state();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (get_highest_layer(layer_state) == _LOWER) {
            if (clockwise) {
                tap_code(KC_F18);
                tap_code(KC_R);
            } else {
                tap_code(KC_F18);
                tap_code(KC_U);
            }
        } else {
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
    }
    return true;
}

#endif
