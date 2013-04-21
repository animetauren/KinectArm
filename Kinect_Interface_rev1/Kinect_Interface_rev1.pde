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

// for each row in the depth image

  // iterate over all the fingers found  -- Below Code
  // and draw them as a red circle -- Below Code
  noStroke();
  fill(255,0,0);
  
  for (int i = 0; i < fingers.getNumFingers(); i++) {
    PVector position = fingers.getFinger(i);
    ellipse(position.x - 5, position.y -5, 10, 10);
  }
  
  //We can most likely select a finger by using fingers.getFinger(i);

PVector fingerOne = fingers.getFinger(1);
PVector fingerTwo = fingers.getFinger(2);
PVector fingerThree = fingers.getFinger(3);
PVector fingerFour = fingers.getFinger(4);
PVector fingerFive = fingers.getFinger(5);
PVector lastFingerPos;


//Sample Position Track for FingerOne

double pos = fingers.getFingerX(1) + fingers.getFingerY(1);

if( pos > 0 && pos != lastPos){ //checks to see that position of x and y are greater thn 0 and if they changed
      // save its value
  lastPos = pos;
      // and save its position (both X and Y coordinates)
  fingerX = fingers.getFingerX(1); 
  fingerY = fingers.getFingerY(1);
}

 //draw the depth image on the screen
image(kinect.depthImage(),0,0);
// draw a red circle over it,
// positioned at the X and Y coordinates
// we saved of the closest pixel.
fill(255,0,0);
ellipse(closestX, closestY, 25, 25);
}

