#include <Wire.h>
//#include <MPU6050.h>
//#include <Servo.h>   // Servo motor library
//#include <NewPing.h> // Ultrasonic sensor function library
#include "getSensorData.h"
#include "moveWheels.h"
// use this file to run everything, #include "all of the header files you have"

void setup()
{
  setupSensors();
  setupWheels();
}

void loop()
{
  runSensors();
  runWheels()
  // put your main code here, to run repeatedly:
}
