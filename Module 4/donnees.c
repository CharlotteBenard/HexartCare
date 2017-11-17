#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "donnees.h"
#include "variables.h"

void ReadFile(){ // Lit le fichier Battements.csv et stocke les données dans un tableau de caractères
    FILE *f = NULL;
    char buffer[100];

    f = fopen("Battements.csv", "r"); // Ouvre le fichier

    if (!f) // Vérifie si le fichier a été ouvert et affiche un message d'erreur sinon
    {
       printf("Le fichier Battements.csv n'a pas pu etre lu.");
	   fclose(f);
       exit(1);
    }

    while (fgets(buffer, 100, f) != NULL){ // Parcours toutes les lignes du fichier et stocke les données dans le tableau buffer
        struct Pulse *pls = NULL; // Initialise un pointeur vers une structure Pulse
        pls = (struct Pulse *)malloc(sizeof(struct Pulse));
        pls->time = atoi(strtok(buffer, ";")); // Transforme la chaîne de caractères située avant le ";" en entiers et stocke la valeur dans le champs time
        pls->pulse = atoi(strtok(NULL, ";"));
        AddPulse(pls);
    }

    fclose(f);

}

void AddPulse(struct Pulse *pls){ // Ajoute une pulsation au tableau des pouls
    PulsesSize++; // Augmente la taille du tableau des pouls de 1
    Pulses = (struct Pulse **) realloc(Pulses, PulsesSize * sizeof(struct Pulse *)); // Réalloue la mémoire au tableau des pouls pour avoir un espace de stockage en plus et pouvoir stocker la nouvelle pulsation
    Pulses[PulsesSize - 1] = pls; // Stocke le pointeur pls à la fin du tableau des pouls
}

struct Pulse **GetPulses(){ return Pulses;} // Affiche le tableau des pouls
int GetPulsesSize() { return PulsesSize;} // Affiche la taille du tableau des pouls
