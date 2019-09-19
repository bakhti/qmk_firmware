// Minidox keymap by dustypomerleau
// Thanks for checking out my keymap. The rationale behind the layout is described in the README.

#include QMK_KEYBOARD_H
#include "keymap_german_osx.h"

extern keymap_config_t keymap_config;

enum my_layers {
  _QWERTZ,
  _SYS,
  _NAV,
  _NUM_N,
  _SYM
};

enum my_keycodes {
  QWERTZ = SAFE_RANGE,
  SYS,
  NAV,
  NUM_N,
  SYM
};

#define DE_MY_LCBR RALT(DE_OSX_8) // {
#define DE_MY_LBRC RALT(DE_OSX_5) // [
#define DE_MY_RBRC RALT(DE_OSX_6) // ]
#define DE_MY_RCBR RALT(DE_OSX_9) // }
#define DE_MY_BSLS RALT(LSFT(DE_OSX_7)) // backslash
#define DE_MY_AT  RALT(DE_OSX_L) // @
#define DE_MY_EURO RALT(DE_OSX_E) // €
#define DE_MY_TILD RALT(DE_OSX_N) // ~
#define DE_MY_PIPE RALT(DE_OSX_7) // |

enum td_keycodes {
  ALT_LP,
  CTL_RCB,
  GUI_RP,
  SFT_LCB,
  SFT_PLS
};

typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

static td_state_t td_state;
int cur_dance (qk_tap_dance_state_t *state);
void altlp_finished (qk_tap_dance_state_t *state, void *user_data);
void altlp_reset (qk_tap_dance_state_t *state, void *user_data);
void ctlrcb_finished (qk_tap_dance_state_t *state, void *user_data);
void ctlrcb_reset (qk_tap_dance_state_t *state, void *user_data);
void guirp_finished (qk_tap_dance_state_t *state, void *user_data);
void guirp_reset (qk_tap_dance_state_t *state, void *user_data);
void sftlcb_finished (qk_tap_dance_state_t *state, void *user_data);
void sftlcb_reset (qk_tap_dance_state_t *state, void *user_data);
void sftpls_finished (qk_tap_dance_state_t *state, void *user_data);
void sftpls_reset (qk_tap_dance_state_t *state, void *user_data);

#define ALT_3 LALT_T(DE_OSX_3)
#define ALT_8 LALT_T(DE_OSX_8)
#define ALT_D LALT_T(DE_OSX_D)
#define ALT_ENT RALT_T(KC_ENT)
#define ALT_K LALT_T(DE_OSX_K)
#define ALT_LB LALT_T(DE_OSX_OE)
#define CTRL_2 LCTL_T(DE_OSX_2)
#define CTRL_9 LCTL_T(DE_OSX_9)
#define CTRL_EQ LCTL_T(DE_OSX_CIRC)
#define CTRL_L LCTL_T(DE_OSX_L)
#define CTRL_S LCTL_T(DE_OSX_S)
#define GUI_4 LGUI_T(DE_OSX_4)
#define GUI_7 LGUI_T(DE_OSX_7)
#define GUI_RB LGUI_T(DE_OSX_UE)
#define GUI_F LGUI_T(DE_OSX_F)
#define GUI_J LGUI_T(DE_OSX_J)
#define MAC_EM S(LALT(KC_MINS))
#define MAC_EN LALT(KC_MINS)
#define NAV_BK LT(_NAV, KC_BSPC)
#define NAV_LK TG(_NAV)
#define NUME_SPC LT(_NUM_E, KC_SPC)
#define NUMLK_E TG(_NUM_E)
#define NUMLK_N TG(_NUM_N)
#define NUMN_SPC LT(_NUM_N, KC_SPC)
#define SFT_0 LSFT_T(DE_OSX_0)
#define SFT_1 LSFT_T(DE_OSX_1)
#define SFT_A LSFT_T(DE_OSX_A)
#define SFT_OS OSM(MOD_LSFT)
#define SFT_QOT LSFT_T(DE_OSX_QUOT)
#define SYM_OS OSL(_SYM)
#define SYS_Y LT(_SYS, DE_OSX_Y)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTZ
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Z  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/A| CTL/S| ALT/D| GUI/F|   G  |           |   H  | GUI/J| ALT/K| CTL/L| SFT/#|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SYS/Y|   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   -  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,----------------------.
 *                  |SFT/OS|NAV/BK|      |    |      |NUM/SP|RALT/ENT|
 *                  `------+------|SYM/OS|    |SYM/OS|------+--------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTZ] = LAYOUT( \
  DE_OSX_P, DE_OSX_O, DE_OSX_I, DE_OSX_U, DE_OSX_Z, DE_OSX_T, DE_OSX_R, DE_OSX_E, DE_OSX_W, DE_OSX_Q, \
  SFT_QOT, CTRL_L, ALT_K, GUI_J, DE_OSX_H, DE_OSX_G, GUI_F, ALT_D, CTRL_S, SFT_A, \
  DE_OSX_MINS, DE_OSX_DOT, DE_OSX_COMM, DE_OSX_M, DE_OSX_N, DE_OSX_B, DE_OSX_V, DE_OSX_C, DE_OSX_X, SYS_Y, \
  ALT_ENT, NUMN_SPC, SYM_OS, SYM_OS, NAV_BK, SFT_OS \
),

/* System, media, and layer lock keys
 * If you use QWERTZ + the Vanilla numbers primarily, change NUMLK_E to NUMLK_N here.
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET|DEBUG |QWERTZ|      |      |           |      | VOL--| VOL++|BRITE-|BRITE+|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |NAV LK|           | POWER| VOL- | VOL+ | MUTE | MPLY |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |AU OFF| AU ON|      |           |      |NUM LK| MRWD | MFFD |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYS] = LAYOUT( \
  KC_BRIU, KC_BRID, KC_VOLU, KC_VOLD, _______, _______, _______, QWERTZ, DEBUG, RESET, \
  KC_MPLY, KC__MUTE, VOL_UP, VOL_DN, KC_POWER, NAV_LK, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, \
  _______, KC_MFFD, KC_MRWD, NUMLK_N, _______, _______, AU_ON, AU_OFF, _______, _______, \
                    _______, _______, _______, _______, _______, _______ \
),

/* Navigation + mouse keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * | PSCR |      | WH U | WH D |      |           | HOME | PGDN | PGUP | END  | BSPC |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |NAV LK|           | LEFT | DOWN |  UP  | RIGHT| CAPS |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | ACL0 | ACL1 | ACL2 | BTN2 |           | MS L | MS D | MS U | MS R | BTN1 |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      | DEL  | ESC  |
 *                  `------+------|      |    | ENT  |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NAV] = LAYOUT( \
  KC_BSPC, KC_END, KC_PGUP, KC_PGDN, KC_HOME, _______, KC_WH_D, KC_WH_U, _______, KC_PSCR, \
  KC_CAPS, KC_RGHT, KC_UP, KC_DOWN, KC_LEFT, NAV_LK, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, \
  KC_BTN1, KC_MS_R, KC_MS_U, KC_MS_D, KC_MS_L, KC_BTN2, KC_ACL2, KC_ACL1, KC_ACL0, _______, \
  KC_ESC, KC_DEL, KC_ENT, _______, _______, _______ \
),

/* Number + function keys (numeric number order - default pairing with QWERTZ)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/1| CTL/2| ALT/3| GUI/4|   5  |           |   6  | GUI/7| ALT/8| CTL/9| SFT/0|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |   -  | SPACE| BSPC |           |  DEL |NUM LK|   {  |   €  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | ESC  | TAB  |      |    |      |      |      |
 *                  `------+------|  ENT |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM_N] = LAYOUT( \
  KC_F10, KC_F9, KC_F8, KC_F7, KC_F6, KC_F5, KC_F4, KC_F3, KC_F2, KC_F1, \
  SFT_0, CTRL_9, ALT_8, GUI_7, DE_OSX_6, DE_OSX_5, GUI_4, ALT_3, CTRL_2, SFT_1, \
  DE_OSX_ACUT, DE_MY_EURO, DE_MY_LCBR, NUMLK_N, KC_DEL, KC_BSPC, KC_SPC, DE_OSX_ASTR, KC_F12, KC_F11, \
  _______, _______, _______, KC_ENT, KC_TAB, KC_ESC \
),


/* Symbols
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   [  |   ]  |   *  |           |   %  |   &  |   =  |   ?  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/+| CTL/^| ALT/(| GUI/)|   "  |           |   ß  | GUI/Ü| ALT/Ö| CTL/Ä| SFT/$|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   <  |  >   |  {   |   }  |   `  |           |   \  |   |  |   /  |   ~  |   ;  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |ENDASH|      |    |      |EMDASH|      |
 *                  `------+------|      |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT( \
  DE_OSX_QUOT, DE_OSX_QST, DE_OSX_EQL, DE_OSX_AMPR, DE_OSX_PERC, DE_OSX_ASTR, DE_MY_RBRC, DE_MY_LBRC, DE_MY_AT, DE_OSX_EXLM, \
  TD(SFT_LCB), TD(CTL_RCB), ALT_LB, GUI_RB, DE_OSX_SS, DE_OSX_DQOT, TD(GUI_RP), TD(ALT_LP), CTRL_EQ, TD(SFT_PLS), \
  DE_OSX_SCLN, DE_MY_TILD, DE_OSX_SLSH, DE_MY_PIPE, DE_MY_BSLS, DE_OSX_GRV, DE_MY_RCBR, DE_MY_LCBR, DE_OSX_MORE, DE_OSX_LESS, \
  _______, MAC_EM, _______, _______, MAC_EN, _______ \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTZ:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTZ);
      }
      return false;
    default:
      return true;
  }
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  if (state->count == 2) return DOUBLE_SINGLE_TAP;
  else return 3;
}

void altlp_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(DE_OSX_LPRN);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LALT));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(DE_OSX_LPRN);
      register_code16(DE_OSX_LPRN);
  }
}

void altlp_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(DE_OSX_LPRN);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LALT));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(DE_OSX_LPRN);
  }
}

void ctlrcb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(DE_OSX_AE);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LCTL));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(DE_OSX_AE);
      register_code16(DE_OSX_AE);
  }
}

void ctlrcb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(DE_OSX_AE);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LCTL));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(DE_OSX_AE);
  }
}

void guirp_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(DE_OSX_RPRN);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LGUI));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(DE_OSX_RPRN);
      register_code16(DE_OSX_RPRN);
  }
}

void guirp_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(DE_OSX_RPRN);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LGUI));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(DE_OSX_RPRN);
  }
}

void sftlcb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(DE_OSX_DLR);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(DE_OSX_DLR);
      register_code16(DE_OSX_DLR);
  }
}

void sftlcb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(DE_OSX_DLR);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(DE_OSX_DLR);
  }
}

void sftpls_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(DE_OSX_PLUS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(DE_OSX_PLUS);
      register_code16(DE_OSX_PLUS);
  }
}

void sftpls_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(DE_OSX_PLUS);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(DE_OSX_PLUS);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [ALT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlp_finished, altlp_reset),
  [CTL_RCB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctlrcb_finished, ctlrcb_reset),
  [GUI_RP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, guirp_finished, guirp_reset),
  [SFT_LCB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftlcb_finished, sftlcb_reset),
  [SFT_PLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftpls_finished, sftpls_reset)
};
