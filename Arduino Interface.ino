int val, xVal, yVal;
int sensorValue;
int sensorPin = 0;

void setup()
{
	serial.gein(9600);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
}

void loop()
{
	sensorValue = analogRead(sensorPin);
	Serial.println(sensorValue);
	delay(10);

	if (Serial.available()>2
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