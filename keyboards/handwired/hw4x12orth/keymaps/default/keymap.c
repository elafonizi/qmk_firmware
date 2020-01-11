#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _DVORAK 1
#define _SYMBOLS 2
#define _CONTROL 3
#define _RGBCNTRL 4
#define _MOUSECTRL 5



enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOLS,
  CONTROL,
  RGBCNTRL,
  OSXSCRN
};

#define KC_SYMBOLS SYMBOLS
#define KC_CONTROL CONTROL
#define KC_RGBCNTRL RGBCNTRL
#define KC_OSXSCRN  OSXSCRN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------------------------------------------.
   * |  ~   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp  |
   * |------+------+------+------+------+-------------+------+------+------+------+-------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter  |
   * |------+------+------+------+------+------|------+------+------+------+------+-------|
   * | L_SH |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | R_SH |SYMBOLS|
   * |------+------+------+------+------+------+------+------+------+------+------+-------|
   * |      | LCTRL| LALT |  OS  | MO(2)|      |    Space    |      |      |      |       |
   * `------------------------------------------------------------------------------------'
   */

[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_GRAVE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, SYMBOLS , \
  KC_NO, KC_LCTL, KC_LALT, KC_LGUI, CONTROL, MO(_CONTROL), KC_NO,  KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO \
),


/* SYMBOLS
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  1!  |  2@  |  3#  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  |  -_  | +=   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | TRNS | KC_NO| KC_NO| KC_NO| KC_NO|  ",  |  ?/  |  {[  |  }]  |  |\  | R_SH | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | KC_NO| TRNS | TRNS | TRNS | KC_NO| KC_NO|   TRNS      | KC_NO| KC_NO| KC_NO| KC_NO|
 * `-----------------------------------------------------------------------------------'
 */

[_SYMBOLS] = LAYOUT_ortho_4x12( \
 KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,      KC_BSPC, \
  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,    KC_EQL, \
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_QUOT,  KC_SLSH,  KC_BSLS,  KC_LBRC,  KC_RBRC,   KC_RSFT,    KC_TRNS, \
  KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,  KC_TRNS, KC_NO,    KC_NO,    KC_NO,      KC_NO \
),

/* _CONTROL
 * ,-----------------------------------------------------------------------------------.
 * |ESC/MO| VOL- | VOL+ | VOLx |  BR+ |  BR- |      |      |  UP  |      | PGUP | L_RGB|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | MO(_MOUSECTRL)|      |      |OSXSCR|      |      |      | LEFT | DOWN | RIGHT| PGDN | TRNS |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |      | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TRNS | TRNS | TRNS | TRNS |      |    TRNS     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
*/

[_CONTROL] = LAYOUT_ortho_4x12( \
  LT(_MOUSECTRL, KC_ESCAPE), KC__VOLDOWN, KC__VOLUP, KC__MUTE, KC_BRMD, KC_BRMU, KC_NO, KC_NO, KC_UP, KC_NO, KC_PGUP, RGBCNTRL, \
  KC_NO, KC_NO, KC_NO, OSXSCRN, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS, \
  KC_TRNS, DF(_DVORAK), DF(_QWERTY), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, \
  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
),

/* _RGBCNTRL
 * ,-----------------------------------------------------------------------------------.
 * |RGB_TG|RGB_MD| RGBH+|RGSAT+|RGVA+ |RGSPD+| RG_MP|RG_MSW| RG_MK| RG_MK| RG_MX| TRNS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | RGNH-|RGSAT-|RGVA_ |RGSPD-| RG_MB|RG_MSN|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | BL_TG|BL_CYC| BL+  | BL_ON|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | TRNS |      |             |      |BL_BRT| BL-  |BL_OFF|
 * `-----------------------------------------------------------------------------------'
*/


[_RGBCNTRL] = LAYOUT_ortho_4x12( \
  RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_M_P, RGB_M_SW, RGB_M_K, RGB_M_X, RGB_M_G, KC_TRNS, \
  KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_M_B, RGB_M_SN, KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_R, KC_NO, BL_TOGG, BL_STEP, BL_INC, BL_ON, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, BL_BRTG, BL_DEC, BL_OFF \
),


[_MOUSECTRL] = LAYOUT_ortho_4x12( \
  KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO, \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
),

[_DVORAK] = LAYOUT_ortho_4x12( \
	KC_GRAVE, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, \
	KC_TAB, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_ENT, \
	KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, SYMBOLS, \
  KC_NO, KC_LCTL, KC_LALT, KC_LGUI, CONTROL, MO(_CONTROL), KC_NO, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case SYMBOLS:
      if (record->event.pressed) {
        //BL_BREATH_START(100);
        layer_on(_SYMBOLS);
      } else {
        //BL_BREATH_END();
        layer_off(_SYMBOLS);
      }
      break;
    case CONTROL:
      if (record->event.pressed) {
        //BL_BREATH_START(250);
        layer_on(_CONTROL);
      } else {
        //BL_BREATH_END();
        layer_off(_CONTROL);
      }
      break;
    case RGBCNTRL:
      if (record->event.pressed) {
        layer_on(_RGBCNTRL);
      } else {
        layer_off(_RGBCNTRL);
      }
      break;
    case OSXSCRN:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI("4"))));
      }
      break;
    default:
      return true;
  }

  return false;
}
