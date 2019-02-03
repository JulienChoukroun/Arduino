// Programme qui permet de contrôler la roue de façon aléatoire + lumière

// servomoteur
#include <Servo.h>
Servo servo1;

const int detecteur = 4;
int Etat = 0;
int i = 0;
int k = 0;
int nbAleatoire = 0;
int l = 0;


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
  // servomoteur
  Serial.begin(9600);
  servo1.attach(3);

  // détecteur
  pinMode(detecteur, INPUT);

  randomSeed(analogRead(0)); // Permet de générer différents numéros de départ à chaque exécution du programme.

  
  // lumière
  strip.begin(); // Lance la connection
  strip.show(); // Initialise toute les led à 'off'

  
}

void loop() {

  lumiere();
  
  Etat = digitalRead(detecteur);
  for (k = 0 ; k <= 10 ; k++){ // Faire 10 tours
    // Serial.println(k);
    for(i = 0 ; i < 38 ; i++){ // La roue fait un tour en 380 ms
      servo1.writeMicroseconds(1300); // La roue tourne à vitesse normale
      delay(10);
    }
  }
  
  nbAleatoire = random(38); // La roue met 380 ms pour faire un tour complet. Donc choisi un nombre aléatoir entre 0 inclus et 39 exclus.
  for(l = 0 ; l < nbAleatoire ; l++){ 
    servo1.writeMicroseconds(1300);
    delay(10);
  }
  Serial.println(l); // Affiche le nombre aléatoire tiré
  
  servo1.detach(); // Arrête la roue 
}

void lumiere() {
  strip.setBrightness(100); // Règle la luminosité à 100 % de la luminosité maximale
  for(int i = 0 ; i < 3 ; i++){ // Ici, on a i < 3 car on utilise 3 led
    strip.setPixelColor(i, 255, 255, 255); // 255 pour la lumière blanche
  }
  strip.show(); // On affiche 
  delay(100);
}
