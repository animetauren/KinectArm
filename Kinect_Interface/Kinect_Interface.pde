import SimpleOpenNI.*;
import processing.serial.*;
SimpleOpenNi kinect;
Serial myPort;

PVector handVec = new PVector();
Pvector mapHandVec = new PVector();
color handPointCol = color(255, 0, 0);
int photoVal;

void setup();
{
	kinect = new SimpleOpenNI(this);
	kinect.setMirror(true);
	
	kinect.enableDepth();
	kinect.enableRGB();
	kinect.enableGesture();
	kinect.enableHands();	
	kinect.addGesture();

	size(kinect.depthWidth(), kinect.depthHeight());
	String portName = Serial.list()[0];
	myPort = new Serial(this, portName, 9600);
	myPort.bufferUntil('\n');
}

void draw()
{
	kinect.update();
	kinect.converRealWorldToProjective(handVec, mapHandVec);
	
	if (photoVal < 500)
	{
		image (kinect.rgbImage(), 0, 0);
	}
	
	else
	{
		image (kinect.depthImage(), 0, 0);
	}

	myPort.write('S');
	myPort.write(int(255*mapHandVec.x/width));
	myPort.write(int(255*mapHandVec.y/height));
}

void serialEvent (Serial myPort)
{
	String inString = myPort.readStringUntil('\n');
	if (inString != null)
	{
		inString = trim(inString);
		photoVal = int(inString);
	}

	else
	{
		println("No Data to Display");
	}
}
