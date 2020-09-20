#include "Arduino.h"

#define E1 10 // Enable Pin for motor 1  // left front side
#define E2 11 // Enable Pin for motor 2  // right front side
#define E3 12 // Enable Pin for motor 1  // left back side
#define E4 13 // Enable Pin for motor 2  // right back side

#define I1 8  // Control pin 1 for motor 1  // forwards left front side
#define I2 9  // Control pin 2 for motor 1  // backwards left front side
#define I3 12 // Control pin 1 for motor 2  // f r f s
#define I4 13 // Control pin 2 for motor 2  // b r f s
#define I5 6  // Control pin 1 for motor 3  // forwards left back side
#define I6 7  // Control pin 2 for motor 3  // backwards left back side
#define I7 5 // Control pin 1 for motor 4  // f r b s
#define I8 4 // Control pin 2 for motor 4  // b r b s

// for the sensor in the front
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
