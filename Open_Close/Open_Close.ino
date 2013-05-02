#include <Servo.h>

Servo thumb, index, ring, pinky, middle; 
int incomingNum;

void setup() {

  pinMode(1,OUTPUT);
  thumb.attach(14); //analog pin 0
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  index.attach(15); //analog pin 1
  ring.attach(16); //analog pin 2
  pinky.attach(17); //analog pin 3
  middle.attach(18); //analog pin 
  Serial.begin(19200);
  Serial.println("Ready");

}

void loop() {

  static int v = 0;

  if ( Serial.available()) {
    incomingNum = Serial.read();

      if(incomingNum > 3){  //checks to see if open
        thumb.write(145);
        delay(15);
        index.write(145);
        delay(15);
        ring.write(145);
        delay(15);
        pinky.write(105);
        delay(15);
        middle.write(145);
        delay(15);
        }
        else //not open so closed
        thumb.write(0);
        index.write(0);
        ring.write(0);
        pinky.write(0);
        middle.write(0);

    }
  }




