// Date and time functions using a DS3231 RTC connected via I2C and Wire library
// Project currently does not use this, 

//#define DEBUG //enables Serial.print

#ifdef DEBUG
  #define DEBUG_PRINT(msg) Serial.println(msg)
#else
  #define DEBUG_PRINT(msg)
#endif

#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

void setupRTC () {
  if (! rtc.begin()) {
    DEBUG_PRINT("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower() || digitalRead(4) == HIGH) {
    DEBUG_PRINT("RTC lost power or manual override, SETTING TIME");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void printDate () {
  DateTime now = rtc.now();
  DEBUG_PRINT("DATE");
  DEBUG_PRINT(now.year());
  DEBUG_PRINT(now.month());
  DEBUG_PRINT(now.day());
}

void printTime(){
  DateTime now = rtc.now();
  DEBUG_PRINT("TIME");
  DEBUG_PRINT(now.hour());
  DEBUG_PRINT(now.minute());
  DEBUG_PRINT(now.second());
}
