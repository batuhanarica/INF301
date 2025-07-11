#include "listes.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* fichier à compléter au besoin */

void init_liste_vide(liste_t *L)//o(1)
{
    if(L == NULL){//o(1)
        printf("Error: Pointer of L is null \n");//o(1)
        return;//o(1)
    }
    L->tete = NULL;//o(1)
}

/*
 * Supprime toutes les cellules d'une liste L, sans faire de free sur
 * L elle-même.
 */
void liberer_liste(liste_t *L) //o(n)
{
    if (L == NULL) { // Pour pointer NULL o(1)
        return; 
    }

    cellule_t *temp; //o(0)
    while (L->tete != NULL) { //o(n)
        temp = L->tete;       //o(1)
        L->tete = L->tete->suivant; //o(1)
        free(temp);//o(1)
    }
    
    L->tete = NULL; //o(1)

}
int ajouter_tete(liste_t *L, string c)//o(1)
{   /* retourne 0 si OK, 1 sinon  */
    if(c == NULL || L == NULL){ //Pour pointer NULL o(1)
        return 1;//o(1)
    }
    cellule_t *temp = malloc(sizeof(cellule_t));;//o(1)
    if (temp == NULL) {//o(1)
        return 1; //o(1)
    }
    temp = L->tete;//o(1)
    L->tete->val = c;//o(1)
    L->tete->suivant = temp;//o(1)
    if(L->tete->val == c){return 0;}//o(1)
    return 1;//o(1)
}
