int ledPin[15] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 44, 45, 46}; // Add PWM pins
int ledState[15] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}; // Reserved led state
int ledFade[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // List of fade values
int ledCount = 15; // The amount of LEDs
int ledOn = false;

int micPin = A0; // Pin used for analog microphone input
int allowRun = true;

void setup() {
// Setup for led pins
  for (int i=0; i < ledCount; i++) {
    pinMode(ledPin[i], OUTPUT); // Sets each pin in array to output mode
  }
  // Setup for microphone
  pinMode(micPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //int micValue = analogRead(micPin); 
  //breathing(micValue);
  int one = random(0,15);
  int two = random(0,15);
  int three = random(0,15);
  peopleNear(one, two, three);
  delay(5);
}

//void breathing(
void breathing(int pin1, int pin2, int pin3) {
  if (pin1 == pin2) {
    // DO NOTHING
  }
  else if (pin1 == pin3) {
    // DO NOTHING
  }
  else if (pin2 == pin3) {
    // DO NOTHING
  }
  if (ledFade[pin1] == 0) {
    for (int q = 0; q <= 255; q += 5) {
      analogWrite(pin1, q)
      delay(10);
    }
    ledFade[pin1] = 255;
  }
  else if (ledFade[pin1] == 255) {
    for q = 255; q >= 0; q -= 5) {
      analoqWrite(pin1, w);
      delay(10);
    }
    ledFade[pin1] = 0;
  }
}
void peopleNear(int pin1, int pin2) {
  if (micVal < micThresh ) {
    //int passedTime = millis(); // Start a millisecond timer to slow down sequence a bit
    //int passedThresh = 200; // Initial threshold for time passed
    if (allowRun == true) {
      for (int p = 0; p < 5000000; p++) { // For loop to randomize the LED thingies
        //if (passedTime == passedThresh) { // Check if threshold milliseconds has been reached
          if (pin1 == pin2 || pin1 == pin3 || pin2 == pin3) {
            // Do nothing
          }
          else if (ledState[pin1] == HIGH) { // Detect prior state in order to reverse
            ledState[pin1] = LOW;
            // Serial.print("OFF");
            }
          else {
            ledState[pin1] = HIGH;
            //Serial.print("ON");
          }
          if (ledState[pin2] == HIGH) {
            ledState[pin2] = LOW;
          }
          else {
            ledState[pin2] = HIGH;
          }
          if (ledState[pin3] == HIGH) {
            ledState[pin3] = LOW;
          }
          else {
            ledState[pin3] = HIGH;
          }
          digitalWrite(ledPin[pin1], ledState[pin1]); // Write decided state to selected pin
          digitalWrite(ledPin[pin2], ledState[pin2]);
          digitalWrite(ledPin[pin3], ledState[pin3]);
          //passedThresh = passedThresh + 200; // Increase the threshold by 200 milliseconds
        //}
      }
      ledOn = true; // Used to tell whether program has been run
      //Serial.print("PERSON DETECTED!"); // Serial confirmation for debugging
    }
    //if (passedTime == 20000) { // 'hide' mode
    //  for (int l = 0; l < ledCount; l++) {
    //    digitalWrite(ledPin[l], LOW); // turn off all LED's
    //  }
    //  allowRun = false;
    //}
    //Serial.print("OH NO I'M SCARED!"); // Serial confirmation for debugging
  }
  Serial.print("SUCCESS "); 
}

