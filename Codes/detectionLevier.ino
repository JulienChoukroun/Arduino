//Programme qui permet de détecter si le levier est descendu.
// Si c'est le cas, les roues vont tourner

#include<NewPing.h>
int cm=0;
NewPing sonar(6,7,100);

void setup() {
  Serial.begin(9600);
}

void loop() {
  cm=sonar.ping_cm();
  if (cm != 0){
    Serial.println("activer machine");
    delay(100);
  }
  delay(100);
}
