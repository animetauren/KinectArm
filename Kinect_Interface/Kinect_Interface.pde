import SimpleOpenNI.*;
import processing.serial.*;
import fingertracker.*;
FingerTracker fingers;
SimpleOpenNi kinect;
Serial myPort;

// set a default threshold distance:
// 625 corresponds to about 2-3 feet from the Kinect
int threshold = 625;

//PVector handVec = new PVector();
//PVector mapHandVec = new PVector();
//color handPointCol = color(255, 0, 0);
//int photoVal;

float spos=90;
float currentX;
float lastX;
float currentY;
float lastY;
int x;
int y;
 
float interpolatedX;
float interpolatedY;

ArrayList<PVector> fingerPositions;
PVector currentLocFinger;
PVector prevLocFinger;
void setup(){
    
        size(640, 480);
	kinect = new SimpleOpenNI(this);
        kinect.enableDepth();
	kinect.setMirror(true);

        // initialize the FingerTracker object
        // with the height and width of the Kinect
        // depth image
        fingers = new FingerTracker(this, 640, 480);
        // the "melt factor" smooths out the contour
        // making the finger tracking more robust
        // especially at short distances
        // farther away you may want a lower number
        fingers.setMeltFactor(100);
        
        fingerPositions = new ArrayList(); // Stores the values from PVector(hand positions over time)
        
	
	//kinect.enableRGB();
	//kinect.enableGesture();
	//kinect.enableHands();	
	//kinect.addGesture();

	//size(kinect.depthWidth(), kinect.depthHeight());
	String portName = Serial.list()[0];
	myPort = new Serial(this, portName, 9600);
	myPort.bufferUntil('\n');
}

void draw()
{
	kinect.update();
        PImage depthImage = kinect.depthImage();
        image(depthImage,0,0);
        fingers.setThreshold(threshold)
        int[] depthMap = kinect.depthMap();
        fingers.update(depthMap);
	
        // iterate over all the fingers found
        // and draw them as a red circle
        noStroke();
        fill(255,0,0);
        for (int i = 0; i < fingers.getNumFingers(); i++)
        {
        PVector position = fingers.getFinger(i);
        ellipse(position.x - 5, position.y -5, 10, 10);
        }
        
        for (int i=1;i<fingerPositions.size();i++)
        {
        currentLocFinger = fingerPositions.get(i);
        prevLocFinger = fingerPositions.get(i-1);
        
        currentX=(currentLocFinger.x);
        lastX=(prevLocFinger.x);   
        currentY=(currentLocFinger.y);
        lastY=(prevLocFinger.y);
        
   
        float interpolatedX = lerp(lastX,currentX,0.3f);
        lastX = int(interpolatedX);
        float interpolatedY = lerp(lastY,currentY,0.3f);
        lastY = int(interpolatedY);
        x= int(lastX);
        y= int(lastY);
        }
   
        fill(255,0,0);
        ellipse(lastX,lastY,15,15); 
        
        spos= lastX/4;       // Calculate the servo position from lastX 
        x= int(lastX);
        println (x);
        myPort.write("s"+spos);    // Output the Servo Positions from 0 to 180
        //kinect.converRealWorldToProjective(handVec, mapHandVec);
	
}

    void onCreateFingers(int handId, PVector position, float time){
      kinect.convertRealWorldToProjective(position,position);
      fingerPositions.add(position);
    }
 
    void onUpdateFingers(int handId, PVector position, float time){
      kinect.convertRealWorldToProjective(position,position);
      fingerPositions.add(position);
    }
 


