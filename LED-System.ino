/* 
/ Name: LED system 
/ Description: LED controlling system for LED white strips for house bedroom (top) and living room (bottom)
/ Author : Richard Guerre
/ License : MIT License
*/

// Define all pins
const int top_LedPin = 3, top_SwitchPin = 4, bottom_LedPin = 5, bottom_SwitchPin = 6;
// initialize time variables
int top_PastTime = 0, top_TimeDifference = 0, bottom_PastTime = 0, bottom_TimeDifference = 0;
// initialize counter variables for switch
int top_SwitchCounter = 0, bottom_SwitchCounter = 0;
// initialize brightness variables;
const int low = 25, med = 120, high = 230;

void setup() {
  pinMode(top_LedPin, OUTPUT);
  pinMode(top_SwitchPin, INPUT);
  pinMode(bottom_LedPin, OUTPUT);
  pinMode(bottom_SwitchPin, INPUT);

  // TODO: Initialize varialbes here ??
}

void loop() {
  if(digitalRead(bottom_SwitchPin)){
  
  }
  if(digitalRead(top_SwitchPin)){
    
  }

  bottom_TimeDifference = millis() - bottom_PastTime;
  top_TimeDifference = millis() - top_PastTime;

  if(bottom_TimeDifference < 700){
    bottom_SwitchCounter = ++bottom_SwitchCounter % 4;
    switch(bottom_SwitchCounter){
      case 1:
        analogWrite(bottom_LedPin, 25);
        break;
      case 2:
        analogWrite(bottom_LedPin, 25);
        break;
      case 3:
        analogWrite(bottom_LedPin, 25);
        break;
      default:
        analogWrite(bottom_LedPin, 25);
        break;
    }
  } else if(){
    bottom_SwitchCounter = 0;
    analogWrite(bottom_LedPin, 0);
  }

  // TODO: top floor
}
