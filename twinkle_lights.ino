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
const int delayVal = 20;  //in milliseconds

//Constant representing max analog output
const int maxAnalog = 255;

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
