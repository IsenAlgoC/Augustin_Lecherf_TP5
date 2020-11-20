#pragma once
#include <stdlib.h>
#include <stdio.h>
#define TAILLEAJOUT 50


int initTab(int* tab, int size) {                    
	if ((tab == NULL) || (size < 0)) {        // test si le tableau est valide
		return - 1;
	}
	for (int i = 0; i < size; i++) {          // on initialise chaque valaur du tableau à 0
		*(tab + i) = 0;
	}
	return size;
}

int afficheTab(int* tab, int size, int nbElts) {
	if ((tab == NULL) || (size < 0) || (nbElts < 0)) {       // test si le tableau est valide
		return -1;
	}
	for (int i = 0; i < nbElts; i++) {                       // affichage du tableau jusqu'à la 'nbElts'ième valeur
		printf("%d ", *(tab + i));
		}
	printf("\n");

}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (*size < 0 || tab == NULL || *size < *nbElts) {                          // test si la tableau est valide
		return -1;
	}
	else if (*size == *nbElts) {                                             // Dans le cas où la taille du tableau est égal au nombre d'elements qu'il contient
		int* save = tab;                                                     // on sauvegarde le tableau
		tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));       // réallocation du pointeur tableau  
		if (tab == NULL) {                                                   // si cela échoue
			tab = save;                                                      // on restitue le pointeur tableau avec sa taille avant la réallocation
			printf("\n Mémoire insuffisante \n");
			return -1;
		}
		else {                                  // sinon on change la taille du tableau, on ajoute la valeur souhaitée, et on augmente le nombre d'élements de 1
			*size += TAILLEAJOUT;                                
			*(tab + *nbElts) = element;
			*nbElts += 1;
			return *nbElts;
		}
	}
	else {                                      // Dans le cas où la taille du tableau est supérieur au nombre d'élements
		
		*(tab + *nbElts) = element;             // on ajoute la valeur souhaitée et on incrémente le nombre d'élements
		*nbElts += 1;
		
		return *nbElts;
	}


}

