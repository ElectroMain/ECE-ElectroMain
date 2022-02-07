#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4); //RX, TX

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT); // KEY PIN
  digitalWrite(8, HIGH); 
  Serial.println("Enter AT commands:");
  mySerial.begin(38400);
}

void loop() {
  if (mySerial.available())
    Serial.write(mySerial.read());
    
  if (Serial.available())
    mySerial.write(Serial.read());
}
