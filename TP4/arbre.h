//
//  arbre.h
//  INFO0501
//
//  Created by Julien Hubert on 06/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#ifndef arbre_h
#define arbre_h

#include "noeud.h"

typedef struct {
    noeud* racine;
    int size;
} arbre;

arbre* creerArbre(noeud* racine);
void detruireArbre(arbre** a);
void inserer(arbre* a, noeud* n);
noeud* rechercher(noeud* n, char* str);
void supprimer(arbre* a, noeud* n);

#endif /* arbre_h */
