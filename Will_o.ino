// Code for the Will-o-Wisp project, created in colaboration with BDEA at ITU-CPH
// This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
// https://creativecommons.org/licenses/by-nc-nd/4.0/
// Code created by Nicholas Krasuski

int ledPin[15] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 44, 45, 46}; // Add PWM pins
int ledFade[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // List of fade values
int ledCount = 15; // The amount of LEDs
int litLed = random(0,15); // Initial position in array
int change = 0; // Reserved for later use

int micThresh = 967; // Microphone threshold level

void setup() { // Code here runs once on boot
  for (int i = 0; i < ledCount; i++) { // Set all used pins to output mode
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(A0, INPUT); // Set input mode on microphone pin
  Serial.begin(9600); // Initiate serial for debugging purposes
}

void loop() { // Code here will run continously
  int n = random(0,4); // Generate a random number from 0-3 - decides the outcome of current iteration
  int micLevel = analogRead(A0); // Read microphone data every iteration from pin
  int lastPin = litLed; // Set the last used pin to the current pin of previous iteration
  if (n == 0 && micLevel > micThresh) { // -2 spots in the array
    if (n == 0 && litLed == 0) { // Specifies the array placement due to different math
      litLed = 13; 
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // For loop to create the fade effect
          analogWrite(ledPin[litLed], fade); // Write fade value to the designated pin in array
          delay(10); // Make number higher/lower to increase/decrease fade time
        }
        ledFade[litLed] = 255; // Set the fade value in array to 255 for litLed
      }
    }  
    else if (n == 0 && litLed == 1) { // Specifies the array placement due to different math
      litLed = 14;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
    else { // none of the above is true then...
      change = 2; // Number used to generate a new position in the array
      litLed = litLed - change;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
  }
  else if (n == 1 && micLevel > micThresh) { // -1 spot in the array
    if (n == 1 && litLed == 0) { // Specifies the array placement due to different math
      litLed = 14;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
    else { // None of the above is true then...
      change = 1;
      litLed = litLed - change;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
  }
  else if (n == 2 && micLevel > micThresh) { // +1 spot in the array
    if (n == 2 && litLed == 14) { // Specifies the array placement due to different math
      litLed = 0;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
    else { // None of the above is true then...
      change = 1;
      litLed = litLed + change;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
  }
  else if (n == 3 && micLevel > micThresh) { // +2 spots in the array
    if (n == 3 && litLed == 14) { // Specifies the array placement due to different math
      litLed = 1;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
    else if (n == 3 && litLed == 13) { // Specifies the array placement due to different math
      litLed = 0;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
    else { // None of the above is true then...
      change = 2;
      litLed = litLed + change;
      if (ledFade[litLed] < 255) {
        for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
          analogWrite(ledPin[litLed], fade);
          delay(10);
        }
        ledFade[litLed] = 255;
      }
    }
  }
  else if (micLevel > micThresh) { // None of the above is true then...
    litLed = litLed + change;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) { // Fade loop
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
    }
  }
  delay(100); // Waits for the specified amount of milliseconds
  for (int o = 255; o >= 0; o -= 5) { // Fade the previous pin from on to off
    analogWrite(ledPin[lastPin], o);
    delay(10);
  }
  ledFade[lastPin] = 0; // Set the fade value in array to 0 for previous pin
  if (micLevel <= micThresh) { // Check if audio level has broken threshold
    for (int i = 0; i < ledCount; i++) { // Flash all LEDs on
      digitalWrite(ledPin[i], HIGH);
    }
    delay(300); // leave them on for this amount of ms
    for (int i = 0; i < ledCount; i++) { // Turn all LEDs off
      digitalWrite(ledPin[i], LOW);
    }
    delay(5000); // Amount of time to wait until running new iteration
  }
  else {
    delay(100); // Amount of time to wait until running new iteration
  }
}
