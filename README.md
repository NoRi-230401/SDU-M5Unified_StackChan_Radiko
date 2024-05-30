# SDU-M5Unified_StackChan_Radiko


SD-Updaterに対応したスタックチャンRadikoです。
robo8080さんのソフトから次の修正を行いました。

- SD-Updater対応。
- SD直下のwifi.txt でWiFi設定をするように修正。
- ボタン押下時のbeepを消音に変更。
- サーボ動作は、OFFです。

ブート時に、SD_Updater用の画面が立ち上がります。<br>
SDに入れたソフトを切り替えることができるようになります。<br>

WiFiの設定は、robo8080さんのAiStackChan2で使用している"wifi.txt"をそのまま使用できます。<br>
各自の設定に合わせてSD直下に"wifi.txt"の名前で保存してください。<br>
- １行目：WiFi_SSID<br>
- ２行目：WiFi_SSID_PASSWD<br>

起動後のソフトの操作方法は、下記のソフトの参照してください。



## 基のリポジトリ
- [M5Unified_StackChan_Radiko (robo8080さん)](https://github.com/robo8080/M5Unified_StackChan_Radiko)「MIT License」<br><br>


## 対応ハードウエア
・M5Stack Core2 for AWS<br>
・M5Stack Core2 <br>
・M5Stack Core2 v1.1　（未確認）<br><br>

## 最新BINの取得
このソフトをコンパイルした最新のBINファイルは、下記のリポジトリよりダウンロードできるようにしました。
- [BinsPack-for-StackChan-Core2](https://github.com/NoRi-230401/BinsPack-for-StackChan-Core2)<br><br>


## SD-Updaterについて
tobozoさん開発。SDに複数のBINファイルを入れて、ソフトを切替えて使用できるようになります。<br>

 https://github.com/tobozo/M5Stack-SD-Updater<br><br>


