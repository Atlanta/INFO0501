//
//  main.c
//  TP4
//
//  Created by Julien Hubert on 06/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//


#include "outilsArbre.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    noeud* n = creerNoeud("Bonjour");
    arbre* a = creerArbre(n);
    n = creerNoeud("Baba");
    inserer(a, n);
    n = creerNoeud("Bobo");
    inserer(a, n);
    n = creerNoeud("Buba");
    inserer(a, n);
    n = creerNoeud("Caba");
    inserer(a, n);
    
    afficherArbreRecursif(a->racine);
    
    detruireNoeud(&n);
    detruireArbre(&a);
    
    return 0;
}
