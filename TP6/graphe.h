//
//  graphe.h
//  INFO0501
//
//  Created by Julien Hubert on 10/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#ifndef graphe_h
#define graphe_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include "outilsListe.h"

#define INFINI INT_MAX

typedef struct sommet_ {
    int id;
    char couleur;
    int distance;
    struct sommet_* pere;
} Sommet;

typedef struct {
    Sommet origine;
    Sommet extremite;
} Arete;

typedef struct {
    int nSommets;
    int nAretes;
    int oriented;
    int valued;
    int complete;
    int** matriceAdjacences;
    Liste** listesAdjacences;
    Sommet* tSommets;
} Graphe;

Liste** creerListeAdjacences(char* filename);
int** creerMatriceAdjacences(char* filename);
Graphe* creerGraphe(char* filename);
Sommet* creerTableauSommets(Graphe g);

void afficherListeAdjacences(Graphe g);
void afficherMatriceAdjacences(Graphe g);
void afficherSommet(Sommet s);

void detruireGraphe(Graphe** g);

void parcoursLargeur(Graphe* g, Sommet* s);
void afficherChemin(Graphe* g, Sommet* s, Sommet* v);

#endif /* graphe_h */
