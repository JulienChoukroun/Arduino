// Programme qui initialise la roue avec le nouveau capteur Keyes IR-01 + lumière

// servomoteur
#include <Servo.h>
Servo servo1;

const int detecteur = 4;
int Etat = 0;

// lumière
#include <Adafruit_NeoPixel.h>
#define PIXEL_PIN 5 // On définit le pin où est connecté la patte DATA du bandeau
#define PIXEL_COUNT 3 // On définit le nombre de LED compris sur le Ruban de LED

//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800); // Paramètre l'objet strip qui correspond à toute les LED du ruban


void setup() {
  //servomoteur
  Serial.begin(9600);
  servo1.attach(3);
  
  //détecteur
  pinMode(detecteur, INPUT);
  
  
  // lumière
  strip.begin(); // Lance la connection
  strip.show(); // Initialise toute les led à 'off'

  
}

void loop() {

  lumiere();
  
  Etat = digitalRead(detecteur);
  servo1.writeMicroseconds(1510); // Vitesse lente
  if (Etat==1) {
    servo1.writeMicroseconds(1525); // Si le capteur rencontre la "ligne" noire, la roue s'arrête
  }
  delay(100);
}

void lumiere() {
  strip.setBrightness(100); // Règle la luminosité à 100 % de la luminosité maximale
  for(int i = 0 ; i < 3 ; i++){ //Ici, on a i < 3 car on utilise 3 led
    strip.setPixelColor(i , 255 , 255 , 255); // 255 pour la lumière blanche
  }
  strip.show(); // On affiche 
  delay(100);
}
   
