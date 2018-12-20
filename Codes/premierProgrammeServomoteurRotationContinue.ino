// Premier programme pour faire tourner la roue à l'aide du servomoteur à rotation continue.

#include <Servo.h>
Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
}

void loop() {
  servo1.writeMicroseconds(1300);
}
   
