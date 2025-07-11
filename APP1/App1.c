
#include <stdio.h>
int main(){
    int num_declarage;
    char declarage_lettre(char c){
        if(((num_declarage + int('a'))<= c <= 'z') || ((num_declarage + int('A'))<= c <= 'Z')){
            int ascii = c ;
            c = char(ascii - num_declarage);
        }
        else if ((('a'<= c <= (int('z') + num_declarage - 26 ))) || (('A'<= c <= (int('Z')+ num_declarage - 26 )))){
            int ascii = c ;
            c = char(ascii - num_declarage +26);
        }
        return c ;
    }
    char ligne[] = [];
    char[] decyrpte(){
        for(int i = 0 ; i < length(ligne);i++){
            
            declarage_lettre[i];
        }
        return ligne;
    }
    return 0;
}
