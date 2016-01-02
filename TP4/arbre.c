//
//  arbre.c
//  INFO0501
//
//  Created by Julien Hubert on 06/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#include "arbre.h"
#include <stdlib.h>
#include <string.h>

arbre* creerArbre(noeud* racine) {
    arbre* a = (arbre*) malloc(sizeof(arbre));
    
    a->racine = racine;
    a->size = 1;
    
    return a;
}

void detruireArbre(arbre** a) {
    free(*a);
    a = NULL;
}

void inserer(arbre* a, noeud* n) {
    noeud* x = a->racine;
    noeud* y = NULL;
    
    while (x != NULL) {
        y = x;
        if (strcmp(n->mot, x->mot) < 0)
            x = x->gauche;
        else
            x = x->droite;
    }
    
    n->pere = y;
    
    if (y == NULL)
        a->racine = n;
    else if (strcmp(n->mot, y->mot) < 0)
        y->gauche = n;
    else
        y->droite = n;
    
    a->size++;
}

noeud* rechercher(noeud* n, char* str) {
    if (strcmp(n->mot, str) == 0 || n == NULL)
        return n;
    else if (strcmp(n->mot, str) < 0)
        return rechercher(n->gauche, str);
    else
        return rechercher(n->droite, str);
}