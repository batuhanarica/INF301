#include <stdio.h>

/*
 *  Auteur(s) : Batuhan ARICA
 *  Date :
 *
 */

int num_declarage = 3;

char declarage_lettre(char c) {
    if ('a'<= c && c <= 'z') {
        c = (char)(c + num_declarage);
        if (c > 'z') {
            c -= 26;
        }
    }
    else if ('A' <= c && c <= 'Z') {
        c = (char)(c + num_declarage);
        if (c > 'Z') {
            c -= 26;
        }
    }
    return c;
}

int main (void)
{
    char lettreLue='?';
    char lettreSuivante3='x';

    printf ("Donner une lettre\n");
    scanf ("%c",&lettreLue);
    
    //completer ici le calcul de la lettre suivante (3 rangs plus loin)
    lettreSuivante3 = declarage_lettre(lettreLue);
    printf("\nResultat : %c\n",lettreSuivante3);

    return 0;
}
