#include <stdlib.h>
#include <stdio.h>
#include "tab2.h"

#define TAILLEINITIALE 100

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));

	if (tab.elt == NULL) {                 // on vérifie que la mémoire s'est bien allouée
		return tab;
	}
	for (int i = 0; i < tab.size; i++) {   // on initialise à 0 le tableau
		*(tab.elt + i) = 0;
	}
		return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if ((*tab).elt == NULL || ((*tab).size+incrementValue) <=0 ) {         // test de validité
		return -1;
	}

	int* save = (*tab).elt;                                  
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));       // on alloue la nouvelle mémoire

	if ((*tab).elt == NULL) {                                                                   // on vérifie que la mémoire est bien allouée		
		(*tab).elt = save;                                                                      // si ça n'est pas le cas, on annule la réallocation
		return -1;
	}

	for (int i = (*tab).size ; i < (*tab).size + incrementValue  ; i++) {                      // initialisation à 0 de toutes les nouvelles valeurs
		(*tab).elt[i] = 0;
	}
	(*tab).size += incrementValue;                          // on augmente la taille du tableau
	return (*tab).size;
}


int setElement(TABLEAU* tab, int pos, int element) {
	if (((*tab).elt == NULL) || (pos < 1)) {                 // test de validité
		return 0;
	}
	if (pos - 1 < (*tab).size) {                             // Dans le cas où on ne dépasse pas la mémoire allouée
		(*tab).elt[pos - 1] = element;                       // on écrit l'élement
		return pos;
	}

	
	else {
		
		if (incrementArraySize(tab, (pos - (*tab).size)) == -1) {    // Dans la cas où on dépasse la mémoire allouée
			return 0;
		}
		(*tab).elt[pos - 1] = element;                               // on écrit l'élement après avoir incrémentée la mémoire nécessaire
		return pos;
	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	int temp = 0;
	if (((*tab).elt == NULL) || (startPos < 1) || (startPos > (*tab).size) || (endPos < 1) || (endPos > (*tab).size)) {   // test de validité
		return -1;
	}
	if (startPos > endPos) {                                           // si start est > à end, on les échanges
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                                          // s'ils sont égaux, on affiche qu'un élément
		printf("pos %d : %d\n", startPos, (*tab).elt[startPos - 1]);
		return 0;
	}
	for (int i = startPos - 1; i < endPos; i++) {                      // sinon on affiche tout entre start et end
		printf("pos %d : %d\n",i+1 ,(*tab).elt[i]);
	}
	printf("\n");
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int temp;                                       // variable pour échanger start et end

	if (((*tab).elt == NULL) || (startPos < 1) || (startPos > (*tab).size) || (endPos < 1) || (endPos > (*tab).size)) {    // test de validité
		return -1;   
	}
	if (startPos > endPos) {                        // échange si start > end
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                       // on supprime un seul élément, et à partir de celui-ci on décale tout vers la gauche
		for (int i = startPos - 1; i < (*tab).size - 1; i++) {
			(*tab).elt[i] = (*tab).elt[i + 1];
		}
		if (incrementArraySize(tab, -1) == -1) {    // on enlève 1 case mémoire
			return -1;
		}	                           
		return (*tab).size;
	}
	for (int i = startPos - 1; i < (*tab).size - (endPos - startPos + 1); i++) {            // cas où on supprime plusieurs éléments
		(*tab).elt[i] = (*tab).elt[i + endPos - startPos + 1];        // à partir de startPos, on décale tout de (end-start+1) vers la gauche
	}
	if (incrementArraySize(tab, -(endPos - startPos + 1)) == -1) {    // on enlève (end-start+1) cases mémoire
		return -1;
	}

	return (*tab).size;
	
}