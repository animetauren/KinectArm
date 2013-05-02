// import the fingertracker library
// and the SimpleOpenNI library for Kinect access
import fingertracker.*;
import SimpleOpenNI.*;
import processing.serial.*; 

// declare FignerTracker and SimpleOpenNI objects
FingerTracker fingers;
SimpleOpenNI kinect;
// set a default threshold distance:
// 625 corresponds to about 2-3 feet from the Kinect
int threshold = 1500;

int lowestDepth = 800;
int highestDepth = 1200;
Serial port;                         // The serial port


void setup() {
size(640, 480);

// initialize your SimpleOpenNI object
// and set it up to access the depth image
kinect = new SimpleOpenNI(this);
kinect.enableDepth();
// mirror the depth image so that it is more natural
kinect.setMirror(true);

// initialize the FingerTracker object
// with the height and width of the Kinect
// depth image
fingers = new FingerTracker(this, 640, 480);
// the "melt factor" smooths out the contour
// making the finger tracking more robust
// especially at short distances
// farther away you may want a lower number
fingers.setMeltFactor(90);
  port = new Serial(this, Serial.list()[1], 19200); 

}

void draw() {
background(0);
// get new depth data from the kinect
kinect.update();
// get a depth image and display it
PImage depthImage = kinect.depthImage();
//image(depthImage, 0, 0);

// update the depth threshold beyond which
// we'll look for fingers
fingers.setThreshold(threshold);

// access the "depth map" from the Kinect
// this is an array of ints with the full-resolution
// depth data (i.e. 500-2047 instead of 0-255)
// pass that data to our FingerTracker
int[] depthMap = kinect.depthMap();
int[] depthValues = new int[640 * 480];

// for each row in the depth image
for(int y = 0; y < 480; y++)
{
// look at each pixel in the row
for(int x = 0; x < 640; x++)
{
int i = x + y * 640;
int currentDepthValue = depthMap[i];

if(currentDepthValue > lowestDepth && currentDepthValue < highestDepth)
{
stroke(255);
point(x, y);
depthValues[i] = currentDepthValue;
}
}
}

fingers.update(depthValues);

// iterate over all the fingers found
// and draw them as a red circle

  int lastAvg = 0 ;
  int currentAvg = 0;
  int sum = 0;
  int n=0;
noStroke();
fill(255,0,0);
for (int i = 0; i < fingers.getNumFingers(); i++) {
PVector position = fingers.getFinger(i);
    n = i;
    sum += (position.x + position.y);
    currentAvg = sum/(i+1);
ellipse(position.x - 5, position.y -5, 10, 10);
}
  
  String numFing;
if (n  > 3){
  numFing = "Open";
}
  else
  numFing = "Closed";

  
// show the threshold on the screen
  String stat; 
if(currentAvg > 500){
  stat = "Open";
}

else 
  stat = "closed";
  
  // show the threshold on the screen

//text("Threshold: " + threshold, 10, 20);


fill(255,0,0);
text("Fingers: " + numFing, 10, 20 + 10);
port.write(n);
}



// keyPressed event:
// pressing the '-' key lowers the threshold by 10
// pressing the '+/=' key increases it by 10 



