#include <stdio.h>
#include <stdlib.h>

void chenille()
{
    FILE* fichier = NULL;                               //initializing of the file pointer
    fichier = fopen("param.h","w+");                    //opening/creating the file and truncates to 0 length
    fprintf(fichier,"int mode=4;");                     //write in the file
}

void everyLeds()
{
    FILE* fichier = NULL;                               //initializing of the file pointer
    fichier = fopen("param.h","w+");                    //opening/creating the file and truncates to 0 length
    fprintf(fichier,"int mode=1;");                     //write in the file
}

void one_led(int led)
{
    FILE* fichier = NULL;                               //initializing of the file pointer
    fichier = fopen("param.h","w+");                    //opening/creating the file and truncates to 0 length
    fprintf(fichier,"int mode=5;\nint led=%d;", led);   //write in the file
}

void one_three_led()
{
  FILE* fichier = NULL;                                 //initializing of the file pointer
    fichier = fopen("param.h","w+");                    //opening/creating the file and truncates to 0 length
    fprintf(fichier,"int mode=3;");                     //write in the file
}

void one_two_led()
{
    FILE* fichier = NULL;                               //initializing of the file pointer
    fichier = fopen("param.h","w+");                    //opening/creating the file and truncates to 0 length
    fprintf(fichier,"int mode=2;");                     //write in the file
}
