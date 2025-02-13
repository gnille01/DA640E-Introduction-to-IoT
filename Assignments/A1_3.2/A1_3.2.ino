#include <WiFiNINA.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDR, HIGH); //RED ON
  delay(4000);
  digitalWrite(LEDG, HIGH); //GREEN ON
  delay(2000);              //YELLOW_
  digitalWrite(LEDG, LOW);  //GREEN OFF
  digitalWrite(LEDB, HIGH); //BLUE ON
  delay(4000);              //MAGENTA_
  digitalWrite(LEDR, LOW);  //RED OFF
  digitalWrite(LEDG, HIGH); //GREEN ON
  delay(2000);              //CYAN_
  digitalWrite(LEDB, LOW);  //BLUE OFF

}
