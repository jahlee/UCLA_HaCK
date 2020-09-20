#include "Arduino.h"

//Left Side Ultrasonic Sensor
const int trigPin1 = 2;
const int echoPin1 = 3;

//Right Side Ultrasonic Sensor
const int trigPin2 = 6;
const int echoPin2 = 7;

void setupSensors();
void runSensors();
