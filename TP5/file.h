//
//  file.h
//  INFO0501
//
//  Created by Julien Hubert on 17/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#ifndef file_h
#define file_h

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

typedef struct {
    Sommet** file;
    Sommet** tete;
    Sommet** queue;
    int longueur;   // Taille max de la file
    int taille;     // Taille actuelle de la file
} File_t;

File_t* creerFile(int size);
void detruireFile(File_t** f);
int fileVide(File_t f);
void enfiler(File_t* f, Sommet* s);
Sommet* defiler(File_t* f);

#endif /* file_h */
