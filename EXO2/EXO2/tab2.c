#include <stdlib.h>
#include <stdio.h>
#include "tab2.h"

#define TAILLEINITIALE 100

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


