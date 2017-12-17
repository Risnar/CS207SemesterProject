#include <Servo.h>

/*
  Fancy Bubble Machine

  This sketch serves two Servos, a DC Motor, a MultiColor_LED and a Laser-Pointer to operate an automatic bubble machine.

  created 27 Nov. 2017
  by Matthias Zehnder
*/

Servo panServo; // create servo object to control the pan servo
Servo tiltServo;  // create servo object to control the tilt servo
const int motorPin = 13;

byte pos = 0; // variable to store starting servo position

// Color Variables and Pin Constants
const int redPin = 2;
const int greenPin = 3;
const int bluePin = 4;
const int laser = 12;
float hue = 0, s = 1, v = 1;
float r,g,b;


void setup() {
  // Set up LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(laser, OUTPUT);

  
  pinMode(motorPin, OUTPUT); // Set up DC motor pin

  panServo.attach(8); //pan servo on pin 8
  tiltServo.attach(9); //tilt servo on pin 9
}

void loop() {
  
  changeLedColor();
  
  for(pos = 0; pos < 95; pos += 1) { //servo moves from 0 degrees to 95 degrees in steps of 1 degree
    tiltServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15); 
  }
  
  changeLedColor();

  for(pos = 95; pos >= 1; pos -= 1) { // tilt servo raises and levels off
    tiltServo.write(pos);
    delay(15);
  }

  changeLedColor();

  for(pos = 0; pos < 90; pos += 1) { //servo moves 0 degrees to 90 degrees in steps of 1 degree
    panServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15); 
  }
  
  changeLedColor();
  motorOnThenOff();

  
  for(pos = 90; pos >=1; pos -= 1) { // pan servo swings wand around
    panServo.write(pos);
    delay(15);
  }

  changeLedColor();

}

/*
 * motorOnThenOff() - turns motor on for 2 seconds and then off.
 */
void motorOnThenOff(){

  digitalWrite(laser, HIGH);   // turn the laser on (HIGH is the voltage level)
  digitalWrite(motorPin, HIGH); // turns the motor On
  delay(2000); // waits for 2 seconds
  digitalWrite(motorPin, LOW); // turns the motor Off
  digitalWrite(laser, LOW);    // turn the laser off by making the voltage LOW
  delay(500); // waits for 0.5 second
}

void changeLedColor(){
  hue = hue + 5;
  //make hue wrap around the color wheel
  if (hue < 0 || hue > 359){
    hue = 0;
  }
  
  //get the red green and blue values for the selected hue at full intensity
  hsv2rgb(hue,s,v,r,g,b);
  
  //write the color to the RGB LED
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);    
}

/* function: hsv2rb
 *   This function converts a color in hsv form to rgb form
 *   Based on the description provided on Wikipedia:
 *     http://en.wikipedia.org/w/index.php?title=HSL_and_HSV&oldid=456731840#From_HSV
 * Inputs:
 *    - h: hue. Must be between 0 and 359 inclusive. 
 *              If it is outside this range the color returned will be black.
 *    - s: saturation. Must be between 0 and 1 inclusive.
 *              s is clamped if it is out of range.
 *    - v: value. Must be between 0 and 1 inclusive.
 *              v is clamped if it is out of range.
 *
 * Outputs:
 *    - r: red. Value will be between 0 and 255 inclusive.
 *    - g: green. Value will be between 0 and 255 inclusive.
 *    - b: blue. Value will be between 0 255 inclusive.
 */
void hsv2rgb(float h, float s, float v, float &r, float &g, float &b)
{
  v = constrain(v, 0, 1);
  s = constrain(s, 0, 1);
  float c = v*s;
  float hprime = h/60.0f;
  float x = c * ( 1 - abs(hprime - ((int)hprime/2)*2 - 1));
  
  if (h < 0 || h > 360)
  {
    r = g = b = 0;
  }
  else if ( 0 <= hprime && hprime < 1)
  {
    r = c;
    g = x;
    b = 0;
  }
    else if ( 1 <= hprime && hprime < 2)
  {
    r = x;
    g = c;
    b = 0;
  }
    else if ( 2 <= hprime && hprime < 3)
  {
    r = 0;
    g = c;
    b = x;
  }
    else if ( 3 <= hprime && hprime < 4)
  {
    r = 0;
    g = x;
    b = c;
  }
    else if ( 4 <= hprime && hprime < 5)
  {
    r = x;
    g = 0;
    b = c;
  }
    else if ( 5 <= hprime && hprime < 6)
  {
    r = c;
    g = 0;
    b = x;
  }
  
  float m = v - c;
  r += m;
  g += m;
  b += m;
  r *= 255;
  g *= 255;
  b *= 255;
  
}

