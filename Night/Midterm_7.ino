#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 5

#define DATA_PIN 11

CRGB leds[NUM_LEDS];



void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  delay(100);
  night(50);
  

  FastLED.show();
}

void night(int wait) {

  static const float nightLength = 4;

  static const float interval = (nightLength * 60) / 256;

  static float nightIndex = 0; // start out at 0

  CRGB color = ColorFromPalette(PartyColors_p, nightIndex);

  fill_solid(leds, NUM_LEDS, color);

  EVERY_N_SECONDS(interval) {
    if (nightIndex < 255) {
      nightIndex++;
    }


  }
}
