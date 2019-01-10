// Programme qui comptent le nombre d'encoches.

#include <Servo.h>
Servo servo1;

const int detecteur = 4;
int Etat = 1;
int i=0;
int fente=0;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);

  pinMode(detecteur, INPUT);
}

void loop() {
  Etat = digitalRead(detecteur);
  //for(i=0;i<10;i++){ //tourne pendant 10 secondes
    servo1.writeMicroseconds(1500);
    // Serial.println(i);
    //delay(1000);
    if (Etat==0){
      fente+=1;
      //Serial.println(fente);
      delay(100);
    }
  //}
  servo1.detach();
  Serial.println(fente);
}
   
