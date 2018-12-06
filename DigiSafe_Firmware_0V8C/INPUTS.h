// FOR BUTTONS AND SENSORS

#define up 4
#define select 5
#define down 6
#define battery A5
const unsigned long supplyVoltage = 4.24;
const unsigned long fullBattery = 4.2;
const unsigned long deadBattery = 3.3;

void setupInputs(){
  pinMode(up, INPUT);
  pinMode(select, INPUT);
  pinMode(down, INPUT);
  pinMode(13, INPUT); //used as USB power monitor
}

boolean upButton(){
  if(digitalRead(up) == HIGH){
    return true;
  }
  return false;
}

boolean selectButton(){
  if(digitalRead(select) == HIGH){
    return true;
  }
  return false;
}

boolean downButton(){
  if(digitalRead(down) == HIGH){
    return true;
  }
  return false;
}

boolean plugged(){
  if(digitalRead(13) == HIGH){
    return true;
  }
  return false;
}

float batteryVoltage(){ 
  unsigned int sense = analogRead(battery);
  float voltage = sense*(supplyVoltage/1023.00);
  return voltage;
}

byte batteryPercent(float voltage){
  byte percent = map(voltage,deadBattery,fullBattery,0,100);
  return percent;
}
