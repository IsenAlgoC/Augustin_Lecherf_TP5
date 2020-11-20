#include <stdlib.h>
#include <stdio.h>
#include "tab2.h"

int main() {
	TABLEAU tab = newArray();
	
	setElement(&tab, 1, 2);     
	setElement(&tab, 4, 12);
	setElement(&tab, 23, 23);
	setElement(&tab, 13, 8);
	displayElements(&tab, 1, 23);
}