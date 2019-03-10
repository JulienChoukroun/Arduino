// Programme qui permet de contrôler les 3 roues de façon aléatoire

// Servomoteur1
#include <Servo.h>
Servo servo1;

// Servomoteur2
Servo servo2;

// Servomoteur3
Servo servo3;

// Détecteur des 3 roues
const int detecteur1 = 4;
const int detecteur2 = 7;
const int detecteur3 = 9;

// Etat des 3 détecteurs sur les roues
int Etat1 = 0;
int Etat2 = 0;
int Etat3 = 0;

int i = 0;
int k = 0;
int l = 0;

// Nombres aléatoires
int nbAleatoire1 = 0;
int nbAleatoire2 = 0;
int nbAleatoire3 = 0;

int nbrand1;
int nbrand2;
int nbrand3;

void setup() {

  Serial.begin(9600);
  
  // Servomoteurs
  servo1.attach(3);
  servo2.attach(6);
  servo3.attach(8);

  // Détecteurs sur les roues
  pinMode(detecteur1, INPUT);
  pinMode(detecteur2, INPUT);
  pinMode(detecteur3, INPUT);

  randomSeed(analogRead(0)); // Permet de générer différents numéros de départ à chaque exécution du programme.

}

void loop() {

  Etat1 = digitalRead(detecteur1);
  Etat2 = digitalRead(detecteur2);
  Etat3 = digitalRead(detecteur3);

  for (k = 0 ; k <= 5 ; k++){ // Les roues tournent environ 10 secondes
    
      for(i = 0 ; i < 39; i++){ // La 1ère roue fait un tour en 390 ms
        servo1.writeMicroseconds(1300); // La roue tourne à vitesse normale
        delay(10);
      }
      for(i = 0 ; i < 38 ; i++){ // La 2ème roue fait un tour en 380 ms
        servo2.writeMicroseconds(1300); // La roue tourne à vitesse normale
        delay(10);
      }
      for(i = 0 ; i < 39 ; i++){ // La 3ème roue fait un tour en 390 ms
        servo3.writeMicroseconds(1300); // La roue tourne à vitesse normale
        delay(10);
      }
    }

    // C'est ici que l'aléatoire entre en jeu
    // Sélection d'un nombre aléatoire
    // Grâce à ce nombre, les roues feront un dernier tour et s'arrêteront aléatoirement
    nbrand1 = random(30,46);
    while ((nbrand1 == 31)||(nbrand1 == 33)||(nbrand1 == 34)||(nbrand1 == 35)||(nbrand1 == 36)||(nbrand1 == 41)||(nbrand1 == 42)||(nbrand1 == 43)){
      nbrand1 = random(30,46);
    }
    nbrand2 = random(29,45);
    while ((nbrand2 == 30)||(nbrand2 == 32)||(nbrand2 == 33)||(nbrand2 == 34)||(nbrand2 == 35)||(nbrand2 == 40)||(nbrand2 == 41)||(nbrand2 == 42)){
      nbrand2 = random(29,46);
    }
    nbrand3 = random(30,46);
    while ((nbrand3 == 31)||(nbrand3 == 33)||(nbrand3 == 34)||(nbrand3 == 35)||(nbrand3 == 36)||(nbrand3 == 41)||(nbrand3 == 42)||(nbrand3 == 43)){
      nbrand3 = random(30,46);
    }
   
    // Tour aléatoire de la 1ère roue
    nbAleatoire1 = nbrand1;
    for (l = 0 ; l < nbAleatoire1 ; l++){ 
      servo1.writeMicroseconds(1300);
      delay(10);
    }
    // Tour aléatoire de la 2ème roue
    nbAleatoire2 = nbrand2;
    for (l = 0 ; l < nbAleatoire2 ; l++){ 
      servo2.writeMicroseconds(1300);
      delay(10);
    }
    // Tour aléatoire de la 3ème roue
    nbAleatoire3 = nbrand3;
    for (l = 0 ; l < nbAleatoire3 ; l++){ 
      servo3.writeMicroseconds(1300);
      delay(10);
    }

    // Affichage des nombres aléatoires pour tester si cela fonctionne bien (optionnel)
    Serial.println(nbAleatoire1);
    Serial.println(nbAleatoire2);
    Serial.println(nbAleatoire3);

    // Arrête les roues
    servo1.detach(); 
    servo2.detach();
    servo3.detach();
    
}
