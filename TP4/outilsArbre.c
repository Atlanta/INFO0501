//
//  outilsArbre.c
//  INFO0501
//
//  Created by Julien Hubert on 06/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#include "outilsArbre.h"
#include <stdio.h>

void afficherArbreRecursif(noeud* n) {
    if (n != NULL) {
        printf("%s\n", n->mot);
        afficherArbreRecursif(n->gauche);
        afficherArbreRecursif(n->droite);
    }
}