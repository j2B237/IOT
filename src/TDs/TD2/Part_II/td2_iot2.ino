/*
	PARTIE II
    
	Programme Arduino qui permet d'allumer une lampe
    a partir d'un relais alimenté avec une pile de 9V.
    Lorsqu'un capteur PIR détecte un mouvement alors on
    allume la lampe. Celle-ci reste allumé pendant 1 minute.
*/

#define RELAY 2
#define PIR  4

unsigned long counttime;

void setup() 
{
  	pinMode(RELAY, OUTPUT);
  	pinMode(PIR, INPUT);
}
void loop() 
{
  // Si un mouvement est détecté
  if (digitalRead(PIR) == HIGH) 
  {
    // On ecrit un état haut sur le pin Signal du relay
    // Si la pin signal est haut alors on allume la lampe
    digitalWrite(RELAY,HIGH);
    if(digitalRead(RELAY) == HIGH)
    {
      	digitalWrite(LED, HIGH);
    	counttime = millis();		// On commence le compte à rebouts
    } 
  }

  // On garde la lampe allumée pendant 1 minute
  if (digitalRead(PIR) == LOW && millis() - counttime > 60000) {
    digitalWrite(LED, LOW);
  }
  
  // On maintient le relais au niveau si aucun mouvement n'est détecté
  if (digitalRead(PIR) == LOW)
  {
  	digitalWrite(RELAY, LOW);
  }
}

