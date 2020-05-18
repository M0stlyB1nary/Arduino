/*
RL: 05/03/2020

HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 12 
Trig to Arduino pin 13
test
More info: https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380

4 digit display: https://github.com/adafruit/Adafruit_LED_Backpack/blob/master/examples/clock_sevenseg_ds1307/clock_sevenseg_ds1307.ino
Tutorial: https://learn.adafruit.com/adafruit-led-backpack/0-dot-56-seven-segment-backpack-arduino-setup

Wiring:
  Arduino A4 (SDA) to HT16k33 SDA
  Arduino A5 (SCL) to HT16k33 SCL
  POS to 5V
  GND to GND
*/


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <RTClib.h>
#include <Adafruit_LEDBackpack.h>

// Distiance sensor 
const int trigPin = 13;
const int echoPin = 12;
float duration, distance;

// Display **
Adafruit_7segment matrix = Adafruit_7segment();

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 1000;  //the value is a number of milliseconds

void setup() {
  Serial.begin(9600);
  Serial.println("\nStartup");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  matrix.begin(0x70);
  startMillis = millis();  //initial start time
}

void loop() {
  currentMillis = millis();

// Distance loop:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = ((duration*.0343)/2)/2.54; 
  //converted cm to inches (/2.54
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 4)
  {
    
  }
  matrix.print(distance);
  matrix.writeDisplay();
  delay(250);


  // Loop function runs over and over again to implement the clock logic.
  // print a floating point 
//  matrix.print(12.34);
//  matrix.writeDisplay();
//  delay(500);

   // print with print/println
//  for (uint16_t counter = 0; counter < 9999; counter++) {
//    matrix.println(counter);
//    matrix.writeDisplay();
//    delay(10);
//  }

}
