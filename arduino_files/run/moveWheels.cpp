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

  // print in case we need the data for python drawing (?)
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
    stop();
  }
  // need to turn
  else if (dist <= 25)
  {
    stop();
    delay(300);
    turnLeft();
  }
  // this else might be unnecessary
  else
  {
    moveForward();
  }
}

void stop()
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
}

// IF NOT then look at some of these examples:

// https://www.instructables.com/id/Using-Motors-With-L293D-IC/
//L293D
//#define E1 10  // Enable Pin for motor 1
//#define E2 11  // Enable Pin for motor 2
//
//#define I1 8  // Control pin 1 for motor 1
//#define I2 9  // Control pin 2 for motor 1
//#define I3 12  // Control pin 1 for motor 2
//#define I4 13  // Control pin 2 for motor 2
//
//void setup() {
//
//    pinMode(E1, OUTPUT);
//    pinMode(E2, OUTPUT);
//
//    pinMode(I1, OUTPUT);
//    pinMode(I2, OUTPUT);
//    pinMode(I3, OUTPUT);
//    pinMode(I4, OUTPUT);
//}
//
//void loop() {
//
//    analogWrite(E1, 153); // Run in half speed
//    analogWrite(E2, 255); // Run in full speed
//
//    digitalWrite(I1, HIGH);
//    digitalWrite(I2, LOW);
//    digitalWrite(I3, HIGH);
//    digitalWrite(I4, LOW);
//
//    delay(10000);
//
//    // change direction
//
//    digitalWrite(E1, LOW);
//    digitalWrite(E2, LOW);
//
//    delay(200);
//
//    analogWrite(E1, 255);  // Run in full speed
//    analogWrite(E2, 153);  // Run in half speed
//
//    digitalWrite(I1, LOW);
//    digitalWrite(I2, HIGH);
//    digitalWrite(I3, LOW);
//    digitalWrite(I4, HIGH);
//
//    delay(10000);
// }

// https://github.com/shveytank/Arduino-obstacle-avoidance-car/blob/master/Obstacl_Avoiding_Robot.ino
//#include <Servo.h>          //Servo motor library. This is standard library
//#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library
//our L298N control pins
//const int LeftMotorForward = 5;
//const int LeftMotorBackward = 4;
//const int RightMotorForward = 3;
//const int RightMotorBackward = 2;

//sensor pins
//#define trig_pin A3 //analog input 1
//#define echo_pin A2 //analog input 2
//
//// max distance it will go before checking
//#define maximum_distance 200
//
//boolean goesForward = false;
//int distance = 100;
//
//NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
//Servo servo_motor; //our servo name
//
//
//void setup(){
//
//  pinMode(RightMotorForward, OUTPUT); // mp1
//  pinMode(LeftMotorForward, OUTPUT);  // mp2
//  pinMode(LeftMotorBackward, OUTPUT); // mp3
//  pinMode(RightMotorBackward, OUTPUT);// mp4
//
//  servo_motor.attach(11); //our servo pin
//
//  servo_motor.write(90);
//  delay(2000);
//  distance = readPing();
//  delay(100);
//  distance = readPing();
//  delay(100);
//  distance = readPing();
//  delay(100);
//  distance = readPing();
//  delay(100);
//}
//
//void loop(){
//
//  int distanceRight = 0;
//  int distanceLeft = 0;
//  delay(50);
//
//  if (distance <= 20){
//    stop();
//    delay(300);
//    moveBackward();
//    delay(400);
//    stop();
//    delay(300);
//    distanceRight = lookRight();
//    delay(300);
//    distanceLeft = lookLeft();
//    delay(300);
//
//    if (distance >= distanceLeft){
//      turnRight();
//      stop();
//    }
//    else{
//      turnLeft();
//      stop();
//    }
//  }
//  else{
//    moveForward();
//  }
//    distance = readPing();
//}
//
//int lookRight(){
//  servo_motor.write(10);
//  delay(500);
//  int distance = readPing();
//  delay(100);
//  servo_motor.write(90);
//  return distance;
//}
//
//int lookLeft(){
//  servo_motor.write(170);
//  delay(500);
//  int distance = readPing();
//  delay(100);
//  servo_motor.write(90);
//  return distance;
//  delay(100);
//}
//
//int readPing(){
//  delay(70);
//  int cm = sonar.ping_cm();
//  if (cm==0){
//    cm=250;
//  }
//  return cm;
//}
//
//void stop(){
//
//  digitalWrite(RightMotorForward, LOW);
//  digitalWrite(LeftMotorForward, LOW);
//  digitalWrite(RightMotorBackward, LOW);
//  digitalWrite(LeftMotorBackward, LOW);
//}
//
//void moveForward(){
//
//  if(!goesForward){
//
//    goesForward=true;
//
//    digitalWrite(LeftMotorForward, HIGH);
//    digitalWrite(RightMotorForward, HIGH);
//
//    digitalWrite(LeftMotorBackward, LOW);
//    digitalWrite(RightMotorBackward, LOW);
//  }
//}
//
//void moveBackward(){
//
//  goesForward=false;
//
//  digitalWrite(LeftMotorBackward, HIGH);
//  digitalWrite(RightMotorBackward, HIGH);
//
//  digitalWrite(LeftMotorForward, LOW);
//  digitalWrite(RightMotorForward, LOW);
//
//}
//
//void turnRight(){
//
//  digitalWrite(LeftMotorForward, HIGH);
//  digitalWrite(RightMotorBackward, HIGH);
//
//  digitalWrite(LeftMotorBackward, LOW);
//  digitalWrite(RightMotorForward, LOW);
//
//  delay(500);
//
//  digitalWrite(LeftMotorForward, HIGH);
//  digitalWrite(RightMotorForward, HIGH);
//
//  digitalWrite(LeftMotorBackward, LOW);
//  digitalWrite(RightMotorBackward, LOW);
//
//
//
//}
//
//void turnLeft(){
//
//  digitalWrite(LeftMotorBackward, HIGH);
//  digitalWrite(RightMotorForward, HIGH);
//
//  digitalWrite(LeftMotorForward, LOW);
//  digitalWrite(RightMotorBackward, LOW);
//
//  delay(500);
//
//  digitalWrite(LeftMotorForward, HIGH);
//  digitalWrite(RightMotorForward, HIGH);
//
//  digitalWrite(LeftMotorBackward, LOW);
//  digitalWrite(RightMotorBackward, LOW);
//}
