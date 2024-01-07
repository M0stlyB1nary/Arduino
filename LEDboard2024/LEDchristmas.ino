// RL 12/4/2016
// 60count LED strip
// Green wire: Pin 11
// Black wire: Pin 13
#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 

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
//Red is Blue
//Blue is Red

void loop() {

//  firstLoops();
  //redandgreen();  
  topBarGreen(25); 
  outerBarGreen(25);
//  topBarBlue(300);
}

void topBarGreen(int interval)
{
  leds[55] = CRGB::Green;
  FastLED.show();
  delay(interval);
  
  leds[55] = CRGB::Black;
  leds[54] = CRGB::Green;
  leds[56] = CRGB::Green;
  FastLED.show();
  delay(interval);

  leds[54] = CRGB::Black;
  leds[56] = CRGB::Black;
  leds[53] = CRGB::Green;
  leds[57] = CRGB::Green;
  FastLED.show();
  delay(interval);

  leds[53] = CRGB::Black;
  leds[57] = CRGB::Black;
  leds[52] = CRGB::Green;
  leds[58] = CRGB::Green;
  FastLED.show();
  delay(interval);

  leds[52] = CRGB::Black;
  leds[58] = CRGB::Black;
  leds[51] = CRGB::Green;
  leds[59] = CRGB::Green;
  FastLED.show();
  delay(interval);
  
  leds[51] = CRGB::Black;
  leds[59] = CRGB::Black;
  FastLED.show();
//  delay(interval);
}

void topBarBlue(int interval)
{
  leds[55] = CRGB::Red;
  FastLED.show();
  delay(interval);
  
  leds[55] = CRGB::Black;
  leds[54] = CRGB::Red;
  leds[56] = CRGB::Red;
  FastLED.show();
  delay(interval);

  leds[54] = CRGB::Black;
  leds[56] = CRGB::Black;
  leds[53] = CRGB::Red;
  leds[57] = CRGB::Red;
  FastLED.show();
  delay(interval);

  leds[53] = CRGB::Black;
  leds[57] = CRGB::Black;
  leds[52] = CRGB::Red;
  leds[58] = CRGB::Red;
  FastLED.show();
  delay(interval);

  leds[52] = CRGB::Black;
  leds[58] = CRGB::Black;
  leds[51] = CRGB::Red;
  leds[59] = CRGB::Red;
  FastLED.show();
  delay(interval);
  
  leds[51] = CRGB::Black;
  leds[59] = CRGB::Black;
  FastLED.show();
//  delay(interval);
}

void outerBarGreen(int interval) {

// Start here
  for(int rowLevel = 17; rowLevel > 0; rowLevel = rowLevel - 1) {
      leftColumnGreen(rowLevel);
      centerColumnGreen(rowLevel);
      rightColumnGreen(rowLevel);
      FastLED.show();
      delay(interval);

      leftColumnBlack(rowLevel);
      centerColumnBlack(rowLevel);
      rightColumnBlack(rowLevel);
      FastLED.show();
      delay(interval);
  }
}

void leftColumnGreen(int rowLevel) {
  leds[33 + rowLevel] = CRGB::Green;
}

void leftColumnBlack(int rowLevel) {
  leds[33 + rowLevel] = CRGB::Black;
}

void rightColumnGreen(int rowLevel) {
  leds[rowLevel - 1] = CRGB::Green;
}

void rightColumnBlack(int rowLevel) {
  leds[rowLevel - 1] = CRGB::Black;
}

void centerColumnGreen(int rowLevel) {
  leds[16 + rowLevel] = CRGB::Green;
}

void centerColumnBlack(int rowLevel) {
  leds[16 + rowLevel] = CRGB::Black;
}

void redandgreen()
{
  //Turn odd LEDs to red
  for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 2) {
      leds[whiteLed] = CRGB::Blue;
   }

  //Turn even LEDs to green
  for(int whiteLed = 1; whiteLed < NUM_LEDS; whiteLed = whiteLed + 2) {
      leds[whiteLed] = CRGB::Green;
   }
  FastLED.show();
  delay(1000);

  //Turn odd LEDs to red
  for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 2) {
      leds[whiteLed] = CRGB::Green;
   }

  //Turn even LEDs to green
  for(int whiteLed = 1; whiteLed < NUM_LEDS; whiteLed = whiteLed + 2) {
      leds[whiteLed] = CRGB::Blue;
   }
  FastLED.show();
  delay(1000);
}

void firstLoops()
{
   // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;
      //leds[whiteLed - 2] = CRGB::Green;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
      //leds[whiteLed - 2] = CRGB::Black;
   }

      // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::Red;
      //leds[whiteLed - 2] = CRGB::Green;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Green;
      //leds[whiteLed - 2] = CRGB::Black;
   }

      // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;
      //leds[whiteLed - 2] = CRGB::Green;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
      //leds[whiteLed - 2] = CRGB::Black;
   }

      // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::Blue;
      //leds[whiteLed - 2] = CRGB::Green;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
      //leds[whiteLed - 2] = CRGB::Black;
   }
      // Wait a little bit
      delay(2000);

}
