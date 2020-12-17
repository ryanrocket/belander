/*
  drone.ino BY RYAN WANS
  MADE FOR 2021 SCIENCE FAIR
  (C) 2020-2021 Ryan Wans & Jack Woods
  Licensed under MIT License
*/

#include <Arduino.h>
#undef max
#undef min

// global variables
bool ledKillStatus;
bool ledChargeStatus;
bool relayStatus = false;
int _temp_chargeDuration;

void setup() {
  /*
    PIN ASSIGNMENTS:
      - PIN 12  : LED       [ OUT ]
      - PIN 11  : LED 2     [ OUT ]
      - PIN 8   : SWITCH    [ IN  ]
      - PIN 4   : RELAY     [ OUT ]
      - PIN 3   : DEBUG     [ OUT ]
  */
  pinMode(4, OUTPUT);       // Control INPUT 1 of 5v Relay 
  pinMode(8, INPUT);        // Switching Control
  pinMode(9, INPUT_PULLUP);
  pinMode(12, OUTPUT);      // Control LED Strip
  pinMode(11, OUTPUT);      // LED Signifier
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(4, HIGH);
  systemInit();
}

void loop() {
  // version 3.0
  // -- -- -- -- -- - -- -- - -- -- -- -- -- -- -- -- - 

  control();

}

void systemInit() {
     // status check all system led's
     digitalWrite(12, HIGH);
     digitalWrite(11, HIGH);
     delay(1000);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     delay(1300);

     // ensure relay / coil is powered off for now;
     relayStatus = false;
     digitalWrite(4, HIGH);
}

void control() {
  digitalWrite(12, HIGH);

  if(digitalRead(9) == HIGH) {
    
    digitalWrite(4, HIGH); // ensure relay is off
    digitalWrite(11, HIGH);
    delay(200);
    digitalWrite(11, LOW);
    delay(200);
    digitalWrite(11, HIGH);
    delay(200);
    digitalWrite(11, LOW);
    delay(200);
  } else {
    digitalWrite(4, LOW); // ensure relay is on
    digitalWrite(11, HIGH);
    delay(400);
  }

  digitalWrite(12, LOW);
  delay(500);
}
