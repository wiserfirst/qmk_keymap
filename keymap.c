#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "user.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base/QWERTY Layer
  *
  * ,----------------------------------------------------.           ,----------------------------------------------------.
  * |    `   |   1  |   2  |   3  |   4  |   5  |        |           |        |   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+---------------|           |--------+------+------+------+------+------+--------|
  * |  TAB   |   Q  |   W  |   E  |   R  |   T  | NUMBER |           | MOUSE  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |  ESC   |CTL A |OPT S |CMD D |SYM F |MSE G |--------|           |--------|MSE H |SYM J |CMD K |OPT L |CTL ; |   '    |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |  CTRL  |   Z  |   X  |   C  |   V  |   B  | SYMBOL |           | SYMBOL |   N  |   M  |   ,  |   .  |   /  | SHIFT  |
  * `--------+------+------+------+------+---------------'           `---------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                           |      |      |      |      |      |
  *   `----------------------------------'                                           `----------------------------------'
  *
  *                                         ,--------------.       ,--------------.
  *                                         |       |      |       |      |       |
  *                                 ,-------|-------|------|       |------+-------+-------.
  *                                 |       |       |CMD L |       |OPT L |       |       |
  *                                 | SHIFT | MOUSE |------|       |------| MOUSE | SHIFT |
  *                                 | BSPC  | TAB   |CMD R |       |OPT R | ENTER | SPACE |
  *                                 `----------------------'       `----------------------'
  */
  [BASE] = LAYOUT_ergodox(
    // Left Hand
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   ___X___,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   NUM_MOD,
    KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_G,
    ___X___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   SYM_MOD,
    ___X___, ___X___, ___X___, ___X___, ___X___,

                                                                   ___X___,  ___X___,
                                                                              CMD_L,
                                                        THUM_BSPC, THUM_TAB,  CMD_R,

    // Right Hand
                      ___X___,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,      KC_MINS,
                      MSE_MOD,  KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,      KC_BSLS,
                                HOME_H, HOME_J, HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
                      SYM_MOD,  KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
                                       ___X___, ___X___, ___X___, ___X___,   ___X___,

    ___X___, ___X___,
     OPT_L,
     OPT_R,  THUM_ENT, THUM_SPC
  ),

  /* Symbol/Fn Layer
  *
  * ,----------------------------------------------------.           ,----------------------------------------------------.
  * |        |  F1  |  F2  |  F3  |  F4  |  F5  |        |           |        |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
  * |--------+------+------+------+------+---------------|           |--------+------+------+------+------+------+--------|
  * |        |  \   |  @   |  +   |  -   |  %   |        |           |        |  [   |  (   |  {   | <%=  |      |  F12   |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |        |  ^   |  $   |  *   |  =   |  #   |--------|           |--------|  ←   |  ↓   |  ↑   |  →   |  `   | CMD ~  |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |        |      |  &   |  !   |  _   |  |   |        |           |        |  ]   |  )   |  }   |  %>  |  ~   |        |
  * `--------+------+------+------+------+---------------'           `---------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                           |      |      |      |      |      |
  *   `----------------------------------'                                           `----------------------------------'
  *
  *                                         ,--------------.       ,--------------.
  *                                         |       |      |       |      |       |
  *                                 ,-------|-------|------|       |------+-------+-------.
  *                                 |       |       |      |       |      |       |       |
  *                                 | CMD L | CMD R |------|       |------| OPT L | OPT R |
  *                                 |       |       |      |       |      |       |       |
  *                                 `----------------------'       `----------------------'
  */
  [SYMB] = LAYOUT_ergodox(
    // Left Hand
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ___X___,
    _______, KC_BSLS, KC_AT,   KC_PLUS, KC_MINS, KC_PERC, _______,
    _______, KC_CIRC, KC_DLR,  KC_ASTR, KC_EQL,  KC_HASH,
    _______, _______, KC_AMPR, KC_EXLM, KC_UNDS, KC_PIPE, _______,
    ___X___, ___X___, ___X___, ___X___, ___X___,

                                                                 ___X___, ___X___,
                                                                          _______,
                                                          CMD_L,  CMD_R,  _______,

    // Right Hand
                              ___X___, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                              _______, KC_LBRC, KC_LPRN, KC_LCBR, L_ERB,   _______, KC_F12,
                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,  CMD_TILD,
                              _______, KC_RBRC, KC_RPRN, KC_RCBR, R_ERB,   KC_TILD, _______,
                                                ___X___, ___X___, ___X___, ___X___, ___X___,

    ___X___, ___X___,
    _______,
    _______,  OPT_L,  OPT_R
  ),

  /* Number/Emoji Layer
  *
  * ,-----------------------------------------------------.           ,----------------------------------------------------.
  * |        |      |      |      |      |       |        |           |        |      |      |      |      |      |        |
  * |--------+------+------+------+------+----------------|           |--------+------+------+------+------+------+--------|
  * |        |  4   |  3   |  2   |  1   |   0   |        |           |        |  5   |  6   |  7   |  8   |  9   |        |
  * |--------+------+------+------+------+-------|        |           |        |------+------+------+------+------+--------|
  * |        | EYES |C_MARK| 100  | PRAY | BOW   |--------|           |--------| WAVE | CLAP | HEART| TADA | SMILE|   +1   |
  * |--------+------+------+------+------+-------|        |           |        |------+------+------+------+------+--------|
  * |        |      | CAKE | OKAY | THINK|CRS FGR|        |           |        | TEA  |COFFEE|F_PALM|EXP_HD|SPRISD|        |
  * `--------+------+------+------+------+----------------'           `---------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                            |      |      |      |      |      |
  *   `----------------------------------'                                            `----------------------------------'
  *
  *                                          ,--------------.       ,--------------.
  *                                          |       |      |       |      |       |
  *                                  ,-------|-------|------|       |------+-------+-------.
  *                                  |       |       |      |       |      |       |       |
  *                                  | LEFT  | RIGHT |------|       |------| LEFT  | RIGHT |
  *                                  | PANE  | PANE  |      |       |      | PANE  | PANE  |
  *                                  `----------------------'       `----------------------'
  */
  [NUMBER] = LAYOUT_ergodox(
    // Left Hand
    _______, _______, _______,  _______, _______,  _______, ___X___,
    _______, KC_4,    KC_3,     KC_2,    KC_1,     KC_0,    _______,
    _______, TM_EYES, TM_CMARK, TM_100,  TM_PRAY,  TM_BOW,
    _______, _______, TM_CAKE,  TM_OKAY, TM_THINK, TM_CSFG, _______,
    ___X___, ___X___, ___X___,  ___X___, ___X___,

                                                                       _______,_______,
                                                                               _______,
                                                               L_PANE, R_PANE, _______,

    // Right Hand
                              ___X___, _______, _______, _______, _______, _______, _______,
                              _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    _______,
                                       TM_WAVE, TM_CLAP, TM_HEART,TM_TADA, TM_SMILE,TM_P_ONE,
                              _______, TM_TEA,  TM_COFE, TM_PALM, TM_EXPH, TM_SURP, _______,
                                                ___X___, ___X___, ___X___, ___X___, ___X___,

    _______, _______,
    _______,
    _______, L_PANE,  R_PANE
  ),

  /* Mouse/RGB control Layer
  *
  * ,-----------------------------------------------------.           ,----------------------------------------------------.
  * |        |      |      |      |      |       |        |           |        |      |      |      |      |      |BOOTLODR|
  * |--------+------+------+------+------+----------------|           |--------+------+------+------+------+------+--------|
  * |        |SA INC|SA DEC|NXT MD|PRV MD|PLN MD |        |           |        |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------|        |           |        |------+------+------+------+------+--------|
  * |        |VO INC|VO DEC| RED  | BLUE |LED TOG|--------|           |--------| MSE L| MSE D| MSE U| MSE R|      |        |
  * |--------+------+------+------+------+-------|        |           |        |------+------+------+------+------+--------|
  * |        |HU INC|HU DEC| GREEN|ORANGE|       |        |           |        |      | L BTN| R BTN|      |      |        |
  * `--------+------+------+------+------+----------------'           `---------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                            |      |      |      |      |      |
  *   `----------------------------------'                                            `----------------------------------'
  *
  *                                          ,--------------.       ,--------------.
  *                                          |       |      |       |      |       |
  *                                  ,-------|-------|------|       |------+-------+-------.
  *                                  |       |       |      |       |      |       |       |
  *                                  |       |       |------|       |------|       |       |
  *                                  |       |       |      |       |      |       |       |
  *                                  `----------------------'       `----------------------'
  */
  [MOUSE] = LAYOUT_ergodox(
    // Left Hand
    _______, ___X___, ___X___, ___X___, ___X___,  ___X___, _______,
    _______, RGB_SAI, RGB_SAD, RGB_MOD, RGB_RMOD, RGB_M_P, _______,
    _______, RGB_VAI, RGB_VAD, LED_RED, LED_BLU,  RGB_TOG,
    _______, RGB_HUI, RGB_HUD, LED_GRN, LED_ORNG, _______, _______,
    ___X___, ___X___, ___X___, ___X___, ___X___,

                                                                       _______,_______,
                                                                               _______,
                                                               _______,_______,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,QK_BOOT,
                              _______,_______,_______,_______,_______,_______,_______,
                                      KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,
                              _______,_______,KC_BTN1,KC_BTN2,_______,_______,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,_______,_______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      // dynamically generate these.
      case LED_BLU:
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
        return false;

      case LED_GRN:
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
        return false;

      case LED_RED:
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
        return false;

      case LED_ORNG:
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
        return false;

      case L_ERB:
        SEND_STRING("<%=");
        return false;

      case R_ERB:
        SEND_STRING("%>");
        return false;

      case CLAP:
        SEND_STRING(":clap:");
        return false;

      case COFFEE:
        SEND_STRING(":coffee:");
        return false;

      case D_ARROW:
        SEND_STRING(":arrow_down:");
        return false;

      case LAUGH:
        SEND_STRING(":joy:");
        return false;

      case L_ARROW:
        SEND_STRING(":arrow_left:");
        return false;

      case MINUS_ONE:
        SEND_STRING(":-1:");
        return false;

      case NEUTRAL:
        SEND_STRING(":neutral:");
        return false;

      case PLUS_ONE:
        SEND_STRING(":+1:");
        return false;

      case R_ARROW:
        SEND_STRING(":arrow_right:");
        return false;

      case SAD:
        SEND_STRING(":disappointed:");
        return false;

      case SMILE:
        SEND_STRING(":smile:");
        return false;

      case TROLL:
        SEND_STRING(":trollface:");
        return false;

      case U_ARROW:
        SEND_STRING(":arrow_up:");
        return false;

      case WINK:
        SEND_STRING(":wink:");
        return false;

      // MS Teams Emojis
      case TM_100:
        SEND_STRING("(hundredpoints)");
        return false;

      case TM_BOW:
        SEND_STRING("(manbowing)");
        return false;

      case TM_CAKE:
        SEND_STRING("(cake)");
        return false;

      case TM_CLAP:
        SEND_STRING("(clap)");
        return false;

      case TM_CMARK:
        SEND_STRING("(checkmarkbutton)");
        return false;

      case TM_COFE:
        SEND_STRING("(coffee)");
        return false;

      case TM_CSFG:
        SEND_STRING("(crossedfingers)");
        return false;

      case TM_EXPH:
        SEND_STRING("(explodinghead)");
        return false;

      case TM_EYES:
        SEND_STRING("(eyes)");
        return false;

      case TM_HEART:
        SEND_STRING("(heart)");
        return false;

      case TM_PALM:
        SEND_STRING("(facepalm)");
        return false;

      case TM_OKAY:
        SEND_STRING("(ok)");
        return false;

      case TM_PRAY:
        SEND_STRING("(pray)");
        return false;

      case TM_P_ONE:
        SEND_STRING("(y)");
        return false;

      case TM_SMILE:
        SEND_STRING(":)");
        return false;

      case TM_SURP:
        SEND_STRING(":O");
        return false;

      case TM_TADA:
        SEND_STRING("(partypopper)");
        return false;

      case TM_TEA:
        SEND_STRING("(chai)");
        return false;

      case TM_THINK:
        SEND_STRING("(thinkingface)");
        return false;

      case TM_WAVE:
        SEND_STRING("(wavinghand)");
        return false;
    }
  }

  return true;
};

void matrix_init_user(void) {
  debug_enable = true;
};

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  ergodox_led_all_set(LED_BRIGHTNESS_LO);
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
};
