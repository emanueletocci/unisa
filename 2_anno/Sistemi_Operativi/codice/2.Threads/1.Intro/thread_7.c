/*
๏ Scrivere in C un programma che prenda come argomenti una lista di interi
positivi e crea NTHREADS thread, dove NTHREADS è una costante. Gli
argomenti sono divisi in NTHREADS parti, ognuna delle quali passata
come input ad un thread.
๏ Ogni thread calcola la funzione fibonacci per ognuno degli interi in input.

๏ Il main stampa a video la lista ordinata (successione di fibonacci) contentente i risultati calcolati dai thread.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>
#define SIZE 100

typedef struct {
    int n;
    float result;
} TParam;

float fibonacci_calculate(int n){
    if (n==0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else    
        return fibonacci_calculate(n-1) + fibonacci_calculate(n-2);
}

void *fibonacci_fun (void* arg){
    TParam *param = (TParam *) arg;
    param->result = fibonacci_calculate(param->n);
    return NULL;
}

int main(int argc, char* argv[]){
    int count, array[SIZE];

    //array init
    for (int i = 0; i < SIZE; i++)
        array[i] = 0;
    puts("Inserire una lista di numeri interi positivi. Inserire un numero negativo per interrompere la lettura.");
    for (int i = 0; i < SIZE; i++){
        int temp;
        printf("Inserire %d^ numero : ", i+1);
        scanf("%d", &temp);
        if(temp < 0)
            break;
        array[i] = temp;
        count = i+1;
    }
    printf("Sono stati inseriti %d valori. ", count);
    const int NTHREADS = count;
    printf("Creo %d threads.\n", NTHREADS);
    TParam param[NTHREADS];

    for(int i=0; i<NTHREADS; i++){
        param[i].n = array[i];
        param[i].result = 0;
    }
    
    //thread init
    pthread_t tid[NTHREADS];
    for (int i=0; i<NTHREADS; i++){
        if (pthread_create(&tid[i], NULL, fibonacci_fun , &param[i])){
            fprintf(stderr, "thread creation error!\n");
            exit(1);
        }
    }

    for (int i=0; i<NTHREADS; i++)
        pthread_join(tid[i], NULL);
    
    puts("Stampo la serie di fibonacci calcolata");
    for(int i=0; i<NTHREADS; i++){
        printf("%g \t", param[i].result);
    }
    return EXIT_SUCCESS;
}