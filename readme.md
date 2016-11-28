Arduino Twinkle Lights in a Jar
===============================

## Introduction

This project is an Arduino variant of the [Pimoroni Firefly Light](https://learn.pimoroni.com/tutorial/sandyj/firefly-light) project. I thought the project was cool, but they threw an awful lot of hardware into the solution, so I wanted to see if I could build something with less parts and for less money.

Basically you place two strings of battery-powered LEDs into a glass jar and use an Arduino to fade one strand on while the other strand fades to off. This process repeats for as long as the Arduino has power. 

## Required Hardware

+ Arduino Pro Trinket 3V
+ Power thingie
+ Battery
+ Glass Jar
+ 2 strings of LEDs

## Hardware Assembly


## Application Code

The application code starts with a few constant definitions:

Use the `pin0` and `pin1` constants to tell the application which analog write pins the LED strand's positive wires are connected. For my implementation, I connected them to pins 9 and 10. If you use different pins, change the values in the following constants:
    
	//Analog ouput pin assignments
	int pin0 = 9;
	int pin1 = 10;
	
As the lights fade up and down, the application uses the `delayVal` value to specify, in milliseconds, how long to wait between each change in voltage.

	//Specifies how long the application delays between changes to output voltage
	int delayVal = 20;  //in milliseconds

The applicaton uses several loops to control fading the LEDs. Rather than type the max loop counter in each loop, I defined a constant to use. Don't change this value, there's no need to that I can think of - I just used this to keep from having a number (255) repeated throughout the code.
	
	//Constant representing max analog output
	int maxAnalog = 255;

This is some text.

	void setup() {
	  //The setup function initializes the application
	  //In this case, we'll just start by winding strand 1 up to
	  //full illumination
	  for (int i = 0; i <= maxAnalog; i++) {
	    //Write the voltage value
	    analogWrite(pin1, i);
	    //Pause for a little while
	    delay(delayVal);
	  }
	  //Wait a second before continuing 
	  delay(1000);
	}

This is some text.

	void loop() {
	  //Strand 0 up, strand 1 down
	  for (int i = 0; i <= maxAnalog; i++) {
	    //Write the voltage values
	    analogWrite(pin0, i);
	    analogWrite(pin1, maxAnalog - i);
	    //Pause for a little while
	    delay(delayVal);
	  }
	  //Wait a second before continuing 
	  delay(1000);
	  //Strand 1 up, strand 0 down
	  for (int i = 0; i <= maxAnalog; i++) {
	    //Write the voltage values
	    analogWrite(pin0, maxAnalog - i);
	    analogWrite(pin1, i);
	    //Pause for a little while
	    delay(delayVal);
	  }
	  //Wait a second before continuing 
	  delay(1000);
	}

and this is some end text.

***

If you find this code useful, and feel like thanking me for providing it, please consider making a purchase from [my Amazon Wish List](https://amzn.com/w/1WI6AAUKPT5P9). You can find information on many different topics on my [personal blog](http://www.johnwargo.com). Learn about all of my publications at [John Wargo Books](http://www.johnwargobooks.com). 