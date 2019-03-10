// Programme qui teste le fonctionnement du monnayeur

#include <Servo.h>
Servo servo4;

int i = 0;

void setup() {
  
  Serial.begin(9600);
  servo4.attach(2);
  servo4.writeMicroseconds(1760); // Position initiale
  
}

void loop() {
  
  for (i = 0 ; i < 5 ; i++){ // Ejecte 5 pièces
    servo4.writeMicroseconds(2050); // Pousse le jeton
    delay(700);
    servo4.writeMicroseconds(1760); // Revient à sa position initiale
    delay(700); 
  }
  servo4.detach(); // Arrête le monnayeur
  
}
