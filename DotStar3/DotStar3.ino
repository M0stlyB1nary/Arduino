// Use if you want to force the software SPI subsystem to be used for some reason (generally, you don't)
// #define FASTLED_FORCE_SOFTWARE_SPI
// Use if you want to force non-accelerated pin access (hint: you really don't, it breaks lots of things)
// #define FASTLED_FORCE_SOFTWARE_SPI
// #define FASTLED_FORCE_SOFTWARE_PINS
#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 

// How many leds are in the strip?
#define NUM_LEDS 60

// Data pin that led data will be written out over
#define DATA_PIN 11

// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define CLOCK_PIN 13

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);


      FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

// This function runs over and over, and is where you do the magic to light
// your leds.

//Red is Blue
//Blue is Red
//Purple
//

void loop() {

  //firstLoops();
  johnsLoops();

  //slider();
   
}

void slider()
{
  for (int currLed = 0; currLed < NUM_LEDS; currLed = currLed + 2)
  {
    leds[currLed] = CRGB::Blue;
    FastLED.show();
    delay(20);
  }  
  delay(5000);
  for (int i = (NUM_LEDS -2); i>=0; i = i - 2)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(20);
  }  
  delay(1000);

  //New
//
//  int left = 0;
//  int right = 59;
// 
//  for (int i = 0; i < 30; i = i + 1)
//  {
//    leds[left] = CRGB::Green;
//    leds[right] = CRGB::Blue;
//    FastLED.show();
//    delay(100);
//  
////    leds[left] = CRGB::Black;
////    leds[right] = CRGB::Black;
////    FastLED.show();
////    delay(100);     
//
//    left = left + 1;
//    right = right -1;
//  }
//
//  left = left - 1;
//  right = right + 1;
//  
//  for (int i = 0; i < 30; i = i + 1)
//  {
//    leds[left] = CRGB::Green;
//    leds[right] = CRGB::Blue;
//    FastLED.show();
//    delay(10);
//  
//    leds[left] = CRGB::Black;
//    leds[right] = CRGB::Black;
//    FastLED.show();
//    delay(10);     
//
//    left = left - 1;
//    right = right + 1;
//  }
}

void johnsLoops()
{
  for (int currLed = 0; currLed < NUM_LEDS; currLed = currLed + 2)
  {
    leds[currLed] = CRGB::Orange;
  }

  FastLED.show();
  delay(5000);

  for (int currLed = 0; currLed < NUM_LEDS; currLed = currLed + 2)
  {
    leds[currLed] = CRGB::Green;
    FastLED.show();
    delay(50);
//    leds[currLed] = CRGB::Black;
//    FastLED.show();
    delay(50);
  }
  FastLED.show();
  delay(5000);
  
  for (int currLed = 0; currLed < NUM_LEDS; currLed = currLed + 2)
  {
    leds[currLed] = CRGB::Blue;
    FastLED.show();
    delay(50);
  }
  FastLED.show();
  delay(5000);
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

}

