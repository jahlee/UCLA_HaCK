#include "Arduino.h"

#define E1 10 // Enable Pin for motor 1  // left side
#define E2 11 // Enable Pin for motor 2  // right side

#define I1 8  // Control pin 1 for motor 1  // forwards left side
#define I2 9  // Control pin 2 for motor 1  // backwards left side
#define I3 12 // Control pin 1 for motor 2 // f r s
#define I4 13 // Control pin 2 for motor 2 // b r s

const int trigPin2 = 5;
const int echoPin2 = 7;

void setupWheels();
double getDistance();
void runWheels();

void stop();
void moveForward();
void moveBackward();
void turnRight();
void turnLeft();
