#include <stdlib.h>
#include <stdio.h>
#include "tab2.h"

#define TAILLEINITIALE 10

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));

	if (tab.elt == NULL) {           //on vérifie que la mémoire s'est bien allouée
		return tab;
	}
	for (int i = 0; i < tab.size; i++) {   //on initialise à 0 le tableau
		*(tab.elt + i) = 0;
	}
		return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if ((*tab).elt == NULL || incrementValue <= 0) {         // test de validité
		return -1;
	}

	int* save = (*tab).elt;                                  
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));       // on alloue la nouvelle mémoire

	if ((*tab).elt == NULL) {                                                                   // on vérifie que la mémoire est bien allouée		
		(*tab).elt = save;
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
		
		if (incrementArraySize(tab, (pos - (*tab).size)) == -1) {  // Dans la cas où on dépasse la mémoire allouée
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
		printf("pos %d : %d\n",startPos +i ,(*tab).elt[i]);
	}
	return 0;
}

