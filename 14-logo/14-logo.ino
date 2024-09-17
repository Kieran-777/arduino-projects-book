int oldpotmeter = 0;

void setup() {
  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // read the value of A0, divide by 4 and send it as a byte over the
  // serial connection
  int potmeter = analogRead(A0) / 4;

  if ( potmeter != oldpotmeter ) {
      Serial.write(potmeter);
      //Serial.println(potmeter);
      delay(500);
      oldpotmeter = potmeter;
  }
}