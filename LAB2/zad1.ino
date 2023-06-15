
const int ledPin = 9;      // the pin that the LED is attached to
const int butt = 2;

void setup() {

  // initialize the ledPin as an output:

  pinMode(ledPin, OUTPUT);
  pinMode(butt, INPUT_PULLUP);

}

void loop() {

  // analogWrite(ledPin, 10);
  // delay(1000);
  // analogWrite(ledPin, 100);
  // delay(1000);

  int state = digitalRead(butt);

  if (state == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }


  // if (digitalRead(butt) == LOW)
  // {
  //   digitalWrite(ledPin, LOW);
  //   delay(1000);
  // }
}





