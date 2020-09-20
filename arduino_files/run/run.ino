#include "getSensorData.h"
#include "moveWheels.h"
// use this file to run everything, #include "all of the header files you have"

void setup()
{
  setupSensors();
  setupWheels();
  Serial.begin(9600);
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
      delay(3000);
    }
    else if (command == 'c') {
      Serial.println("CLOSE: -1");
      adjustClose();
    }
    else if (command == 'f') {
      Serial.println("FAR: -1");
      adjustFar();
    }
  }
  runSensors();
  runWheels();
}
