#include <AccelStepper.h>

#define FULLSTEP 4
#define TOT_MOTOR_STEPS 2038L
#define N_OF_ROUNDS 10L
#define MAX_SPEED 2000L
#define ACCELERATION 50

AccelStepper mioStepper(FULLSTEP, 8, 10, 9, 11);

void setup() {
    mioStepper.setMaxSpeed(MAX_SPEED);
    mioStepper.setAcceleration(ACCELERATION);
    mioStepper.setSpeed(500);
    mioStepper.moveTo(N_OF_ROUNDS*TOT_MOTOR_STEPS);
}
void loop()
{
    if (mioStepper.distanceToGo() == 0){
        mioStepper.moveTo(-mioStepper.currentPosition());
    }
    mioStepper.run();
}