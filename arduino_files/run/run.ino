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
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'e') {
      Serial.println("EXIT: 0");
      return;
    }
    else if (command == 'w') {
      Serial.println("WAIT: 0");
      return;
    }
    else if (command == 's') {
      delay(5000);
      Serial.println("STOP: 0");
    }
  }
  runSensors();
  runWheels()
  // put your main code here, to run repeatedly:
}
