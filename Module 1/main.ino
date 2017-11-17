#include "cardio.h"

long last; // Variable contenant l'instant du battement précécdent
// Variables utilisées par les fonctions du coeur de LEDs
int i;
int n;

void setup() {
  Serial.begin(9600); // Démarrage de la communication série
  last = millis(); // Initialisation de la valeur du dernier battement enregistré à l'instant du démarrage du programme
  for(int j = 2; j < 12; j++){ // Initialisation des pins du coeur
    pinMode(j, OUTPUT);
  }
  i = 0;
  n = 2;
}

void loop() {
  if (analogRead(0) >= 650) { // Chaque battement génère un pic qui dépasse 650
    calc_pouls(millis(), millis() - last, i, n); // On calcule le pouls en faisant la différence entre l'instant du battement avec l'instant de l'ancien battement
    last = millis();
  }
}
