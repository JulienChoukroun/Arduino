// Programme qui teste le fonctionnement du bouton

const int bouton = 10;
int val = 0;

#include <Servo.h>
// Servomoteur1
Servo servo1;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(bouton,INPUT);
  
  servo1.attach(3);
  servo1.writeMicroseconds(1525); // La roue ne tourne pas

}

void loop() {
  
  val = digitalRead(bouton);
  if (val == LOW) { // Si on appuie sur le bouton
    servo1.writeMicroseconds(1300); // La roue tourne
    Serial.println("bonton activé");
  }
  else{
    Serial.println("rien");
  }
  
}
