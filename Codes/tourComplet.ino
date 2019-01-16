#include <Servo.h>
Servo servo1;

const int detecteur = 4;
int Etat = 1;
float i = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);

  pinMode(detecteur, INPUT);
}

void loop() {
  Etat = digitalRead(detecteur);
  for(i=0;i<38;i++){ // la roue fait un tour complet
    servo1.writeMicroseconds(1300);
    Serial.println(i);
    delay(10);
  }
  servo1.detach(); // arrête la roue
}
