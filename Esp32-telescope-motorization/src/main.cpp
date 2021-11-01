#include <Arduino.h>

// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech

const int StepX = 26;//2;
const int DirX = 16;//5;
const int StepY = 25;//3;
const int DirY = 27;//6;

void setup() {
  pinMode(StepX, OUTPUT);
  pinMode(DirX, OUTPUT);
  pinMode(StepY, OUTPUT);
  pinMode(DirY, OUTPUT);
}

void loop() {
digitalWrite(DirX, HIGH);
digitalWrite(DirY, LOW);
 
 for(int x = 0; x < 200; x++) { // loop for 200 steps
  digitalWrite(StepX, HIGH);
  delayMicroseconds(500);
  digitalWrite(StepX, LOW); 
  delayMicroseconds(500);
 }
delay(1000); // delay for 1 second

for(int x = 0; x < 200; x++) { // loop for 200 steps
  digitalWrite(StepY, HIGH);
  delayMicroseconds(500);
  digitalWrite(StepY, LOW); 
  delayMicroseconds(500);
 }
delay(1000); // delay for 1 second
}


// #include <Arduino.h>
// #define LED 2

// void setup() {
//   // Set pin mode
//   pinMode(LED,OUTPUT);
// }

// void loop() {
//   delay(500);
//   digitalWrite(LED,HIGH);
//   delay(500);
//   digitalWrite(LED,LOW);
// }