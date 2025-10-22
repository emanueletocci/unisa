/*
Si scriva un programma in linguaggio C che
condivide un contatore, inizializzato a 3, tra 4
thread.
La metà dei thread incrementa il contatore di uno
mentre l’altra metà lo decrementa di uno. Tutti i
thread attendondo un intervallo di tempo casuale
tra 0 e 4 secondi prima di modificare il contatore.
Questa operazione viene iterata 5 volte da ogni
thread.
Si implementi un sistema di sincronizzazione che
faccia in modo che il valore del contatore non esca
dal range [0,5] (estremi compresi).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREAD 4
#define TIMES 5

typedef struct{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int contatore;
} TParam;

typedef struct {
    int numero;   /* Numero assegnato al thread */
    TParam *Ptrbuffer; /* Puntatore al buffer */
} TWorkerParam;

void* incremento(void *arg);
void* decremento(void *arg);

int main (int argc, char *argv[]){
    TParam param;
    TWorkerParam WorkerParam[NUM_THREAD];

    param.contatore=3; 
    for (int i=0; i<NUM_THREAD; i++){
        WorkerParam[i].numero = i;
        WorkerParam[i].Ptrbuffer = &param;
    }

    pthread_mutex_init(&param.mutex, NULL);
    pthread_cond_init(&param.cond, NULL);

    pthread_t tid[NUM_THREAD];

    for (int i=0; i<NUM_THREAD/2; i++){
        if(pthread_create(&tid[i], NULL, incremento, &WorkerParam[i])){
            fprintf(stderr, "thread creation error!\n");
            exit(1);
        }
    }
    for (int i=NUM_THREAD/2; i<NUM_THREAD; i++){
        if(pthread_create(&tid[i], NULL, decremento, &WorkerParam[i])){
            fprintf(stderr, "thread creation error!\n");
                return EXIT_FAILURE;
        }
    }
    for(int i=0; i<NUM_THREAD; i++)
        pthread_join(tid[i], NULL);
        
    return EXIT_SUCCESS;
}

void* incremento(void *arg){
    TWorkerParam * p = (TWorkerParam*) arg ;
    for (int i=0; i<TIMES; i++){
        int sleep_time = rand() % 5;
        printf("sleep:\t %d \n", sleep_time);
        sleep(sleep_time);
        pthread_mutex_lock(&p->Ptrbuffer->mutex);
        while(p->Ptrbuffer->contatore >= 5)
            pthread_cond_wait(&p->Ptrbuffer->cond, &p->Ptrbuffer->mutex);
        p->Ptrbuffer->contatore++;
        printf("Thread %d \t contatore = %d\n", p->numero, p->Ptrbuffer->contatore);
        pthread_cond_broadcast(&p->Ptrbuffer->cond);
        pthread_mutex_unlock(&p->Ptrbuffer->mutex);
    }
    return NULL;
}

void* decremento(void *arg){
    TWorkerParam* p = (TWorkerParam *) arg;
    for (int i=0; i<TIMES; i++){
        int sleep_time = rand() % 5;
        printf("sleep:\t %d \n", sleep_time);
        sleep(sleep_time);
        pthread_mutex_lock(&p->Ptrbuffer->mutex);
        while(p->Ptrbuffer->contatore <= 0)
            pthread_cond_wait(&p->Ptrbuffer->cond, &p->Ptrbuffer->mutex);
        p->Ptrbuffer->contatore--;
        printf("Thread %d \t contatore = %d \n", p->numero , p->Ptrbuffer->contatore);
        pthread_cond_broadcast(&p->Ptrbuffer->cond);
        pthread_mutex_unlock(&p->Ptrbuffer->mutex);
    }
    return NULL;
}