#include "kb.h"


#define _QWERTY 0
#define _WINDOWS 1
#define _DVORAK 2
#define _SYMBOLS 3
#define _CONTROL 4
#define _RGBCNTRL 5
#define _MOUSECTRL 6
#define _MACDOWS 7




enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOLS,
  CONTROL,
  RGBCNTRL,
  OSXSCRN1,
  OSXSCRN2,
  OSXSCRN3,
  OSXSCRN4,
  MACDOWS,
  MD_WINR,
  MD_CMDQ,
  MD_CMDW,
  MD_CTRLS,
  MD_CTRLA,
  MD_CTRLC,
  MD_CTRLD,
  MD_CTRLF,
  MD_CTRLZ,
  MD_CTRLX,
  MD_CTRLV,
  MD_ALTTAB
};

#define KC_SYMBOLS SYMBOLS
#define KC_CONTROL CONTROL
#define KC_RGBCNTRL RGBCNTRL
#define KC_OSXSCRN1  OSXSCRN1
#define KC_OSXSCRN2  OSXSCRN2
#define KC_OSXSCRN3  OSXSCRN3
#define KC_OSXSCRN4  OSXSCRN4
#define KC_MACDOWS  MACDOWS

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

[_QWERTY] = layout5x15( \
  KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO, \
  KC_GRAVE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_NO, KC_NO, KC_NO, \
  KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_NO, KC_NO, KC_NO, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, SYMBOLS , KC_NO, KC_UP, KC_NO, \
  KC_NO, KC_LCTL, KC_LALT, KC_LGUI, CONTROL, MO(_CONTROL), KC_SPC, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT \
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

[_SYMBOLS] = layout5x15( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_BSPC, KC_NO, KC_NO, KC_NO,  \
 KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_NO, KC_NO,  \
 KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_QUOT, KC_SLSH, KC_BSLS, KC_LBRC, KC_RBRC, KC_RSFT, KC_TRNS, KC_NO, KC_TRNS, KC_NO,  \
 KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS  \
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

[_CONTROL] = layout5x15( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  LT(_MOUSECTRL, KC_ESCAPE), KC__VOLDOWN, KC__VOLUP, KC__MUTE, KC_BRMD, KC_BRMU, KC_NO, KC_NO, KC_UP, KC_NO, KC_PGUP, RGBCNTRL, KC_NO, KC_NO, KC_NO,  \
  OSXSCRN1, OSXSCRN2, OSXSCRN3, OSXSCRN4, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS, KC_NO, KC_NO, KC_NO,  \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO,  \
  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS  \
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


[_RGBCNTRL] = layout5x15( \
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_WINDOWS), \
  RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_M_P, RGB_M_SW, RGB_M_K, RGB_M_X, RGB_M_G, KC_TRNS, KC_NO, KC_NO, KC_NO,  \
  KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_M_B, RGB_M_SN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  \
  KC_NO, DF(_DVORAK), DF(_QWERTY), KC_NO, KC_NO, KC_NO, RGB_M_R, KC_NO, BL_TOGG, BL_STEP, BL_INC, BL_ON, KC_NO, KC_TRNS, KC_NO,  \
  RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, BL_BRTG, BL_DEC, BL_OFF, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS \
),


[_MOUSECTRL] = layout5x15( \
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_NO,  \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO,  \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,  \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS \
),

[_DVORAK] = layout5x15( \
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
	KC_GRAVE, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, KC_NO, KC_NO, KC_NO,  \
	KC_TAB, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_ENT, KC_NO, KC_NO, KC_NO,  \
	KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, SYMBOLS, KC_NO, KC_TRNS, KC_NO,  \
  KC_NO, KC_LCTL, KC_LALT, KC_LGUI, CONTROL, MO(_CONTROL), KC_SPC, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS \
),

[_WINDOWS] = layout5x15( \
  KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO, \
  KC_GRAVE, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_NO, KC_NO, KC_NO, \
  KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_NO, KC_NO, KC_NO, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, SYMBOLS , KC_NO, KC_UP, KC_NO, \
  KC_NO, KC_LCTL, KC_LALT, LT(_MACDOWS, KC_LGUI), CONTROL, MO(_CONTROL), KC_SPC, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT \
),

[_MACDOWS] = layout5x15( \
  KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO, \
  KC_GRAVE, MD_CMDQ, MD_CMDW, KC_E, MD_WINR, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_NO, KC_NO, KC_NO, \
  MD_ALTTAB, MD_CTRLA, MD_CTRLS, MD_CTRLD, MD_CTRLF, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_NO, KC_NO, KC_NO, \
  KC_LSFT, MD_CTRLZ, MD_CTRLX, MD_CTRLC, MD_CTRLV, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, SYMBOLS , KC_NO, KC_UP, KC_NO, \
  KC_NO, KC_LCTL, KC_LALT, KC_TRNS, KC_NO, KC_NO, KC_SPC, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT \
)

};

// BACKLIGHTING EFFECTS WHILE SWITCHING LAYERS
#ifdef BACKLIGHT_ENABLE
  extern backlight_config_t backlight_config;

  inline void enable_backlight(bool on) {
      backlight_config.enable = on;
      //if (backlight_config.raw == 1) // enabled but level = 0
          //backlight_config.level = 1;
      eeconfig_update_backlight(backlight_config.raw);
      // dprintf("backlight toggle: %u\n", backlight_config.enable);
      backlight_set(backlight_config.enable ? backlight_config.level : 0);
  }

  uint8_t bl_breath_count;
  uint8_t bl_breath_speed = 20;
  int8_t bl_breath_updown = 1;
  bool bl_breath_on;
  backlight_config_t bl_breath_backup;

  void bl_breath_start(uint8_t speed) {

    if (backlight_config.level > 0) {
      bl_breath_on = true;
      bl_breath_speed = speed;
      bl_breath_backup = backlight_config;
    }
  }

  void bl_breath_end(void) {


    if (backlight_config.level > 0) {
      bl_breath_on = false;
      backlight_config = bl_breath_backup;
      eeconfig_update_backlight(backlight_config.raw);
      backlight_set(backlight_config.enable ? backlight_config.level : 0);
    }
  }

  void bl_breath_update(void) {

    if (bl_breath_on) {
      ++bl_breath_count;
      if (bl_breath_count > bl_breath_speed) {
        bl_breath_count = 0;

        backlight_config.level += bl_breath_updown;
        bl_breath_updown = (backlight_config.level > (BACKLIGHT_LEVELS-10)) ? -1 : (backlight_config.level <= 0) ? 1 : bl_breath_updown;
        enable_backlight(true);
      }
    }
  }

  #define BL_BREATH_START bl_breath_start
  #define BL_BREATH_END bl_breath_end
  #define BL_BREATH_UPDATE bl_breath_update

#else

  #define BL_BREATH_START(a)
  #define BL_BREATH_END()
  #define BL_BREATH_UPDATE()
#endif


// Loop
void matrix_scan_user(void) {

  BL_BREATH_UPDATE();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case SYMBOLS:
      if (record->event.pressed) {
        BL_BREATH_START(150);
        layer_on(_SYMBOLS);
      } else {
        BL_BREATH_END();
        layer_off(_SYMBOLS);
      }
      break;
    case CONTROL:
      if (record->event.pressed) {
        BL_BREATH_START(100);
        layer_on(_CONTROL);
      } else {
        BL_BREATH_END();
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
    case OSXSCRN1:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LGUI("3")));
      }
      break;
    case OSXSCRN2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI("4"))));
      }
      break;
    case OSXSCRN3:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI("3"))));
      }
      break;
    case OSXSCRN4:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI("4"))));
      }
      break;
    case MD_WINR:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
      }
      break;
    case MD_CTRLF:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("f"));
      }
      break;
    case MD_CTRLA:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("a"));
      }
      break;
    case MD_CTRLS:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("s"));
      }
      break;
    case MD_CTRLD:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("d"));
      }
      break;
    case MD_CTRLZ:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("z"));
      }
      break;
    case MD_CTRLX:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("x"));
      }
      break;
    case MD_CTRLC:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c"));
      }
      break;
    case MD_CTRLV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("v"));
      }
      break;
    case MD_CMDW:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("w"));
      }
      break;
    case MD_CMDQ:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
      }
      break;
    case MD_ALTTAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
      }
      break;

    default:
      return true;
  }

  return false;
}
