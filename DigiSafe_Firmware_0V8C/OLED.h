// ANYTHING THAT REQUIRES THE SCREEN TO PRINT/UPDATE GOES HERE

//#define DEBUG //enables Serial.print

#ifdef DEBUG
  #define DEBUG_PRINT(msg) Serial.println(msg)
#else
  #define DEBUG_PRINT(msg)
#endif

#include <Wire.h> //i2c library
#include <Adafruit_GFX.h> //OLED graphics/text library
#include <Adafruit_SSD1306.h> //OLED driver
#include "AUTOTYPE.h"

Adafruit_SSD1306 display(0); // hardware display reset, unused pin 0

void displaySetup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // turn on OLED internal boost converter
  display.display(); // show Adafruit splash
  delay(1000);
  display.clearDisplay();
  display.setTextColor(WHITE); //draw splash screen
  display.setCursor(0,0);
  display.setTextSize(2);
  display.print("D");
  display.setCursor(12,7);
  display.setTextSize(1);
  display.print("IGI   AFE");
  display.setCursor(70,0);
  display.print("TM");
  display.setCursor(24,0);
  display.setTextSize(2);
  display.print(" S");
  //display.setCursor(0,24);
  display.setTextSize(1);
  //display.print("scan QR code");
  display.display(); // write OLED RAM to display
  delay(1000);
}

//this is for the purpose of the project to easily switch between sort methods on startup
void displaySortMenu(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Alphabetical >");
  display.setCursor(0,24);
  display.print("Popularity   >");
  display.display();
}

void printAccountName(byte selected){
  if(sortMode){
    display.print(accountList[accountRank[selected]][0]);
  }
  else{
    display.print(accountList[selected][0]);
  }
}

//print the Account Menu screen to the display
void displayAccountList(byte selected) {
  DEBUG_PRINT("AccountList");
  DEBUG_PRINT(selected);
  display.clearDisplay();
  
  for(byte index=selected-1, linePX=0, line=0; index<selected+2; index++, linePX+=12, line++){
    display.setCursor(0,linePX);
    if(line == 1){
      display.setTextColor(BLACK,WHITE);
    }
    else {
      display.setTextColor(WHITE);
    }
    printAccountName(index);
    // draw scrollbar and battery level
    display.setCursor(120,linePX);
    if(index!=0 && line==0){
      display.print("|");
    }
    else if (line==0){
      display.setCursor(80,linePX);
      display.print("0.00");//Voltage();
    }
    if(index!=accounts+1 && line==2){
      display.print("|");
    }
    if(line==1){
      display.setTextColor(WHITE);
      display.setCursor(120,linePX);
      display.print(">");
    }
  }
  display.display();
}

//acount delete confirmation
/*void menuAccountDelete(byte selected){
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Delete Account?");
  display.setCursor(0,12);
  printAccountName(selected);
  display.setCursor(110,0);
  display.print("YES");
  display.setCursor(110,12);
  display.print("NO");
  display.display();
}*/

//swap selected account index with previous index
void rankUpdate(byte selected){
  if(selected != 1){ //first account doesn't need to be swapped
    //typical swap
    byte temp = accountRank[selected];
    accountRank[selected]=accountRank[selected-1];
    accountRank[selected-1] = temp;
  }
}

//print account sub menu
//TODO: digitalRead() button stuff should be moved to main, Work in Progress
byte displayAccountMenu(byte selected) {
//void displayAccountMenu(byte selected) {
  DEBUG_PRINT("AccountMenu");
  DEBUG_PRINT(selected);
  display.clearDisplay();
  display.setCursor(0,0);
  printAccountName(selected);
  display.setCursor(80,0);
  display.print("BACK");
  display.setCursor(80,12);
  display.print("ACCESS");
  //DELETING DISABLED
  /*display.setCursor(80,24);
  display.print("DELETE");*/
  display.display();
  delay(250);
  while(true){
    //if(upButton()) {
    if(digitalRead(4) == HIGH){
      delay(250);
      break;
    }
    //if(selectButton()) {
    if(digitalRead(5) == HIGH){
      display.clearDisplay();
      display.setCursor(0,12);
      if(digitalRead(13) == HIGH) { //check if plugged in (disable to use micro port)
        display.print("Logging In");
        display.display();
        if(sortMode){ //check if account indexing is popularity or alphabetical
          printKeys(accountRank[selected]);
          rankUpdate(selected); //update popularity
        }
        else{
          printKeys(selected);
        }
        selected = 1; // reset menu back to first account index
      }
      else{
        display.print("Error: No Host");
        display.display();
      }
      delay(1000);
      break;
    }
    /* //DELETING DISABLED
    //if(downButton()) {
    if(digitalRead(6) == HIGH){
      delay(250);
      menuAccountDelete(selected);
      while(true){
        //if(upButton()) {
        if(digitalRead(4) == HIGH){
          delay(250);
          //Serial.println("YES");
          break;
        }
        //if(selectButton()) {
        if(digitalRead(5) == HIGH){
          delay(250);
          //Serial.println("NO");
          break;
        }
        //if(downButton()) {
        if(digitalRead(6) == HIGH){
          delay(250);
          //Serial.println("null");
          break;
        }
      }
      break;
    }*/
  }
  return selected;
}

void displayOff(){
  display.clearDisplay();
  display.display();
}

void displayAlert(char msg[]){
  display.clearDisplay();
  display.setCursor(0,12);
  display.print(msg);
  display.display();
}
