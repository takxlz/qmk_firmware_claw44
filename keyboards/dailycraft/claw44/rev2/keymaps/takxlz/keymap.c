#include QMK_KEYBOARD_H
#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
#endif
// #include <stdio.h>

/************************************************************ 各種定義 ************************************************************/
// レイヤー定義
enum layer_number {
    _0 = 0,
    _1,
    _2,
    _3,
};

// カスタムキー定義
enum custom_keycodes {
    TK_FWRD = SAFE_RANGE, // 進む
    TK_BACK,              // 戻る
    TK_SLEP,              // スリープ
    TK_REST,              // リセット
    // TK_MCTL,              // ミッションコントロール
    // TK_SCLN,              // セミコロン、コロン
    // TK_PLAS,              // プラス、アスタリスク
    // TK_EISU,              // 英数
    // TK_KANA,              // かな
};

#ifdef TAP_DANCE_ENABLE
// TDキーコード定義
enum {
    TD_EN = 0,
    TD_JP,
    TD_F10,
    TD_F2,
};

// TD種別定義
enum {
    SINGLE_TAP = 1,    // タップ
    SINGLE_HOLD,       // ホールド
    DOUBLE_TAP,        // ダブルタップ
    SINGLE_TAP_HOLD,   // タップ＆ホールド
    DOUBLE_SINGLE_TAP, // appleのようなpp入力とダブルタップを区別
};

// TD状態定義
static int td_state = 0;

// TD種別判定関数定義
int cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return SINGLE_TAP_HOLD;
        else
            return DOUBLE_TAP;
    } else
        return 9;
}
#endif

/************************************************************ タップダンス ************************************************************/
#ifdef TAP_DANCE_ENABLE
/*
// TD_EN
void td_en_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            register_code(KC_LCTL);
        } else {
            register_code(KC_LGUI);
        }
    } else {
        tap_code(KC_LNG2);
    }
}
void td_en_reset(tap_dance_state_t *state, void *user_data) {
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            unregister_code(KC_LCTL);
        } else {
            unregister_code(KC_LGUI);
        }
    }
    td_state = 0;
}

// TD_JP
void td_jp_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            register_code(KC_LGUI);
        } else {
            register_code(KC_LCTL);
        }
    } else {
        tap_code(KC_LNG1);
    }
}
void td_jp_reset(tap_dance_state_t *state, void *user_data) {
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            unregister_code(KC_LGUI);
        } else {
            unregister_code(KC_LCTL);
        }
    }
    td_state = 0;
}
*/

// TD_F10
void td_f10_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            register_code(KC_LCTL);
        } else {
            register_code(KC_LGUI);
        }
    } else {
        tap_code(KC_F10);
    }
}
void td_f10_reset(tap_dance_state_t *state, void *user_data) {
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            unregister_code(KC_LCTL);
        } else {
            unregister_code(KC_LGUI);
        }
    }
    td_state = 0;
}

// TD_F2
void td_f2_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            register_code(KC_LGUI);
        } else {
            register_code(KC_LCTL);
        }
    } else {
        tap_code(KC_F2);
    }
}
void td_f2_reset(tap_dance_state_t *state, void *user_data) {
    if (td_state == SINGLE_HOLD) {
        if (detected_host_os() == OS_WINDOWS) {
            unregister_code(KC_LGUI);
        } else {
            unregister_code(KC_LCTL);
        }
    }
    td_state = 0;
}

// TD割り当て
tap_dance_action_t tap_dance_actions[] = {
    // [TD_EN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_en_finished, td_en_reset),
    // [TD_JP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_jp_finished, td_jp_reset),
    [TD_F10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_f10_finished, td_f10_reset),
    [TD_F2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_f2_finished, td_f2_reset),
};
#endif

/************************************************************ キー割り当て ************************************************************/
// layer
#define KC_1_SPC LT(_1, KC_SPC)
#define KC_2_ENT LT(_2, KC_ENT)

// lctl_t
#define KC_C_ENT LCTL_T(KC_ENT)
#define KC_C_MINS LCTL_T(KC_MINS)
#define KC_C_F LCTL_T(KC_F)
#define KC_C_J LCTL_T(KC_J)

// lgui_t
#define KC_G_G LGUI_T(KC_G)
#define KC_G_H LGUI_T(KC_H)
#define KC_G_ESC LGUI_T(KC_ESC)
#define KC_G_LBRC LGUI_T(KC_LBRC)

// lsft_t
#define KC_S_ENT LSFT_T(KC_ENT)
#define KC_S_EN LSFT_T(KC_LNG2)
#define KC_S_JP LSFT_T(KC_LNG1)
#define KC_S_BS LSFT_T(KC_BSPC)
#define KC_S_DEL LSFT_T(KC_DEL)
#define KC_S_ALT LSFT_T(KC_LALT)

// lalt_t
#define KC_A_D LALT_T(KC_D)
#define KC_A_K LALT_T(KC_K)
#define KC_A_TAB LALT_T(KC_TAB)

// cmd+shift
#define KC_GS_S SCMD_T(KC_S)
#define KC_GS_L SCMD_T(KC_L)

// ctrl+shift
#define KC_CS_A MT(MOD_LCTL | MOD_LSFT, KC_A)
#define KC_CS_SCLN MT(MOD_LCTL | MOD_LSFT, KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_0] = LAYOUT(
    // .-----------------------------------------------------------------------------------.                  .-----------------------------------------------------------------------------------.
        KC_G_ESC     , KC_Q        , KC_W        , KC_E        , KC_R        , KC_T        ,                   KC_Y         , KC_U        , KC_I        , KC_O        , KC_P        , KC_G_LBRC   ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        KC_C_ENT     , KC_CS_A     , KC_GS_S     , KC_A_D      , KC_C_F      , KC_G_G      , XXXXXXX, XXXXXXX, KC_G_H       , KC_C_J      , KC_A_K      , KC_GS_L     , KC_CS_SCLN  , KC_C_MINS   ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        KC_S_BS      , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B        , XXXXXXX, XXXXXXX, KC_N         , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH     , KC_S_ALT    ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
                                     TD(TD_F10)  , KC_S_EN     , KC_1_SPC    , KC_A_TAB    ,                   KC_BSPC      , KC_2_ENT    , KC_S_JP     , TD(TD_F2)
    // ,                            -------------------------------------------------------.                  .-------------------------------------------------------.
   ),

   [_1] = LAYOUT(
    // .-----------------------------------------------------------------------------------.                  .-----------------------------------------------------------------------------------.
        _______      , KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5       ,                   KC_SLSH      , S(KC_MINS)  , S(KC_QUOT)  , S(KC_SCLN)  , S(KC_5)     , KC_PGUP     ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        S(KC_INT1)   , KC_1        , KC_2        , KC_3        , KC_4        , KC_5        , XXXXXXX, XXXXXXX, KC_6         , KC_7        , KC_8        , KC_9        , KC_0        , _______     ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        KC_S_DEL     , KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10      , XXXXXXX, XXXXXXX, _______      , _______      , _______    , _______     , S(KC_4)     , KC_PGDN     ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
                                     _______     , _______     , _______     , _______     ,                   _______       , _______     , _______    , _______
    // ,                            -------------------------------------------------------.                  .-------------------------------------------------------.
   ),

   [_2] = LAYOUT(
    // .-----------------------------------------------------------------------------------.                  .-----------------------------------------------------------------------------------.
        _______      , S(KC_SLSH)  , S(KC_1)     , S(KC_6)     , S(KC_INT3)  , KC_INT3     ,                   KC_SLSH      , S(KC_MINS)  , S(KC_QUOT)  , S(KC_SCLN)  , S(KC_5)     , KC_HOME     ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        KC_EQL       , S(KC_3)     , S(KC_LBRC)  , S(KC_2)     , S(KC_7)     , S(KC_EQL)   , XXXXXXX, XXXXXXX, KC_LEFT      , KC_DOWN     , KC_UP       , KC_RGHT     , KC_QUOT     , S(KC_INT1)  ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        KC_S_DEL     , KC_LBRC     , S(KC_COMM)  , KC_RBRC     , S(KC_8)     , S(KC_RBRC)  , XXXXXXX, XXXXXXX, S(KC_NUHS)   , S(KC_9)     , KC_NUHS     , S(KC_DOT)   , S(KC_4)     , KC_END      ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
                                     _______     , _______     , _______     , _______     ,                   _______      , _______     , _______     , _______
    // ,                            -------------------------------------------------------.                  .-------------------------------------------------------.
   ),

   [_3] = LAYOUT(
    // .-----------------------------------------------------------------------------------.                  .-----------------------------------------------------------------------------------.
        _______      , _______     , _______     , _______     , _______     , _______     ,                   _______      , _______     , _______     , _______     , KC_PSCR     , _______     ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        _______      , _______     , _______     , _______     , TK_BACK     , TK_FWRD     , XXXXXXX, XXXXXXX, KC_MS_LEFT   , KC_MS_DOWN  , KC_MS_UP    , KC_MS_RIGHT , _______     , _______     ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
        _______      , _______     , _______     , _______     , KC_F11      , KC_F12      , XXXXXXX, XXXXXXX, KC_BTN3      , KC_BTN1     , KC_BTN2     , _______     , _______     , _______     ,
    // .-------------+-------------+-------------+-------------+-------------+-------------.                  .-------------+-------------+-------------+-------------+-------------+-------------.
                                     _______     , _______     , _______     , _______     ,                   _______      , _______     , TK_REST     , TK_SLEP
    // ,                            -------------------------------------------------------.                  .-------------------------------------------------------.
   ),
};
// clang-format on

/************************************************************ カスタムキー ************************************************************/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // 進む
  if (keycode == TK_FWRD && record -> event.pressed) {
    if (detected_host_os() == OS_WINDOWS) {
      register_code(KC_LALT);
      tap_code(KC_RGHT);
      unregister_code(KC_LALT);
    } else {
      register_code(KC_LGUI);
      tap_code(KC_RGHT);
      unregister_code(KC_LGUI);
    }
    return false;
  }
  // 戻る
  if (keycode == TK_BACK && record -> event.pressed) {
    if (detected_host_os() == OS_WINDOWS) {
      register_code(KC_LALT);
      tap_code(KC_LEFT);
      unregister_code(KC_LALT);
    } else {
      register_code(KC_LGUI);
      tap_code(KC_LEFT);
      unregister_code(KC_LGUI);
    }
    return false;
  }
  // スリープ
  if (keycode == TK_SLEP && record -> event.pressed) {
    tap_code16(LALT(LGUI(KC_EJCT)));
    return false;
  }
  // リセット
  if (keycode == TK_REST && record -> event.pressed) {
    clear_keyboard();
    // unregister_code(KC_LGUI);
    // unregister_code(KC_LCTL);
    // unregister_code(KC_LSFT);
    // unregister_code(KC_LALT);
    return false;
  }
  /*
  // ミッションコントロール
  if (keycode == TK_MCTL && record -> event.pressed) {
    if (detected_host_os() == OS_WINDOWS) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      tap_code(KC_TAB);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    } else {
      register_code(KC_LCTL);
      tap_code(KC_UP);
      unregister_code(KC_LCTL);
    }
    return false;
  }
  // 英数
 if (keycode == TK_EISU && record -> event.pressed) {
    if (detected_host_os() == OS_WINDOWS) {
      tap_code(KC_LNG2);
      tap_code(KC_F22);
    } else {
      tap_code(KC_LNG2);
    }
    return false;
  }
  // かな
 if (keycode == TK_KANA && record -> event.pressed) {
    if (detected_host_os() == OS_WINDOWS) {
      tap_code(KC_LNG1);
      tap_code(KC_F21);
    } else {
      tap_code(KC_LNG1);
    }
    return false;
  }
  // セミコロン、コロン
  if (keycode == TK_SCLN && record -> event.pressed) {
    bool shift = get_mods() & MOD_MASK_SHIFT;
    if (shift) {
      uint8_t mods = get_mods();  // 現在のModifierの状態を保存
      del_mods(MOD_MASK_SHIFT);   // Shiftを外す
      tap_code(KC_QUOT);          // コロン（del_modsによってShiftを外す）
      set_mods(mods);             // 元のModifier状態に戻す
    } else {
      tap_code(KC_SCLN);          // セミコロン
    }
    return false;
  }
  // プラス、アスタリスク
  if (keycode == TK_PLAS && record -> event.pressed) {
    bool shift = get_mods() & MOD_MASK_SHIFT;
    if (shift) {
      tap_code(KC_QUOT);          // アスタリスク
    } else {
      add_mods(MOD_MASK_SHIFT);   // Shiftを追加する
      tap_code(KC_SCLN);          // プラス（add_modsによってShiftを追加してセミコロンからプラスにしている）
      del_mods(MOD_MASK_SHIFT);   // Shiftを外す
    }
    return false;
  }
  */
  return true;
};

/************************************************************ その他 ************************************************************/
// キーごとにTAPPING_TERMを調整する
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // レイヤー0：左手中段
        case KC_C_ENT:
        case KC_CS_A:
        case KC_GS_S:
        case KC_A_D:
        case KC_C_F:
        case KC_G_G:
        // レイヤー0：右手中段
        case KC_C_MINS:
        case KC_CS_SCLN:
        case KC_GS_L:
        case KC_A_K:
        case KC_C_J:
        case KC_G_H:
            return TAPPING_TERM_LONG;
        case KC_S_EN:
        case KC_S_JP:
            return TAPPING_TERM_SHORT;
        default:
            return TAPPING_TERM;
    }
}

// キーごとにRETRO_TAPPINGを調整する
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // 以下のキーのみRETRO_TAPPINGを無効化する
        case KC_1_SPC:
        case KC_2_ENT:
            return false;
        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // _1と_2が同時に有効になった場合、_3を有効にする
    return update_tri_layer_state(state, _1, _2, _3);
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[0] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)}, [1] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}, [2] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}, [3] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}};
#endif
