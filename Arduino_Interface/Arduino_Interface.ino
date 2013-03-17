#include <Servo.h>

Servo thumbServo;  //thumb servo
Servo finger2Servo;  //the finger beneath the thumb servo
Servo finger3Servo; //the middle finger
Servo finger4Servo; //the penultimate finger
Servo pinkyServo;   // pinky servo

int val, xVal, yVal;
int sensorValue;
int sensorPin = 0;

void setup()
{
	pinMode(1,OUTPUT);

        thumbServo.attach(2);
        finger2Servo.attach(3);
        finger3Servo.attach(4);
        finger4Servo.attach(5);
        pinkyServo.attach(6);
        
        Serial.begin(9600);
        Serial.println("Ready");
}

void loop()
{
static int v = 0;
 
 
  if ( Serial.available()) {
    char ch = Serial.read();
 
 
    switch(ch) {
      case '0'...'9':
        v = v*10 + (int)(ch - '0');
        break;
      case 's':
        thumbServo.write(v);
        v = 0;
        break;
      case 'w':
        finger2Servo.write(v);
        v = 0;
        break;
      case 'd':
        finger2Servo.detach();
        break;
      case 'a':
        finger2Servo.attach(15);
        break;
    }
  }
}
