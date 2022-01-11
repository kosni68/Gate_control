

// ***********************************************************************
// *******************   Inclusion des librairies     ********************
// ***********************************************************************

#include "constantes.h"
#include "variables_globales.h"

#include <Arduino.h>
#include "utils.h"

// ***********************************************************************
// **********************    Création des objets     *********************
// ***********************************************************************

// ***********************************************************************
// ******************    Declarations des fonctions     ******************
// ***********************************************************************

void read_input_btn()
{

    if (digitalRead(BTN_MODE_PIN))
    {
        Serial.print("BTN_MODE_PIN : HIGH");
        operating_mode++;
        overflow(operating_mode, 0, NB_MAX_MODE);
    }

    if (digitalRead(BTN_OPEN_CLOSE_PIN))
    {
        Serial.print("BTN_OPEN_CLOSE_PIN : HIGH");
        relay_signal = HIGH;
        start_time_relay = millis();
    }
}

void manage_gate(unsigned long delay)
{

    if (digitalRead(END_STOP_CLOSE_PIN) == HIGH)
    {
        start_time_close = millis();
        tentative = 0;
        return;
    }

    if (tentative > 0)
        delay = DELAY_TENTATIVE;
    else
        delay = delay * 60000;

    elapsed_time_close = millis() - start_time_close;
    if (elapsed_time_close > delay * 60000)
        return;

    tentative++;
    if (tentative > NB_MAX_TENTATIVE)
    {
        operating_mode = 5;
        return;
    }

    relay_signal = HIGH;
    start_time_close = millis();
}

void manage_relay()
{
    if (relay_signal != HIGH)
        return;

    elapsed_time_relay = millis() - start_time_relay;
    if (elapsed_time_relay < TIME_MAX_SIGNAL_RELAY)
    {
        digitalWrite(RELAY_PIN, HIGH);
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW);
        relay_signal = LOW;
    }
}

// ***********************************************************************
// ***********************     FONCTION SETUP     ************************
// ***********************************************************************
void setup()
{
    Serial.begin(115200);

    pinMode(LED_MODE1_PIN, OUTPUT);
    pinMode(LED_MODE2_PIN, OUTPUT);
    pinMode(LED_MODE3_PIN, OUTPUT);
    pinMode(LED_MODE4_PIN, OUTPUT);

    pinMode(END_STOP_OPEN_PIN, INPUT);
    pinMode(END_STOP_CLOSE_PIN, INPUT);

    pinMode(BTN_MODE_PIN, INPUT);
    pinMode(BTN_OPEN_CLOSE_PIN, INPUT);

    pinMode(LED_BTN_MODE_PIN, OUTPUT);
    pinMode(LED_BTN_OPEN_CLOSE_PIN, OUTPUT);

    start_time_close = millis();
}

// ***********************************************************************
// ***********************     FONCTION LOOP     *************************
// ***********************************************************************

void loop()
{

    read_input_btn();
    manage_relay();

    switch (operating_mode)
    {
    case 0:
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, LOW);
        digitalWrite(LED_MODE3_PIN, LOW);
        digitalWrite(LED_MODE4_PIN, LOW);
        break;

    case 1:
        digitalWrite(LED_MODE1_PIN, HIGH);
        digitalWrite(LED_MODE2_PIN, LOW);
        digitalWrite(LED_MODE3_PIN, LOW);
        digitalWrite(LED_MODE4_PIN, LOW);
        manage_gate(5);
        break;

    case 2:
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, HIGH);
        digitalWrite(LED_MODE3_PIN, LOW);
        digitalWrite(LED_MODE4_PIN, LOW);
        manage_gate(30);
        break;

    case 3:
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, LOW);
        digitalWrite(LED_MODE3_PIN, HIGH);
        digitalWrite(LED_MODE4_PIN, LOW);
        manage_gate(60);
        break;

    case 4:
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, LOW);
        digitalWrite(LED_MODE3_PIN, LOW);
        digitalWrite(LED_MODE4_PIN, HIGH);
        manage_gate(24 * 60);
        break;

    case 5:
        digitalWrite(LED_MODE1_PIN, HIGH);
        digitalWrite(LED_MODE2_PIN, HIGH);
        digitalWrite(LED_MODE3_PIN, HIGH);
        digitalWrite(LED_MODE4_PIN, HIGH);
        break;
    }
}
