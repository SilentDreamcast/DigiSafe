// USED TO STORE POPULARITY RANKING FOR POWER CYCLE AND RESTORE ON BOOT

//#define DEBUG //enables Serial.print

#ifdef DEBUG
  #define DEBUG_PRINT(msg) Serial.println(msg)
#else
  #define DEBUG_PRINT(msg)
#endif

#include <EEPROM.h>

void save() {
  for(byte i = 0; i < accounts+2; i++) {
    EEPROM.write(i,accountRank[i]);
    delay(5);
  }
  DEBUG_PRINT("Saving Finished");
}

void reload(){
  for(byte i = 0; i < accounts+2; i++) {
    accountRank[i] = EEPROM.read(i);
    delay(5);
  }
  DEBUG_PRINT("Load Finished");
}
