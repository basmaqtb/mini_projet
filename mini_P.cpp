#include <stdio.h>
#include <stdlib.h>

void Add(int T[][2], int *taille, int code, int Q) {
    int produitExist = 0;
    for (int i = 0; i < *taille; i++) {
        if (T[i][0] == code) {
            T[i][1] += Q;
            produitExist = 1;
            break;
        }
    }
    if (produitExist != 1) {
        T[*taille][0] = code;
        T[*taille][1] = Q;
        (*taille)++;
    }
}

void Remove(int T[][2], int *taille, int code, int Q) {
    int produitExist = 0;
    for (int i = 0; i < *taille; i++) {
        if (T[i][0] == code) {
            if (T[i][1] >= Q) {
                T[i][1] -= Q;
                produitExist = 1;
            } else {
                printf("Erreur : La quantité à retirer n'est pas valable\n");
            }
            break;
        }
        else (produitExist != 1) {
        printf("Erreur : Le produit avec le code %d n'existe pas\n", code);
    }
    }
}

void Affichage(int T[][2], int *taille) {
    for (int i = 0; i < *taille; i++) {
        printf("Le produit avec le code : %d - Quantite : %d\n ", T[i][0], T[i][1]);
    }
}

int main() {
    int T[3][2] = {{0310, 45}, {2109, 10}, {1209, 20}};
    int taille = 3;
    int Q, code;
    char choice;

    do {
        printf("<<<<<<<< Menu: >>>>>>>>>\n");
        printf("1: Ajouter \n");
        printf("2: Retirer \n");
        printf("3: Afficher le stock\n");
        printf("4: Quitter\n");

        printf("Entrer votre choix : ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Entrer le code produit : ");
                scanf("%d", &code);
                printf("Entrer la Quantite : ");
                scanf("%d", &Q);
                Add(T, &taille, code, Q);
                break;
            case '2':
                printf("Entrer le code produit : ");
                scanf("%d", &code);
                printf("Entrer la Quantite : ");
                scanf("%d", &Q);
                Remove(T, &taille, code, Q);
                break;
            case '3':
                Affichage(T, &taille);
                break;
            case '4':
                printf("Vous avez quitte!\n");
                break;
            default:
                printf("Choix invalide. Entrer un choix entre 1 et 4!\n");
        }

    } while (choice != '4');

   
}
