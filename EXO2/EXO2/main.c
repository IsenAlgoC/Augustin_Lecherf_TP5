#include <stdlib.h>
#include <stdio.h>
#include "tab2.h"

int main() {
	TABLEAU tab = newArray();

	setElement(&tab, 1, 1);                // �criture des valeurs dans le tableau
	setElement(&tab, 4, 12);
	setElement(&tab, 4, 5);
	setElement(&tab, 6, 8);
	setElement(&tab, 7, 2);
    setElement(&tab, 10, 10);
	displayElements(&tab, 3, 10);          // affichage des �lements de la position 3 � 10
	deleteElements(&tab, 4, 6);            // supressions des �lements de la position 4 � 6
	displayElements(&tab, 1, 10);          // affichage des �lements de la position 1 � 10
}