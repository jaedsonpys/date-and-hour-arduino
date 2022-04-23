#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DS1302.h>

const int lcdEnd = 0x27;

DS1302 rtc(2,3,4);
LiquidCrystal_I2C lcd(lcdEnd, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  rtc.halt(false);
  rtc.writeProtect(false);

//  rtc.setTime(23, 19, 00);
//  rtc.setDate(21, 04, 2022);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDateStr());
  delay(1000);
  lcd.clear();
}
