#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3
#define RED_BUTTON 2

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, LOW);

    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);

    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW);

    pinMode(RED_BUTTON, INPUT_PULLUP);
}

void blinkRed()
{
    const unsigned long BlinkChangePeriod = 900UL;
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
        }
        else
        {
            ledState = HIGH;
        }

        digitalWrite(LED_RED, ledState);
        //czemu tutaj nie można inaczej? mozna
        lastBlinkChange = millis();
        //lastBlinkChange += BlinkChangePeriod;
        
    }
}
void blinkGreen()
{
    const unsigned long BlinkChangePeriod = 1000UL;
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
        }
        else
        {
            ledState = HIGH;
        }

        digitalWrite(LED_GREEN, ledState);
        //czemu tutaj nie można inaczej? mozna
        lastBlinkChange = millis();
        //lastBlinkChange += BlinkChangePeriod;
        
    }
}
void blinkBlue()
{
    const unsigned long BlinkChangePeriod = 1100UL;
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
        }
        else
        {
            ledState = HIGH;
        }

        digitalWrite(LED_BLUE, ledState);
        //czemu tutaj nie można inaczej? mozna
        lastBlinkChange = millis();
        //lastBlinkChange += BlinkChangePeriod;
        
    }
}
void readButtonSetLed()
{
    if (digitalRead(RED_BUTTON) == LOW)
        digitalWrite(LED_RED, HIGH);
    else
        digitalWrite(LED_RED, LOW);
}


bool redOff = true;
bool greenOff = true;
bool blueOff = true;

void loop()
{   
  if(greenOff && blueOff){
    redOff = false;
    blinkRed();
    redOff = true; 
  }
  if(redOff && blueOff){
    greenOff = false;
    blinkGreen();
    greenOff = true; 
  }
  if(greenOff && redOff){
    blueOff = false;
    blinkBlue();
    blueOff = true; 
  }

  //readButtonSetLed();
}
