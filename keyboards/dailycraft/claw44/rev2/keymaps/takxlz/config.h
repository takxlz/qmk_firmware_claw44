#pragma once

// RDPでS(xxx)が効かない問題の対処
#define TAP_CODE_DELAY 10
#define USB_POLLING_INTERVAL_MS 5

#define MASTER_LEFT

#define TAPPING_TERM 180
#define TAPPING_TERM_LONG 195
#define TAPPING_TERM_SHORT 100
#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING_PER_KEY
#define RETRO_TAPPING
#define RETRO_TAPPING_TERM 1000
// #define IGNORE_MOD_TAP_INTERRUPT  // *QMKのデフォルトの挙動となり、設定しているとエラーになるで削除

// オートリピートをOFFにする
// #define TAPPING_FORCE_HOLD

// レイヤー数
#define DYNAMIC_KEYMAP_LAYER_COUNT 4