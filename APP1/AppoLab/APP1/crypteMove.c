#include "client.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXMSG MAXREP

int minumum(int e, int x) {
   return (e < x) ? e : x;
}

void crypteMove(char TXT[], char ENC[]) {
   int s;

   while (strlen(TXT) != 0) {
     char C = TXT[0];

     strncat(ENC, &C, 1);
     memmove(TXT, TXT + 1, strlen(TXT));  // Remove first char from TXT
     int a = C % 8;
     s = minumum(strlen(TXT), a);
     for (int i = 0; i < s; i++) {
        C = TXT[0];
        memmove(TXT, TXT + 1, strlen(TXT));
        strncat(TXT, &C, 1);  // Rotate character
     }
   }
}

char* crypte(const char* TXT) {
    int length = strlen(TXT);
    char* enc = (char*)malloc((length + 1) * sizeof(char));  // Allocate memory for the encrypted string
    enc[0] = '\0';  // Ensure it's null-terminated at the start

    char* txtCopy = strdup(TXT);  // Make a copy of the input string

    for (int i = 0; i < length; i++) {
        enc[i] = txtCopy[0];
        enc[i + 1] = '\0';  // Null-terminate after each addition

        // Shift txtCopy to the left by 1 character
        memmove(txtCopy, txtCopy + 1, length - 1);  // Shift left the string
        txtCopy[length - 1] = '\0';  // Null-terminate

        // Calculate rotation based on the current character
        int decale = enc[i] % 8;  // Calculate rotation using modulo
        if (decale > 0) {
            char inter[MAXMSG] = {0};  // Temporary buffer for rotated string
            int ii = 0;

            // Copy the remaining part after the decale position
            for (int j = decale; txtCopy[j] != '\0'; j++) {
                inter[ii++] = txtCopy[j];
            }
            // Copy the first part (0 to decale - 1) to the end of the new string
            for (int z = 0; z < decale; z++) {
                inter[ii++] = txtCopy[z];
            }
            inter[ii] = '\0';  // Null-terminate the intermediate string

            // Replace the original txtCopy with the rotated version
            strcpy(txtCopy, inter);
        }
    }

    free(txtCopy);  // Free the duplicated string
    return enc;  // Return the encrypted string
}

int main() {
    char reponse[10000];
    // Enable debug mode (set to true)
    mode_debug(true);

    // Connect to server and authenticate
    connexion("im2ag-appolab.u-ga.fr");
    envoyer_recevoir("login 12311150 ARICA", reponse);
    envoyer_recevoir("load crypteMove", reponse);
    envoyer_recevoir("aide", reponse);

    // Encrypt the server response using crypte
    char* encryptedResponse = crypte(reponse);  // Store the result of crypte in encryptedResponse

    // Send the encrypted response to the server
    envoyer_recevoir("depart", reponse);
    envoyer_recevoir(encryptedResponse, reponse);

    // Free the dynamically allocated memory
    free(encryptedResponse);

    return 0;
}
