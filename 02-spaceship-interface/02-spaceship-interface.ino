int switchState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  // Read pin 2
  switchState = digitalRead(2);

  // if button is not pressed
  if (switchState == LOW) {
    digitalWrite(3, HIGH); // Green
    digitalWrite(4, LOW); // Red
    digitalWrite(5, LOW); // Red
  }
  // if button not pressed
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250); // quater second delay

    // toggle LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250); // quater second delay
  
  }
}
