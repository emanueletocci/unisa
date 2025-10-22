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
#define SIZE2 10
#define NTHREADS 5

typedef struct {
    int length;
    int *result;
} TParam;

int fibonacci_calculate(int n){
    if (n==0 || n ==1)
        return n;
    else    
        return fibonacci_calculate(n-1) + fibonacci_calculate(n-2);
}

void *fibonacci_fun (void* arg){
    TParam *param = (TParam *) arg;
    int *array = param->result;
    int n = param->length;

    for (int i=0; i<n; i++)
        array[i] = fibonacci_calculate(array[i]);
    return NULL;
}

int main (int argc, char* argv[]){
    int num[SIZE];
    pthread_t tid[NTHREADS];
    TParam param[NTHREADS];

    if (argc < 2){
        fprintf(stderr, "Numero insufficiente di parametri!\n");
        return EXIT_FAILURE;
    }

    //salvataggio parametri nell'array num
    for (int i = 0; i < argc-1; i++){
        if (atoi(argv[i+1]) >= 0)
            num[i] = atoi(argv[i+1]);
        else 
            printf("%d : \t Numero negativo!\n");
    }

    //suddivisione argomenti
    int offset = round((argc-1)/NTHREADS); 
    for (int i = 0; i < NTHREADS; i++){
        param[i].result = num + i*offset;                  //base dell'array
    if (i != NTHREADS-1) 
        param[i].length = offset;
    else 
        param[i].length = (argc-1)-i*offset;

    }

    for (int i=0 ; i < NTHREADS; i++){
        if(pthread_create(&tid[i], NULL, fibonacci_fun , &param[i])){
            fprintf(stderr, "errore creazione thread!\n");
            return EXIT_FAILURE;
        }
    }

    for (int i=0; i < NTHREADS; i++)
        pthread_join(tid[i], NULL);
    
    puts("Stampo la serie di fibonacci calcolata ...");
    for (int i=0; i<argc-1; i++)
        printf("Input: %s\tOutput: %d\n", argv[i+1], num[i]);
    return EXIT_SUCCESS;
}