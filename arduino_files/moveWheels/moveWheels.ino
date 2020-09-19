// NOT SURE WHICH MOTOR WE HAVE
// pick and choose from either... at the very bottom is a mix of both that i'm going to guess is what will work
// but ill let you test it out



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
//    moveStop();
//    delay(300);
//    moveBackward();
//    delay(400);
//    moveStop();
//    delay(300);
//    distanceRight = lookRight();
//    delay(300);
//    distanceLeft = lookLeft();
//    delay(300);
//
//    if (distance >= distanceLeft){
//      turnRight();
//      moveStop();
//    }
//    else{
//      turnLeft();
//      moveStop();
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
//void moveStop(){
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



// WHAT I THINK WILL WORK

#include <Servo.h>          // Servo motor library
#include <NewPing.h>        // Ultrasonic sensor function library

// our L293D control pins
#define E1 10  // Enable Pin for motor 1  // left side
#define E2 11  // Enable Pin for motor 2  // right side
 
#define I1 8  // Control pin 1 for motor 1  // forwards left side
#define I2 9  // Control pin 2 for motor 1  // backwards left side
#define I3 12  // Control pin 1 for motor 2 // f r s
#define I4 13  // Control pin 2 for motor 2 // b r s

//const int LeftMotorForward = 5;
//const int LeftMotorBackward = 4;
//const int RightMotorForward = 3;
//const int RightMotorBackward = 2;

//sensor pins
#define trig_pin A3 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo


void setup(){

    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
  
  servo_motor.attach(11);   // our servo pin

  servo_motor.write(90);    // look forwards i think
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();    // idk why it does this so many times lol
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(I1, LOW)
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
}

void turnRight(){
  // turn
  analogWrite(E1, 255);  // Run in full speed
  analogWrite(E2, 153);  // Run in half speed
  
  digitalWrite(I1, HIGH);
  digitalWrite(I4, HIGH);
  
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  
  delay(500); // how long we turn for
  
  // go forwards
  analogWrite(E1, 255);  // Run in full speed
  analogWrite(E2, 255);  // Run in full speed
  
  digitalWrite(I1, HIGH);
  digitalWrite(I3, HIGH);
  
  digitalWrite(I2, LOW);
  digitalWrite(I4, LOW);
  
}

void turnLeft(){

  // turn
  analogWrite(E1, 153); // Run in half speed
  analogWrite(E2, 255); // Run in full speed
  
  digitalWrite(I2, HIGH);
  digitalWrite(I3, HIGH);
  
  digitalWrite(I1, LOW);
  digitalWrite(I4, LOW);
  
  delay(500); // how long we turn for
  
  // go forwards
  analogWrite(E1, 255);  // Run in full speed
  analogWrite(E2, 255);  // Run in full speed
  
  digitalWrite(I1, HIGH);
  digitalWrite(I3, HIGH);
  
  digitalWrite(I2, LOW);
  digitalWrite(I4, LOW);
}
