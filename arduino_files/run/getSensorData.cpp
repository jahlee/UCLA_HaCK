#include "getSensorData.h"
// ~ = trig = write
void setupSensors()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

void runSensors()
{
  // inside sensor (facing middle)
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  long duration = pulseIn(echoPin1, HIGH);

  // distance is in centimeters
  double distance1 = (double)duration * 345 / 2 / 10000;

  // distance is <= 1.5 meters
  if (distance1 <= 150)
  {
    Serial.print("inside: ");
    Serial.println(distance1); // in cm
  }


  // outside sensor (facing wall)
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  duration = pulseIn(echoPin3, HIGH);

  // distance is in centimeters
  double distance3 = (double)duration * 345 / 2 / 10000;

  // distance is <= 1.5 meters
  if (distance3 <= 150)
  {
    Serial.print("outside: ");
    Serial.println(distance3); // in cm
  }
}
