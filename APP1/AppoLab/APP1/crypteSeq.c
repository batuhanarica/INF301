/*
    CrypteSeq
    Batuhan ARICA - Omer GIZBILI
*/

#include <string.h>
#include "client.h"
#include <stdio.h>
#include <stdlib.h>

struct sequence {
  char tab[1000000];
  int longuer;
}; typedef struct sequence seq;

//BayOfPigs//
void delete(seq *s, int x){ 
    s->tab[s->longuer - x] = '\0';
    s->longuer -= x;
}

void add_to_start_one(seq *s, char ch1) {
    memmove(s->tab + 1, s->tab, s->longuer + 1);
    s->tab[0] = ch1;
    s->longuer ++;
}

void add_to_begin(seq *s, char *ch) { 
    int len = strlen(ch);
    char temp[1000000];  
    strcpy(temp, ch);    
    strcat(temp, s->tab);     
    strcpy(s->tab, temp);   
    s->longuer += len;     
}

void last(seq *s, int i, char *text){ 
    int len = s->longuer;
    for(int j=len-i; j<len; j++){
        strncat(text, &s->tab[j], 1);
    }
}

void BayOfPigs(seq *s1, seq *s2){  int l, l2, x;
    char c, d[1000000];

    l = s1->longuer;
    for (int j=0; j<l; j++){
        l2 = s2->longuer;

        c = s1->tab[l-j-1];

        x = c % 8;

        if (x!=0 && x < l2){
            strcpy(d, "");
            last(s2, x, d);
            delete(s2, x);
            add_to_begin(s2, d);
        }
        add_to_start_one(s2, c);
    }
}
//End BayOfPigs

//CrypteSeq
void add_to_end(seq *s, char ch1) {
    s->longuer ++;
    s->tab[s->longuer - 1] = ch1;
}

int findIndex(seq *s, char c1){
    for (int i = 0; i < s->longuer; i++) { 
        if (s->tab[i] == c1) { 
            return i; 
        } 
    } 
    return -1;  
}

char find_d(seq *s,int index){

    if (index == 0) {
        return s->tab[s->longuer - 1];  // Return the last character if index is 0
    } else {
        return s->tab[index - 1];  // Return the character just before
    }
}


void seq_list_change(seq *s,char c1){
    
    int index_c = findIndex(s, c1);
    if (index_c != -1) {
        char temp = s->tab[index_c];
        for (int i = index_c; i < s->longuer - 1; i++) {
            s->tab[i] = s->tab[i + 1];
        }
        s->tab[s->longuer - 1] = temp;
    }
}

void crypteSeq(seq *s1,char input[], char encrypted[]){

    int len_input = strlen(input);
    int len_enc = 0 ;

    for (int i = 0; i < len_input; i++) {
        char current = input[i];
        int index_c = findIndex(s1, current);

        if (index_c == -1) {
            encrypted[len_enc] = current;
            len_enc++;
            add_to_end(s1, current);
        
        } else {
            char d = find_d(s1, index_c);
            encrypted[len_enc] = d;
            len_enc++;
            seq_list_change(s1, current); 
        }
    }
    
    encrypted[len_enc] = '\0';
}
//End Of crypteSeq

//Northwoods
char find_next(seq *s, int index) {
    if (index == s->longuer - 1) {
        return s->tab[0];  // Wrap around to the beginning
    } else {
        return s->tab[index + 1];  // Return the character just after
    }
}

void decrypteSeq(seq *s1, char encrypted[], char decrypted[]) {
    int len_enc = strlen(encrypted);
    int len_dec = 0;

    for (int i = 0; i < len_enc; i++) {
        char current = encrypted[i];
        int index_c = findIndex(s1, current);

        if (index_c == -1) {
            decrypted[len_dec] = current;
            len_dec++;
            seq_list_change(s1, current);
        } else {
            char prev_char = find_next(s1, index_c);
            decrypted[len_dec] = prev_char;
            len_dec++;
            seq_list_change(s1, prev_char);
        }
    }

    decrypted[len_dec] = '\0';
}

void catch_password(char message[],char password[]){
    const char *key_phrase = "mot de passe actuel est";
    char *found = strstr(message, key_phrase);
    
    if (found != NULL) {
        found += strlen(key_phrase);  // Move pointer past the key phrase
        while (*found == ' ' || *found == '\'') {
            found++;  // Skip any spaces or single quotes
        }
        
        int i = 0;
        while (*found != '\'' && *found != '\0') {  // Extract until the next quote or end of string
            password[i++] = *found++;
        }
        password[i] = '\0';  // Null-terminate the extracted password
    } else {
        strcpy(password, "Password not found");
    }
}
//End of Northwoods

int main(){
    seq s1;
    s1.longuer = 0;
    // Enable debug mode (set to true)
    mode_debug(true);

    // Connect to server and authenticate
    connexion("im2ag-appolab.u-ga.fr");
    envoyer("login 12311150 ARICA");
    envoyer("load crypteSeq");
    char reponse[MAXREP];
    char output[MAXREP];
    seq reponsebop;
    seq outputbop;
    envoyer_recevoir("start\n",reponse);
    char encrypted[ MAXREP+ 1];
    //Decrypte
    strcpy(reponsebop.tab,reponse);
    reponsebop.longuer=strlen(reponse);
    strcpy(outputbop.tab,"");
    outputbop.longuer = 0;
    BayOfPigs(&reponsebop,&outputbop);
    printf("%s\n",outputbop.tab);
    //Encrypte
    crypteSeq(&s1,outputbop.tab,encrypted);
    envoyer_recevoir(encrypted,reponse);
    //Decrypte
    strcpy(reponsebop.tab,reponse);
    reponsebop.longuer=strlen(reponse);
    strcpy(outputbop.tab,"");
    outputbop.longuer = 0;
    decrypteSeq(&s1,reponse,output);
    printf("\n%s\n",output); 
   
    
    return 0;
}


