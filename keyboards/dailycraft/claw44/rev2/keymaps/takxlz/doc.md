### ビルド
make dailycraft/claw44:takxlz

### 書き込み
make dailycraft/claw44:takxlz:flash

# QMKファームウェア構築方法の比較  
foostan / Yowkees / dailycraft の違い

---

## 1. リポジトリの位置づけの違い

| リポジトリ | 位置づけ・目的 | 特徴 |
|------------|----------------|------|
| foostan/kbd_firmware | QMK/Vial を内包するラッパー型ファームウェア管理リポジトリ | サブモジュール管理、makeラッパー、crkbd特化 |
| Yowkees/keyball | 標準QMK環境にKeyball定義を追加して使う方式 | 標準QMKフローでビルド可能 |
| dailycraft/qmk_firmware | QMK本体をDailyCraft向けにforkした専用版QMK | 専用QMKとして単体使用可能 |

---

## 2. ビルド環境構築の流れの違い

### ■ foostan/kbd_firmware（ラッパー型）

```
git clone https://github.com/foostan/kbd_firmware
cd kbd_firmware
make git-submodule
```

ビルド例：

```
kb=crkbd kr=rev4_1/standard km=via make qmk-compile
make vial-qmk-compile kb=crkbd km=vial
```

特徴：
- QMK/Vial をサブモジュールとして内包
- makeコマンドが独自ラッパー形式
- リポジトリ内ですべて完結

---

### ■ Yowkees/keyball（標準QMK拡張型）

```
git clone https://github.com/qmk/qmk_firmware.git
git clone https://github.com/Yowkees/keyball.git
mv keyball/qmk_firmware/keyboards/keyball/ qmk_firmware/keyboards/
```

ビルド例：

```
cd qmk_firmware
make keyball44:default
qmk compile -kb keyball44 -km default
```

特徴：
- 公式QMKをそのまま使用
- キーボード定義のみ追加して使う
- 標準QMKの構造や流儀を理解するのに向く

---

### ■ dailycraft/qmk_firmware（専用QMK型）

```
git clone https://github.com/dailycraftkeyboard/qmk_firmware.git
cd qmk_firmware
git checkout dailycraft-0.22
```

ビルド例：

```
make dailycraft/claw44/rev2:default
make dailycraft/claw44/rev2:via
```

特徴：
- QMK本体そのものがDailyCraft専用にカスタマイズ済み
- Claw44 / Wings42 など複数モデルを標準で内包
- 標準QMK形式のままビルド可能（ラッパー不要）

---

## 3. ビルド方式の特徴比較

| 観点 | foostan | Yowkees | dailycraft |
|------|---------|---------|------------|
| QMK本体 | サブモジュール内包 | 公式QMKを別途clone | QMK本体fork構成 |
| 定義追加 | 内包済み | 手動コピー | 内包済み |
| ビルド方式 | 独自makeラッパー | 標準QMK | 標準QMK |
| VIA対応 | 強い | 要設定 | 強い |
| 学習性 | △ | ◎ | ○ |
| 実用性 | ○ | △ | ◎ |

---

## 4. 用途別のおすすめ

| 利用目的 | 適したリポジトリ |
|----------|------------------|
| 標準QMKの学習・理解 | Yowkees |
| Claw44やWings42専用で使いたい | dailycraft |
| Corne用で完結させたい | foostan |
| VIAで柔軟に運用したい | dailycraft or foostan |
| 自分でQMKを改造したい | dailycraft |

---

## 5. 一言まとめ

| リポジトリ | 一言でいうと |
|------------|--------------|
| foostan | Corne専用のファームウェア管理セット |
| Yowkees | 標準QMKにKeyball定義を足して使う方式 |
| dailycraft | DailyCraft向けに調整された専用QMK本体 |

---
