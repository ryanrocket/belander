/**
 * BEACON / TRANSMITTER MODULE
 * BeLander (c) 2021
 * by Ryan Wans for Project Aeolus
 */

#include <Arduino.h>

void setup() {
    pinMode(4, OUTPUT);
    Serial.begin(9600);

    digitalWrite(4, LOW);

    randomSeed(analogRead(0));
}

int getDelayer() {
    return (random(10,111) * 10 * 2);
}

void loop() {
    int unique = getDelayer();

    digitalWrite(4, HIGH);             // BEACON ON
    delay(50);        
    digitalWrite(4, LOW);              // FIRST BEACON FLASH COMPLETE

    delay(unique);                     // DELAY BY UNIQUE IDENTIFIER

    digitalWrite(4, HIGH);             // BEACON ON
    delay(50);        
    digitalWrite(4, LOW);              // SECOND BEACON FLASH COMPLETE

    delay(2000);                       // WAIT 2 SECONDS FOR NEXT CYCLE
}

// yeah pretty simple :| 