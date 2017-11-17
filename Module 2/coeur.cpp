#include "Arduino.h"

void chenille(int& n) { // Les LEDs clignotent une par une
  digitalWrite(n, HIGH);
  if (n == 2) { // Si la LED 2 doit être allumée, on éteint la 11 (et non la 1)
    digitalWrite(11, LOW);
  }
  else {
    digitalWrite(n - 1, LOW);
  }
  n++;
  if (n > 11) { // Si la LED 11 vient d'être allumée, la prochaine à allumer est la 2 (et non la 12)
    n = 2;
  }
}

void everyLeds() { // Toutes les LEDs clignotent en même temps

  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);


}

void led_1_3(int& i) { // Une LED sur trois s'allume
  if (i == 0) {
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    i = 1;
  }
  else if (i == 1) {
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    i = 2;
  }
  else if (i == 2) {
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    i = 0;
  }

  delay(200);

  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
}

void led_1_2(int& i) { // Une LED sur deux s'allume
  if (i == 0)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    i = 1;
  }
  else if (i == 1)
  {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
    i = 0;
  }
  
  delay(200);
  
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
}

void one_led(int led) { // Une seule LED clignote
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
}
