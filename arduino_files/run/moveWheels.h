#include "Arduino.h"

// top left
const int E1 = 24; //Enable Pin for top Left
const int I1 = 26; //Move forward
const int I2 = 28; //Move backward

// top right
const int E2 = 13; //Enable pin for top right
const int I3 = 11; //Move forward
const int I4 = 12; //Move backward

//bottom left
const int E3 = 38; //Enable pin for bottom left
const int I5 = 40; //Move forward
const int I6 = 42; //Move backward

//bottom right
const int E4 = 48; //Enable pin for bottom right
const int I7 = 44; //Move forward
const int I8 = 46; //Move backward

//Top Left Ultrasonic Sensor
const int trigPin3 = 5;
const int echoPin3 = 4;

void setupWheels();
double getDistance();
void runWheels();

void stopCar();
void moveForward(int ms);
void moveBackward(int ms);
void turnRight(int ms);
void turnLeft(int ms);
void adjustFar();
void adjustClose();
