/*
Esercizio 2
๏ Scrivere in C un programma che legge da tastiera due numeri interi: n e k.
๏ Successivamente il processo crea 3 thread secondari che provvedono a
calcolare indipendentemente il fattoriale di n, quello di k e quello di (n-k)
mediante una funzione factorial_thread che richiama un’altra funzione
per il calcolo vero e proprio del fattoriale.
๏ Una volta terminati i thread secondari, il thread principale stampa i risultati
di ognuno e calcola e stampa il coefficiente binomiale .
(n/k) = n!/(k!(n − k)!)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#define THREADS 3

typedef struct{
    int n;
    int result;
} TParam;

int factorial (int n){
    if (n<=1)
        return 1;
    return n*factorial(n-1);
}

void* factorial_thread (void *arg){
    TParam *p = (TParam*) arg;
    p->result = factorial(p->n);
    return NULL;
}

int main(int argc, char* argv[]){
    TParam param[THREADS];
    do{
        puts("Inserire un numero intero (n): ");
        scanf("%d", &param[0].n);
    } while (param[0].n <= 0);

    do {
        puts("Inserire un numero intero (k): ");
        scanf("%d", &param[1].n);    
    } while (param[1].n <= 0);
    param[2].n = param[0].n - param[1].n;

    pthread_t tid[THREADS];
    for (int i=0 ; i<THREADS; i++){
        if (pthread_create(&tid[i], NULL, factorial_thread, &param[i])){
            puts("Errore creazione thread");
            return 2;
        }
    }
    for (int i=0; i<THREADS; i++){
        if (pthread_join(tid[i], NULL)){
            puts("Errore join thread");
            return 2;
        }
    }
    puts("Fattoriali calcolati:");
    for (int i = 0; i < THREADS ; i++)
        printf("%d! = %d\n", param[i].n, param[i].result);
    float bin_coef = (param[0].result)/(param[1].result*param[2].result);
    puts("Coefficiente binomiale calcolato:");
    printf("%g\n", bin_coef);
    return 0;
}