#include <stdio.h>
#include <stdlib.h>

#include "actions.h"
#include "donnees.h"

void Show(){ // Affiche toutes les valeurs des pouls en fonction du temps dans l'ordre du fichier
    int i = 0;
    for(; i < GetPulsesSize(); i++){
       printf("%d ms -> %d\n", GetPulses()[i]->time, GetPulses()[i]->pulse);
    }
}

void ShowIncreasing(int parameter){
    if(parameter == 0){ // Affiche les données dans l'ordre croissant en fonction du temps
        Show();
    }
    else { // Affiche les valeurs des pouls dans l'ordre croissant
        struct Pulse **sorted;
        sorted = (struct Pulse **) malloc(GetPulsesSize() * sizeof(struct Pulse *));
        int i = 0;
        for(; i<GetPulsesSize(); i++)
            sorted[i] = (struct Pulse *) malloc(sizeof(struct Pulse));
        i = 0;
        for(; i<GetPulsesSize(); i++){ // Stocke les données du tableau des pouls dans un autre tableau : sorted
            sorted[i]->time = GetPulses()[i]->time;
            sorted[i]->pulse = GetPulses()[i]->pulse;
        }
        int swapped = 1;
        struct Pulse *temp;
        while(swapped == 1){ // Effectue un tri pour mettre les pouls dans l'ordre croissant
            swapped = 0;
            for(i = 1; i<GetPulsesSize(); i++){
                if(sorted[i]->pulse < sorted[i-1]->pulse){
                    temp = sorted[i];
                    sorted[i] = sorted[i-1];
                    sorted[i-1] = temp;
                    swapped = 1;
                }
            }
        }
        for(i = 0; i<GetPulsesSize(); i++){ // Parcours le tableau trié et affiche les pouls dans l'ordre croissant
            printf("%d ms -> %d\n", sorted[i]->time, sorted[i]->pulse);
        }
    }
}

void ShowDecreasing(int parameter){
    if(parameter == 0){ // Affiche les données dans l'ordre décroissant en fonction du temps
        int i = GetPulsesSize() - 1;
        for(; i>-1; i--){
            printf("%d ms -> %d\n", GetPulses()[i]->time, GetPulses()[i]->pulse);
        }
    }
    else { // Affiche les valeurs des pouls dans l'ordre décroissant
        struct Pulse **sorted = NULL;
        sorted = (struct Pulse **) malloc(GetPulsesSize() * sizeof(struct Pulse *));
        int i = 0;
        for(; i<GetPulsesSize(); i++)
            sorted[i] = (struct Pulse *) malloc(sizeof(struct Pulse));
        i = 0;
        for(; i<GetPulsesSize(); i++){ // Stocke les données du tableau des pouls dans un autre tableau : sorted
            sorted[i]->time = GetPulses()[i]->time;
            sorted[i]->pulse = GetPulses()[i]->pulse;
        }
        int swapped = 1;
        struct Pulse *temp;
        while(swapped == 1){ // Effectue un tri pour mettre les pouls dans l'ordre décroissant
            swapped = 0;
            for(i = 1; i<GetPulsesSize(); i++){
                if(sorted[i]->pulse > sorted[i-1]->pulse){
                    temp = sorted[i];
                    sorted[i] = sorted[i-1];
                    sorted[i-1] = temp;
                    swapped = 1;
                }
            }
        }
        for(i = 0; i<GetPulsesSize(); i++){ // Parcours le tableau trié et affiche les pouls dans l'ordre décroissant
            printf("%d ms -> %d\n", sorted[i]->time, sorted[i]->pulse);
        }
    }
}

int LookAt(int time){ // Recherche puis affiche un pouls en fonction d'un temps particulier
    int i = 0;
    for(; i<GetPulsesSize(); i++){
        if(time == GetPulses()[i]->time) // Recherche le temps correspondant à celui demandé et affiche le pouls associé
            return GetPulses()[i]->pulse;
    }
    return -1;
}


int Average(int borne_inf, int borne_sup){ // Retourne la moyenne des pouls dans un intervalle de temps donné
    int inf = 0;
    while(borne_inf > GetPulses()[inf]->time){ // On cherche l'index de la borne inférieure
        inf++;
    }
    int sup = 0;
    while(borne_sup >= GetPulses()[sup]->time){ // On cherche l'index de la borne supérieure
        sup++;
    }
    int resultat = 0;
    int i = inf;
    for(; i <= sup; i++){ // Additionne toutes les valeurs des pouls comprises entre la borne inférieure et la borne supérieure
        resultat += GetPulses()[i]->pulse;
    }
    return resultat / (sup - inf + 1); // Effectue la moyenne des pouls en divisant la somme des valeurs des pouls par le nombre de valeurs
}

int Min(){ // Recherche et retourne la valeur minimale des pouls avec le temps associé
    int minimum = GetPulses()[0]->pulse;
    int i = 1;
    for(; i<GetPulsesSize(); i++){
        if(minimum > GetPulses()[i]->pulse)
            minimum = GetPulses()[i]->pulse;
    }
    return minimum;
}

int Max(){ // Recherche et retourne la valeur maximale des pouls avec le temps associé
    int maximum = GetPulses()[0]->pulse;
    int i = 1;
    for(; i < GetPulsesSize(); i++){
        if(maximum < GetPulses()[i]->pulse)
            maximum = GetPulses()[i]->pulse;
    }
    return maximum;
}

int Count(){ // Retourne le nombre de lignes du tableau des pouls
    return GetPulsesSize();
}
