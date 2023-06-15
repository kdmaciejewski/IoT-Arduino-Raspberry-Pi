#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define RED_BUTTON 2
#define GREEN_BUTTON 4

int time = 0;

void timer()
{
    const unsigned long BlinkChangePeriod = 1000UL;
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;
    

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        
        lcd.setCursor(0, 0);
        lcd.print(time);
        time++;
        //czemu tutaj nie można inaczej? mozna
        lastBlinkChange = millis();
        //lastBlinkChange += BlinkChangePeriod;
        
    }
}


#define DEBOUNCE_PERIOD 100UL

bool isRedButtonPressed()
{
    static int debounced_button_state2 = HIGH;
    static int previous_reading2 = HIGH;
    static unsigned long last_change_time2 = 0UL;
    bool isPressed = false;

    int current_reading = digitalRead(RED_BUTTON);

    if (previous_reading2 != current_reading)
    {
        last_change_time2 = millis();
    }

    if (millis() - last_change_time2 > DEBOUNCE_PERIOD)
    {
        if (current_reading != debounced_button_state2)
        {
            if (debounced_button_state2 == HIGH && current_reading == LOW)
            {
                isPressed = true;
            }
            debounced_button_state2 = current_reading;
        }
    }

    previous_reading2 = current_reading;

    return isPressed;
}

bool isGreenButtonPressed()
{
    static int debounced_button_state = HIGH;
    static int previous_reading = HIGH;
    static unsigned long last_change_time = 0UL;
    bool isPressed = false;

    int current_reading = digitalRead(GREEN_BUTTON);

    if (previous_reading != current_reading)
    {
        last_change_time = millis();
    }

    if (millis() - last_change_time > DEBOUNCE_PERIOD)
    {
        if (current_reading != debounced_button_state)
        {
            if (debounced_button_state == HIGH && current_reading == LOW)
            {
                isPressed = true;
            }
            debounced_button_state = current_reading;
        }
    }
    previous_reading = current_reading;

    return isPressed;
}
void setup()
{
    lcd.init();
    lcd.backlight();
    pinMode(RED_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_BUTTON, INPUT_PULLUP);
    // lcd.blink();
}

bool isGreenButtonReleased()
{
    static int debounced_button_state = LOW;
    static int previous_reading = LOW;
    static unsigned long last_change_time = 0UL;
    bool isReleased = false;

    int current_reading = digitalRead(GREEN_BUTTON);

    if (previous_reading != current_reading)
    {
        last_change_time = millis();  //ważny moment
    }

    if (millis() - last_change_time > DEBOUNCE_PERIOD) // jeżeli trochę minęło
    {
        if (current_reading != debounced_button_state)  
        {
            if (debounced_button_state == LOW && current_reading == HIGH) 
            {
                isReleased = true;                      
            }
            debounced_button_state = current_reading;   
        }
    }

    previous_reading = current_reading;

    return isReleased;
}

bool isStopped = true;

void loop()
{

  bool stan = isGreenButtonPressed();
  bool stanred = isRedButtonPressed();

  if(stan && isStopped)  // uruchamianie gdy nie działa
  {
    timer();
    isStopped = false;
  }
  else if(stan)         //zatrzymywanie gdy działa
  {
    isStopped = true;
  }
  
  if(!isStopped)                   //normalna praca
  {
    timer();
  }
  
  if(stanred)
  {
    isStopped = true;
    time = 0;
    lcd.setCursor(0, 0);
    lcd.print(time);
  }
}