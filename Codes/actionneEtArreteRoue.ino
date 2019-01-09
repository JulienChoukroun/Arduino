// Programme qui fait actionne la roue pendant x secondes et l'arrête.

#include <Servo.h>
Servo servo1;

int i=0;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
}

void loop() {
for(i=0;i<10;i++){ // actionne la roue pendant 10 secondes
    servo1.writeMicroseconds(1300);
    Serial.println(i);
    delay(1000);
  }
  servo1.detach(); // arrête la roue
}
