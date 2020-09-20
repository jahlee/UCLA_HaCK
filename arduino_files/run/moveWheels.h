#include "Arduino.h"

// top left
const int enA = 24; //Enable Pin for top Left
const int in1 = 26; //Move forward
const int in2 = 28; //Move backward

// top right
const int enB = 13; //Enable pin for top right
const int in3 = 11; //Move forward
const int in4 = 12; //Move backward

//bottom left
const int enC = 38; //Enable pin for bottom left
const int in5 = 40; //Move forward
const int in6 = 42; //Move backward

//bottom right
const int enD = 48; //Enable pin for bottom right
const int in7 = 44; //Move forward
const int in8 = 46; //Move backward

//Top Left Ultrasonic Sensor
const int trigPin3 = 5;
const int echoPin3 = 4;

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
