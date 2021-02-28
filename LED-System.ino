/* 
/ Name: LED system
/ Description: LED controlling system for LED white strips for house bedroom (top) and living room (bottom)
/ Author: Richard Guerre
/ License: MIT License
*/

// Define all pins
const int
    top_LedPin = 3,
    top_SwitchPin = 2,
    bottom_LedPin = 5,
    bottom_SwitchPin = 4;
// initialize time variables
unsigned long
    top_PastTime = 0,
    top_TimeDifference = 0,
    bottom_PastTime = 0,
    bottom_TimeDifference = 0;
// initialize switch variables
int top_SwitchCounter, bottom_SwitchCounter;
// initialize brightness variables;
const int base = 255;
const int low = 0.05 * base, med = 0.3 * base, high = 0.9 * base;

void setup()
{
  pinMode(top_LedPin, OUTPUT);
  pinMode(top_SwitchPin, INPUT_PULLUP);
  pinMode(bottom_LedPin, OUTPUT);
  pinMode(bottom_SwitchPin, INPUT_PULLUP);

  analogWrite(top_LedPin, 0);
  analogWrite(bottom_LedPin, 0);

  // Serial.begin(9600);
  // Serial.print("start \n");

  top_SwitchCounter = 0;
  bottom_SwitchCounter = 0;
}

void loop()
{
  updateSystem(bottom_SwitchPin, bottom_LedPin, bottom_PastTime, bottom_TimeDifference, bottom_SwitchCounter);
  updateSystem(top_SwitchPin, top_LedPin, top_PastTime, top_TimeDifference, top_SwitchCounter);
}

void updateSystem(uint8_t switchPin, uint8_t ledPin, unsigned long &pastTime, unsigned long &timeDiff, int &counter)
{
  pastTime = millis();
  delay(20);
  if (digitalRead(switchPin) == LOW)
  {
    delay(40);
  }
  if (digitalRead(switchPin) == LOW)
  {
    delay(80);
  }
  if (digitalRead(switchPin) == LOW)
  {
    delay(160);
  }
  if (digitalRead(switchPin) == LOW)
  {
    delay(320);
  }
  if (digitalRead(switchPin) == LOW)
  {
    delay(200);
  }

  timeDiff = millis() - pastTime;
  // Serial.print("timeDifference: ");
  // Serial.print(timeDiff);
  // Serial.print("\n");

  if (timeDiff >= 50 && timeDiff < 700)
  {
    counter = (counter + 1) % 4;
    switch (counter)
    {
    case 0:
      fade(ledPin, high, 0);
      break;
    case 1:
      fade(ledPin, 0, low);
      break;
    case 2:
      fade(ledPin, low, med);
      break;
    case 3:
      fade(ledPin, med, high);
      break;
    default:
      fade(ledPin, high, 0);
      break;
    }
  }
  else if (timeDiff >= 700)
  {
    analogWrite(ledPin, 0);
    counter = 4;
    delay(700);
  }
}

void fade(uint8_t pin, int from, int to)
{
  int fadeDelay = 5;
  log("start fade");
  if (from < to)
  {
    for (int i = from; i <= to; i++)
    {
      analogWrite(pin, i);
      delay(fadeDelay);
    }
  }
  else
  {
    for (int i = from; i >= to; i--)
    {
      analogWrite(pin, i);
      delay(fadeDelay);
    }
  }
  log("end fade");
}

void logLine(String s)
{
  String line = "-------------";
  log(line + s + line);
}

void log(String s)
{
  Serial.println(s);
}
void log(int n)
{
  Serial.println(n);
}