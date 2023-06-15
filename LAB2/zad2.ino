
const int ledPin = 6;      // the pin that the LED is attached to
const int butttop = 2;
const int buttdown = 4;

void setup() {

  // initialize the ledPin as an output:

  pinMode(ledPin, OUTPUT);
  pinMode(butttop, INPUT_PULLUP);
  pinMode(buttdown, INPUT_PULLUP);
}

int light = 128;

void loop() {
  int state1 = digitalRead(butttop);
  
  if (state1 == HIGH){
    light += 10;
    if(light > 255){
      light = 255;
    }
    analogWrite(ledPin, light);
    delay(500);
  }

// CHODZI O TO ŻEBY DELAY BYŁO DŁUŻSZE NIŻ CZAS PODCZAS KTÓREGO PRZYCISK SIE STYKA
// BO WTEDY JAK JEST ZA MAŁY TO ZMIELI DO KOŃCA!!!

  int state2 = digitalRead(buttdown);

  if (state2 == HIGH ){
    light -= 10;
    if (light < 0){
      light = 0;
    }
    analogWrite(ledPin, light);
    delay(500);
  }
}





