//
//  noeud.h
//  INFO0501
//
//  Created by Julien Hubert on 06/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#ifndef noeud_h
#define noeud_h

typedef struct noeud_ {
    char* mot;
    struct noeud_* pere;
    struct noeud_* gauche;
    struct noeud_* droite;
} noeud;

noeud* creerNoeud(char* mot);
void detruireNoeud(noeud** n);

#endif /* noeud_h */
