#include <stdio.h>
#include "outilsListe.h"
#include "liste.h"
#include "cellule.h"

void afficherListe(Liste* l)
{
    if (l->head == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    Cellule* curseur = l->head;
	int i = 1;

	while(curseur->next != NULL) {
		printf("Cellule n°%d :\t%d\tPoids : %d\n", i, curseur->data, curseur->poids);
		i++;
		curseur = curseur->next;
	}
	printf("Cellule n°%d :\t%d\tPoids : %d\n", i, curseur->data, curseur->poids);
}