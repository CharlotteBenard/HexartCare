//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output; // Fichier de sortie
Serial udSerial; // Objet permettant la communication série
String SenVal; // Texte lu sur le port série

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600); // Ouverture du premier port de la liste des ports série
  output = createWriter ("Battements.csv"); // Création du fichier Battements.csv
  SenVal = ""; // Initialisation du texte
}

void draw() {
  if (udSerial.available() > 0) { // Si le port série est ouvert
    SenVal += udSerial.readString(); // On ajoute au texte lu le texte à lire sur le port série
    if (SenVal.length() >= 5 && SenVal.indexOf('S') != -1 && SenVal.indexOf('E') != -1 && SenVal.substring(SenVal.indexOf('S') + 1, SenVal.indexOf('E')).indexOf('S') == -1) { // Si un S et un E sont détectés
      output.println(SenVal.substring(SenVal.indexOf('S') + 1, SenVal.indexOf('E'))); // Ecriture dans le fichier du bloc contenu entre les deux flags
      SenVal = SenVal.substring(SenVal.indexOf('E') + 1); // Suppression du bloc lu
    }
  }
}

void keyPressed(){ // Fonction qui ferme le fichier ainsi que l'application quand une touche est pressée
  output.flush();
  output.close();
  exit(); 
}