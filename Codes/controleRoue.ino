//Programme qui permet de contrôler la roue mais de façon aléatoire. 

#include <Servo.h>
Servo servo1;

const int detecteur = 4;
int Etat = 1;
float i = 0;
int k = 0;
int nbAleatoire = 0;
int l = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);

  pinMode(detecteur, INPUT);

  randomSeed(analogRead(0)); // permet de générer différents numéros de départ à chaque exécution du programme.
}

void loop() {
  Etat = digitalRead(detecteur);
  for (k = 0 ; k < 10 ; k++){ // faire 10 tours
    for(i = 0 ; i < 46 ; i++){ 
      servo1.writeMicroseconds(1300); // la roue tourne à vitesse normale
      delay(10);
    }
  }
  nbAleatoire = random(40); // La roue met 390 ms pour faire un tour complet. Donc choisi un nombre aléatoir entre 0 inclus et 40 exclus.
  for(l = 0 ; l < nbAleatoire ; l++){ 
    servo1.writeMicroseconds(1300);
    delay(10);
  }
  Serial.println(l); // affiche le nombre aléatoire tiré
  servo1.detach(); // arrête la roue 
}
