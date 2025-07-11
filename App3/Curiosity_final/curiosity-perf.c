#include "environnement.h"
#include "interprete.h"
#include "programme.h"
#include "generation_terrains.h"
#include "curiosity_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BLOQUE -1
#define TOMBE -2
#define ECRASE -3

int main(int argc, char **argv) {
    if (argc != 9) {
        printf("Usage : %s fichier_programme N L H d graine nb_step_max fichier_res_nom\n", argv[0]);
        return 1;
    }

    char *fichier_programme_nom = argv[1];
    int N = atoi(argv[2]);
    int L = atoi(argv[3]);
    int H = atoi(argv[4]);
    float d = atof(argv[5]);
    int graine = atoi(argv[6]);
    int nb_step_max = atoi(argv[7]);
    char *fichier_res_nom = argv[8];

    // Controle d'imparite des dimensions
    if (L % 2 == 0 || H % 2 == 0) {
        printf("Erreur : L et H doivent être impairs.\n");
        return 1;
    }
    //Controle des dimensions
    if (H > DIM_MAX || L > DIM_MAX || H < 0 || L < 0) {
    printf("Hauteur et largeur doit etre entre 0 et %d\n", DIM_MAX);
    return 1;
    }
    if ((d > 1) || (d < 0)) {
    printf("Densité incorrecte : doit être comprise entre 0 et 1\n");
    return 1;
    }
    // Ouvrir les fichiers
    FILE *fichier_programme = fopen(fichier_programme_nom, "r");
    if (!fichier_programme) {
        printf("Erreur : impossible d'ouvrir le fichier programme %s\n", fichier_programme_nom);
        return 1;
    }

    // Ouvrir le fichier resultat pour ecrire
    FILE *res_file = fopen(fichier_res_nom, "w");
    if (!res_file) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", fichier_res_nom);
        return 1;
    }


    // Ecrire le nombre de terrain
    fprintf(res_file, "%d\n", N);

    // initalisation des statistiques
    int sorties = 0, bloques = 0, tombes = 0, ecrases = 0;
    int total_pas = 0;

    
    srand(graine);
    Environnement envt;
    Programme prog;
    etat_inter etat;
    resultat_inter res;

    for (int n = 0; n < N; n++) {
        Terrain terrain;
        float dObst_obtenu;
        initialise_terrain(&terrain, L, H);
        generation_aleatoire(&terrain, L, H, d, &dObst_obtenu);
        printf("Terrain initialized with L=%d, H=%d\n", L, H);
        printf("\n");
        printf("\n");
        
        //Coordonnes du robot au centre et initialisation du robot
        int cX = L/2 ; int cY = H/2;
        init_robot(&(envt.r),cX,cY,Nord);
        envt.t = terrain;
		lire_programme(&prog, argv[1]);
        //Init d'etat
        int pas = 0;
        init_etat(&etat);
		do {
			res = exec_pas(&prog, &envt, &etat);
			pas++;
			/* Affichage du terrain et du robot */
			//afficher_envt(&envt);
		} while (res == OK_ROBOT && pas < nb_step_max);
        total_pas += pas;

        // Affichage du resultat
        int result_value = 0;
        switch (res) {
            case SORTIE_ROBOT:
                result_value = pas; //Le nombre des pas
                sorties++;
                total_pas += pas;
                break;
            case OK_ROBOT:
            case ARRET_ROBOT:
                result_value = BLOQUE;
                bloques++;
                break;
            case PLOUF_ROBOT:
                result_value = TOMBE;
                tombes++;
                break;
            case CRASH_ROBOT:
                result_value = ECRASE;
                ecrases++;
                break;
            default:
                break;
            case ERREUR_PILE_VIDE:
		        printf("ERREUR : pile vide\n");
		        break;
		    case ERREUR_ADRESSAGE:
		        printf("ERREUR : erreur d'adressage\n");
		        break;
		    case ERREUR_DIVISION_PAR_ZERO:
		        printf("ERREUR : division par 0\n");
		        break;
        }
        fprintf(res_file, "%d\n", result_value);
    }

    fclose(res_file);

    // Les statistoques
    printf("Statistiques de performance :\n");
    printf("- Nombre de terrains testés : %d\n", N);
    printf("- Sorties : %d (%.2f%%)\n", sorties, (100.0 * sorties) / N);
    printf("- Bloqués : %d (%.2f%%)\n", bloques, (100.0 * bloques) / N);
    printf("- Tombés dans l'eau : %d (%.2f%%)\n", tombes, (100.0 * tombes) / N);
    printf("- Écrasés contre un rocher : %d (%.2f%%)\n", ecrases, (100.0 * ecrases) / N);
    if (sorties > 0) {
        printf("- Nombre moyen de pas pour les sorties : %.2f\n", (float)total_pas / sorties);
    } else {
        printf("- Nombre moyen de pas pour les sorties : N/A\n");
    }
    return 0;
}
