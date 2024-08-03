#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>

 
#define PIN      9
#define N_LEDS 24
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

#define GREEN 0x00FF00

void setup() {
  strip.begin();
}
 
void loop() {
  alight(strip.Color(255, 0, 0)); // Red
  alight(GREEN); // Green
  alight(strip.Color(0, 0, 255)); // Blue
}

void alight(uint32_t color) {
    strip.fill(color, 0, N_LEDS);
    strip.show();
    delay(20);
}