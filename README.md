# CS 207 SemesterProject: Fancy Bubble Machine
===================================

This repository is for a semester project of the CS 207 – Building Interactive Gadgets
Course. The aim of the project is to build a 3D Spherical Atmosphere Encapsulated Phosphorous
Printer and a CNC Anti-Gravity transparent Orb Machine at the same time. The
target solution is a Bubble-Machine after the model of Bernard Katz Glass. The model is based on a movable arm that dips
a ring in soapy water. Afterwards, it turns around and a fan gets activated to blow bubbles into the air.


![alt text][pic1]

[pic1]: https://github.com/Risnar/CS207SemesterProject/blob/master/img/FancyBubbleBot.jpg "Fancy Bubble Bot"

Repository Contents
============
* **/documentation** - In this folder you will find all the documentation I handed in during this project.
* **/src** - In this folder is the source code for the bubble machine.
* **/hardware** - Here are all models and schematics.
* **/libraries** - Any libraries that are needed to build your software for your device.
* **/img** - This is where all images are stored.
* **/LICENSE** - The license file.
* **/README.md** - The file you're reading now! :-D

Requirements and Materials
============
Dependencies:
* Servo.h https://www.arduino.cc/en/Reference/Servo

Bill of Materials:
* 1x Arduino Uno
* 1x DC Motor
* 2x Micro servos
* 1x Stripe of LED / Multidimensional LED
* 1x Laser pointer
* 1x Diode
* 1x Transistor
* 4x 560Ω resistors
* 1x 2.2kΩ resistor
* Jumping wires

* 1x Bubble-Mix
* 2x metal angles
* 1x plastic plate
* Nuts and bolts of various sizes
* Poster putty
* Aluminum foil
* Cup/Bowl
* Duct Tape

Build Instructions
==================

To build the Fancy Bubble Machine, you have to realize the following schematic on your Arduino:

![alt text][pic2]

[pic2]: https://github.com/Risnar/CS207SemesterProject/blob/master/hardware/circuit.jpg "Arduino Circuit"

![alt text][pic3]

[pic3]: https://github.com/Risnar/CS207SemesterProject/blob/master/hardware/schematic.jpg "Arduino Schematic"

The multicolor LED needs three 560Ω resistors, for each color one before being connected to the Arduino digital pins 2 (red), 3 (green) and 4 (blue). Don't forget to connect it also to ground.

I used two servos to build the movable arm. Turn the lower(panServo) one 180 degrees, and the upper(tiltServo) one 90 degrees, then stick them together with poster putty. With duct tape I added the ring for the bubbles to the tiltServo. It should be in a 45 degree angle up. Due to the fact, that the wires are too short, I used jumper wires and connected them with a self-built aluminum /duct tape adapter to the servos. The three wires from each Servo have to be connected on the breadboard with 5V, Ground, digital pin 8 (panServo) and digital pin 9 (tiltServo).

The DC-Motor moves because of magnetism. Electromagnets can generate power. When you turn off an inductor it turns its magnetic field back into electricity flowing in the same direction as the previous current. This happens very quickly and the voltage can be very high - up to 10 times of the source voltage. This is the reason why I added a Diode to protect the other parts in my circuit. To ensure, that the motor gets enough power, an NPN transistor has been added. NPN stands for negative positive negative which is their internal silicone structure. A small amount of current applied to the base can allow very large amounts of current to flow from the emitter to the collector. The whole motor-circle is following: Connect digital pin 13 with a 2.2kΩ resistor to the transistor. The transistor is connected to ground on one side and to the motor and the diode on the other side. The opposite wire of the motor and the diode are connected to 5V.

The laser pointer works similar to a led. You need a 560Ω resistor, connect one side to ground and the other to the digital pin 12.

My playground is a plastic cake box. Screw the metal angles together and then onto the cake box. On top of the smaller angle I attached the motor with poster putty. My propeller is made out of duct tape, but I am sure that you can find better solutions. Above the motor I glued the laser. Make sure that it points in the right direction to illuminate the bubbles. The last step is to stick the moveable arm onto the box. I also did this with poster putty. Check that the servos can move without touching anything but are still close enough, that the motor can create bubbles. On the side of the cake box I made a whole for all wires. With this set up the Arduino and the electronic parts are protected from the bubble soap.


Usage
=====
* Upload the code to the Arduino.
* Fill bubble soap into the bowl
* Connect the Arduino to a power supply, either USB or with an AC-DC adapter
* Enjoy the automatic produced bubbles.

Credits
=======
I would like to give credit to:

* Bernard Katz Glass - He gave me the idea and the model described on the website www.instructables.com
* Julián Rodales - For his support in building the robot.
