
// --- for SD-Updater -----
// -----------------------------------------------------------
#include <Arduino.h>
#include <SD.h>
#include <M5Unified.h>
#include <ESP32-targz.h>
#include <M5StackUpdater.h>
#define TFCARD_CS_PIN 4

const String PROG_NAME = "StackChan-Radiko";
#define SDU_SKIP_TMR 5000 // skip timer : ms

void SDU_lobby();
void SDU_fromSD();
void SDU_saveBin(String flname);

void SDU_lobby()
{
  SDUCfg.setAppName(PROG_NAME.c_str()); // lobby screen label: application name
  SDUCfg.setLabelMenu("< Menu");       // BtnA label: load menu.bin

  checkSDUpdater(
      SD,           // filesystem (default=SD)
      MENU_BIN,     // path to binary (default=/menu.bin, empty string=rollback only)
      SDU_SKIP_TMR, // wait delay, (default=0, will be forced to 2000 upon ESP.restart() )
      TFCARD_CS_PIN // usually default=4 but your mileage may vary
  );

  Serial.println("SDU_lobby done");
}

void SDU_fromSD()
{
  updateFromFS(SD);
}

void SDU_saveBin(String flname)
{
  if (!flname.startsWith("/"))
    flname = "/" + flname;

  Serial.println("save to sdupdater bin file in SD : " + flname);
  delay(50);

  saveSketchToFS(SD, flname.c_str());
  Serial.println("save done");
}
// -----------------------------------------------------------

void SDU_disp()
{
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextDatum(0);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.fillScreen(BLACK);

  M5.Lcd.print( "**  SD-Updater  **\n\n");
  M5.Lcd.print( PROG_NAME.c_str());
  M5.Lcd.print("\n\n\nBtnA: lobby screen appear\n\n");
  M5.Lcd.print("BtnB: load menu binary\n\n");
  M5.Lcd.print("BtnC: store BIN file to SD\n");
}


