//NOT USED BUT WAS JUST IN CASE WE NEEDED REMOVABLE ON-BOARD DATA LOGGING

//#define DEBUG //enables Serial.print

#ifdef DEBUG
  #define DEBUG_PRINT(msg) Serial.println(msg)
#else
  #define DEBUG_PRINT(msg)
#endif

#include <Wire.h>
#define address 0x50 //please read the datasheet for your i2c EEPROM chip to get this information
#define EEPROMsize 4096 //please read the datasheet for your i2c EEPROM chip to get this information

void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data ) {
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();
  delay(5);
}
 
byte readEEPROM(int deviceaddress, unsigned int eeaddress ) {
  byte rdata = 0xFF;
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(deviceaddress,1);
  if (Wire.available()) rdata = Wire.read();
  return rdata;
}

// dump EEPROM to serial
void dumpEEPROM() {
  DEBUG_PRINT("Dumping EEPROM");
  for(int i = 0; i < EEPROMsize; i++) {
    Serial.println(readEEPROM(address,i));
  }
  DEBUG_PRINT("EEPROM dumped!");
}

void wipeEEPROM(){
  DEBUG_PRINT("Deleting EEPROM"
  for(int i = 0; i < EEPROMsize; i++) {
    writeEEPROM(address,i,0);
  }
  DEBUG_PRINT("EEPROM erased!");
}
