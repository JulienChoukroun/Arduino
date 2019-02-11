#include <Servo.h>
Servo servo2;

int i = 0;
int jeton=0;

void setup() {
  Serial.begin(9600);
  servo2.attach(5);
  servo2.writeMicroseconds(544);
}

void loop() {
  if (nbAleatoire1==38 && nbAleatoire2==34 && nbAleatoire3==37 ){
    //cas où on tombe sur trois 7
    jeton=20;
  }
  else if ( nbAleatoire1==4,75 && nbAleatoire2==4,25 && nbAleatoire3==4,625 || nbAleatoire1==14,25 && nbAleatoire2==12,75 && nbAleatoire3==13,875 || nbAleatoire1==23,75 && nbAleatoire2==21,25 && nbAleatoire3==23,125 || nbAleatoire1==33,25 && nbAleatoire2==29,75 && nbAleatoire3==32,375){
    //cas où on tombe sur trois trèfles ou trois coeurs ou trois piques ou carreaux
    jeton=10;
  }
  else if (nbAleatoire1==9,5 && nbAleatoire2==8,5 && nbAleatoire3==9,25 || nbAleatoire1==19 && nbAleatoire2==17 && nbAleatoire3==18,5 || nbAleatoire1==28,5 && nbAleatoire2==25,25 && nbAleatoire3==27,75){
    //cas où on tombe sur trois ananas ou trois raisin ou trois cerises
    jeton=5;
  }
  for (i=0 ; i<jeton ; i++){ 
    servo2.writeMicroseconds(820);
    delay(700);
    servo2.writeMicroseconds(544); // 0°
    delay(700); 
  }
  servo2.detach();
}
