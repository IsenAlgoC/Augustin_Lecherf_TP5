#include <stdlib.h>
#include <stdio.h>
#include "tab2.h"

#define TAILLEINITIALE 100

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));

	if (tab.elt == NULL) {                 // on v�rifie que la m�moire s'est bien allou�e
		return tab;
	}
	for (int i = 0; i < tab.size; i++) {   // on initialise � 0 le tableau
		*(tab.elt + i) = 0;
	}
		return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if ((*tab).elt == NULL || ((*tab).size+incrementValue) <=0 ) {         // test de validit�
		return -1;
	}

	int* save = (*tab).elt;                                  
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));       // on alloue la nouvelle m�moire

	if ((*tab).elt == NULL) {                                                                   // on v�rifie que la m�moire est bien allou�e		
		(*tab).elt = save;                                                                      // si �a n'est pas le cas, on annule la r�allocation
		return -1;
	}

	for (int i = (*tab).size ; i < (*tab).size + incrementValue  ; i++) {                      // initialisation � 0 de toutes les nouvelles valeurs
		(*tab).elt[i] = 0;
	}
	(*tab).size += incrementValue;                          // on augmente la taille du tableau
	return (*tab).size;
}


int setElement(TABLEAU* tab, int pos, int element) {
	if (((*tab).elt == NULL) || (pos < 1)) {                 // test de validit�
		return 0;
	}
	if (pos - 1 < (*tab).size) {                             // Dans le cas o� on ne d�passe pas la m�moire allou�e
		(*tab).elt[pos - 1] = element;                       // on �crit l'�lement
		return pos;
	}

	
	else {
		
		if (incrementArraySize(tab, (pos - (*tab).size)) == -1) {    // Dans la cas o� on d�passe la m�moire allou�e
			return 0;
		}
		(*tab).elt[pos - 1] = element;                               // on �crit l'�lement apr�s avoir incr�ment�e la m�moire n�cessaire
		return pos;
	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	int temp = 0;
	if (((*tab).elt == NULL) || (startPos < 1) || (startPos > (*tab).size) || (endPos < 1) || (endPos > (*tab).size)) {   // test de validit�
		return -1;
	}
	if (startPos > endPos) {                                           // si start est > � end, on les �changes
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                                          // s'ils sont �gaux, on affiche qu'un �l�ment
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
	int temp;                                       // variable pour �changer start et end

	if (((*tab).elt == NULL) || (startPos < 1) || (startPos > (*tab).size) || (endPos < 1) || (endPos > (*tab).size)) {    // test de validit�
		return -1;   
	}
	if (startPos > endPos) {                        // �change si start > end
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {                       // on supprime un seul �l�ment, et � partir de celui-ci on d�cale tout vers la gauche
		for (int i = startPos - 1; i < (*tab).size - 1; i++) {
			(*tab).elt[i] = (*tab).elt[i + 1];
		}
		if (incrementArraySize(tab, -1) == -1) {    // on enl�ve 1 case m�moire
			return -1;
		}	                           
		return (*tab).size;
	}
	for (int i = startPos - 1; i < (*tab).size - (endPos - startPos + 1); i++) {            // cas o� on supprime plusieurs �l�ments
		(*tab).elt[i] = (*tab).elt[i + endPos - startPos + 1];        // � partir de startPos, on d�cale tout de (end-start+1) vers la gauche
	}
	if (incrementArraySize(tab, -(endPos - startPos + 1)) == -1) {    // on enl�ve (end-start+1) cases m�moire
		return -1;
	}

	return (*tab).size;
	
}