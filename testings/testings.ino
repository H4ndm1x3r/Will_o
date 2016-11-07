int ledPin[15] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 44, 45, 46};
int ledFade[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int ledState[15] = {LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW};
int ledCount = 15;

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i < ledCount; i++) {
    pinMode(ledPin[i], OUTPUT); // Sets each pin in array to output mode
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], HIGH);
  digitalWrite(ledPin[3], LOW);
  digitalWrite(ledPin[4], HIGH);
  digitalWrite(ledPin[5], LOW);
  digitalWrite(ledPin[6], HIGH);
  digitalWrite(ledPin[7], LOW);
  digitalWrite(ledPin[8], HIGH);
  digitalWrite(ledPin[9], LOW);
  digitalWrite(ledPin[10], HIGH);
  digitalWrite(ledPin[11], LOW);
  digitalWrite(ledPin[12], HIGH);
  digitalWrite(ledPin[13], LOW);
  digitalWrite(ledPin[14], HIGH);
  delay(300);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[3], HIGH);
  digitalWrite(ledPin[4], LOW);
  digitalWrite(ledPin[5], HIGH);
  digitalWrite(ledPin[6], LOW);
  digitalWrite(ledPin[7], HIGH);
  digitalWrite(ledPin[8], LOW);
  digitalWrite(ledPin[9], HIGH);
  digitalWrite(ledPin[10], LOW);
  digitalWrite(ledPin[11], HIGH);
  digitalWrite(ledPin[12], LOW);
  digitalWrite(ledPin[13], HIGH);
  digitalWrite(ledPin[14], LOW);
  delay(300);
}
/*
void blinks(int pin) {
  if (ledFade[pin] == 0) {
    for (int q = 0; q <= 255; q += 5) {
      analogWrite(pin, q);
      delay(20);
    }
    ledFade[pin] = 255; 
  }
  delay(1000);
  if (ledFade[pin] > 0) {
    for (int w = 255; w >= 0; w -= 5) {
      analogWrite(pin, w);
      delay(20);
    }
    ledFade[pin] = 0;
  }
*/

