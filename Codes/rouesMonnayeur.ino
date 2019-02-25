// Programme qui fait fonctionner les roues et rend les pièces gagnées par le monnayeur

// servomoteur1
#include <Servo.h>
Servo servo1;

// servomoteur2
Servo servo2;

// servomoteur3
Servo servo3;

// servomoteur4 monnayeur
Servo servo4;

const int detecteur1 = 4;
const int detecteur2 = 7;
const int detecteur3 = 9;

int Etat1 = 0;
int Etat2 = 0;
int Etat3 = 0;

int i = 0;
int k = 0;
int l = 0;

int nbAleatoire1 = 0;
int nbAleatoire2 = 0;
int nbAleatoire3 = 0;

//monnayeur
int m = 0;
int jeton=0;

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
  // servomoteurs
  servo1.attach(3);
  servo2.attach(6);
  servo3.attach(8);

  // détecteurs
  pinMode(detecteur1, INPUT);
  pinMode(detecteur2, INPUT);
  pinMode(detecteur3, INPUT);

  randomSeed(analogRead(0)); // Permet de générer différents numéros de départ à chaque exécution du programme.
  
  // lumière
  strip.begin(); // Lance la connection
  strip.show(); // Initialise toute les led à 'off'
  
  
  // monnayeur
  servo4.attach(10);
  servo4.writeMicroseconds(544); // 0°
  
}

void lumiere() {
  
  strip.setBrightness(100); // Règle la luminosité à 100 % de la luminosité maximale
  for(int i = 0 ; i < 3 ; i++){ // Ici, on a i < 3 car on utilise 3 led
    strip.setPixelColor(i, 255, 255, 255); // 255 pour la lumière blanche
  }
  strip.show(); // On affiche 
  delay(100);
  
}

void loop() {
  
  lumiere();

  Etat1 = digitalRead(detecteur1);
  Etat2 = digitalRead(detecteur2);
  Etat3 = digitalRead(detecteur3);
  
  for (k = 0 ; k < 5 ; k++){ // Chacunes des roues fera 10 tours
    for(i = 0 ; i < 38 ; i++){ // La 1ère roue fait un tour en 380 ms
      servo1.writeMicroseconds(1300); // La roue tourne à vitesse normale
      delay(10);
    }
    for(i = 0 ; i < 34 ; i++){ // La 2ème roue fait un tour en 340 ms
      servo2.writeMicroseconds(1300); // la roue tourne à vitesse normale
      delay(10);
    }
    for(i = 0 ; i < 37 ; i++){ // La 3ème roue fait un tour en 370 ms
      servo3.writeMicroseconds(1300); // la roue tourne à vitesse normale
      delay(10);
    }
  }
  
  // Tour aléatoire de la 1ère roue
  nbAleatoire1 = random(38); // La roue met 380 ms pour faire un tour complet. Donc on choisi un nombre aléatoire entre 0 inclus et 39 exclus.
  for(l = 0 ; l < nbAleatoire1 ; l++){ 
    servo1.writeMicroseconds(1300);
    delay(10);
  }
  Serial.println(l); // Affiche le nombre aléatoire tiré
  
  // Tour aléatoire de la 2ème roue
  nbAleatoire2 = random(34); // La roue met 340 ms pour faire un tour complet. Donc on choisi un nombre aléatoire entre 0 inclus et 35 exclus.
  for(l = 0 ; l < nbAleatoire2 ; l++){ 
    servo2.writeMicroseconds(1300);
    delay(10);
  }
  Serial.println(l); // Affiche le nombre aléatoire tiré

  // Tour aléatoire de la 3ème roue
  nbAleatoire3 = random(37); // La roue met 370 ms pour faire un tour complet. Donc on choisi un nombre aléatoire entre 0 inclus et 38 exclus.
  for(l = 0 ; l < nbAleatoire3 ; l++){ 
    servo3.writeMicroseconds(1300);
    delay(10);
  }
  Serial.println(l); // Affiche le nombre aléatoire tiré
  
  // Arrête les roues
  servo1.detach(); 
  servo2.detach();
  servo3.detach();

  // monnayeur
  if (nbAleatoire1==38 && nbAleatoire2==34 && nbAleatoire3==37 ){
    //cas où on tombe sur trois 7
    jeton=20;
  }
  else if ( nbAleatoire1==4,75 && nbAleatoire2==4,25 && nbAleatoire3==4,625 || nbAleatoire1==14,25 && nbAleatoire2==12,75 && nbAleatoire3==13,875 || nbAleatoire1==23,75 && nbAleatoire2==21,25 && nbAleatoire3==23,125 || nbAleatoire1==33,25 && nbAleatoire2==29,75 && nbAleatoire3==32,375){
    //cas où on tombe sur trois trèfles ou trois coeurs ou trois piques ou carreaux
    jeton=10;
  }
  else if (nbAleatoire1==9,5 && nbAleatoire2==8,5 && nbAleatoire3==9,25 || nbAleatoire1==19 && nbAleatoire2==17 && nbAleatoire3==18,5 || nbAleatoire1==28,5 && nbAleatoire2==25,25 && nbAleatoire3==27,75){
    //cas où on tombe sur trois ananas ou trois raisin ou trois cerises
    jeton=5;
  }
  
  for (m=0 ; m<jeton ; m++){ 
    servo4.writeMicroseconds(825); // Pousse le jeton
    delay(700);
    servo4.writeMicroseconds(544); // Revient à la position initial 0°
    delay(700); 
  }
  // Arrête le monnayeur
  servo4.detach();
  
}
