#include "getSensorData.h"

void setupSensors()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  Serial.begin(9600);
}

void runSensors()
{
  // ~ = trig = write

  // inside sensor
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
}

/* troubleshoot:
 *  
 *  Disconnect and reconnect the USB cable.
    Press the reset button on the board.
    Restart the Arduino IDE.
    Make sure you select the right board in Tools ► Board ►, e.g. If you are using the Duemilanove 328, select that instead of Duemilanove 128. The board should say what version it is on the microchip.
    Make sure you selected the right port in Tools ► Serial Port ►. One way to figure out which port it is on is by following these steps:
    Disconnect the USB cable.
    Go to Tools ► Serial Port ► and see which ports are listed (e.g. COM4 COM5 COM14).
    Reconnect the USB cable.
    Go back to Tools ► Serial Port ►, and see which port appeared that wasn't there before.
 */

/*
char Incoming_value = 0;

void setupSensors()
{

  Serial.begin(9600); //Sets the baud rate for serial data
                      //transmission
}

void runSensors()
{
  if (Serial.available() > 0)
  {
    float val = 30.00;
    char cmd = Serial.read();
    if (cmd == 's')
    {
      Serial.println(val);
      delay(100);
    }
  }
}

/*
 * const int trigPin = 3;
const int echoPin = 4;
long duration;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  double distance = (double)duration * 345 / 2 / 1000000;
  if (distance > 0.75) {
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);
  }
  Serial.println(duration);
  Serial.println(distance); // in meters
}
 */
