
const int StepX = 26;//2;
const int DirX = 16;//5;
const int StepY = 25;//3;
const int DirY = 27;//6;

#define N_STEPS 1500

void setup() {
  pinMode(StepX, OUTPUT);
  pinMode(DirX, OUTPUT);
  pinMode(StepY, OUTPUT);
  pinMode(DirY, OUTPUT);
}

void loop() {
digitalWrite(DirX, HIGH);
digitalWrite(DirY, LOW);
 
 for(int x = 0; x < N_STEPS; x++) { // loop for 200 steps
  digitalWrite(StepX, HIGH);
  delayMicroseconds(500);
  digitalWrite(StepX, LOW); 
  delayMicroseconds(500);
 }
delay(500); // delay for 1 second

for(int x = 0; x < N_STEPS; x++) { // loop for 200 steps
  digitalWrite(StepY, HIGH);
  delayMicroseconds(500);
  digitalWrite(StepY, LOW); 
  delayMicroseconds(500);
 }
delay(500); // delay for 1 second
}
