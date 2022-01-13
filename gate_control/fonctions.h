
void send_signal_relay()
{
    digitalWrite(RELAY_PIN, HIGH);
    delay(500);
    digitalWrite(RELAY_PIN, LOW);
}

bool close_gate(unsigned long delay)
{
    // on sort de la fonction si le delai nest pas depassé
    unsigned long elapsed_time = millis() - start_time_close;
    if (elapsed_time > delay * 60000)
        return LOW;

    send_signal_relay();
    return HIGH;
}

void blink_led(byte led_pin, bool &state_led, unsigned long &start_time, unsigned int delay)
{
    unsigned long elapsed_time = millis() - start_time;
    if (elapsed_time > delay)
    {
        digitalWrite(led_pin, state_led);
        start_time = millis();
    }
    state_led = !state_led;
}

void read_input_btn()
{
    if (digitalRead(BTN_MODE_PIN))
    {
        Serial.print("BTN_MODE_PIN : HIGH");
        operating_mode++;
        overflow(operating_mode, 0, NB_MAX_MODE);
        delay(1000);
    }

    if (digitalRead(BTN_OPEN_CLOSE_PIN))
    {
        Serial.print("BTN_OPEN_CLOSE_PIN : HIGH");
        send_signal_relay();
        delay(1000);
    }
}

void management_input_endstop(unsigned int delay)
{

    if (digitalRead(END_STOP_OPEN_PIN) != HIGH && digitalRead(END_STOP_CLOSE_PIN) != HIGH)
    {
        if (close_tentative > NB_MAX_TENTATIVE)
        {
            // Si tentative est supereieur au max on bascule en defaut
            operating_mode = 5;
            close_tentative = 0;
            return;
        }
        else if (close_tentative > 0)
        {
            // Si ce nest pas une premiere tentative le delai est raccourci et la led clignote vite
            delay = DELAY_TENTATIVE;
            delay_blink_led_btn_gate = 300;
        }
        else{
            // Si cest une premiere tentative le delai est convertit en minute et la led clignote lentement
            delay = delay * 60000;
            delay_blink_led_btn_gate = 800;
            }

        if (close_gate(delay))
        {
            // Si le signal a été envoyé on incremente close_tentative 
            close_tentative++;
            start_time_close = millis();
        }

        blink_led(LED_BTN_GATE_PIN, state_led_btn_gate, start_time_blink_led_btn_gate, delay_blink_led);
    }
    else if (digitalRead(END_STOP_CLOSE_PIN) == HIGH)
    {
        close_tentative = 0;
        start_time_close = millis();
        return;
    }
}