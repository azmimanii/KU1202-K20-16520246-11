const int pingPin = 7;   // pin Arduino that will read the sensor output

void setup() {
  Serial.begin(9600);    // start serial port
}

void loop() {
  long duration, cm;
  
  pinMode (pingPin, OUTPUT); // set pin as OUTPUT
  digitalWrite(pingPin, LOW); // set initial signal as LOW
  delayMicroseconds(2); // Wait for 2 microsecond(s)
  digitalWrite(pingPin, HIGH); // trigger sensor with HIGH signal
  delayMicroseconds(5);// Wait for 5 microsecond(s)
  digitalWrite(pingPin, LOW);
  
  pinMode (pingPin, INPUT);                  // set pin as INPUT
  duration = pulseIn (pingPin, HIGH);
  cm = microsecondsToCentimeters (duration); // conversion from microsecond to cm
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);                             
}

long microsecondsToCentimeters(long microseconds) {
  // the velocity of sound is 340 m/s or 29 microsecond/cm
  // divided by two to find the distance of sensor and object
  return microseconds / 29 / 2;
}