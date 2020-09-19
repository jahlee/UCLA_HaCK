// use this file to run everything, #include "all of the header files you have"

#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>   // Servo motor library
#include <NewPing.h> // Ultrasonic sensor function library

#inlcude "accel.h"
#inlcude "getSensorData.h"
#inlcude "gyro.h"
#inlcude "moveWheels.h"

// comment out whichever you don't need to use
void setup()
{
  setupAccel();
  setupSensors();
  setupGyro();
  setupWheels();
}

// put your main code here, to run repeatedly:
void loop()
{
  runAccel();
  runSensors();
  runGyro();
  runWheels();
}
