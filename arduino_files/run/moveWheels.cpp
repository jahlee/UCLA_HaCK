#include "moveWheels.h"

void setupWheels()
{
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(E3, OUTPUT);
  pinMode(E4, OUTPUT);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(I5, OUTPUT);
  pinMode(I6, OUTPUT);
  pinMode(I7, OUTPUT);
  pinMode(I8, OUTPUT);
  
  // sets up the front sensor
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void runWheels()
{
  double dist = getDistance();
  delay(50);
  moveForward(500);
  
  // too close for a full turn
  if (dist <= 15)
  {
    moveBackward(300);
    stopCar();
  }
  // need to turn
  else if (dist <= 30)
  {
    stopCar();
    turnLeft(500);
  }
}


double getDistance()
{
  delayMicroseconds(2);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  long duration = pulseIn(echoPin3, HIGH);

  // distance is in centimeters
  double distance3 = (double)duration * 345 / 2 / 10000;

  // print so that python has this data
  if (distance3 > 150)
  {
    Serial.print("front: ");
    Serial.println(distance3); // in cm
  }
  return distance3;
}

void stopCar()
{
  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
  digitalWrite(I5, LOW);
  digitalWrite(I6, LOW);
  digitalWrite(I7, LOW);
  digitalWrite(I8, LOW);
  delay(500);
}

void moveForward(int ms)
{
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  digitalWrite(I5, HIGH);
  digitalWrite(I6, LOW);
  digitalWrite(I7, HIGH);
  digitalWrite(I8, LOW);
  delay(ms);
}

void moveBackward(int ms)
{
  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  digitalWrite(I5, LOW);
  digitalWrite(I6, HIGH);
  digitalWrite(I7, LOW);
  digitalWrite(I8, HIGH);
  delay(ms);
}

void turnRight(int ms)
{
  // turn
  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 153); // Run in half speed
  analogWrite(E3, 255); // Run in full speed
  analogWrite(E4, 153); // Run in half speed

  digitalWrite(I1, HIGH);
  digitalWrite(I4, HIGH);

  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);

  digitalWrite(I5, HIGH);
  digitalWrite(I8, HIGH);

  digitalWrite(I6, LOW);
  digitalWrite(I7, LOW);

  delay(ms); // how long we turn for

  // go forwards
  moveForward(ms / 2);
}

void turnLeft(int ms)
{
  // turn
  analogWrite(E1, 153); // Run in half speed
  analogWrite(E2, 255); // Run in full speed
  analogWrite(E3, 153); // Run in half speed
  analogWrite(E4, 255); // Run in full speed

  digitalWrite(I2, HIGH);
  digitalWrite(I3, HIGH);

  digitalWrite(I1, LOW);
  digitalWrite(I4, LOW);

  digitalWrite(I6, HIGH);
  digitalWrite(I7, HIGH);

  digitalWrite(I5, LOW);
  digitalWrite(I8, LOW);

  delay(ms); // how long we turn for

  // go forwards
  moveForward(ms / 2);
}

void adjustFar() {
  // turn right
  turnRight(250);

  // turn left
  turnLeft(150);

  // go forwards
  moveForward(100);
}

void adjustClose() {
  // turn left
  turnLeft(250);

  // turn right
  turnRight(150);
  
  // go forwards
  moveForward(100);
}
