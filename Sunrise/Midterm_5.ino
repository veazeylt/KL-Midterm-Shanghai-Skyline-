#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 5

#define DATA_PIN 11

CRGB leds[NUM_LEDS];



void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
//  sunrise(10);
}

void loop() {
  sunrise(50);
  delay(100);
//  sunset(50);
  

  FastLED.show();
}

void sunrise(int wait) {

  static const float sunriseLength = 4;

  static const float interval = (sunriseLength * 60) / 256;

  static float heatIndex = 0;

   CRGB color = ColorFromPalette(HeatColors_p, heatIndex);

  fill_solid(leds, NUM_LEDS, color);

  EVERY_N_SECONDS(interval) {
    if (heatIndex < 255) {
      heatIndex++;
    }

  }
}


