const int detecteur = 5;     
const int led =  9;        
// LED témoin 
int Etat =0 ;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(detecteur, INPUT);
  Serial.println("Détection de présence");

}

void loop() {
  Etat = digitalRead(detecteur);
  Serial.print("Etat ");
  if (Etat == HIGH) {     
    // La LED témoin s'allume
    digitalWrite(led, HIGH);
     Serial.println("Presence");
  }
  else {
    // La LED témoin est éteinte
    digitalWrite(led, LOW);
    Serial.println("Vide");
  }
  delay(200);
}
