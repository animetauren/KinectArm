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
    int count = Serial.read();
int v = 90;
    switch(count) {
      case 3:
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(thumbServo, 0 , v);
        delay(500);
        break;
        
      case 4:
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(thumbServo, 0 , v);
        delay(500);
        
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger2Servo, 0 , v);
       delay(500);
        break;
        
      case 5:
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(thumbServo, 0 , v);
        delay(500);
        
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger2Servo, 0 , v);
       delay(500);
       
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger3Servo, 0 , v);
      break;
      
        case 6:
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(thumbServo, 0 , v);
        delay(500);
        
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger2Servo, 0 , v);
       delay(500);
       
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger3Servo, 0 , v);
        delay(500);
        
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger4Servo, 0 , v);
      break;
      
        case 7:
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(thumbServo, 0 , v);
        delay(500);
        
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger2Servo, 0 , v);
        delay(500);
       
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger3Servo, 0 , v);
        delay(500);
        
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(finger4Servo, 0 , v);
        delay(500); 
        pulseInput = map(v , 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(pinkyServo, 0 , v);
        
      break;

    }
  }


} 

