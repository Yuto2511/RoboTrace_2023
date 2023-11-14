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

### パーツ一覧

#### CPU
- CPU : [STM32F405RGT6](https://www.stmcu.jp/stm32/stm32f4/stm32f405415/12229/)

#### 電源

#### モータ

#### センサ

#### その他

### 回路図

## プログラム

