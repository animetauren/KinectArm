#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)


uint8_t thumbServo = 0;  //thumb servo
uint8_t finger2Servo = 1;  //the finger beneath the thumb servo
uint8_t finger3Servo = 2; //the middle finger
uint8_t finger4Servo = 3; //the penultimate finger
uint8_t pinkyServo = 4;   // pinky servo

int val, xVal, yVal;
int sensorValue;
int sensorPin = 0;

void setup()
{
        Serial.begin(9600);
        Serial.println("Ready");
        pwm.begin();
        pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
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
        pwm.setPWM(1,0,9)
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
