/** Projet Arduino : machine à sous

* Auteur : Julien Choukroun et Jessica Gourdon

* Ce programme fait fonctionner notre machine à sous.
* Le principe est d'insérer une pièce. A ce moment là, les roues vont se mettre à une position initiale.
* Puis on appuie sur le bonton. Les roues vont tourner et s'arrêter aléatoirement.
* Pour gagner, il faut aligner 3 symboles identiques.
* Si on a gagné, le monnayeur nous donne des pièces. Sinon le monnayeur nous rend rien.
* Dans notre programme, on a aussi inséré un système de lumière, de musique et de bluetooth.
*/


// Bluetooth
#include <SoftwareSerial.h>
#define RX 12
#define TX 13
SoftwareSerial BlueT(RX,TX);

// Servomoteur1
#include <Servo.h>
Servo servo1;

// Servomoteur2
Servo servo2;

// Servomoteur3
Servo servo3;

// Servomoteur4 monnayeur
Servo servo4;

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

// Monnayeur
int m = 0;
int jeton = 0;

// Bouton
const int bouton = 10;
int val = 0;

// Détecteur de pièce
const int detecteurPiece = 11;
int EtatPiece = 0;

int variable1 = 0;
int variable2 = 0;
int variable3 = 0;


// Lumière
#include <Adafruit_NeoPixel.h>
#define PIXEL_PIN 5 // On définit le pin où est connecté la patte DATA du bandeau
#define PIXEL_COUNT 3 // On définit le nombre de LED compris sur le Ruban de LED

//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800); // Paramètre l'objet strip qui correspond à toute les LED du ruban


// Musique
#define ARDUINO_RX 15//should connect to TX of the Serial MP3 Player module 
#define ARDUINO_TX 14//connect to RX of the module 
SoftwareSerial mySerial(ARDUINO_RX, ARDUINO_TX);//init the serial protocol, tell to myserial wich pins are TX and RX 
char data="A";
//////////////////////////////////////////////////////////////////////////////////// 
//all the commands needed in the datasheet(http://geekmatic.in.ua/pdf/Catalex_MP3_board.pdf) 
static int8_t Send_buf[8] = {0} ;//The MP3 player undestands orders in a 8 int string 
                                //0X7E FF 06 command 00 00 00 EF;(if command =01 next song order)  
#define NEXT_SONG 0X01  
#define PREV_SONG 0X02  
#define CMD_PLAY_W_INDEX 0X03 //DATA IS REQUIRED (number of song) 
#define VOLUME_UP_ONE 0X04 
#define VOLUME_DOWN_ONE 0X05 
#define CMD_SET_VOLUME 0X06//DATA IS REQUIRED (number of volume from 0 up to 30(0x1E)) 
#define SET_DAC 0X17 
#define CMD_PLAY_WITHVOLUME 0X22 //data is needed  0x7E 06 22 00 xx yy EF;(xx volume)(yy number of song) 
#define CMD_SEL_DEV 0X09 //SELECT STORAGE DEVICE, DATA IS REQUIRED 
#define DEV_TF 0X02 //HELLO,IM THE DATA REQUIRED 
#define SLEEP_MODE_START 0X0A 
#define SLEEP_MODE_WAKEUP 0X0B 
#define CMD_RESET 0X0C//CHIP RESET 
#define CMD_PLAY 0X0D //RESUME PLAYBACK 
#define CMD_PAUSE 0X0E //PLAYBACK IS PAUSED 
#define CMD_PLAY_WITHFOLDER 0X0F//DATA IS NEEDED, 0x7E 06 0F 00 01 02 EF;(play the song with the directory \01\002xxxxxx.mp3 
#define STOP_PLAY 0X16 
#define PLAY_FOLDER 0X17// data is needed 0x7E 06 17 00 01 XX EF;(play the 01 folder)(value xx we dont care) 
#define SET_CYCLEPLAY 0X19//data is needed 00 start; 01 close 
#define SET_DAC 0X17//data is needed 00 start DAC OUTPUT;01 DAC no output 
//////////////////////////////////////////////////////////////////////////////////// 

void sendCommand(int8_t command, int16_t dat) { 
delay(20); 
Send_buf[0] = 0x7e; //starting byte 
Send_buf[1] = 0xff; //version 
Send_buf[2] = 0x06; //the number of bytes of the command without starting byte and ending byte 
Send_buf[3] = command; // 
Send_buf[4] = 0x00;//0x00 = no feedback, 0x01 = feedback 
Send_buf[5] = (int8_t)(dat >> 8);//datah 
Send_buf[6] = (int8_t)(dat); //datal 
Send_buf[7] = 0xef; //ending byte 
for(uint8_t i=0; i<8; i++){ 
  mySerial.write(Send_buf[i]) ; 
} 
} 


void setup() {
  
  Serial.begin(9600);
  
  // Bluetooth
  BlueT.begin(9600);
  
  // Servomoteurs
  servo1.attach(3);
  servo1.writeMicroseconds(1525); // Ne tourne pas
  
  servo2.attach(6);
  servo2.writeMicroseconds(1525); // Ne tourne pas
  
  servo3.attach(8);
  servo3.writeMicroseconds(1537); // Ne tourne pas
  

  // Détecteurs sur les roues
  pinMode(detecteur1, INPUT);
  pinMode(detecteur2, INPUT);
  pinMode(detecteur3, INPUT);

  randomSeed(analogRead(0)); // Permet de générer différents numéros de départ à chaque exécution du programme.
  
  // Lumière
  strip.begin(); // Lance la connection
  strip.show(); // Initialise toute les led à 'off'
  
  
  // Monnayeur
  servo4.attach(2);
  servo4.writeMicroseconds(1760); // Position initiale
  
  // Bouton
  pinMode(bouton,INPUT);

  // Détecteur de pièce
  pinMode(detecteurPiece,INPUT);

  // Musique
  mySerial.begin(9600);//Start our Serial coms for our serial monitor! 
  delay(500);//Wait chip initialization is complete 
  sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card   
  delay(200);//wait for 200ms 
  
}

// Fonction qui allume les bandes de led en blanc
void lumiere() {
  
  strip.setBrightness(100); // Règle la luminosité à 100 % de la luminosité maximale
  for(int i = 0 ; i < 3 ; i++){ // Ici, on a i < 3 car on utilise 3 led
    strip.setPixelColor(i, 255, 255, 255); // 255 pour la lumière blanche
  }
  strip.show(); // On affiche 
  delay(100);
  
}

void loop() {

  // Allume les leds
  lumiere();

  // Etat de tous les détecteurs Keyes-01
  Etat1 = digitalRead(detecteur1);
  Etat2 = digitalRead(detecteur2);
  Etat3 = digitalRead(detecteur3);
  EtatPiece = digitalRead(detecteurPiece);

  //Détecteur de piece
  if (EtatPiece == 1) { // Si on passe une pièce devant ce détecteur alors initialise les 3 variables suivantes à 1
    variable1 = 1;
    variable2 = 1;
    variable3 = 1;
    delay(10);
  }

  // Initialisation
  // On place les roues à une position initiale qui est "7-7-7" en sortie
  if (variable1 == 1 || variable2 == 1 || variable3 == 1){ // Si on a passé une pièce devant le détecteur
    
    servo1.writeMicroseconds(1510); // La première roue se met à touner à vitesse lente
    if (Etat1 == 1) {
      servo1.writeMicroseconds(1525); // Si le détecteur rencontre la bande noire, la roue s'arrête
      variable1 = 0;
    }
    
    servo2.writeMicroseconds(1510); // La deuxième roue se met à touner à vitesse lente
    if (Etat2 == 1) {
      servo2.writeMicroseconds(1525); // Si le détecteur rencontre la bande noire, la roue s'arrête
      variable2 = 0;
    }
    
    servo3.writeMicroseconds(1525); // La troisième roue se met à touner à vitesse lente
    if (Etat3 == 1) {
      servo3.writeMicroseconds(1537); // Si le détecteur rencontre la bande noire, la roue s'arrête
      variable3 = 0;
    }
    
    delay(50);
  }
  
  // Bouton
  val = digitalRead(bouton);
  if (val == LOW){ // Si on appuie sur le bouton, les roues tournent
    
    // Musique d'ambiance
    sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00101);
  
    // Le jeu commence
  
    servo1.writeMicroseconds(1485);
    delay(1500);
    servo2.writeMicroseconds(1492);
    servo3.writeMicroseconds(1500);
    delay(600);
  
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
 

    // Monnayeur et Bluetooth

    // Cas où on tombe sur trois 7
    if ((nbAleatoire1 == 39)&&(nbAleatoire2 == 38)&&(nbAleatoire3 == 39)){
      jeton = 20;
      // Bluetooth
      BlueT.print("*A" + String("Bravo ! Vous avez gagne 20 jetons !") + "*");
      // Musique de gros jackpot
      sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00103);
    }
  
    // Cas où on tombe sur trois trèfles ou trois coeurs ou trois piques ou trois carreaux
    else if (((nbAleatoire1 == 45)&&(nbAleatoire2 == 44)&&(nbAleatoire3 == 45)) || ((nbAleatoire1 == 40)&&(nbAleatoire2 == 39)&&(nbAleatoire3 == 40)) || ((nbAleatoire1 == 38)&&(nbAleatoire2 == 37)&&(nbAleatoire3 == 38)) || ((nbAleatoire1 == 30)&&(nbAleatoire2 == 29)&&(nbAleatoire3 == 30))) {
      jeton = 10;
      // Bluetooth
      BlueT.print("*A" + String("Bravo ! Vous avez gagne 10 jetons !") + "*");
      // Musique de petit jackpot
      sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00102);
    }
  
    // Cas où on tombe sur trois ananas ou trois raisin ou trois cerises
    else if (((nbAleatoire1 == 37)&&(nbAleatoire2 == 36)&&(nbAleatoire3 == 37)) || ((nbAleatoire1 == 32)&&(nbAleatoire2 == 31)&&(nbAleatoire3 == 32)) || ((nbAleatoire1 == 44) && (nbAleatoire2 == 43) && (nbAleatoire3 == 44))) {
      jeton = 5;
      // Bluetooth
      BlueT.print("*A" + String("Bravo ! Vous avez gagne 5 jetons !") + "*");
      // Musique de petit jackpot
      sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00102);
    }

    // Cas où aucun des 3 symboles ne sont alignés
    else {
      // Bluetooth
      BlueT.print("*A" + String("Perdu ! Vous n'avez rien gagne !") + "*");
      // Musique de perdant
      sendCommand(CMD_PLAY_WITHFOLDER, 0X0F00104);
    }

    // Rendu du monnayeur
    for (m = 0 ; m < jeton ; m++){ 
      servo4.writeMicroseconds(2050); // Pousse le jeton
      delay(700);
      servo4.writeMicroseconds(1760); // Revient à sa position initiale
      delay(700); 
    }
  
    // Arrête le monnayeur
    servo4.detach();
  
  }
  
}
