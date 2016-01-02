#ifndef LISTE_H
#define LISTE_H

#include "cellule.h"

typedef struct _list {
	Cellule* head;
} Liste;

Liste* creerListe();
void detruireListe(Liste** l);
void insererListe(Liste* l, Cellule* c);
Cellule* rechercherListe(Liste* l, Element e);
void supprimerListe(Liste* l, Cellule* c);

#endif