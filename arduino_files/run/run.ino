#include "getSensorData.h"
#include "moveWheels.h"
// use this file to run everything, #include "all of the header files you have"
int looper = 11;
double pastWallDist = -1;

void setup()
{
  setupSensors();
  setupWheels();
  Serial.begin(9600);
  delay(3000); // wait 3 seconds before starting
}

void loop()
{
  //  if (Serial.available() > 0) {
  //    char command = Serial.read();
  //    if (command == 'e') {
  //      Serial.println("EXIT: 0");
  //      return;
  //    }
  //    else if (command == 'w') {
  //      Serial.println("WAIT: 0");
  //      delay(3000);
  //    }
  //    else if (command == 'c') {
  //      Serial.println("CLOSE: -1");
  //      adjustClose();
  //    }
  //    else if (command == 'f') {
  //      Serial.println("FAR: -1");
  //      adjustFar();
  //    }
  //  }
  double curr = runSensors();
  if (looper == 11)
  {
    pastWallDist = curr;
  }
  else if (looper == 0)
  {
    looper = 10;
    if (pastWalDist - curr > 20)
    {
      shiftLeft(pastWallDist - curr);
    }
    else if (curr - pastWallDist > 20)
    {
      shiftRight(curr - pastWallDist);
    }
  }
  runWheels();
}
