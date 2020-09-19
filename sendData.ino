// currently gets the distance of 4 sensors if they are further than 150cm
const int trigPin1 = 3;
const int echoPin1 = 4;

const int trigPin2 = 5;
const int echoPin2 = 7;

const int trigPin3 = 6;
const int echoPin3 = 8;

const int trigPin4 = 9;
const int echoPin4 = 12;
long duration;

void setup()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // ~ = trig = write
  
  // TOP LEFT
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration = pulseIn(echoPin1, HIGH);
  
  // distance is in centimeters
  double distance1 = (double)duration * 345 / 2 / 10000;
  
  if (distance1 > 150) {
    Serial.print("topleft: ");
    Serial.println(distance1); // in xm
  }
  
  
  // TOP RIGHT
  delayMicroseconds(2);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  duration = pulseIn(echoPin2, HIGH);
  
  // distance is in centimeters
  double distance2 = (double)duration * 345 / 2 / 10000;
  
  if (distance2 > 150) {
    Serial.print("topright: ");
    Serial.println(distance2); // in xm
  }
  
  
  // BOTTOM LEFT
  delayMicroseconds(2);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  
  duration = pulseIn(echoPin3, HIGH);
  
  // distance is in centimeters
  double distance3 = (double)duration * 345 / 2 / 10000;
  
  if (distance3 > 150) {
    Serial.print("bottomleft: ");
    Serial.println(distance3); // in xm
  }
  
  
  // BOTTOM RIGHT
  delayMicroseconds(2);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  
  duration = pulseIn(echoPin4, HIGH);
  
  // distance is in centimeters
  double distance4 = (double)duration * 345 / 2 / 10000;
  
  if (distance4 > 150) {
    Serial.print("bottomright: ");
    Serial.println(distance4); // in xm
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

//char Incoming_value = 0;
//
//void setup() 
//{
//
//  Serial.begin(9600); //Sets the baud rate for serial data
//         //transmission 
//}
//
//void loop()
//{
//  if(Serial.available() > 0) 
//  {
//    float val = 30.00;
//    char cmd = Serial.read(); 
//    if (cmd == 's')
//    {
//      Serial.println(val);
//      delay(100);
//    }
//  }
//}

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
