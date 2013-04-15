#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625 // this is the 'maximum' pulse length count (out of 4096)

uint8_t thumbServo = 0;  //thumb servo
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
  pulselengthmax = map(180, 0, 180, SERVOMIN, SERVOMAX);
  
  Serial.println(thumbServo);
  for (uint16_t pulselen = pulselengthmin; pulselen < pulselengthmax; pulselen++) {
    pwm.setPWM(thumbServo, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = pulselengthmax; pulselen > pulselengthmin; pulselen--) {
    pwm.setPWM(thumbServo, 0, pulselen);
  }
  delay(500);

  thumbServo ++;
  if (thumbServo > 0) thumbServo = 0;
}
