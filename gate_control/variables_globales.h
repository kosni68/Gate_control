// ***********************************************************************
// ******************    Déclaration des variables     *******************
// ***********************************************************************

byte operating_mode = 0;
unsigned long start_time_close;

//btn gate
bool state_led_btn_gate = LOW;
unsigned int delay_blink_led_btn_gate = 800;
unsigned long start_time_blink_led_btn_gate;


byte close_tentative = 0;