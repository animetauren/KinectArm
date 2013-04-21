// Use the included processing code serial library
import processing.serial.*;        


int gx = 15;
int gy = 35;
int spos=90;

float leftColor = 0.0;
float rightColor = 0.0;
Serial port;                         // The serial port



void setup() 
{
  size(640, 480);
  colorMode(RGB, 1.0);
  noStroke();
  rectMode(CENTER);
  frameRate(100);

  println(Serial.list()); // List COM-ports

  //select second com-port from the list
  port = new Serial(this, Serial.list()[1], 19200); 
}

void draw() 
{
  background(0.0);
  update(mouseX); 
  fill(mouseX/4); 
  rect(150, 320, gx*2, gx*2); 
  fill(180 - (mouseX/4)); 
  rect(450, 320, gy*2, gy*2);
}

void update(int x) 
{
  //Calculate servo postion from mouseX
  spos= x/4;

  //Output the servo position ( from 0 to 180)
  
  println(x);
  println(spos);
  port.write("s"+spos); 
  port.write("w" + spos);



  // Just some graphics
  leftColor = -0.002 * x/2 + 0.06;
  rightColor =  0.002 * x/2 + 0.06;

  gx = x/2;
  gy = 100-x/2;

}

