//ANYTHING THAT REQUIRES USING THE KEYBOARD (HID) PROTOCOL GOES HERE

#include "Keyboard.h"

void printKeys(byte accountNumber){
  Keyboard.print(accountList[accountNumber][1]); //username
  delay(50);
  Keyboard.press(KEY_TAB); 
  Keyboard.release(KEY_TAB);
  delay(50);
  Keyboard.print(accountList[accountNumber][2]); //password
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
}
