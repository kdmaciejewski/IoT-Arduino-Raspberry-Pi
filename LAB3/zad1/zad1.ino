#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

int led[] = {LED_RED, LED_GREEN, LED_BLUE};

void initRGB()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, HIGH);

    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);

    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW);
}

void initButtons()
{
    pinMode(RED_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

#define DEBOUNCE_PERIOD 10UL

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
        if (current_reading != debounced_button_state)  //teraz nie równa się kiedyś
        {
            if (debounced_button_state == LOW && current_reading == HIGH) //napięciowo zwolniony
            {
                isReleased = true;                      //to jest zwolniony
            }
            debounced_button_state = current_reading;   
        }
    }

    previous_reading = current_reading;

    return isReleased;
}

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

bool isRedButtonReleased()
{
    static int debounced_button_state = HIGH;
    static int previous_reading = HIGH;
    static unsigned long last_change_time = 0UL;
    bool isReleased = false;

    int current_reading = digitalRead(RED_BUTTON);

    if (previous_reading != current_reading)
    {
        last_change_time = millis();
    }

    if (millis() - last_change_time > DEBOUNCE_PERIOD)
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

void setup()
{
    initRGB();
    initButtons();
}

int led_index = 0;
void loop()
{
    // if (isGreenButtonPressed())
    // {
    //   delay(6);
    //   if(isGreenButtonReleased())
    //   {
    //     digitalWrite(led[led_index], LOW);
    //     delay(1000);
    //     led_index = ++led_index % 3;
    //     digitalWrite(led[led_index], HIGH);
    //   }
    // }

    // if(isRedButtonPressed())
    // {   
    //   //delay(1000);
    //   if(isRedButtonReleased())
    //   {
    //     digitalWrite(led[led_index], LOW);
    //     delay(1000);
    //     led_index = ++led_index % 3;
    //     digitalWrite(led[led_index], HIGH);
    //   } 
    // }

    if(isGreenButtonReleased())
    {
        digitalWrite(led[led_index], LOW);
        delay(1000);
        led_index = ++led_index % 3;
        digitalWrite(led[led_index], HIGH);
      
    }

    if(isRedButtonReleased())
    {
        digitalWrite(led[led_index], LOW);
        delay(1000);
        led_index = ++led_index % 3;
        digitalWrite(led[led_index], HIGH);
      
    }

    // if (isGreenButtonReleased())
    // {
    //   if (!isRedButtonReleased())
    //   {
    //     digitalWrite(led[led_index], LOW);
    //     delay(1000);
    //     led_index = ++led_index % 3;
    //     digitalWrite(led[led_index], HIGH);
    //   }
    // }
    // if (isRedButtonReleased())
    // {
    //   if (!isGreenButtonReleased())
    //   {
    //     digitalWrite(led[led_index], LOW);
    //     delay(1000);
    //     led_index = ++led_index % 3;
    //     digitalWrite(led[led_index], HIGH);
    //   }
    // }
}
