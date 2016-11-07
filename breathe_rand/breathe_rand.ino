int ledPin[15] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 44, 45, 46}; // Add PWM pins
int ledFade[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // List of fade values
int ledCount = 15; // The amount of LEDs
int litLed = 7;
int change = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int n = random(3);
  int lastPin = litLed;
 // int lastPinNum = 
  if (n == 0) { // -2
    change = -2;
  }
  else if (n == 1) { // -1
    change = -1;
  }
  else if (n == 2) { // +1
    change = 1;
  }
  else if (n == 3) { // +2
    change = 2;
  }
  if (n == 0 && litLed == 0) {
    litLed = 13;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) {
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
    }
  }
  if (n == 0 && litLed == 1) {
    litLed = 14;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) {
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
      Serial.print("mew");
    }
  }
  if (n == 1 && litLed == 0) {
    litLed = 14;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) {
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
      Serial.print("mew2");
    }
  }
  if (n == 2 && litLed == 14) {
    litLed = 0;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) {
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
    }
  }
  if (n == 3 && litLed == 14) {
    litLed = 1;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) {
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
    }
  }
  if (n == 3 && litLed == 13) {
    litLed = 0;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) {
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
    }
  }
  else {
    litLed = litLed + change;
    if (ledFade[litLed] < 255) {
      for (int fade = 0; fade <= 255; fade += 5) {
        analogWrite(ledPin[litLed], fade);
        delay(10);
      }
      ledFade[litLed] = 255;
    }
  }
  delay(100);
  for (int o = 255; o >= 0; o -= 5) {
    analogWrite(ledPin[lastPin], o);
    delay(10);
  }
  ledFade[lastPin] = 0;
  delay(100);
}
