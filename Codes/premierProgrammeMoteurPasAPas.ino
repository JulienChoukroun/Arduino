// Premier programme pour faire fonctionner le moteur pas à pas sur la roue en bois.

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
// Le temps entre chaque séquence doit être d'au moins 1900 µs donc le moteur peut faire un tour en : 1900 (µs) * 2048 (pas) = 3.891 s.
// Donc il peut faire au mieux 15.4 tours par minutes (= 60 / 3.891).
// En dessous de 1900 µs, la roue ne tourne pas.
int temps=1900;
int i=0;

void setup() {
  Serial.begin(115200);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  // Pour 1 tour : 32 (séquences) / 4(A-B-C-D) * 64 (réducteur) = 512 boucles.
  for(i=0;i<=511;i++) {
    Serial.println(i);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delayMicroseconds(temps);
    
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delayMicroseconds(temps);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    delayMicroseconds(temps);

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    delayMicroseconds(temps);
  }  
}
