// DigiSafe
// version: 0.8C on December 4, 2018
// by: Marvin Mallari
// email: marvin.mallari.912@my.csun.edu
// email: silentdreamcast@gmail.com

/* ==================== ABOUT ====================
 * DigiSafe is an offline password storage device
 * A finite number of accounts can be stored on the device in secure memory that can self destruct if physically tampered or firmware is modified
 * Accounts are accessed through a 128x32 pixel OLED screen and 3 buttons
 * Once unlocked, username and password is automatically typed into your computer via virtual keyboard.
 * Future TODOs are memory implementation, AES encryption finalizing (removed for this project), Biometric authentication, Key generator
 */

//#define DEBUG //enables Serial.print

#ifdef DEBUG
  #define DEBUG_PRINT(msg) Serial.println(msg)
#else
  #define DEBUG_PRINT(msg)
#endif

#include "ACCOUNTS.h"
#include "OLED.h"
#include "RTC.h"
#include "INPUTS.h"
#include "intEEPROM.h"

unsigned long previousMillis = 0;
const unsigned long sleep = 10000; //sleep timer delay
boolean displayUpdate = true;
boolean displaySleep = false;
byte selected = 1;

//runs once at power up
void setup() {
  displaySetup();
  Serial.begin(11520); // enable USB UART for debug
  setupInputs();
  setupRTC(); // program DS3231 Real Time Clock if no time set
  Keyboard.begin();
  DEBUG_PRINT("setup complete");
  displaySortMenu();
  
  while(true){ //wait for until a sort option is chosen
    if(downButton()){
      sortMode = true;
      displayAlert("Loading List");
      reload();
      delay(1000);
      break;
    }
    else if(upButton()){
      break;
    }
  }
  delay(250); // basic button debounce
}

//runs forever after setup
void loop() {
  unsigned long currentMillis = millis();

  //watch buttons and update screen if necessary
  if(upButton() && downButton() && sortMode){ // this should happen automatically in the future but is manual for now
    displayAlert("Saving List");
    save();
    displayAlert("Done");
    delay(1000);
    displayUpdate = true;
  }
  if(upButton() && selectButton()){
    //something
  }
  if(upButton() && !displayUpdate && selected>1) {
    selected--;
    displayUpdate = true;
  }
  if(selectButton() && !displayUpdate) {
    selected = displayAccountMenu(selected);
    //selected is updated in case we need to reset index or stay, depending on action of displayAccountMenu()
    displayUpdate = true;
  }
  if(downButton() && !displayUpdate && selected<accounts) {
    selected++;
    displayUpdate = true;
  }

  // print main menu
  if(displayUpdate) {
    DEBUG_PRINT("SELECTED: ");
    DEBUG_PRINT(selected);
    displaySleep = false;
    previousMillis = currentMillis;
    displayAccountList(selected);
    displayUpdate = false;
    delay(250); // basic button debounce
  }

  // put display to sleep after set inactivity
  if(currentMillis - previousMillis >= sleep){
    if(!displaySleep){
      DEBUG_PRINT("display is sleeping");
      displayOff();
      displaySleep = true; //don't send sleep command after already asleep, saves power
    }
  }

  // reminder to log out of account after unplugging, NOT IMPLEMENTED
}
