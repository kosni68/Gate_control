// ***********************************************************************
// ******************    Déclaration des variables     *******************
// ***********************************************************************
 
byte operating_mode = 0;

bool relay_signal = LOW;
unsigned long start_time_relay;
unsigned long elapsed_time_relay;

unsigned long start_time_close;
unsigned long elapsed_time_close;

byte tentative=0;