#include "Arduino.h"

// change as you please
const int trigPin1 = 3;
const int echoPin1 = 4;

const int trigPin2 = 5;
const int echoPin2 = 7;

const int trigPin3 = 6;
const int echoPin3 = 8;

const int trigPin4 = 9;
const int echoPin4 = 12;
long duration;

void setupSensors();
void runSensors();