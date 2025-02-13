
#include <WiFiNINA.h>

int buttonpin= 3;   // declare the variable for the store button pin
int pinstatus, lastatus;     // declare variable to store the pin status
int R = 0;        //counter
int G = 0;
int B = 0;


void setup() {
  pinMode(buttonpin, INPUT);  //
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop()
{
pinstatus=digitalRead(buttonpin);  // read the status of digital pin and stores the value of pin status

if (pinstatus == LOW && lastatus == HIGH){  //if statament checks if button is pressed
  R++;                  //adds 1 to x if button is pressed
  G++;
  B++;
  Serial.println("Cyrus");
}
  if (R > 2){           //checks if x is higher than 2 
    R = 0;              //and sets x to 0
  }
  if (G > 2){
    G = 0;
  }
  if (B > 2){
    B = 0;
  }
  //if (x==0) {
  //digitalWrite(LEDR, LOW);
  //digitalWrite(LEDG, LOW);
  //digitalWrite(LEDB, LOW);
  //}

  if (R==0) {    // if statement checks buttonpress count                      
      digitalWrite(LEDR, HIGH);   // and turns on an RGB and turns off the others
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, LOW);
    }

  if (G==1){
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, LOW);
    }

  if (B==2){
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, HIGH);
  }  

  if (R > 2 || G > 2 || B > 2){
    R = 0;
    G = 0;
    B = 0;
  }

lastatus = pinstatus;
}
