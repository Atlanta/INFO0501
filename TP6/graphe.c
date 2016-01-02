//
//  graphe.c
//  INFO0501
//
//  Created by Julien Hubert on 10/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//  http://cosy.univ-reims.fr/~pdelisle/fichiers/info0501_15-16/Tp5_Info0501.pdf
//

#include "graphe.h"
#include "file.h"

Liste** creerListeAdjacences(char* filename) {
    FILE* f;
    fpos_t defAretes;
    int nAretes = 0; int nSommets = 0; int i, j, k, poids;
    char* def = (char*) malloc(14 * sizeof(char));
    char* buffer = (char*) malloc(255 * sizeof(char));
    Cellule* c;
    
    if ((f = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier !\n");
        exit(EXIT_FAILURE);
    }
    
    // Recherche de "debutDefAretes"
    strcpy(def, "debutDefAretes");
    
    while (strcmp(def, buffer) != 0) {
        fscanf(f, "%s", buffer);
        if (strcmp(buffer, "nSommets") == 0) {
            fscanf(f, "%d", &nSommets);
        }
    }
    
    fgetpos(f, &defAretes);
    
    // Rehcerche de "finDefAretes" et comptage du nombre d'arêtes
    strcpy(def, "finDefAretes");
    
    while (strcmp(def, buffer) != 0) {
        fscanf(f, "%s", buffer);
        if (strcmp(def, buffer) != 0) {
            nAretes++;
        }
    }
    nAretes /= 3;
    
    Liste** tableauListesAdjacences = (Liste**) malloc(nSommets * sizeof(Liste*));
    for (i = 0; i < nSommets; i++) {
        tableauListesAdjacences[i] = creerListe();
        // On alloue les tableaux
    }
    
    fsetpos(f, &defAretes);
    
    for(k = 0; k < nAretes; k++)
    {
        fscanf(f, "%d %d %d", &i, &j, &poids);
        c = creerCellule(j, poids);
        insererListe(tableauListesAdjacences[i], c);
    }
    
    fclose(f);
    
    return tableauListesAdjacences;
}

int** creerMatriceAdjacences(char* filename) {
    FILE* f;
    fpos_t defAretes;
    int nAretes = 0; int nSommets = 0; int i, j, k;
    char* def = (char*) malloc(14 * sizeof(char));
    char* buffer = (char*) malloc(255 * sizeof(char));
    
    if ((f = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier !\n");
        exit(EXIT_FAILURE);
    }
    
    // Recherche de "debutDefAretes"
    strcpy(def, "debutDefAretes");
    
    while (strcmp(def, buffer) != 0) {
        fscanf(f, "%s", buffer);
        if (strcmp(buffer, "nSommets") == 0) {
            fscanf(f, "%d", &nSommets);
        }
    }
    
    fgetpos(f, &defAretes);
    
    // Rehcerche de "finDefAretes" et comptage du nombre d'arêtes
    strcpy(def, "finDefAretes");
    
    while (strcmp(def, buffer) != 0) {
        fscanf(f, "%s", buffer);
        if (strcmp(def, buffer) != 0) {
            nAretes++;
        }
    }
    nAretes /= 2;
    
    // Allocation du tableau à 2 dimensions
    int ** matriceAdjacences = calloc(nSommets, sizeof(int*)); // On alloue nSommets tableaux 1D
    for (i=0; i<nSommets; i++) {
        matriceAdjacences[i] = calloc(nSommets, sizeof(int)); // On alloue les tableaux
    }
    
    fsetpos(f, &defAretes);
    
    // Remplissage de la matrice
    for(k = 0; k < nAretes; k++)
    {
        fscanf(f, "%d %d", &i, &j);
        // Si il y a une arête entre i et j on met la case à 1
        matriceAdjacences[i][j] = 1;
    }
    
    fclose(f);
    
    return matriceAdjacences;
}

Graphe* creerGraphe(char* filename) {
    Graphe* g = (Graphe*) malloc(sizeof(Graphe));
    FILE* f;
    char buffer[255];
    int nSommets = 0, oriented = 0, valued = 0, complete = 0;
    
    if((f = fopen(filename, "r")) == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    
    while (!feof(f)) {
        fscanf(f, "%s", buffer);
        if (strcmp(buffer, "nSommets") == 0) {
            fscanf(f, "%d", &nSommets);
        }
        else if (strcmp(buffer, "oriente") == 0) {
            fscanf(f, "%d", &oriented);
        }
        else if (strcmp(buffer, "value") == 0) {
            fscanf(f, "%d", &valued);
        }
        else if (strcmp(buffer, "complet") == 0) {
            fscanf(f, "%d", &complete);
        }
    }
    
    fclose(f);
    
    g->listesAdjacences = creerListeAdjacences(filename);
    g->matriceAdjacences = creerMatriceAdjacences(filename);
    g->nSommets = nSommets;
    g->oriented = oriented;
    g->valued = valued;
    g->complete = complete;
    g->tSommets = creerTableauSommets(*g);
    
    return g;
}

Sommet* creerTableauSommets(Graphe g) {
    Sommet* tSommets = (Sommet*) malloc(g.nSommets * sizeof(Sommet));
    
    for (int i = 0; i < g.nSommets; i++) {
        tSommets[i].id = i;
        tSommets[i].couleur = 'b';
        tSommets[i].distance = INFINI;
        tSommets[i].pere = NULL;
    }
    
    return tSommets;
}

void afficherListeAdjacences(Graphe g) {
    int i;
    
    for (i = 0; i < g.nSommets; i++) {
        printf("\tSommet n°%d :\n", i+1);
        afficherListe(g.listesAdjacences[i]);
        printf("\n");
    }
}

void afficherMatriceAdjacences(Graphe g) {
    int i, j;
    
    for (i = 0; i < g.nSommets; i++) {
        for (j = 0; j < g.nSommets; j++) {
            printf("%d ", g.matriceAdjacences[i][j]);
        }
        printf("\n");
    }
}
void afficherSommet(Sommet s) {
    printf("Numéro du sommet : %d\n", s.id);
    printf("Couleur du sommet : ");
    switch (s.couleur) {
        case 'b':
            printf("Blanc\n");
            break;
        case 'g':
            printf("Gris\n");
            break;
        case 'n':
            printf("Noir\n");
            break;
        default:
            break;
    }
    printf("Distance : ");
    if (s.distance == INFINI)
        printf("Infini\n");
    else
        printf("%d\n", s.distance);
    printf("Père : ");
    if (s.pere != NULL)
        printf("%d\n", s.pere->id);
    else
        printf("nil\n");
}

void detruireGraphe(Graphe** g) {
    free((*g)->matriceAdjacences);
    free(*g);
    g = NULL;
}

void parcoursLargeur(Graphe* g, Sommet* s) { // s est le sommet d'origine du parcours en largeur
    int i;
    Cellule* curseur;
    Sommet u, v;
    
    // Initialisation
    for (i = 0; i < g->nSommets; i++) {
        u = g->tSommets[i];
        
        u.couleur = 'g';
        u.distance = 0;
        u.pere = NULL;
    }
    
    // Initialisation du sommet d'origine
    s->couleur = 'g';
    s->distance = 0;
    s->pere = NULL;
    
    // Création de la file et mise en file des sommets
    File_t* f = creerFile(INFINI);
    
    for (i = 0; i < g->nSommets; i++) {
        enfiler(f, g->tSommets[i]);
    }
    
    while (!fileVide(*f)) {
        u = defiler(f);
        curseur = g->listesAdjacences[u.id]->head;
        while (curseur != NULL) {
            v = g->tSommets[curseur->data];  // C'est plus lisible
            if (v.couleur == 'b') {
                v.couleur = 'g';
                v.distance = u.distance + 1;
                v.pere = &u;
                enfiler(f, v);
            }
            curseur = curseur->next;
        }
        u.couleur = 'n';
    }
    
    detruireFile(&f);
    detruireCellule(&curseur);
}

void afficherChemin(Graphe* g, Sommet* s, Sommet* v) {
    if (v->pere == s)
        afficherSommet(*s);
    else {
        if (v->pere == NULL)
            printf("Il n'y a aucun chemin de s à v.\n");
        else {
            afficherChemin(g, s, v->pere);
            afficherSommet(*v);
        }
    }
}