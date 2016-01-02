//
//  main.c
//  CM2
//
//  Created by Julien Hubert on 11/11/2015.
//  Copyright © 2015 Solana Inc. All rights reserved.
//

#include "cm2.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 8;
    int a = 78, b = 44;
    printf("%d! = %d\n", n, factorielle(n));
    printf("PGCD(%d,%d) = %d\n", a, b, pgcd_iteratif(a, b));
    return 0;
}

int factorielle(int n) {
    int fact;
    
    if (n == 0) {
        fact = 1;
    }
    else {
        fact = n * factorielle(n-1);
    }
    
    return fact;
}

int pgcd(int a, int b) {
    int res;
    
    if (a == b) {
        res = a;
    }
    else if (a > b) {
        res = pgcd(a-b, a);
    }
    else {
        res = pgcd(a, b-a);
    }
    
    return res;
}

int pgcd_iteratif(int a, int b) {
    int res;
    
    while (a != b) {
        if (a > b) {
            a = a-b;
        }
        else {
            b = b-a;
        }
    }
    
    res = a;
    return res;
}

int fibonacci(int n) {
    int res;
    
    if (n == 0) {
        res = 1;
    }
    else if (n == 1) {
        res = 1;
    }
    else {
        res = fibonacci(n-1) + fibonacci(n-2);
    }
    
    return res;
}
