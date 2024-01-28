// GOUMIS ISMAIL
//     CMPI 
//   2023/2024

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *liste = NULL;
    int taille = 0;
    int capacite = 0;
    int choix;

    printf("Menu de gestion de la liste\n");
    printf("1- Afficher la liste des nombres saisis.\n");
    printf("2- Afficher la liste des nombres dans l’ordre croissant.\n");
    printf("3- Afficher la liste des nombres dans l’ordre décroissant.\n");
    printf("4- Afficher le nombre de redondances d’un nombre donné.\n");
    printf("5- Afficher les nombres positifs.\n");
    printf("6- Afficher les nombres négatifs.\n");
    printf("7- Supprimer les redondances d’un nombre donné.\n");
    printf("8- Ajouter des nombres.\n");
    printf("9- Afficher la moyenne de tous les nombres de la liste.\n");
    printf("0- Quitter le programme.\n");

    do {
        printf("Donner votre choix (0-1-2-3-4-5-6-7-8-9): ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Liste des nombres saisis : ");
                for (int i = 0; i < taille; i++) {
                    printf("%d ", liste[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Liste des nombres dans l'ordre croissant : ");
                for (int i = 0; i < taille; i++) {
                    for (int j = i + 1; j < taille; j++) {
                        if (liste[i] > liste[j]) {
                            int temp = liste[i];
                            liste[i] = liste[j];
                            liste[j] = temp;
                        }
                    }
                }
                for (int i = 0; i < taille; i++) {
                    printf("%d ", liste[i]);
                }
                printf("\n");
                break;
            case 3:
                printf("Liste des nombres dans l'ordre décroissant : ");
                for (int i = 0; i < taille; i++) {
                    for (int j = i + 1; j < taille; j++) {
                        if (liste[i] < liste[j]) {
                            int temp = liste[i];
                            liste[i] = liste[j];
                            liste[j] = temp;
                        }
                    }
                }
                for (int i = 0; i < taille; i++) {
                    printf("%d ", liste[i]);
                }
                printf("\n");
                break;
            case 4: {
                int nombre;
                printf("Donner le nombre pour lequel vous voulez compter les redondances : ");
                scanf("%d", &nombre);
                int compteur = 0;
                for (int i = 0; i < taille; i++) {
                    if (liste[i] == nombre) {
                        compteur++;
                    }
                }
                printf("Nombre de redondances de %d : %d\n", nombre, compteur);
                break;
            }
            case 5:
                printf("Nombres positifs : ");
                for (int i = 0; i < taille; i++) {
                    if (liste[i] > 0) {
                        printf("%d ", liste[i]);
                    }
                }
                printf("\n");
                break;
            case 6:
                printf("Nombres négatifs : ");
                for (int i = 0; i < taille; i++) {
                    if (liste[i] < 0) {
                        printf("%d ", liste[i]);
                    }
                }
                printf("\n");
                break;
            case 7: {
                int nombre;
                printf("Donner le nombre dont vous voulez supprimer les redondances : ");
                scanf("%d", &nombre);
                int j = 0;
                for (int i = 0; i < taille; i++) {
                    if (liste[i] != nombre) {
                        liste[j++] = liste[i];
                    }
                }
                taille = j;
                break;
            }
            case 8: {
                int nombreAjout;
                printf("Donner le nombre à ajouter : ");
                scanf("%d", &nombreAjout);
                if (taille >= capacite) {
                    capacite += 10;
                    liste = realloc(liste, capacite * sizeof(int));
                    if (liste == NULL) {
                        printf("Erreur lors de l'allocation de mémoire.\n");
                        return 1;
                    }
                }
                liste[taille++] = nombreAjout;
                printf("Nombre ajouté avec succès.\n");
                break;
            }
            case 9: {
                int somme = 0;
                for (int i = 0; i < taille; i++) {
                    somme += liste[i];
                }
                printf("La moyenne de tous les nombres de la liste est : %.2f\n", (float)somme / taille);
                break;
            }
            case 0:
                printf("Programme terminé.\n");
                free(liste);
                break;
            default:
                printf("Choix invalide. Veuillez saisir un choix valide.\n");
        }
    } while (choix != 0);

    return 0;
}
