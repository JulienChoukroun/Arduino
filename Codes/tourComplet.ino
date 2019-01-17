#include <Servo.h>
Servo servo1;

const int detecteur = 4;
int Etat = 1;
int i = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);

  pinMode(detecteur, INPUT);
}

void loop() {
  Etat = digitalRead(detecteur);
  for(i=0;i<39;i++){ 
    servo1.writeMicroseconds(1300);
    delay(10);
    }
  servo1.detach(); // arrête la roue
}
