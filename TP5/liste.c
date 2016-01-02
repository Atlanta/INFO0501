#include <stdlib.h>
#include "cellule.h"
#include "liste.h"

Liste* creerListe()
{
	Liste* l = (Liste*) malloc(sizeof(Liste));
	l->head = NULL;
	return l;
}

void detruireListe(Liste** l)
{
	free(*l);
	l = NULL;
}

void insererListe(Liste* l, Cellule* c)
{
	if(l->head != NULL)
	{
		Cellule* curseur = l->head;
		while(curseur->next != NULL)
		{
			curseur = curseur->next;
		}
		curseur->next = c;
	}
	else
	{
		l->head = c;
	}
}

Cellule* rechercherListe(Liste* l, Element e)
{
	Cellule* curseur = NULL;

	if(l->head == NULL)
	{
		return NULL;
	}
	
	curseur = l->head;
	while(curseur->next != NULL)
	{
		if(curseur->data == e)
		{
			return curseur;
		}
		else
		{
			curseur = curseur->next;
		}
	}
	if(curseur->data == e)
	{
		return curseur;
	}
	else
	{
		return NULL;
	}
}

void supprimerListe(Liste* l, Cellule* c)
{
	Cellule* curseur = l->head;

	while(curseur->next != c)
	{
		curseur = curseur->next;
	}

	curseur->next = c->next;

	detruireCellule(&c);
}

