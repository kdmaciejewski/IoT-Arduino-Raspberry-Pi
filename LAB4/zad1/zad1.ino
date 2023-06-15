#define RED 2
#define GREEN 4

void setup()
{
    pinMode(RED, INPUT_PULLUP);
    pinMode(GREEN, INPUT_PULLUP);
    Serial.begin(19200);
    while (!Serial)
    { /* just wait */
    }
}

int i = 0;
int j = 0;
void loop()
{
  int redState = digitalRead(RED);
  int greenState = digitalRead(GREEN);

  if(redState == HIGH){
  
    Serial.println("Czerwony: ");
    Serial.println(redState);
    Serial.println(2);
  }

  if(greenState == HIGH){
    Serial.println("Zielony: ");
    Serial.println(greenState);
    Serial.println(-2);
  }
  // Serial.println("Czerwony: ");
  // Serial.println(redState);

  // Serial.println("Zielony: ");
  // Serial.println(greenState);
}