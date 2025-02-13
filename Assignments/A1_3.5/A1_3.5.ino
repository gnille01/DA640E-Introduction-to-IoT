#include <Arduino_LSM6DSOX.h>
#include <WiFiNINA.h>

//Defining input analog pins that are gouing to be used to read each axis

const int VRx_pin = 1;
const int VRy_pin = 0;

void setup() {
  // put your setup code here, to run once:

  //Connecting serial port to read the output data in serial plotter or serial monitor  
  Serial.begin(9600);

  //RGB LED
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //defining two variables to read the input
  int position_x;
  int position_y;

  //Reading the X an Y axes input as analog parameters

  position_x = analogRead(VRx_pin);
  position_y = analogRead(VRy_pin);

  //Print the variables X, Y
  Serial.print("X-axis: ");
  Serial.print(analogRead(VRx_pin));
  Serial.print("\n"); //Goes to the next line
  Serial.print("Y-axis: ");
  Serial.print(analogRead(VRy_pin));
  Serial.print("\n\n");

  delay(5); //Delay to improve the data visibility

  //RGB LED - axis
  // OFF
  if (position_x > 400 < 600 && position_y > 400 < 600){
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
  }

  // RED == HIGH if x > 600
  if (position_x > 600 && position_y > 400){
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
  }
  // GREEN == HIGH if x < 400
  if (position_x < 400 && position_y > 400){
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
  }
  //BLUE == HIGH if y > 600
  if (position_y > 600){
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
  }
  // YELLOW, RED & GREEN == HIGH
  if (position_y < 400){
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
  }

}
