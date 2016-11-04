// Software for the Will-o-Wisp concept.
// Created in collaboration with Digital Experience & Aesthetics.

// Values used for output/LED addressing
int ledPin[15] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 46, 45, 44}; // Add PWM pins
int ledState[15] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}; // Reserved led state
int ledFade[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // List of fade values
int ledCount = 15; // The amount of LEDs
int ledOn = false;

// Microphone/input values
int micPin = A0; // Pin used for analog microphone input
int micThresh = 960; // Microphone threshold level
int micValue = 0;

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
  micValue = analogRead(micPin); //Read the analog value from the microphone
// Aggressive blinking
  if (micValue  < micThresh) {
    int passedTime = millis(); // Start a millisecond timer to slow down sequence a bit
    int passedThresh = 200; // Initial threshold for time passed
    for (int p = 0; p < 50000; p++) { // For loop to randomize the LED thingies
      int pinNum = random(0,15);
      if (passedTime == passedThresh) { // Check if threshold milliseconds has been reached
        if (ledState[pinNum] == HIGH) { // detect prior state in order to reverse
          ledState[pinNum] = LOW;
        }
        else {
          ledState[pinNum] = HIGH;
        }
        digitalWrite(ledPin[pinNum], ledState[pinNum]); // Write decided state to selected pin
        passedThresh = passedThresh + 200; // Increase the threshold by 200 milliseconds
      }
      
    }
    ledOn = true; // Used to tell whether program has been run
    Serial.printIn("PERSON DETECTED") // Serial confirmation for debugging
    /*
     * ADD A 'HIDE' MODE AFTER CERTAIN AMOUNT OF BLINKING
     *   > DONE WITH COUNTER INSIDE FOR-LOOP
     *   > RESET COUNTER EACH TIME
     */
  }
  
// Slow pulse/breathing
  if (micValue > micThresh) {
    if (ledOn == true) { // Detect if Aggressive Blinking program has run
      for (int o = 0; 0 < ledCount; o++) { // Turn off all LEDs for fresh start
      digitalWrite(ledPin[o], LOW);
      ledFade[o] = 0;
      }
    }
    for (int q = 0; p < 100000; q++) { // For-loop to increase/decrease fade amount on LEDs
      int pinNum = random(0,15); // Choose a random pin
      if (ledFade[pinNum] == 0) { // if-statement to increase brightness level
        for (int fade = 0; fade <= 255; fade += 5) {
          analogWrite(ledPin[pinNum],fade);
          if (fade == 255) {
            ledFade[pinNum] = fade;
          }
          delay(30); // Delay to visualize the fade effect
        }
      }
      if (ledFade[pinNum] > 0) { // if-statement to decrease brightness level
        for (int fade = 255; fade >= 0; -= 5) {
          analogWrite(ledPin[pinNum], fade);
          if (fade == 0) {
            ledFade[pinNum] = fade;
          }
          delay(30); // Delay to visualize the fade effect
        }
      }
    }
  }
// A 20 or so second sleep while selected program runs
}

