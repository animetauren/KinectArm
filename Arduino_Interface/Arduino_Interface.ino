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
        Serial.println("Ready!");
}

void loop()
{
	sensorValue = analogRead(sensorPin);
	Serial.println(sensorValue);
	delay(10);

	if (Serial.available()>2)
	{
		val = Serial.read();
		if (val =='S')
		{
			xVal = Serial.read();
			yVal = Serial.read();
		}
	}
	
	analogWrite(10, xVal);
	analogWrite(11, yVal);
}
