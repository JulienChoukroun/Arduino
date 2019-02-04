const int bouton=7;
const int led=2;
int val=0;


void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(bouton,INPUT);
  digitalWrite(led,LOW);
  delay(1000);

}

void loop() {
  val=digitalRead(bouton);
  if (val==HIGH){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW); 
  }
}
