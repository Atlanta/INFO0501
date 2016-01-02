//
//  file.c
//  INFO0501
//
//  Created by Julien Hubert on 17/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#include "file.h"

File_t* creerFile(int size) {
    File_t* f = (File_t*) malloc(sizeof(File_t));
    f->file = (Sommet**) malloc(size*sizeof(Sommet*));
    f->tete = &f->file[0];
    f->queue = f->tete;
    f->longueur = size;
    f->taille = 0;
    return f;
}

void detruireFile(File_t** f) {
    free(*f);
    f = NULL;
}

int fileVide(File_t f) {
    if (f.taille == 0)
        return 1;
    else
        return 0;
}

void enfiler(File_t* f, Sommet* s) {
    if (fileVide(*f)) {
        f->file[0] = s;
        f->queue = f->tete;
        f->taille = 1;
    }
    else if (f->taille < f->longueur) {
        f->file[f->taille] = s;
        f->queue = &f->file[f->taille];
        f->taille++;
    }
    else {
        printf("Erreur de file : File pleine !\n");
        exit(EXIT_FAILURE);
    }
}

Sommet* defiler(File_t* f) {
    if (!fileVide(*f)) {
        Sommet* s = *f->tete;
        for (int i = 1; i < f->taille; i++) {
            if (i == f->taille - 2) {
                f->queue = &f->file[i];
            }
            f->file[i-1] = f->file[i];
        }
        f->taille--;
        return s;
    }
    return NULL;
}