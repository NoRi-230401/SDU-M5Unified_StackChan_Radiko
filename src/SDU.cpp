
// --- for SD-Updater -----
// -----------------------------------------------------------
#include <Arduino.h>
#include <WiFi.h>
#include <SD.h>
#include <M5Unified.h>
#include <ESP32-targz.h>
#include <M5StackUpdater.h>
#define TFCARD_CS_PIN 4

const String PROG_NAME = "StackChan-Radiko";
#define SDU_SKIP_TMR 5000 // skip timer : ms
#define WIFI_TXT "/wifi.txt"   // 

void SDU_lobby();

void SDU_lobby()
{
  SDUCfg.setAppName(PROG_NAME.c_str()); // lobby screen label: application name
  SDUCfg.setLabelMenu("< Menu");        // BtnA label: load menu.bin

  checkSDUpdater(
      SD,           // filesystem (default=SD)
      MENU_BIN,     // path to binary (default=/menu.bin, empty string=rollback only)
      SDU_SKIP_TMR, // wait delay, (default=0, will be forced to 2000 upon ESP.restart() )
      TFCARD_CS_PIN // usually default=4 but your mileage may vary
  );

  Serial.println("SDU_lobby done");
}

// #define WIFI_SSID "aterm-d5c4c3-g"
// #define WIFI_PASS "86c71a78ea6e1"
extern String SSID;
extern String SSID_PASS;
void Wifi_setup2();
bool wifiTxtSDRead();
bool SdBegin();

void Wifi_setup2()
{
  WiFi.disconnect();
  WiFi.softAPdisconnect(true);
  WiFi.mode(WIFI_STA);

  M5.Display.println("WiFi begin");
  Serial.println("WiFi begin");

  if (wifiTxtSDRead())
  {  
    Serial.println("wifi.txt read success ....");
    Serial.println("SSID = " + SSID);
    Serial.println("SSID_PASS = " + SSID_PASS);
    WiFi.begin(SSID, SSID_PASS);
  }
  else
  { 
    Serial.println("wifi.txt read fail .... ");
    WiFi.begin(); // 前回接続時情報で接続する
  }

  while (WiFi.status() != WL_CONNECTED)
  {
    M5.Display.print(".");
    Serial.print(".");
    delay(500);
    // 10秒以上接続できなかったら抜ける
    if (10000 < millis())
    {
      break;
    }
  }
  M5.Display.println("");
  Serial.println("");
  // 未接続の場合にはSmartConfig待受
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.mode(WIFI_STA);
    WiFi.beginSmartConfig();
    M5.Display.println("Waiting for SmartConfig");
    Serial.println("Waiting for SmartConfig");
    while (!WiFi.smartConfigDone())
    {
      delay(500);
      M5.Display.print("#");
      Serial.print("#");
      // 30秒以上接続できなかったら抜ける
      if (30000 < millis())
      {
        Serial.println("");
        Serial.println("Reset");
        ESP.restart();
      }
    }
    // Wi-fi接続
    M5.Display.println("");
    Serial.println("");
    M5.Display.println("Waiting for WiFi");
    Serial.println("Waiting for WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      M5.Display.print(".");
      Serial.print(".");
      // 60秒以上接続できなかったら抜ける
      if (60000 < millis())
      {
        Serial.println("");
        Serial.println("Reset");
        ESP.restart();
      }
    }
    M5.Display.println("");
    Serial.println("");
    M5.Display.println("WiFi Connected.");
    Serial.println("WiFi Connected.");
  }
  M5.Display.print("IP Address: ");
  Serial.print("IP Address: ");
  M5.Display.println(WiFi.localIP());
  Serial.println(WiFi.localIP());
}

bool wifiTxtSDRead()
{
  if (!SdBegin())
  {
    SD.end();
    return false;
  }

  File file = SD.open(WIFI_TXT, FILE_READ);
  if (!file)
  {
    SD.end();
    return false;
  }

  size_t sz = file.size();
  char buf[sz + 1];
  file.read((uint8_t *)buf, sz);
  buf[sz] = 0;
  file.close();

  int y = 0;
  for (int x = 0; x < sz; x++)
  {
    if (buf[x] == 0x0a || buf[x] == 0x0d)
      buf[x] = 0;
    else if (!y && x > 0 && !buf[x - 1] && buf[x])
      y = x;
  }

  SSID = String(buf);
  SSID_PASS = String(&buf[y]);

  if ((SSID == "") || (SSID_PASS == ""))
  {
    Serial.println("Fail : ssid or passwd is void ");
    SD.end();
    return false;
  }

  SD.end();
  return true;
}


bool SdBegin()
{
  // --- SD begin -------
  int i = 0;
  bool success = false;
  Serial.println("SD.begin Start ...");

  while (i < 3)
  { // SDカードマウント待ち
    // success = SD.begin(GPIO_NUM_4, SPI, 16000000,"/sd", 10, false);
    // success = SD.begin(GPIO_NUM_4, SPI, 15000000U, "/sd", 10U, false);
    // success = SD.begin(GPIO_NUM_4, SPI, 25000000U);
    success = SD.begin(GPIO_NUM_4, SPI, 15000000U);

    if (success)
      return true;

    Serial.println("SD Wait...");
    delay(500);
    i++;
  }

  if (i >= 3)
  {
    Serial.println("SD.begin faile ...");
    return false;
  }
  else
    return true;
}
