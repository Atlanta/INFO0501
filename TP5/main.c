//
//  main.c
//  TP5
//
//  Created by Julien Hubert on 10/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#include "graphe.h"
#include "file.h"

int main(int argc, const char * argv[]) {
    char* filename = "/Users/Atlanta/XCode/INFO0501/TP5/graphe1.txt";
    Graphe* g = creerGraphe(filename);
    
    //afficherListeAdjacences(*g);
    
    parcoursLargeur(g, &g->tSommets[0]);
    
    for (int i = 0; i < g->nSommets; i++) {
        afficherSommet(g->tSommets[i]);
    }
    
    afficherChemin(g, &g->tSommets[1], &g->tSommets[10]);
    
    detruireGraphe(&g);
    
    File_t* f = creerFile(5);
    
    Sommet s; s.couleur = 'n';
    Sommet s2; s2.couleur = 'b';
    Sommet s3; s3.couleur = 'g';
    
    enfiler(f, &s);
    enfiler(f, &s2);
    enfiler(f, &s3);
    
    //printf("%c\n", defiler(f).couleur);
    
    detruireFile(&f);
    
    return EXIT_SUCCESS;
}
