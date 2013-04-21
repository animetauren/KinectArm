#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625 // this is the 'maximum' pulse length count (out of 4096)

uint8_t thumbServo = 0;  //thumb 
uint8_t s2Servo = 1;
void setup(){
  Serial.begin(9600);
  Serial.println("Let's Start");
  
  pwm.begin();
  
  pwm.setPWMFreq(60);
 
}

void loop() {
  // Drive each servo one at a time
  uint16_t pulselengthmin;
  uint16_t pulselengthmax;
  
  pulselengthmin = map(0, 0, 180, SERVOMIN, SERVOMAX);
  pulselengthmax = map(135, 0, 180, SERVOMIN, SERVOMAX);
  
 pwm.setPWM(thumbServo, 0 , pulselengthmax); //Goes from 0 to 25 degrees
 delay(500);
 
 //pwm.setPWM(thumbServo, pulselengthmin,0 );
//delay(500);

 pwm.setPWM(thumbServo, 0, pulselengthmin ); //goes from 25 degrees to 0 degress  
delay(500);


}
