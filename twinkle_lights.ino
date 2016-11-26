void setup() {
  //Set the two Digital pins to OUTPUT
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);

  //Turn the LEDs off
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);

  //Initialize the random number generator with a random seed pulled from
  //analog pin #3
  randomSeed(analogRead(3));
}

void loop() {

  //for (int i = 0; i < 1; i++) {

  //}
}
