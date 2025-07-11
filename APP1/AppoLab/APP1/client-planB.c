/*
    client-planB
    Batuhan ARICA
*/


#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr");

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer("login 12311150 ARICA");
    envoyer("load planB");
    char reponse[MAXREP];
    envoyer_recevoir("help",reponse);
    envoyer("start");
    envoyer("42");
    int decalage;
    if(reponse[0] >= 'C' && reponse[0] <= 'Z') {
        decalage = (int)reponse[0] - 67;  // 'C' is ASCII 67
    } else {
        decalage = (int)reponse[0] + 25 - 67;
    }
    
    char answer[20]="hasta la revolucion";
    int len = strlen(answer);
   for(int i = 0; i < len; i++) {
        if(answer[i] >= 'a' && answer[i] <= 'z') {
            answer[i] = answer[i] - decalage;
            if(answer[i] < 'a') {
                answer[i] += 26;  
            }
        }
    }
    printf("%d\n",decalage);
    printf("%s\n",answer);
    envoyer(answer);
    char codesecret[20]="5402 2586 9910 4327";
    envoyer(codesecret);
    printf ("Fin d'envoi des messages.\n");
    printf ("Pour envoyer d'autres lignes, ajouter des appels à la fonction `envoyer`\n");
    deconnexion();
    printf ("Fin de la connection au serveur\n");
    return 0;
}