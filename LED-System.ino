/* 
/ Name: LED system 
/ Description: LED controlling system for LED white strips for house bedroom (top) and living room (bottom)
/ Author : Richard Guerre
/ License : MIT License
*/

// Define all pins
const int top_LedPin = 3, top_SwitchPin = 2, bottom_LedPin = 5, bottom_SwitchPin = 4;
// initialize time variables
unsigned long top_PastTime = 0, top_TimeDifference = 0, bottom_PastTime = 0, bottom_TimeDifference = 0;
// initialize switch variables
int top_SwitchCounter, bottom_SwitchCounter;
int isTopSwitchActive = false, isBottomSwitchActive = false;
// initialize brightness variables;
const int low = 25, med = 110, high = 230;

void setup() {
  pinMode(top_LedPin, OUTPUT);
  pinMode(top_SwitchPin, INPUT_PULLUP);
  pinMode(bottom_LedPin, OUTPUT);
  pinMode(bottom_SwitchPin, INPUT_PULLUP);

  // analogWrite(top_LedPin, 0);
  // analogWrite(bottom_LedPin, 0);
  
  // Serial.begin(9600);
  // Serial.print("start \n");
  // TODO: Initialize varialbes here ??
  
  bottom_SwitchCounter = 0;
}

void loop() {
  bottom_PastTime = millis();
  delay(20);
  if(digitalRead(bottom_SwitchPin) == LOW){
    delay(680);
  }
  if(digitalRead(bottom_SwitchPin) == LOW){
    delay(200);
  }

  bottom_TimeDifference = millis() - bottom_PastTime;
  // Serial.print("timeDifference: ");
  // Serial.print(bottom_TimeDifference);
  // Serial.print("\n");

  if(bottom_TimeDifference >= 50 && bottom_TimeDifference < 800){
    bottom_SwitchCounter = (bottom_SwitchCounter + 1) % 4;
    switch(bottom_SwitchCounter){
      case 0:
        analogWrite(bottom_LedPin, 0);
        break;
      case 1:
        analogWrite(bottom_LedPin, low);
        break;
      case 2:
        analogWrite(bottom_LedPin, med);
        break;
      case 3:
        analogWrite(bottom_LedPin, high);
        break;
      default:
        analogWrite(bottom_LedPin, 0);
        break;
    }
  } else if(bottom_TimeDifference >= 800){
    analogWrite(bottom_LedPin, 0);
    bottom_SwitchCounter = 4;
    delay(2000);
  }

  top_PastTime = millis();
  delay(20);
  if(digitalRead(top_SwitchPin) == LOW){
    delay(680);
  }
  if(digitalRead(top_SwitchPin) == LOW){
    delay(200);
  }

  top_TimeDifference = millis() - top_PastTime;
  // Serial.print("timeDifference: ");
  // Serial.print(top_TimeDifference);
  // Serial.print("\n");

  if(top_TimeDifference >= 50 && top_TimeDifference < 800){
    top_SwitchCounter = (top_SwitchCounter + 1) % 4;
    switch(top_SwitchCounter){
      case 0:
        analogWrite(top_LedPin, 0);
        break;
      case 1:
        analogWrite(top_LedPin, low);
        break;
      case 2:
        analogWrite(top_LedPin, med);
        break;
      case 3:
        analogWrite(top_LedPin, high);
        break;
      default:
        analogWrite(top_LedPin, 0);
        break;
    }
  } else if(top_TimeDifference >= 800){
    analogWrite(top_LedPin, 0);
    top_SwitchCounter = 4;
    delay(2000);
  }
}
