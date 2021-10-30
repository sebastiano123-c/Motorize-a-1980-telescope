#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 1000;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(20);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  myStepper.step(-stepsPerRevolution);
}


// #define ONBOARD_LED  2

// void setup() {
//   pinMode(ONBOARD_LED,OUTPUT);
// }

// void loop() {
//   delay(1000);
//   digitalWrite(ONBOARD_LED,HIGH);
//   delay(100);
//   digitalWrite(ONBOARD_LED,LOW);
// }