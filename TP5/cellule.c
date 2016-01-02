#include <stdlib.h>
#include <string.h>
#include "cellule.h"

Cellule* creerCellule(Element data)
{
	Cellule* c = (Cellule*) malloc(sizeof(Cellule));
	c->data = (Element) malloc(sizeof(Element));
    c->data = data;
	c->next = NULL;
	return c;
}

void detruireCellule(Cellule** c)
{
	free(*c);
	c = NULL;
}