#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAB2SIZE 100

int main() {
	int myTab1[10];                         // déclaration d'un tableau de 10 valeurs
	initTab(myTab1, 10);                    // initialisation des valeurs à 0 
	afficheTab(myTab1, 10, 5);              // affichage des 5 premières valeurs

	int* myTab2 = NULL;                     // création du pointeur myTab2 
	int nbElts = 20;
	int tabSize = TAB2SIZE;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));     // allocation de la mémoire nécessaire au tableau dynamique
	if (myTab2 != NULL) {                              // on test si le systeme accepte d'allouer la memoire demandée
		initTab(myTab2, tabSize);                      // si c'est le cas on initialise toutes les valeurs à 0
	}
	else { 
		printf("mémoire insuffisante");
		return(-1);
	}
	for (int i = 0; i < nbElts; i++)                  // on remplace les 'nbElts' premières valeurs par les valeurs de 1 à 'nbElts'
	{
		*(myTab2 + i) = i + 1;
	}

	afficheTab(myTab2, tabSize, nbElts);              // affichage de myTab2 jusqu'à la 'nbElts'ième valeur

	ajoutElementDansTableau(myTab2, &tabSize, &nbElts, 47);         // on ajoute 47 à la suite de mytab2
	afficheTab(myTab2, tabSize, nbElts);                            // affichage de myTab2 avec la nouvelle valeur
	
	free(myTab2);                                                   // destruction de myTab2
}