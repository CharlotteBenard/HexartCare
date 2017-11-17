#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "actions.h"

char *append(char *str1, char stri){
    char * new_str ; // Chaine qui va être retournée
    char str2[] = {stri, '\0'};
    if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){ // Alloue de la mémoire pour stocker str 1 + str 2 (+ '\0')
        new_str[0] = '\0';
        strcat(new_str,str1); // Ajoute str1 à new_str
        strcat(new_str,str2); // Ajoute str2 à new_str
        return new_str; // Renvoie str1 + str2
    } else {
        printf("malloc failed!\n");
        return "";
    }
}


char** split(char* str, char split){
    int count = 1;
    int i = 0;

    while(str[i] != '\0'){ // Compte le nombre de blocs
        if(str[i] == split)
            count++;
        i++;
    }

    int *sizes = (int*)malloc(count * sizeof(int)); // Tableau des tailles des différents blocs

    for(i = 0; i < count; i++){ // Initialisation du tableau
        sizes[i] = 0;
    }

    i = 0;
    int j = 0;

    while(str[i] != '\0'){ // Calcul des différentes tailles des blocs
        if(str[i] != split)
            sizes[j]++;
        else
            j++;
        i++;
    }

    int totalSize = strlen(str) - count; // Taille du texte sans les délimiteurs

    char** strings = (char**)malloc(totalSize * sizeof(char)); // On alloue la mémoire requise pour le tableau qui contiendra les chaines de caractères

    i = 0;
    j = 0;

    for(i = 0; i < count; i++){ // Initialise le tableau avec des textes vides
        strings[i] = "";
    }

    j = 0;

    for(i = 0; i < totalSize + count; i++){ // Ajout des différents blocs dans le tableau des textes
        if(str[i] != split){
            strings[j] = append(strings[j], str[i]);
        }
        else
        {
            j++;
        }
    }

    return strings; // Retourne le tableau des blocs
}

void ShowMenu(){
    ReadFile(); // Lit le fichier et stocke les différents pouls dans un tableau
    printf("Choisissez une commande parmi :\n- liste\n- croissant [temps/pouls]\n- decroissant [temps/pouls]\n- recherche_temps [temps]\n- moyenne_pouls [borne superieure, borne inferieure]\n- nombre_lignes\n- recherche_max\n- recherche_min\n- exit\n\n");
    char commande[50];
    while(strcmp(commande, "exit") != 0){
        printf("> ");
        gets(commande);
        char **com = split(commande, ' '); // Sépare la commande en plusieurs mots
        // Appel de la bonne fonction en regard du premier mot écrit
        if(strcmp(com[0], "liste") == 0){ // Si la commande est "liste"
            Show(); // On affiche la liste des données
        }
        else if(strcmp(com[0], "croissant") == 0){ // Si la commande est "croissant"
            if(strcmp(com[1], "temps") == 0) // Si le deuxième paramètre est temps
                ShowIncreasing(0); // On trie la liste en fonction du temps
            else if(strcmp(com[1], "pouls") == 0) // Si le deuxième paramètre est pouls
                ShowIncreasing(1); // On trie la liste en fonction du pouls
        }
        else if(strcmp(com[0], "decroissant") == 0){ // Si la commande est "décroissant"
            if(strcmp(com[1], "temps") == 0) // Si le deuxième paramètre est temps
                ShowDecreasing(0); // On trie la liste en fonction du temps
            else if(strcmp(com[1], "pouls") == 0) // Si le deuxième paramètre est pouls
                ShowDecreasing(1); // On trie la liste en fonction du pouls
        }
        else if(strcmp(com[0], "recherche_temps") == 0){ // Si la commande est "recherche_temps"
            printf("%d\n", LookAt(atoi(com[1]))); // On affiche le pouls à l'instant com[1]
        }
        else if(strcmp(com[0], "moyenne_pouls") == 0){ // Si la commande est "moyenne_pouls"
            printf("%d\n", Average(atoi(com[1]), atoi(com[2]))); // On affiche la moyenne entre les bonres com[1] et com[2]
        }
        else if(strcmp(com[0], "nombre_lignes") == 0){ // Si la commande est "nombre_lignes"
            printf("%d\n", Count()); // On affiche le nombre de lignes
        }
        else if(strcmp(com[0], "recherche_max") == 0){ // Si la commande est "recherche_max"
            printf("%d\n", Max()); // On affiche le maximum
        }
        else if(strcmp(com[0], "recherche_min") == 0){ // Si la commande est "recherche_min"
            printf("%d\n", Min()); // On affiche le minimum
        }

    }
}



