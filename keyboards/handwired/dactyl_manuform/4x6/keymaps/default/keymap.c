#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _WINDOWS_QWERTY,
    _COLEMAK_DH,
    _GAMING_QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+      +------+                             +------+      +-------------+
 *                                    |      |                             |      |
 *                                    +------+-------------+ +-------------+------+
 *                                           |      |      | |      |      |
 *                                           |------+------| |------+------|
 *                                           |      |      | |      |      |
 *                                           +-------------+ +-------------+
 */

[_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLASH, \
    KC_LSFT, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    KC_LCTL, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_MINS,   \
                    KC_LCBR,KC_LPRN,                                                  KC_RPRN,KC_RCBR,                   \
                                                                                                                         \
                            KC_LALT,                                                  KC_RSHIFT,                           \
                            KC_LGUI,LT(_LOWER, KC_BSPACE),         LT(_RAISE, KC_ENT),KC_SPC,                            \
                            KC_HOME,LT(_RAISE, KC_DELETE),         LT(_LOWER, KC_TAB),KC_END                             \
),

[_WINDOWS_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLASH, \
    KC_LSFT, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    KC_LGUI, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_MINS,   \
                    KC_LCBR,KC_LPRN,                                                  KC_RPRN,KC_RCBR,                   \
                                                                                                                         \
                            KC_LALT,                                                  KC_RSHIFT,                           \
                            KC_LCTL,LT(_LOWER, KC_BSPACE),         LT(_RAISE, KC_ENT),KC_SPC,                            \
                            KC_HOME,LT(_RAISE, KC_DELETE),         LT(_LOWER, KC_TAB),KC_END                             \
),

[_COLEMAK_DH] = LAYOUT( \
    KC_ESC,  KC_Q,  KC_W,   KC_F,   KC_P,   KC_B,                     KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSLASH, \
    KC_LSFT, KC_A,  KC_R,   KC_S,   KC_T,   KC_G,                     KC_M,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,   \
    KC_LCTL, KC_X,  KC_C,   KC_D,   KC_V,   KC_Z,                     KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,KC_MINS,   \
                    KC_LCBR,KC_LPRN,                                                  KC_RPRN,KC_RCBR,                   \
                                                                                                                         \
                            KC_LALT,                                                  KC_RSHIFT,                           \
                            KC_LGUI,LT(_LOWER, KC_BSPACE),         LT(_RAISE, KC_ENT),KC_SPC,                            \
                            KC_HOME,LT(_RAISE, KC_DELETE),         LT(_LOWER, KC_TAB),KC_END                             \
),

[_GAMING_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLASH, \
    KC_LSFT, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    KC_LCTL, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_MINS,   \
                    KC_LCBR,KC_LPRN,                                                  KC_RPRN,KC_RCBR,                   \
                                                                                                                         \
                            KC_LALT,                                                  KC_RSHIFT,                           \
                            KC_SPC, KC_BSPACE,                     LT(_RAISE, KC_ENT),KC_SPC,                            \
                            KC_HOME,KC_DELETE,                     LT(_LOWER, KC_TAB),KC_END                             \
),

[_LOWER] = LAYOUT(
    _______,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,            _______,_______,_______,_______,_______,KC_BSLS,   \
    _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,             KC_PLUS,KC_MINS,KC_SLSH,KC_ASTR,KC_PERC,KC_QUOT,   \
    _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,            KC_AMPR,KC_EQL, KC_COMM,KC_DOT, KC_SLSH,KC_MINS,   \
                    _______,_______,                                            _______,_______,                   \
                                            _______,                    _______,                                   \
                                            KC_SCLN,KC_EQL,     KC_EQL, KC_SCLN,                                   \
                                            _______,_______,    _______,_______                                    \
),

[_RAISE] = LAYOUT(
    _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,   \
    _______,_______,_______,_______,_______,KC_VOLU,            KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______,   \
    _______,_______,_______,_______,KC_MUTE,KC_VOLD,            _______,_______,_______,_______,_______,_______,   \
                    _______,_______,                                            _______, _______,                  \
                                            _______,                    _______,                                   \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
),

[_ADJUST] = LAYOUT(
    _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,             _______,_______,_______,_______,_______, _______,   \
    _______,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,            _______,DF(_QWERTY),DF(_WINDOWS_QWERTY),DF(_COLEMAK_DH),DF(_GAMING_QWERTY), _______,   \
    _______,KC_F11, KC_F12, _______,_______,_______,           _______,_______,_______,_______,_______,_______,  \
                    _______,_______,                                            _______, _______,                  \
                                            _______,                    _______,                                   \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

