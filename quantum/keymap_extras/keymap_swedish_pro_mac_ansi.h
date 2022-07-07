/* Copyright 2021
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

#pragma once

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ < │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ + │ ´ │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ Å │ ¨ │ ' │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ö │ Ä │      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤
 * │        │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ - │        │
 * ├─────┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define AE_LABK KC_GRV  // <
#define AE_1    KC_1    // 1
#define AE_2    KC_2    // 2
#define AE_3    KC_3    // 3
#define AE_4    KC_4    // 4
#define AE_5    KC_5    // 5
#define AE_6    KC_6    // 6
#define AE_7    KC_7    // 7
#define AE_8    KC_8    // 8
#define AE_9    KC_9    // 9
#define AE_0    KC_0    // 0
#define AE_PLUS KC_MINS // +
#define AE_ACUT KC_EQL  // ´ (dead)
// Row 2
#define AE_Q    KC_Q    // Q
#define AE_W    KC_W    // W
#define AE_E    KC_E    // E
#define AE_R    KC_R    // R
#define AE_T    KC_T    // T
#define AE_Y    KC_Y    // Y
#define AE_U    KC_U    // U
#define AE_I    KC_I    // I
#define AE_O    KC_O    // O
#define AE_P    KC_P    // P
#define AE_ARNG KC_LBRC // Å
#define AE_DIAE KC_RBRC // ¨ (dead)
#define AE_QUOT KC_NUHS // '
// Row 3
#define AE_A    KC_A    // A
#define AE_S    KC_S    // S
#define AE_D    KC_D    // D
#define AE_F    KC_F    // F
#define AE_G    KC_G    // G
#define AE_H    KC_H    // H
#define AE_J    KC_J    // J
#define AE_K    KC_K    // K
#define AE_L    KC_L    // L
#define AE_ODIA KC_SCLN // Ö
#define AE_ADIA KC_QUOT // Ä
// Row 4
#define AE_Z    KC_Z    // Z
#define AE_X    KC_X    // X
#define AE_C    KC_C    // C
#define AE_V    KC_V    // V
#define AE_B    KC_B    // B
#define AE_N    KC_N    // N
#define AE_M    KC_M    // M
#define AE_COMM KC_COMM // ,
#define AE_DOT  KC_DOT  // .
#define AE_MINS KC_SLSH // -

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ > │ ! │ " │ # │ € │ % │ & │ / │ ( │ ) │ = │ ? │ ` │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │ ^ │ * │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤
 * │        │   │   │   │   │   │   │   │ ; │ : │ _ │        │
 * ├─────┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#define AE_RABK S(AE_LABK) // >
#define AE_EXLM S(AE_1)    // !
#define AE_DQUO S(AE_2)    // "
#define AE_HASH S(AE_3)    // #
#define AE_EURO S(AE_4)    // €
#define AE_PERC S(AE_5)    // %
#define AE_AMPR S(AE_6)    // &
#define AE_SLSH S(AE_7)    // /
#define AE_LPRN S(AE_8)    // (
#define AE_RPRN S(AE_9)    // )
#define AE_EQL  S(AE_0)    // =
#define AE_QUES S(AE_PLUS) // ?
#define AE_GRV  S(AE_ACUT) // `
// Row 2
#define AE_CIRC S(AE_DIAE) // ^ (dead)
#define AE_ASTR S(AE_QUOT) // *
// Row 4
#define AE_SCLN S(AE_COMM) // ;
#define AE_COLN S(AE_DOT)  // :
#define AE_UNDS S(AE_MINS) // _

/* Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ ≤ │ © │ @ │ £ │ $ │ ∞ │ § │ | │ [ │ ] │ ≈ │ ± │   │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ • │ Ω │ É │ ® │ † │ µ │ Ü │ ı │ Œ │ π │ ˙ │ ~ │ ™ │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │      │  │ ß │ ∂ │ ƒ │ ¸ │ ˛ │ √ │ ª │ ﬁ │ Ø │ Æ │      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤
 * │        │ ÷ │   │ Ç │ ‹ │ › │ ‘ │ ’ │ ‚ │ … │ – │        │
 * ├─────┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 * 
 */
// Row 1 
#define AE_LTEQ A(AE_LABK) // ≤
#define AE_COPY A(AE_1)    // ©
#define AE_AT   A(AE_2)    // @
#define AE_PND  A(AE_3)    // £
#define AE_DLR  A(AE_4)    // $
#define AE_INFN A(AE_5)    // ∞
#define AE_SECT A(AE_6)    // §
#define AE_PIPE A(AE_7)    // |
#define AE_LBRC A(AE_8)    // [
#define AE_RBRC A(AE_9)    // ]
#define AE_AEQL A(AE_0)    // ≈
#define AE_PLMN A(AE_PLUS) // ±
// Row 2
#define AE_BULT A(AE_Q)    // •
#define AE_OMEG A(AE_W)    // Ω
#define AE_EACU A(AE_E)    // É
#define AE_REGD A(AE_R)    // ®
#define AE_DAGG A(AE_T)    // †
#define AE_MICR A(AE_Y)    // µ
#define AE_UDIA A(AE_U)    // Ü
#define AE_DLSI A(AE_I)    // ı
#define AE_OE   A(AE_O)    // Œ
#define AE_PI   A(AE_P)    // π
#define AE_DOTA A(AE_ARNG) // ˙
#define AE_TILD A(AE_DIAE) // ~ (dead)
#define AE_TM   A(AE_QUOT) // ™
// Row 3
#define AE_APPL A(AE_A)    //  (Apple logo)
#define AE_SS   A(AE_S)    // ß
#define AE_PDIF A(AE_D)    // ∂
#define AE_FHK  A(AE_F)    // ƒ
#define AE_CEDL A(AE_G)    // ¸
#define AE_OGON A(AE_H)    // ˛
#define AE_SQRT A(AE_J)    // √
#define AE_FORD A(AE_K)    // ª
#define AE_FI   A(AE_L)    // ﬁ
#define AE_OSTR A(AE_ODIA) // Ø
#define AE_AE   A(AE_ADIA) // Æ
// Row 4
#define AE_DIV  A(AE_Z)    // ÷
#define AE_CCED A(AE_C)    // Ç
#define AE_LSAQ A(AE_V)    // ‹
#define AE_RSAQ A(AE_B)    // ›
#define AE_LSQU A(AE_N)    // ‘
#define AE_RSQU A(AE_M)    // ’
#define AE_SLQU A(AE_COMM) // ‚
#define AE_ELLP A(AE_DOT)  // …
#define AE_NDSH A(AE_MINS) // –

/* Shift+Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ ≥ │ ¡ │   │ ¥ │ ¢ │ ‰ │ ¶ │ \ │ { │ } │ ≠ │ ¿ │   │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ ° │ ˝ │   │   │ ‡ │ ˜ │   │ ˆ │   │ ∏ │ ˚ │   │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │      │ ◊ │ ∑ │ ∆ │ ∫ │ ¯ │ ˘ │ ¬ │ º │ ﬂ │   │   │      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤
 * │        │ ⁄ │ ˇ │   │ « │ » │ “ │ ” │ „ │ · │ — │        │
 * ├─────┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 * 
 */
// Row 1
#define AE_GTEQ S(A(AE_LABK)) // ≥
#define AE_IEXL S(A(AE_1))    // ¡
#define AE_YEN  S(A(AE_3))    // ¥
#define AE_CENT S(A(AE_4))    // ¢
#define AE_PERM S(A(AE_5))    // ‰
#define AE_PILC S(A(AE_6))    // ¶
#define AE_BSLS S(A(AE_7))    // (backslash)
#define AE_LCBR S(A(AE_8))    // {
#define AE_RCBR S(A(AE_9))    // }
#define AE_NEQL S(A(AE_0))    // ≠
#define AE_IQUE S(A(AE_PLUS)) // ¿
// Row 2
#define AE_DEG  S(A(AE_Q))    // °
#define AE_DACU S(A(AE_W))    // ˝
#define AE_DDAG S(A(AE_T))    // ‡
#define AE_STIL S(A(AE_Y))    // ˜
#define AE_DCIR S(A(AE_I))    // ˆ
#define AE_NARP S(A(AE_P))    // ∏
#define AE_RNGA S(A(AE_ARNG)) // ˚
// Row 3
#define AE_LOZN S(A(AE_A))    // ◊
#define AE_NARS S(A(AE_S))    // ∑
#define AE_INCR S(A(AE_D))    // ∆
#define AE_INTG S(A(AE_F))    // ∫
#define AE_MACR S(A(AE_G))    // ¯
#define AE_BREV S(A(AE_H))    // ˘
#define AE_NOT  S(A(AE_J))    // ¬
#define AE_MORD S(A(AE_K))    // º
#define AE_FL   S(A(AE_L))    // ﬂ
// Row 4
#define AE_FRSL S(A(AE_Z))    // ⁄
#define AE_CARN S(A(AE_X))    // ˇ
#define AE_LDAQ S(A(AE_V))    // «
#define AE_RDAQ S(A(AE_B))    // »
#define AE_LDQU S(A(AE_N))    // “
#define AE_RDQU S(A(AE_M))    // ”
#define AE_DLQU S(A(AE_COMM)) // „
#define AE_MDDT S(A(AE_DOT))  // ·
#define AE_MDSH S(A(AE_MINS)) // —
