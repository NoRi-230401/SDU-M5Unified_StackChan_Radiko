# SDU-M5Unified_StackChan_Radiko


SD-Updaterに対応したスタックチャンRadikoです。
robo8080さんのソフトから次の修正を行いました。

- SD-Updater対応。
- WiFi設定は、SD直下のwifi.txt　ファイルでおこなう。<br>
- サーボ設定は、SD直下の servo.txtファイルでおこなう。<br>
- ボタン押下時のbeepを消音に変更。<br>
<br>

ブート時に、SD_Updater用の画面が立ち上がります。<br>
SDに入れたソフトを切り替えることができるようになります。
<br><br>

## 設定ファイル
### WiFi設定 "wifi.txt"
robo8080さんのAiStackChan2の設定ファイル"wifi.txt"を使用できるようにしました。</b><br>
各自の設定に合わせてSD直下に"wifi.txt"の名前で保存してください。<br>
- １行目：WiFi_SSID<br>
- ２行目：WiFi_SSID_PASSWD<br>
<br>
<br>

### Servo設定　"servo.txt"<br>
Servo設定ファイル<br>
- １行目(USE_SERVO)   ： "on" または、 "off"<br>
- ２行目(SERVO_PIN_X) ： "13"(PortC)　または、"33"(PortA)<br>
- ３行目(SERVO_PIN_Y) ： "14"(PortC)　または、"32"(PortA)<br>


サンプルを用意しています。ファイル名を"servo.txt"に変更してご使用ください。<br>
<br>
<br><br>

ソフトの操作方法は、下記のソフトを参照してください。
<br>

## 基のリポジトリ
- [M5Unified_StackChan_Radiko (robo8080さん)](https://github.com/robo8080/M5Unified_StackChan_Radiko)<br><br>

<br>

## 対応ハードウエア
・M5Stack Core2 for AWS<br>
・M5Stack Core2 <br>
・M5Stack Core2 v1.1　（未確認）<br>
<br>
<br>
## 最新BINの取得
コンパイル済みの最新BINファイルは、下記のリポジトリから取得できます。
- [BinsPack-for-StackChan-Core2](https://github.com/NoRi-230401/BinsPack-for-StackChan-Core2)<br>

<br><br>



## SD-Updaterについて
tobozoさん開発。SDに複数のBINファイルを入れて、ソフトを切替えて使用できるようになります。<br>

 https://github.com/tobozo/M5Stack-SD-Updater<br><br>


タカオさん、2023/7/29 ｽﾀｯｸﾁｬﾝ お誕生日会 2023のLTで、M5Stack-SD-Updaterの概要を説明した時のスライド<br>
https://speakerdeck.com/mongonta0716/sutatukutiyandefu-shu-apuriwoqie-riti-erutekunituku

<br><br><br>

