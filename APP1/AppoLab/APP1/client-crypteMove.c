/*
    CrypteMove
    Batuhan ARICA - Omer GIZBILI
*/

#include "client.h"
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char TXT[MAXREP];
char ENC[MAXREP];
char C;
int lenENC_courant=0;

void delete(char txt[],int x){
    //puts("delete");
    int len= strlen(txt);
    //puts("rentre boucle");
    if (x >= len) {
        txt[0] = '\0';
        return;
    }
    for (int i = 0; i < len - x; i++) {
        txt[i] = txt[i + x];
    }
    if(len -x>0){
        txt[len - x] = '\0';
    }
    //puts("apres char nul del");
}

void add(char txt[], int x, int lentxt){
    if (lentxt + x >= MAXREP) {
        printf("Error: Buffer overflow risk, cannot add characters\n");
        return;
    }
    for (int i = 0; i < x && i<lentxt; i++) {
        if(lentxt +i<MAXREP){
        txt[lentxt + i] = txt[i];
        }
    }
    //printf("sortie\n");
    txt[lentxt + x] = '\0';
    //puts("apres char nul");
}

void encrypte(char txt[]){
    if(strlen(txt)==0){
        return;
    }
    
    int x = (int) txt[0] % 8;
    C= txt[0];

    if(lenENC_courant <=MAXREP-1){
        ENC[lenENC_courant++]=C;
        ENC[lenENC_courant] = '\0';
    }
    if (lenENC_courant >= MAXREP - 1) {
        printf("Error: Buffer overflow risk in 'ENC' array\n");
        ENC[MAXREP - 1] = '\0';  
        return;
    }
    
    if(x==0){
        delete(txt,1);
       //printf("Modulo est 0\n");
    }
    else{
        //printf("Modulo n est pas 0\n");
        delete(txt,1);
        int lentxt = strlen(txt);
        if(lentxt+x<= MAXREP){
            add(txt,x,lentxt);
        }
        delete(txt,x);
    }
    //puts("sortie?");
}

int main() {
    char reponse[MAXREP] = "Petit message court."; 
    connexion("im2ag-appolab.u-ga.fr");
    mode_debug(true);
    envoyer("login 12311150 ARICA");
    envoyer("load crypteMove");
    envoyer_recevoir("help",reponse);
    if(reponse==NULL){
        printf("On n'a pas pu prendre le reponse");
        return -1;
    }
    envoyer("start");

    
    while(strlen(reponse)>0){
        //puts("entre main boucle");
        encrypte(reponse);
        //puts("quel est reponse");
        //puts(reponse);
        //puts("call strlen");
    } 
    envoyer(ENC);
    printf("\nCurrent ENC Len %d \n",lenENC_courant);
    int len_txt = strlen(TXT);
    printf("Current Txt Len  %d\n",len_txt);

    return 0;
}