int ledPin[] = {}; // Add PWM pins
int dB = 0; // Add microphone value
// int LED_group1 = 11; // Add pin
// int LED_group2 = 10; // Add pin
// int LED_group3 = 9; // Add pin

int bright = 0; // Adjusted later on
int fade = 0; // Adjusted later on

void setup() {
  pinMode(LED_group1, OUTPUT);
  pinMode(LED_group2, OUTPUT);
//  pinMode(LED_group3, OUTPUT);
}

void loop() {
// Aggressive blinking
  if (dB < 30 && dB > 25) {
    digitalWrite(ledPin[x],HIGH); // Add array numbers when known
    // Continue digitalWrite for Applicable amount
  }
  //digitalWrite(LED_group1, HIGH);
  //digitalWrite(LED_group2, LOW);
  delay(200);
  //digitalWrite(LED_group1, LOW);
  //digitalWrite(LED_group2, HIGH);
  delay(200);
  
// Slow pulse/breathing
  if (dB < 25) {
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

