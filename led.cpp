#include <Adafruit_NeoPixel.h>

#include "led.h"

const int LED_PIN = 6;

Adafruit_NeoPixel rgbLed = Adafruit_NeoPixel(1, LED_PIN, NEO_RGB + NEO_KHZ800);
