/*
 * Simple application pour allumer une led
 * Depuis son smartphone en utilisant un module Bluetooth HC-05
 */

#define PIN 2

void setup() 
{
  pinMode(PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Initializing com");
  delay(1000);
}

void loop() 
{
  // Lecture du Port Rx pour savoir si des données sont envoyées
  if (Serial.available())
  {
    // On lit le buffer jusqu'a rencontrer le saut de retour de chaine
    String sig = Serial.readStringUntil("\n");

    // Si on lit 1 on allume la led
    if (sig == "1") { digitalWrite(PIN, HIGH);}

    // Si on lit 0 on eteint la led
    else if (sig == "0") {digitalWrite(PIN, LOW);}
  }
}
