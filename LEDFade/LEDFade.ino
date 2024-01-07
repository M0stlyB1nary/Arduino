/*
 Fade
 RL: Expanded to also use led 10.
 */

int ledRed = 11;// the pin that the LED is attached to
int ledYellow = 10;
int brightnessRed = 0;    // how bright the LED is
int fadeAmountRed = 5;    // how many points to fade the LED by

int brightnessYello = 255;    // how bright the LED is
int fadeAmountYello = -5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop() {
  // set the brightness of pin 9:
  analogWrite(ledRed, brightnessRed);

  // change the brightness for next time through the loop:
  brightnessRed = brightnessRed + fadeAmountRed;

  // reverse the direction of the fading at the ends of the fade:
  if (brightnessRed == 0 || brightnessRed == 255) {
    fadeAmountRed = -fadeAmountRed ;
  }

// Yellow LED
    // set the brightness of pin 10:
  analogWrite(ledYellow, brightnessYello);

  // change the brightness for next time through the loop:
  brightnessYello = brightnessYello + fadeAmountYello;

  // reverse the direction of the fading at the ends of the fade:
  if (brightnessYello == 0 || brightnessYello == 255) {
    fadeAmountYello = -fadeAmountYello ;
  }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(10);
}

