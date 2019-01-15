#include <Servo.h>
Servo servo2;

int i = 0;

void setup() {
  Serial.begin(9600);
  servo2.attach(5);
  servo2.writeMicroseconds(544);
}

void loop() {
  for (i=0 ; i<10 ; i++){ // éjecte 10 pièces
    servo2.writeMicroseconds(800);
    delay(700);
    servo2.writeMicroseconds(544); // 0°
    delay(700); 
  }
  servo2.detach();
}
