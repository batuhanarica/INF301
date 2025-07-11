/*
    projetX
    Batuhan ARICA - Omer GIZBILI
*/


#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
char reponse[MAXREP];

int main() {
    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr");

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer("login 12311150 ARICA ");
    envoyer("load projetX");
    envoyer("help");
    envoyer("start");
    envoyer_recevoir("OUI",reponse);
    for(int i = 0 ; i<15 ; i++){
        int j=0;
        while (reponse[j]) {
        char ch = reponse[j];
        reponse[j]=toupper(ch);
        j++;
        }
        printf("%s",reponse);
    }
    envoyer("veni vidi vici");
    deconnexion();
    printf ("Fin de la connection au serveur\n");
    return 0;
}