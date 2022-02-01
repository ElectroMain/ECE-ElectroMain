#include <Servo.h>
#include <SoftwareSerial.h>

#define servoPinX 10
#define servoPinY 11

typedef struct {
  int x;
  int y;
} coord;

Servo servoX;
Servo servoY;
SoftwareSerial hc05Serial(3, 4); //RX, TX

int movementFlag = 0;
float speedRatioX = 1;
float speedRatioY = 0.95;

coord movements[] = {
  {80, 130},   // Neutre
  {90, 180},    // Reculer
  {0, 90},    // Gauche
  {180, 90},  // Droite
  {90, 0},  // Avancer
};

void setup() {
  hc05Serial.begin(9600);
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);
}

void loop() {
  // Position neutre si fonctionnement commande continu
  if (movementFlag == 1) {
    servoX.write(movements[0].x);
    servoY.write(movements[0].y);
  }
  
  // Commande recu 
  if (hc05Serial.available()) {
    // Reset du flag de fonctionnement
    movementFlag = 0;
    
    String msg = hc05Serial.readString();
    int cmd = msg.toInt();

    // Cas fonctionnement commande ponctuelle
    if (cmd >= 0 && cmd <= 4) {
      float x = (movements[cmd].x - 90) * speedRatioX + 90;
      float y = (movements[cmd].y - 90) * speedRatioY + 90;
      servoX.write(x);
      servoY.write(y);
    }
    // Cas fonctionnement commande continu
    else if (cmd >= 5 && cmd <= 8) {
      movementFlag = 1;
      servoX.write(movements[cmd-4].x);
      servoY.write(movements[cmd-4].y);
    }
    // Si commande non reconnu => position neutre par sécurité
    else {
      servoX.write(movements[0].x);
      servoY.write(movements[0].y);
    }
  }
  delay(100);
}
