#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"


/*
 *  Auteur(s) :Batuhan ARICA \ Omer GIZBILI
 *  Date :10/11/2024
 *  Suivi des Modifications :
 *
 */

bool silent_mode = false;


cellule_t* nouvelleCellule (void){
    cellule_t* cel = (cellule_t*)malloc(sizeof(cellule_t));
    if (cel != NULL) {
        cel->command = '\0'; // on initialise la command du cellule
        cel->suivant = NULL; // initialiement an n'a pas une cellule suivant
    }
    return cel;
}

sequence_t* creer_sequence(){
    sequence_t *seq = (sequence_t*)malloc(sizeof(sequence_t));
    seq->tete = NULL;
    return seq;
}

void detruireCellule (cellule_t* cel){
    free(cel);
}

// free la case du seq
void detruire_seq(sequence_t *seq){
    free(seq);
}

void remove_tous_elem_seq(sequence_t* seq){    
    while(seq->tete != NULL){ //comme on doit examiner la situation "{" on doit regarder la cellule avant
        cellule_t *cel_avant = seq->tete;
        seq->tete = seq->tete->suivant;//passer au  cellule suivante
        detruireCellule(cel_avant);;         
    }    
}

void conversion (char *texte, sequence_t *seq){
    if(seq==NULL){
        seq = creer_sequence();
    }
    cellule_t *cel_avant= nouvelleCellule();
    cel_avant->command=texte[0];
    seq->tete =cel_avant;
    for (int i=1;texte[i];i++){
        cellule_t *cel = nouvelleCellule();
        cel->command=texte[i];
        cel_avant->suivant =cel;
        cel_avant=cel;
        
    }
}


void afficher (sequence_t* seq){
    assert (seq); /* Le pointeur doit être valide */ //on break le code si faux
    
    cellule_t *cel;
    cel=seq->tete;
    
    while(cel!= NULL){
        
        printf("%c",cel->command);
        cel=cel->suivant;
        
    }
}   