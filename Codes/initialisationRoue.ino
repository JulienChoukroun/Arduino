// Programme qui initialise la roue.

#include <Servo.h>
Servo servo1;

const int detecteur = 4;
int Etat = 1;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);

  pinMode(detecteur, INPUT);
}

void loop() {
  Etat = digitalRead(detecteur);
  servo1.writeMicroseconds(1510); // vitesse lente
  if (Etat==0) {
    servo1.writeMicroseconds(1525); // si le capteur rencontre une fente, la roue s'arrête
  }
  delay(100);
}
   
