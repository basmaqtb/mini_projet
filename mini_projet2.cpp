#include <stdio.h>
#include <stdlib.h>

int quantite[100];
int codes[100];
int taille = 0; // Initialize the size of the array

void Add(int code, int Q) {
    int produitExist = 0;

    for (int i = 0; i < taille; i++) {
        if (codes[i] == code) {
            quantite[i] += Q;
            produitExist = 1;
            break;
        }
    }

    if (produitExist != 1) {
        codes[taille] = code;
        quantite[taille] = Q;
        taille++;
    }
}

void Remove(int code, int Q) {
    int produitExist = 0;

    for (int i = 0; i < taille; i++) {
        if (codes[i] == code) {
            if (quantite[i] >= Q) {
                quantite[i] -= Q;
                produitExist = 1;
            } else {
                printf("Erreur : La quantité à retirer n'est pas valable\n");
            }
        }
		else{
        	printf("Erreur : Le produit avec le code %d n'existe pas\n", code);
		}
    }

    
    
}

void Affichage() {
    if (taille == 0) {
        printf("Le stock est vide.\n");
    }

    printf("\n=== Stock :=== \n");

    for (int i = 0; i < taille; i++) {
        printf("Le produit avec le code : %d - Quantite : %d\n ", codes[i], quantite[i]);
    }
}

int main() {
    int Q, code;
    char choice;

    do {
        printf("\n<<<<<<<< Menu: >>>>>>>>>\n");
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
                Add(code, Q);
                break;
            case '2':
                printf("Entrer le code produit : ");
                scanf("%d", &code);
                printf("Entrer la Quantite : ");
                scanf("%d", &Q);
                Remove(code, Q);
                break;
            case '3':
                Affichage();
                break;
            case '4':
                printf("Vous avez quitte!\n");
                break;
            default:
                printf("Choix invalide. Entrer un choix entre 1 et 4!\n");
        }

    } while (choice != '4');

    return 0;
}
