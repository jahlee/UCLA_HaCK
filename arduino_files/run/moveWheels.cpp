#include "moveWheels.h"

// WHAT I THINK WILL WORK

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
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

double getDistance()
{
  delayMicroseconds(2);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  long duration = pulseIn(echoPin2, HIGH);

  // distance is in centimeters
  double distance2 = (double)duration * 345 / 2 / 10000;

  // print so that python has this data
  if (distance2 > 150)
  {
    Serial.print("front: ");
    Serial.println(distance2); // in cm
  }
  return distance2;
}

void runWheels()
{
  double dist = getDistance();
  delay(50);

  // too close for a full turn
  if (dist <= 10)
  {
    moveBackward();
    delay(500);
    stopCar();
  }
  // need to turn
  else if (dist <= 25)
  {
    stopCar();
    delay(300);
    turnLeft();
  }
  // this else might be unnecessary
  else
  {
    moveForward();
  }
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
}

void moveForward()
{
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  digitalWrite(I5, HIGH);
  digitalWrite(I6, LOW);
  digitalWrite(I7, HIGH);
  digitalWrite(I8, LOW);
}

void moveBackward()
{
  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  digitalWrite(I5, LOW);
  digitalWrite(I6, HIGH);
  digitalWrite(I7, LOW);
  digitalWrite(I8, HIGH);
}

void turnRight()
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

  delay(500); // how long we turn for

  // go forwards
  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 255); // Run in full speed
  analogWrite(E3, 255); // Run in full speed
  analogWrite(E4, 255); // Run in full speed

  digitalWrite(I1, HIGH);
  digitalWrite(I3, HIGH);

  digitalWrite(I2, LOW);
  digitalWrite(I4, LOW);

  digitalWrite(I5, HIGH);
  digitalWrite(I7, HIGH);

  digitalWrite(I6, LOW);
  digitalWrite(I8, LOW);
}

void turnLeft()
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

  delay(500); // how long we turn for

  // go forwards
  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 255); // Run in full speed
  analogWrite(E3, 255); // Run in full speed
  analogWrite(E4, 255); // Run in full speed

  digitalWrite(I1, HIGH);
  digitalWrite(I3, HIGH);

  digitalWrite(I2, LOW);
  digitalWrite(I4, LOW);

  digitalWrite(I5, HIGH);
  digitalWrite(I7, HIGH);

  digitalWrite(I6, LOW);
  digitalWrite(I8, LOW);

}

void adjustFar() {
  // turn right
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

  delay(250); // how long we turn for

  // turn left
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

  delay(150); // how long we turn for

  // go forwards
  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 255); // Run in full speed
  analogWrite(E3, 255); // Run in full speed
  analogWrite(E4, 255); // Run in full speed

  digitalWrite(I1, HIGH);
  digitalWrite(I3, HIGH);

  digitalWrite(I2, LOW);
  digitalWrite(I4, LOW);

  digitalWrite(I5, HIGH);
  digitalWrite(I7, HIGH);

  digitalWrite(I6, LOW);
  digitalWrite(I8, LOW);
}

void adjustClose() {
  // turn left
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

  delay(250); // how long we turn for

  // turn right
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

  delay(150); // how long we turn for

  // go forwards
  analogWrite(E1, 255); // Run in full speed
  analogWrite(E2, 255); // Run in full speed
  analogWrite(E3, 255); // Run in full speed
  analogWrite(E4, 255); // Run in full speed

  digitalWrite(I1, HIGH);
  digitalWrite(I3, HIGH);

  digitalWrite(I2, LOW);
  digitalWrite(I4, LOW);

  digitalWrite(I5, HIGH);
  digitalWrite(I7, HIGH);

  digitalWrite(I6, LOW);
  digitalWrite(I8, LOW);
}
