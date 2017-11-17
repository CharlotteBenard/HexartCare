#include <arduino.h>
#include "cardio.h"
#include "coeur.h"
#include "param.h"

int calc_pouls(long time, long pulse, int& i, int& n) {
  Variables var; // Objet permettant d'extraire les paramètres dans param.h
  int resultat = 60000 / pulse; // Calcul du pouls
  if (resultat > 40 && resultat < 150) { // Un résultat valable n'est compris qu'entre 40 et 150 en moyenne
    // On envoie une chaine, par le port série, qui commence par un S et se termine par un E, ce qui permet de contrôler l'intégrité de l'information reçue par la suite (flags) (e.g "S1000;80E")
    Serial.print("S");
    Serial.print(time);
    Serial.print(";");
    Serial.print(resultat);
    Serial.print("E");
    // En fonction du mode renseigné dans param.h, on appelle la fonction qui contrôle les LEDs adéquate
    switch(var.mode){
      case 1:
      chenille(n);
      break;
     case 2:
      everyLeds();
      break;
     case 3:
      led_1_3(i);
      break;
     case 4:
      led_1_2(i);
      break;
     case 5:
      one_led(var.led);
    }
  }
}

