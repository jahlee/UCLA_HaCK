#include "Arduino.h"

#define E1 22  // Enable Pin for motor 1  // top left side
#define E2 31  // Enable Pin for motor 2  // top right side
#define E3 8   // Enable pin for motor 3 // bottom left side
#define E4 45  // Enable pin for motor 4 // bottom right side

//Top left 
#define I1 24  // Control pin 1 for motor 1  // determine if forward or reverse
#define I2 26  // Control pin 2 for motor 1  // determine if forward or reverse

//Top Right
#define I3 27  // Control pin 1 for motor 2 // f r s
#define I4 29  // Control pin 2 for motor 2 // b r s

//Bottom Left
#define I5 9  // Control pin 1 for motor 3
#define I6 10 // Control pin 2 for motor 3

//Bottom Right
#define I7 47   //Control pin 1 for motor 4
#define I8 49   //Control pin 2 for motor 4

// for the sensor in the front
const int trigPin2 = 5;
const int echoPin2 = 7;

void setupWheels();
double getDistance();
void runWheels();

void stopCar();
void moveForward();
void moveBackward();
void turnRight();
void turnLeft();
void adjustFar();
void adjustClose();
