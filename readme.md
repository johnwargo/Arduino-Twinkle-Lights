Arduino Twinkle Lights in a Jar
===============================

## Introduction

This project is an Arduino variant of the [Pimoroni Firefly Light](https://learn.pimoroni.com/tutorial/sandyj/firefly-light) project. I thought the project was cool, but they threw an awful lot of hardware into the solution, so I wanted to see if I could build something with less parts and for less money.

Basically you place two strings of battery-powered LEDs into a glass jar and use an Arduino to fade one strand on while the other strand fades to off. This process repeats for as long as the Arduino has power.

![Finished Project](images/figure-01.png)

Here's a video of the project in action:

<iframe src="https://player.vimeo.com/video/193441242" width="640" height="360" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
<p><a href="https://vimeo.com/193441242">Arduino Twinkle Lights</a> from <a href="https://vimeo.com/user39135142">John Wargo</a> on <a href="https://vimeo.com">Vimeo</a>.</p>

## Required Hardware

Basically, all you need is an Arduino, battery, glass vessel and some battery-powered LEDs. The project (as I've implemented it) uses the following hardware: 

+ [Adafruit Pro Trinket - 3V 12MHz](https://www.adafruit.com/products/2010)
+ [Adafruit Pro Trinket LiIon/LiPoly Backpack Add-On](https://www.adafruit.com/products/2124)
+ [Lithium Ion Polymer Battery - 3.7v 500mAh](https://www.adafruit.com/products/1578)
+ Ikea [ENSIDIG Glass Jar](http://www.ikea.com/gb/en/products/decoration/vases-bowls/ensidig-vase-clear-glass-art-10239888/)
+ 2 of Ikea [SÄRDAL LED light chain with 12 lights](http://www.ikea.com/us/en/catalog/products/60277514/)

## Hardware Assembly

1.	Solder the included headers to the **Adafruit Pro Trinket LiIon/LiPoly Backpack Add-On**. 

	![Soldered Headers](images/figure-02.png)

	> **Note:** If you want, connect a SPST switch to the board using the instructions available on [the board's product page](https://www.adafruit.com/products/2124).
	 
	> ![Power Switch](images/figure-0#.png)

2.	Solder the Adafruit Pro Trinket LiIon/LiPoly Backpack Add-On onto the **Arduino Pro Trinket 3V**.  

	![Solder backpack to the Arduino device](images/figure-03.png)

3.	Disassemble the **SÄRDAL LED light chain** units. Use a Philips screwdriver to remove the screws from the top and bottom of the battery case. The LED strand connects to a circuit board inside the battery case, make note of which wires are connected to the battery's positive (`+`) and negative (`-`) terminals. 

	![Battery Terminals](images/figure-04.png)

4.	*Optional:* To protect the circuit, solder a small resistor (in my measurements, the existing battery pack includes a 2.5 Ohm resistor) to each strand's positive (`+`) wire. I grabbed some 47 Ohm resistors I had lying around to use for this. 
	
	> **Note:** To protect the circuit from shorting out, I added some shrink tubing over the soldered connection and resistor.  

	![Adding Resistors](images/figure-05.png)
	
5.	Solder the wires from the LED strands to the appropriate pins on the **Arduino Pro Trinket 3V**.

	For each strand, solder the strand's negative (`-`) wire to the two `GROUND` pins in the lower-left corner of the figure. Solder each strand's positive (`+`) wire to pins `9` and `10` in the upper-left corner of the figure. Solder the wires from one strand to pin `9` and the wire from the other strand to pin `10`.  

	![Adafruit Pro Trinket Pinouts](https://cdn-learn.adafruit.com/assets/assets/000/025/646/medium800/adafruit_products_pro5.png?1432753967)

	![Completed Assembly](images/figure-06.png)

6.	Plug the **Lithium Ion Polymer Battery** to the Adafruit Pro Trinket LiIon/LiPoly Backpack Add-On.

	![Completed Project](images/figure-07.png)

7.	Connect the Trinket to your PC using a USB cable and **download the project's compiled code** into the device. The project's code is located in the repository's `twinkle_lights.ino` file. You can find complete directions on how to setup your development environment and deploy compiled code to the Trinket in the [Trinket tutorial](https://learn.adafruit.com/introducing-pro-trinket/overview). 
	
8.	**Stuff the whole contraption into the jar** and turn it on. You're done!

	![Finished Project](images/figure-01.png)

## Application Code

The application code starts with a few constant definitions:

Use the `pin0` and `pin1` constants to tell the application which analog write pins the LED strand's positive wires are connected. For my implementation, I connected them to pins 9 and 10. If you use different pins, change the values in the following constants:
    
	//Analog ouput pin assignments
	const int pin0 = 9;
	const int pin1 = 10;
	
As the lights fade up and down, the application uses the `delayVal` value to specify, in milliseconds, how long to wait between each change in voltage. Increase the value to the right of the equals sign to make the LEDs fade slower. Decrease the value to the right of the equals sign to make the LEDs fade faster. 

	//Specifies how long the application delays between changes to output voltage
	const int delayVal = 20;  //in milliseconds

The applicaton uses several loops to control fading the LEDs. Rather than type the max loop counter in each loop, I defined a constant to use. Don't change this value, there's no need to that I can think of - I just used this to keep from having a number (255) repeated throughout the code.
	
	//Constant representing max analog output
	const int maxAnalog = 255;

The `setup` function is where the Arduino sketch initializes its hardware and software parameters. For this project, we don't have to do much; since the LED strands alternate between fading up and down, we want to fade one of the strands to maximum brightness before we start repeating the process. So, in the `setup` function, the code simply fades the second strand (the one connected to `pin1`) up to max.

	void setup() {
	  //Initialize the up and down pin designators
	  upPin = pin1;
	  downPin = pin0;
	
	  //The setup function initializes the application
	  //In this case, we'll just start by winding strand 1 up to
	  //full illumination
	  for (int i = 0; i <= maxAnalog; i++) {
	    //Write the voltage value
	    analogWrite(upPin, i);
	    //Pause for a little while
	    delay(delayVal);
	  }
	  //Wait a second before continuing
	  delay(1000);
	}

With the LED strands properly initialized, the `loop` function cycles one strand up to maximum power while cycling the other down to off. This process repeats until power is removed from the microcontroller.

	void loop() {
	  //Variable to keep track of one of the pin assignments
	  //as we swap them
	  int tmp;
	  //Hold on to the current upPin value
	  tmp = upPin;
	  //set upPin to the downPin value
	  upPin = downPin;
	  //Then set downPin to what used to be in upPin
	  downPin = tmp;
	
	  //Look through the voltage output values (from 0 to 255)
	  //increment by 1
	  for (int i = 0; i <= maxAnalog; i++) {
	    //Drive the upPin up to maxAnalog
	    analogWrite(upPin, i);
	    //While simultaneously driving downPin down to 0
	    analogWrite(downPin, maxAnalog - i);
	    //Pause for a little while
	    delay(delayVal);
	  }
	  //Wait a second before continuing
	  delay(1000);
	}


***

If you find this code useful, and feel like thanking me for providing it, please consider making a purchase from [my Amazon Wish List](https://amzn.com/w/1WI6AAUKPT5P9). You can find information on many different topics on my [personal blog](http://www.johnwargo.com). Learn about all of my publications at [John Wargo Books](http://www.johnwargobooks.com). 
