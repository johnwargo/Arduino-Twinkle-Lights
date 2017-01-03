/*************************************************************************

    Arduino Twinkle Lights
    by John M. Wargo (www.johnwargo.com)
    November, 2016

    This project is an Arduino variant of the Pimoroni Firefly Light
    (https://learn.pimoroni.com/tutorial/sandyj/firefly-light) project.
 ************************************************************************/

//Analog ouput pin assignments
const int pin0 = 9;
const int pin1 = 10;
//Specifies how long the application delays between changes to output voltage
const int delayVal = 10;  //in milliseconds
//Constant representing max analog output
const int maxAnalog = 255;

//Used to track which pin is going up and which down
int upPin, downPin;

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
