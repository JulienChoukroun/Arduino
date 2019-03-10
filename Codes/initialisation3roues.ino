// Programme qui initialise les roues. 
// Les roues vont tourner à vitesse lente jusqu'à trouver la fente noire. A ce moment là, elles s'arrêteront.

#include <Servo.h>
// Servomoteur1
Servo servo1;

// Servomoteur2
Servo servo2;

// Servomoteur3
Servo servo3;

const int detecteur1 = 4;
const int detecteur2 = 7;
const int detecteur3 = 9;

int Etat1 = 0;
int Etat2 = 0;
int Etat3 = 0;

void setup() {
  
  Serial.begin(9600);
  
  // Servomoteurs
  servo1.attach(3);
  servo2.attach(6);
  servo3.attach(8);
  
  // Détecteurs
  pinMode(detecteur1, INPUT);
  pinMode(detecteur2, INPUT);
  pinMode(detecteur3, INPUT);

}

void loop() {
  
  Etat1 = digitalRead(detecteur1);
  Etat2 = digitalRead(detecteur2);
  Etat3 = digitalRead(detecteur3);
  
  // Servo1
  servo1.writeMicroseconds(1510); // La première roue se met à touner à vitesse lente
  if (Etat1 == 1) {
    servo1.writeMicroseconds(1526); // Si le détecteur rencontre la bande noire, la roue s'arrête
  }
  
  // Servo2
  servo2.writeMicroseconds(1508); // La deuxième roue se met à touner à vitesse lente
  if (Etat2 == 1) {
    servo2.writeMicroseconds(1525); // Si le détecteur rencontre la bande noire, la roue s'arrête
  }

  // Servo3
  servo3.writeMicroseconds(1525); // La troisième roue se met à touner à vitesse lente
  if (Etat3 == 1) {
    servo3.writeMicroseconds(1537); // Si le détecteur rencontre la bande noire, la roue s'arrête
  }
  
  delay(100);
  
}
