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

//Proto LEGO
//float speedRatioX = 0.95;
//float speedRatioY = -0.95;

//Proto 3D
float speedRatioX = 0.70;
float speedRatioY = 0.70;
 
coord movements[] = {
  {90, 90},   // Neutre
  {90, 180},    // Avancer
  {90, 0},  // Reculer
  {0, 90},    // Gauche
  {180, 90},  // Droite
  {0, 180},    // Diagonale NO
  {180, 180},  // Diagonale NE
  {0, 0},    // Diagonale SO
  {180, 0},  // Diagonale SE
};

void setup() {
  hc05Serial.begin(38400);
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);
  Serial.begin(115200);
}

void loop() {
  
  // Commande recu 
  if (hc05Serial.available()) {
    
    int cmd = hc05Serial.read();
    // Convertion ASCII vers décimal
    if (cmd >= 48 && cmd <= 57) {
      cmd = cmd - 48;
    } else {
      cmd = 0;
    }
      
    // Cas fonctionnement commande ponctuelle
    if (cmd >= 0 && cmd <= 8) {
      float x = (movements[cmd].x - 90) * speedRatioX + 90;
      float y = (movements[cmd].y - 90) * speedRatioY + 90;
      servoX.write(x);
      servoY.write(y);
    }    // Si commande non reconnu => position neutre par sécurité
    else {
      servoX.write(movements[0].x);
      servoY.write(movements[0].y);
    }
    
    
  }
  delay(60);
}


