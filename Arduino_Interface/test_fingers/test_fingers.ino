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

void setup() {
  Serial.begin(9600);
  Serial.println("Let's Test Some Servos!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
 
}

void loop(){
  uint16_t pulselen;
 double degrees;
  pulselen = map(degrees,0,180, SERVOMIN, SERVOMAX );   

    pwm.setPWM(2, 300, 600);
    //pwm.setPWM(2, 0, 400);
    pwm.setPWM(2, 300, 450);
    //pwm.setPWM(2, 0, 600);
    //pwm.setPWM(2, 0, 600);
    //pwm.setPWM(2, 0, 600);
    //pwm.setPWM(2, 0, 450);
   //pwm.setPWM(2, 0, 400);
   pwm.setPWM(2, 300, 600);
    

   
}
