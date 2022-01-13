

// ***********************************************************************
// *******************   Inclusion des librairies     ********************
// ***********************************************************************

#include "constantes.h"
#include "variables_globales.h"

#include <Arduino.h>
#include "utils.h"
#include "fonctions.h"

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
    pinMode(LED_BTN_MODE_PIN, OUTPUT);
    pinMode(LED_BTN_GATE_PIN, OUTPUT);

    pinMode(END_STOP_OPEN_PIN, INPUT);
    pinMode(END_STOP_CLOSE_PIN, INPUT);
    pinMode(BTN_MODE_PIN, INPUT);
    pinMode(BTN_OPEN_CLOSE_PIN, INPUT);

    for (byte i = 0; i < 3; i++)
    {
        // au demmarrage on controle si toutes les led fonctionnent en les faisant clignoter 3 fois
        digitalWrite(LED_MODE1_PIN, HIGH);
        digitalWrite(LED_MODE2_PIN, HIGH);
        digitalWrite(LED_MODE3_PIN, HIGH);
        digitalWrite(LED_MODE4_PIN, HIGH);
        digitalWrite(LED_BTN_MODE_PIN, HIGH);
        digitalWrite(LED_BTN_GATE_PIN, HIGH);
        delay(400)
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, LOW);
        digitalWrite(LED_MODE3_PIN, LOW);
        digitalWrite(LED_MODE4_PIN, LOW);
        digitalWrite(LED_BTN_MODE_PIN, HIGH);
        digitalWrite(LED_BTN_GATE_PIN, HIGH);
        delay(400)
    }
    

    start_time_close = millis();
    start_time_blink_led_btn_gate = millis();
}

// ***********************************************************************
// ***********************     FONCTION LOOP     *************************
// ***********************************************************************

void loop()
{

    read_input_btn();

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
        management_input_endstop(5);
        break;

    case 2:
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, HIGH);
        digitalWrite(LED_MODE3_PIN, LOW);
        digitalWrite(LED_MODE4_PIN, LOW);
        management_input_endstop(30);
        break;

    case 3:
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, LOW);
        digitalWrite(LED_MODE3_PIN, HIGH);
        digitalWrite(LED_MODE4_PIN, LOW);
        management_input_endstop(60);
        break;

    case 4:
        digitalWrite(LED_MODE1_PIN, LOW);
        digitalWrite(LED_MODE2_PIN, LOW);
        digitalWrite(LED_MODE3_PIN, LOW);
        digitalWrite(LED_MODE4_PIN, HIGH);
        management_input_endstop(60);
        break;

    case 5:
        digitalWrite(LED_MODE1_PIN, HIGH);
        digitalWrite(LED_MODE2_PIN, HIGH);
        digitalWrite(LED_MODE3_PIN, HIGH);
        digitalWrite(LED_MODE4_PIN, HIGH);
        break;
    }
}
