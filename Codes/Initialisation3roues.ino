// Programme qui initialise les roues. 
//Les roues vont tourner à vitesse lente jusqu'à trouver la fente noire. A ce moment là, elles s'arrêteront.

#include <Servo.h>
// servomoteur1
Servo servo1;

//servomoteur2
Servo servo2;

//servomoteur3
Servo servo3;

const int detecteur1 = 4;
const int detecteur2 = 7;
const int detecteur3 = 9;

int Etat1 = 0;
int Etat2 = 0;
int Etat3 = 0;

int i = 0;
int k = 0;
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
  
  Serial.begin(9600);
  //servomoteurs
  servo1.attach(3);
  servo2.attach(6);
  servo3.attach(8);
  
  //détecteurs
  pinMode(detecteur1, INPUT);
  pinMode(detecteur2, INPUT);
  pinMode(detecteur3, INPUT);
  
  // lumière
  strip.begin(); // Lance la connection
  strip.show(); // Initialise toute les led à 'off'

}

void lumiere() {
  
  strip.setBrightness(100); // Règle la luminosité à 100 % de la luminosité maximale
  for(int i = 0 ; i < 3 ; i++){ // Ici, on a i < 3 car on utilise 3 led
    strip.setPixelColor(i , 255 , 255 , 255); // 255 pour la lumière blanche
  }
  strip.show(); // On affiche 
  delay(100);
  
}

void loop() {

  lumiere();
  
  Etat1 = digitalRead(detecteur1);
  Etat2 = digitalRead(detecteur2);
  Etat3 = digitalRead(detecteur3);
  
  //servo1
  servo1.writeMicroseconds(1510); // Vitesse lente
  if (Etat1==1) {
    servo1.writeMicroseconds(1526); // Si le capteur rencontre la "ligne" noire, la roue s'arrête
  }
  
  //servo2
  servo2.writeMicroseconds(1508); // Vitesse lente
  if (Etat2==1) {
    servo2.writeMicroseconds(1525); // Si le capteur rencontre la "ligne" noire, la roue s'arrête
  }

  //servo3
  servo3.writeMicroseconds(1525); // Vitesse lente
  if (Etat3==1) {
    servo3.writeMicroseconds(1537); // Si le capteur rencontre la "ligne" noire, la roue s'arrête
  }
  delay(100);
  
}
