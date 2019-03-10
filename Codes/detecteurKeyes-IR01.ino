// Programme qui teste le fonctionnement des détecteurs Keyes-IR01

int detecteur = 9;

void setup() {
  Serial.begin(9600);
  pinMode(detecteur,INPUT);
}

void loop() {
  Serial.println(digitalRead(detecteur)); // Affiche "1" si le détecteur passe devant la bande noire
  delay(50);
}
