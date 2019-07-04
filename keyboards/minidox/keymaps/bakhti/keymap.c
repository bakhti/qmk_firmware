// Minidox keymap by dustypomerleau
// Thanks for checking out my keymap. The rationale behind the layout is described in the README.

#include QMK_KEYBOARD_H
#include "keymap_german_osx.h"

extern keymap_config_t keymap_config;

enum my_layers {
  _QWERTZ,
  _CMK_DHM,
  _SYS,
  _NAV,
  _NUM_E,
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
  DE_OSX_Q, DE_OSX_W, DE_OSX_E, DE_OSX_R, DE_OSX_T,         DE_OSX_Z, DE_OSX_U, DE_OSX_I,    DE_OSX_O,   DE_OSX_P,    \
  SFT_A,    CTRL_S,   ALT_D,    GUI_F,    DE_OSX_G,         DE_OSX_H, GUI_J,    ALT_K,       CTRL_L,     SFT_QOT,     \
  SYS_Y,    DE_OSX_X, DE_OSX_C, DE_OSX_V, DE_OSX_B,         DE_OSX_N, DE_OSX_M, DE_OSX_COMM, DE_OSX_DOT, DE_OSX_MINS, \
                           SFT_OS,  NAV_BK,  SYM_OS,       SYM_OS,  NUMN_SPC, ALT_ENT                                 \
),

/* System, media, and layer lock keys
 * If you use QWERTZ + the Vanilla numbers primarily, change NUMLK_E to NUMLK_N here.
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET|DEBUG |QWERTZ|CMKDHM|      |           |      | VOL--| VOL++|BRITE-|BRITE+|
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
  RESET,   DEBUG,   QWERTZ,  CMK_DHM, _______,       _______,  KC_VOLD, KC_VOLU, KC_BRID,  KC_BRIU, \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, NAV_LK,        KC_POWER, VOL_DN,  VOL_UP,  KC__MUTE, KC_MPLY, \
  _______, _______, AU_OFF,  AU_ON,   _______,       _______,  NUMLK_N, KC_MRWD, KC_MFFD,  _______, \
                    _______, _______, _______,       _______,  _______, _______                     \
),

/* Navigation + mouse keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * | PSCR |      | WH U | WH D |      |           | BSPC | PGDN | PGUP | HOME |  END |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |NAV LK|           | LEFT | DOWN |  UP  | RIGHT| CAPS |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | ACL0 | ACL1 | ACL2 | BTN2 |           | BTN1 | MS L | MS D | MS U | MS R |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      | ENTER|      |
 *                  `------+------|  ESC |    | DEL  |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NAV] = LAYOUT( \
  KC_PSCR, _______, KC_WH_U, KC_WH_D, _______,       KC_BSPC, KC_PGDN, KC_PGUP, KC_HOME, KC_END,  \
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, NAV_LK,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, \
  _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN2,       KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, \
                    _______, _______, KC_ESC,        KC_DEL,  KC_ENT,  _______                    \
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
 *                  |      | TAB  |      |    |      |      |      |
 *                  `------+------|  ESC |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM_N] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,       KC_F4,   KC_F5,         KC_F6,    KC_F7,   KC_F8,      KC_F9,      KC_F10,  \
  SFT_1,   CTRL_2,  ALT_3,       GUI_4,   DE_OSX_5,      DE_OSX_6, GUI_7,   ALT_8,      CTRL_9,     SFT_0,   \
  KC_F11,  KC_F12,  DE_OSX_ASTR, KC_SPC,  KC_BSPC,       KC_DEL,   NUMLK_N, DE_MY_LCBR, DE_MY_EURO, DE_OSX_ACUT, \
                        _______, KC_TAB,  KC_ESC,        _______, _______, _______                    \
),


/* Symbols
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   [  |   ]  |   *  |           |   %  |   &  |   =  |   ?  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/+| CTL/^| ALT/(| GUI/)|   "  |           |   ß  | GUI/Ü| ALT/Ö| CTL/Ä| SFT/$|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   <  |  >   |  {   |   }  |   \  |           |   `  |   |  |   /  |   ~  |   ;  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |ENDASH|      |    |      |EMDASH|      |
 *                  `------+------|      |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYM] = LAYOUT( \
  DE_OSX_EXLM, DE_MY_AT,    DE_MY_LBRC,  DE_MY_RBRC,  DE_OSX_ASTR,       DE_OSX_PERC, DE_OSX_AMPR, DE_OSX_EQL, DE_OSX_QST,  DE_OSX_QUOT, \
  TD(SFT_PLS), CTRL_EQ,     TD(ALT_LP),  TD(GUI_RP),  DE_OSX_DQOT,       DE_OSX_SS,   GUI_RB,      ALT_LB,      TD(CTL_RCB), TD(SFT_LCB), \
  DE_OSX_LESS, DE_OSX_MORE, DE_MY_LCBR,  DE_MY_RCBR,  DE_MY_BSLS,        DE_OSX_GRV,  DE_MY_PIPE, DE_OSX_SLSH, DE_MY_TILD,  DE_OSX_SCLN, \
                               _______,    MAC_EN,     _______,          _______, MAC_EM,  _______                            \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMK_DHM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CMK_DHM);
      }
      return false;
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
