import SimpleOpenNI.*;
import processing.serial.*;
import fingertracker.*;
FingerTracker fingers;
SimpleOpenNI kinect;


// set a default threshold distance:
// 625 corresponds to about 2-3 feet from the Kinect
int threshold = 625;
int closestValue; //This holds our closest value 
double lastPos = 0.0;
int closestX; //closest X value
double fingerX;
int closestY; //closest Y value
double fingerY;

ArrayList<PVector> fingerPositions;

void setup(){
size(640, 480);
kinect = new SimpleOpenNI(this);
kinect.enableDepth();
kinect.setMirror(true);
fingers = new FingerTracker(this, 640, 480);

fingers.setMeltFactor(100);
fingerPositions = new ArrayList();


}
void draw(){
closestValue = 8000; 
kinect.update();
PImage depthImage = kinect.depthImage();
image(depthImage, 0, 0);

fingers.setThreshold(threshold);


// get the depth array from the kinect
int[] depthValues = kinect.depthMap();
fingers.update(depthValues);
// for each row in the depth image

  // iterate over all the fingers found  -- Below Code
  // and draw them as a red circle -- Below Code
  noStroke();
  fill(255,0,0);
  
  int lastAvg = 0 ;
  int currentAvg = 0;
  int sum = 0;
  int n;
  for (int i = 0; i < fingers.getNumFingers(); i++) {
    PVector position = fingers.getFinger(i);
    sum += (position.x + position.y);
    currentAvg = sum/5;
   ellipse(position.x - 5, position.y -5, 10, 10);
  }
  
  String stat; 
if(currentAvg > 600){
  stat = "Open";
}
else if (currentAvg >300 && currentAvg < 600){
  stat = "moving in between" ;
  }
else 
  stat = "closed";
  
  // show the threshold on the screen

//text("Threshold: " + threshold, 10, 20);

fill(255,0,0);
text("Fingers: " + currentAvg, 10, 20 + 10);


}

