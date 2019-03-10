// Programme qui permet l'éclairage des leds en blanc

#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 5 // On définit le pin où est connecté la patte DATA du bandeau
#define PIXEL_COUNT 3 // On définit le nombre de LED compris sur le Ruban de LED

//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800); // Paramètre l'objet strip qui correspond à toute les LED du ruban

void setup() {
  
  strip.begin(); // Lance la connection
  strip.show(); // Initialise toute les led à 'off'
  
}

void loop() {
  
  strip.setBrightness(100); // Règle la luminosité à 100 % de la luminosité maximale
  for (int i = 0 ; i < 3 ; i++) { // Ici, on a i < 3 car on utilise 3 led
    strip.setPixelColor(i, 255, 255, 255); // 255 pour la lumière blanche
  }
  strip.show(); // On affiche 
  delay(100);
  
}
