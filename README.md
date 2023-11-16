# RoboTrace_2023

2023年に製作するロボトレーサーのリポジトリ(見返すためのメモ)  

## Technical data

### CPU 
ARM系 / STmicro stm32f405

### バッテリー
CPU,モータ共用  
Lipo / 3セル / -[v] / -[mAh] / -  

### モータ
- 走行用　DCモータ : 2[個] / maxon DCX10L  
- 走行以外 DCモータ : 1[個] / maxon DCX8M  
- モータドライバIC : DRV8874,DRV8876

### センサ
- 赤外線センサ : 6[個] / TEMT7100X01 / ラインセンサ(反射光AD変換)  
- 赤外線センサ : 2[個] / S7136 / サイドセンサ  
- ジャイロセンサ : 1[個] / ICM20649 / デジタル値出力型  
- エンコーダ : 2[個] / ENX 10 EASY  
- エンコーダ : 1[個] / ENX 8 MAG  

### サイズ
- -x-[mm]
- -[g]

### 動輪
4輪 / 直径27mm 幅　11mm

### 速度
- 直進最高速度 : -[m/s]
- 加速度 : -[m/s^2]
- 加速度 : -[m/s^2]

## 機械設計
### CAD
![RoboTrace_2023_aseembly](https://github.com/Yuto2511/RoboTrace_2023/assets/83150974/e4d29c2c-2e9d-4079-8f14-94e62b698d20)

### モータ
- 駆動輪 : DCX10L
- センサステア : DCX8M
- 吸引 : 8520モータ

### ギヤ
- 駆動輪
  - ピニオン : M0.3, Z-
  - 動輪ギヤ : M0.3, Z63
- センサステア
  - ピニオン : M0.5, Z10
  - [クラウンギヤ](https://www.tamiya.com/japan/products/15462/index.html) : M0.5, Z20
  - [スパーギヤ](https://www.tamiya.com/japan/products/15434/index.html) : M0.5, Z26

### その他
- フレーム : カーボン板(1mm)
- プリントパーツ : Onyx(Mark Two), -(光造形)
- シャフト : アルミ丸棒(4mm), ステンレス丸棒(3mm)
- ベアリング : 内径4mm外形7mm, 内径3mm外形6mm
- ねじ : M2, M2.6

## 回路設計

### 回路図
[回路図](https://github.com/Yuto2511/RoboTrace_2023/blob/main/RoboTrace_2023.pdf)

### パーツ一覧

#### CPU
- [STM32F405RGT6](https://www.stmcu.jp/stm32/stm32f4/stm32f405415/12229/)
- [クロック-DSC6021CI2](https://www.digikey.jp/ja/products/detail/microchip-technology/DSC6021CI2A-009S/8639204)

#### 電源
- [DC/DC-LXDC55FAAA-203](https://akizukidenshi.com/catalog/g/gM-09577/)
- [積層セラミックコンデンサ-4.7uF-50V](https://akizukidenshi.com/catalog/g/gP-15634/)
- [アルミ電解コンデンサ-100uF-16V](https://akizukidenshi.com/catalog/g/gP-17422/)
- [積層セラミックコンデンサ-2.2uF-35V](https://akizukidenshi.com/catalog/g/gP-16077/)
- [レギュレタ-NJU7223DL1](https://akizukidenshi.com/catalog/g/gI-03705/)
- [ショットキーバリアダイオード-MA10EB045](https://www.digikey.jp/ja/products/detail/kyocera-avx/MA10EB045/16580541?s=N4IgTCBcDaILYEMCMAGApgIxQFgKwgF0BfIA)
- [スライドスイッチ-1回路2接点](https://akizukidenshi.com/catalog/g/gP-13989/)

#### モータ
- [モータドライバ-DRV8874](https://www.mouser.jp/ProductDetail/Texas-Instruments/DRV8874QPWPRQ1?qs=mAH9sUMRCttZUT1myh3Itg%3D%3D)
- [モータドライバ-DRV8876](https://www.digikey.jp/ja/products/detail/texas-instruments/DRV8876PWPR/10270191)
- [積層セラミックコンデンサ-22pF-50V](https://akizukidenshi.com/catalog/g/gP-11626/)
- [アルミ電解コンデンサ-100uF-16V](https://akizukidenshi.com/catalog/g/gP-17422/)
- [FFCコネクタ-12極-0.5ピッチ](https://www.digikey.jp/ja/products/detail/molex/0527451297/3044841?s=N4IgTCBcDaILIHsA2BTAHgAgKxgOwBYsBaARjAE5cQBdAXyA)
- コネクタ-10極-1.27ピッチ
- [NchMOSFET-30V-5.7A](https://akizukidenshi.com/catalog/g/gI-14653/)
- [ショットキーバリアダイオード-40V-2A](https://akizukidenshi.com/catalog/g/gI-02073/)
- [積層セラミックコンデンサ-10uF-35V](https://akizukidenshi.com/catalog/g/gP-13336/)

#### センサ

#### その他・共通

## プログラム

