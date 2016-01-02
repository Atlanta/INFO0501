#ifndef CELLULE_H
#define CELLULE_H

typedef int Element;

typedef struct _cellule {
	Element data;
	struct _cellule* next;
} Cellule;

Cellule* creerCellule(Element data);
void detruireCellule(Cellule** c);

#endif