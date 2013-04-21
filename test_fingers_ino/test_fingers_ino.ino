#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625 // this is the 'maximum' pulse length count (out of 4096)
// 387 is our middle pulse length of 90
// 

uint8_t thumbServo = 0;  //thumb servo
uint8_t finger2Servo = 1;  //the finger beneath the thumb servo
uint8_t finger3Servo = 2; //the middle finger
uint8_t finger4Servo = 3; //the penultimate finger
uint8_t pinkyServo = 4;   // pinky servo



void setup() {

  Serial.begin(19200);
  Serial.println("Ready");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {

  static int v = 0;
   uint16_t pulseInput;

  if ( Serial.available()) {
    char ch = Serial.read();

    switch(ch) {
      case '0'...'9':
        v = v * 10 + ch - '0';
        break;
      case 's':
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(thumbServo, 0 , v);
        v = 0;
        break;
      case 'w':
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger2Servo, 0 , v);
        v = 0;

    }
  }


} 

