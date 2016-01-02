#ifndef CELLULE_H
#define CELLULE_H

typedef int Element;

typedef struct _cellule {
	Element data;
    Element poids;
	struct _cellule* next;
} Cellule;

Cellule* creerCellule(Element data, Element poids);
void detruireCellule(Cellule** c);

#endif