/*
	Programme Arduino qui permet d'allumer une lampe lorsque 
    le capteur PIR détecte un mouvement. La lampe est gardée 
    allumée pendant une minute. Pendant ce temps le micro-
    controleur fait clignoter une led connectée sur la broche
    12.

*/
#define PIR  2
#define LED  13
#define LED2 12

unsigned long counttime, timeElapsed;

void setup() {
   	pinMode(PIR, INPUT);
   	pinMode(LED, OUTPUT);
  	pinMode(LED2, OUTPUT);
}

void loop() {
  	timeElapsed = millis();
    if (digitalRead(PIR) == HIGH) 
    {
      digitalWrite(LED, HIGH);
      counttime = millis();
    }
  
  	if (digitalRead(PIR) == LOW && millis() - counttime > 60000) {
      digitalWrite(LED, LOW);
    }

  	
  	digitalWrite(LED2, HIGH);
  	delay(100);
  	digitalWrite(LED2, LOW);
  	delay(100);
   
}