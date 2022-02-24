#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#define SPC_L C(KC_LEFT)
#define SPC_R C(KC_RGHT)
#define SPC_U C(KC_UP)
#define SPC_D C(KC_DOWN)
#define WIN_D_L C(G(KC_LEFT))
#define WIN_D_R C(G(KC_RIGHT))
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

const uint16_t PROGMEM ESC_COMBO[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM ENTER_COMBO[] = {KC_P, KC_SCOLON, COMBO_END};

const uint16_t PROGMEM TAB_COMBO[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM SHIFT_TAB_COMBO[] = {KC_U, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(ESC_COMBO, KC_ESC),
  COMBO(ENTER_COMBO, KC_ENTER),
  COMBO(TAB_COMBO, KC_TAB),
  COMBO(SHIFT_TAB_COMBO, LSFT(KC_TAB)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON,
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                    KC_LSFT, LA_NAV, LA_SYM,  KC_SPC
    ),

    [SYM] = LAYOUT(
    
        KC_EXLM, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_QUOT,
        KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_CMD,  OS_ALT,  OS_SHFT, OS_CTRL, 
        KC_PLUS, KC_PIPE, KC_AT,   KC_BSLS, KC_PERC, KC_GRV,  KC_SLSH, KC_AMPR, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______
    ),

    [NAV] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        OS_CTRL, OS_SHFT, OS_ALT,  OS_CMD,  KC_VOLU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
        SPC_L,   SPC_D,   SPC_U,   SPC_R,   KC_VOLD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
                                   _______, _______, _______, _______
    ),

    [NUM] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,  KC_F8,    KC_F9,   KC_F10,
        OS_CTRL, OS_SHFT, OS_ALT,  OS_CMD,  KC_F11,  KC_F12,  OS_CMD, OS_ALT,   OS_SHFT, OS_CTRL,
        RGB_VAI, RGB_SAI, RGB_HUI, WIN_D_L, RGB_MOD, RGB_TOG, WIN_D_R,RGB_HUD,  RGB_SAD, RGB_VAD,
                                   _______, _______, _______, _______
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
