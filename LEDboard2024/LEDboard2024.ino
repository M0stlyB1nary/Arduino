// RL 12/4/2016
// Last Update 1/6/2024
// 60count LED strip
// Green wire: Pin 11
// Black wire: Pin 13
#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 
// If Permission is needed to update the sketch do this: sudo chmod a+rw /dev/ttyACM0

// How many leds are in the strip?
#define NUM_LEDS 60

// Data pin that led data will be written out over  Green Wire
#define DATA_PIN 11

// Clock pin only needed for SPI based chipsets when not using hardware SPI  Black wire
#define CLOCK_PIN 13

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
    FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

// Red is Blue
// Blue is Red
// Main Program function
void loop() { 
  int interval = 80;
  topBarSpread(interval, CRGB::Green); 
  allBarsDrop(interval, CRGB::Red);
  outerBarsDropInnerRise(interval, CRGB::Green);

//  leftBarDrop(35); 
//  centerBarDrop(35);
//  rightBarDrop(35);
}

void topBarSpread(int interval, CRGB color)
{
  leds[55] = color;
  FastLED.show();
  delay(interval);
  leds[55] = CRGB::Black;
  FastLED.show();
  
  for(int column = 0; column < 5; column = column + 1){
    leds[55 - column] = color;
    leds[55 + column] = color;
    FastLED.show();
    delay(interval);

    leds[55 - column] = CRGB::Black;
    leds[55 + column] = CRGB::Black;
    FastLED.show();
    delay(interval);
  }
}

void allBarsDrop(int interval, CRGB color) {
  for(int rowLevel = 17; rowLevel > 0; rowLevel = rowLevel - 1) {
      leftColumnDown(rowLevel, color);
      centerColumnDown(rowLevel, color);
      rightColumnDown(rowLevel, color);
      FastLED.show();
      delay(interval);

      leftColumnBlack(rowLevel);
      centerColumnBlack(rowLevel);
      rightColumnBlack(rowLevel);
      FastLED.show();
      delay(interval);
  }
}

void outerBarsDropInnerRise(int interval, CRGB color) {
  for(int rowLevel = 17; rowLevel > 0; rowLevel = rowLevel - 1) {
      leftColumnDown(rowLevel, color);
      centerColumnRise(rowLevel, color);
      rightColumnDown(rowLevel, color);
      FastLED.show();
      delay(interval);

      leftColumnBlack(rowLevel);
      centerColumnRiseBlack(rowLevel);
      rightColumnBlack(rowLevel);
      FastLED.show();
      // delay(interval);
  }
}

void leftBarDrop(int interval, CRGB color) {
  for(int rowLevel = 17; rowLevel > 0; rowLevel = rowLevel - 1) {
      leftColumnDown(rowLevel, color);
      FastLED.show();
      delay(interval);
      leftColumnBlack(rowLevel);
      FastLED.show();
      // delay(interval);
  }
}

void centerBarDrop(int interval) {
  for(int rowLevel = 17; rowLevel > 0; rowLevel = rowLevel - 1) {
      centerColumnGreen(rowLevel);
      FastLED.show();
      delay(interval);
      centerColumnBlack(rowLevel);
      FastLED.show();
      // delay(interval);
  }
}

void rightBarDrop(int interval, CRGB color) {
  for(int rowLevel = 17; rowLevel > 0; rowLevel = rowLevel - 1) {
      rightColumnDown(rowLevel, color);
      FastLED.show();
      delay(interval);
      rightColumnBlack(rowLevel);
      FastLED.show();
      // delay(interval);
  }
}

void leftColumnDown(int rowLevel, CRGB color) {
  leds[33 + rowLevel] = color;
}

void leftColumnBlack(int rowLevel) {
  leds[33 + rowLevel] = CRGB::Black;
}

void rightColumnDown(int rowLevel, CRGB color) {
  leds[rowLevel - 1] = color;
}

void rightColumnBlack(int rowLevel) {
  leds[rowLevel - 1] = CRGB::Black;
}

void centerColumnGreen(int rowLevel) {
  leds[17 + (17 - rowLevel)] = CRGB::Green;
}

void centerColumnDown(int rowLevel, CRGB color) {
  leds[17 + (17 - rowLevel)] = color;
}

void centerColumnBlack(int rowLevel) {
  leds[17 + (17 - rowLevel)] = CRGB::Black;
}

void centerColumnRise(int rowLevel, CRGB color) {
  leds[16 + rowLevel] = color;
}

void centerColumnRiseBlack(int rowLevel) {
  leds[16 + rowLevel] = CRGB::Black;
}
