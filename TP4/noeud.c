//
//  noeud.c
//  INFO0501
//
//  Created by Julien Hubert on 06/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#include "noeud.h"
#include <stdlib.h>
#include <string.h>

#define MOT_MAX_LENGTH 50

noeud* creerNoeud(char* mot) {
    noeud* n = (noeud*) malloc(sizeof(noeud));
    n->mot = (char*) malloc(sizeof(char) * MOT_MAX_LENGTH);
    n->pere = NULL; n->gauche = NULL; n->droite = NULL;
    
    strcpy(n->mot, mot);
    
    return n;
}

void detruireNoeud(noeud** n) {
    free((*n)->mot);
    free(*n);
    n = NULL;
}