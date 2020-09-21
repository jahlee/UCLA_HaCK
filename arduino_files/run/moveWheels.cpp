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

  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 255); // Run in full speed
  analogWrite(E3, 255); // Run in full speed
  analogWrite(E4, 255); // Run in full speed

  // sets up the front left sensor
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // sets up the front right sensor
  //  pinMode(trigPin4, OUTPUT);
  //  pinMode(echoPin4, INPUT);
}

void runWheels()
{
  double dist = getDistance();
  delay(50);

  // too close for a full turn
  if (dist <= 15)
  {
    stopCar();
    moveBackward(1500);
    turnLeft(750);
  }
  // need to turn
  else if (dist <= 35)
  {
    stopCar();
    turnLeft(2700);
  }
  else
  {
    moveForward(300);
  }
}

double getDistance()
{
  // distance from left front sensor
  delayMicroseconds(2);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  long duration = pulseIn(echoPin3, HIGH);

  // distance is in centimeters
  double distance3 = (double)duration * 345 / 2 / 10000;

  // distance from front right sensor
  //  delayMicroseconds(2);
  //  digitalWrite(trigPin4, LOW);
  //  delayMicroseconds(2);
  //
  //  digitalWrite(trigPin4, HIGH);
  //  delayMicroseconds(10);
  //  digitalWrite(trigPin4, LOW);
  //
  //  duration = pulseIn(echoPin4, HIGH);
  //
  //  // distance is in centimeters
  //  double distance4 = (double)duration * 345 / 2 / 10000;
  //
  //  double avgDistance = (distance3 + distance4) / 2;
  //  double minDistance = min(distance3, distance4);
  //  double maxDistance = max(distance3, distance4);
  //
  //  // print so that python has this data
  //  if (avgDistance < 150)
  //  {
  //    Serial.print("afront: ");
  //    Serial.println(avgDistance); // in cm
  //  }
  //
  //  Serial.print("LeftFront: ");
  //  Serial.println(distance3);
  //  Serial.print("RightFront: ");
  //  Serial.println(distance4);
  //
  //  if (abs(distance3 - distance4) > 20) {
  //    return maxDistance;
  //  }
  //  return avgDistance;
  Serial.print("front: ");
  Serial.println(distance3);
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
  delay(250);
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
}

void adjustFar(double dist)
{
  // turn right
  turnRight((int)dist * 10);

  // turn left
  turnLeft((int)dist * 5);

  // go forwards
  moveForward(100);
}

void adjustClose(double dist)
{
  // turn left
  turnLeft((int)dist * 10);

  // turn right
  turnRight((int)dist * 5);

  // go forwards
  moveForward(100);
}