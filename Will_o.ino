// Software for the Will-o-Wisp concept.
// Created in collaboration with Digital Experience & Aesthetics.

// Values used for output/LED addressing
int ledPin[15] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 46, 45, 44}; // Add PWM pins
int ledState[15] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}; // Reserved led state
int ledCount = 15; // The amount of LEDs
int ledOn = false;
int bright = 0; // Reserved brightness value
int fade = 0; // Reserved fade value

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
  micValue = analogRead(micPin);
// Aggressive blinking
  if (micValue  < micThresh) {
    for (int p = 0; p < ledCount; p++) { // For loop to randomize the LED thingies
      int pinNum = random(0,15);
      ledState[pinNum] = !ledState[pinNum]
      digitalWrite(ledPin[pinNum], ledState[pinNum]);
    }
    ledOn = !ledOn;
    // Timeout to avoid high speeds
  }
  
// Slow pulse/breathing
  if (micValue > micThresh) {
    if (ledOn == true) {
      for (int o = 0; 0 < ledCount; o++) { //
      digitalWrite(ledPin[o], LOW);
      }
    } 
    // Group LEDs possibly
    analogWrite(ledPin[x], brightness); // Add array numbers when known
    // Continue analogWrite for applicable amount
    bright = bright + fade;
    if (bright <= 0 || bright >= 255) {
      fade = -fade;
    }
    delay(30);
  }
  
// Randomly chosen (timebased or number generation)

// A 20 or so second sleep while selected program runs

}

