/*
Si scriva un programma in linguaggio C che, dati in
input tre vettori di interi, calcola il minimo valore in
essi contenuto.
Il programma esegue tre thread, uno per ogni
vettore, che condividono l’area di memoria in cui
salvare il minimo.
Infine, il thread principale attende la terminazione
dei thread secondari e stampa a video il valore
risultante.

Attenzione: Vi è un solo valore minimo calcolato su
tutti e tre i vettori!
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREAD 3
#define DIM 10
#define MAX 50

typedef struct{
    pthread_mutex_t mutex;
    int minimo;
}TBuffer;

typedef struct{
    int vet[DIM];
    TBuffer *bufferPtr;
}TParam;

void* min_cal(void *arg);

int main(int argc, char *argv[]){

    // dichiarazione strutture
    TBuffer buffer;
    TParam param[NUM_THREAD];

    // inizializzazione parametri
    buffer.minimo = MAX+1;
    if(pthread_mutex_init(&buffer.mutex, NULL)){
        fprintf(stderr, "init error!\n");
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    for (int i=0; i < NUM_THREAD; i++){
        param[i].bufferPtr = &buffer;
        printf("vet[%d] = ", i);
        for (int j=0; j<DIM; j++){
            param[i].vet[j] = (rand()%MAX); // generazione casuale dei vettori
            printf("%d ", param[i].vet[j]);
        }
        printf("\n");
    }
    
    printf("\n");

    // creazione thread(s)
    pthread_t tid[NUM_THREAD];
    for (int i=0; i<NUM_THREAD; i++){
        if(pthread_create(&tid[i], NULL, min_cal, &param[i]) != 0){
            fprintf(stderr, "creation error!\n");
            return EXIT_FAILURE;
        }
    }

    // join
    for (int i=0; i<NUM_THREAD; i++)
        pthread_join(tid[i], NULL);
    
    printf("Minimo = %d \n", buffer.minimo);
    return EXIT_SUCCESS;

}

void* min_cal(void *arg){
    TParam* p = (TParam*) arg;
    int min = p->vet[0];

    // ricerca minimo locale
    for (int i=1; i<DIM; i++){
        if (p->vet[i] < min )
            min = p->vet[i];
    }

    printf("Minimo locale: %d \n", min);

    // sezione critica
    pthread_mutex_lock(&p->bufferPtr->mutex);
    if (min < p->bufferPtr->minimo)
        p->bufferPtr->minimo = min;  // sostituisci il minimo globale con quello locale
    pthread_mutex_unlock(&p->bufferPtr->mutex);

    return NULL;
}