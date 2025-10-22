/*
Si realizzi un programma in C che crea un thread produttore e dieci (10) thread consumatori, che
eseguono le funzioni producer_thread e consumer_thread. I thread condividono un buffer, definito
attraverso la struttura TBuffer, che può contenere una stringa oppure essere vuoto. Inoltre, i thread
consumatori hanno un numero identificativo, diverso per ciascuno di essi, che va da 1 a 10.
Il thread producer ripete le seguenti operazioni:

1. Aspetta che il buffer sia vuoto
2. Legge una stringa da tastiera (con fgets) inserendola nel buffer
3. Rende il buffer non vuoto
4. Ricomincia dal passo 1.
I thread consumer ripetono le seguenti operazioni:
1. Aspetta che il buffer sia non vuoto
2. Stampa il proprio numero identificativo insieme alla stringa presente nel buffer.
3. Rende il buffer vuoto
4. Attende per 10 secondi.
5. Ricomincia dal passo 1.
I thread devono gestire in maniera appropriata la sincronizzazione nell’accesso al buffer.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

#define NTHREADS 11
#define STR_SIZE 120

typedef struct buffer {
    pthread_mutex_t mutex;
    pthread_cond_t cond_var;
    char string[STR_SIZE];
    bool empty;
} TBuffer;

typedef struct param {
    int id;
    TBuffer *buffer;
} TParam;

void *producer_thread(void *arg);
void *consumer_thread(void *arg);

int main(int argc, char *argv[]){
    pthread_t tid[NTHREADS];        //1 produttore, 10 consumatori
    TParam param[NTHREADS];
    TBuffer buffer;
    buffer.empty = true;

    //mutex & cond_var init
    if (pthread_mutex_init(&buffer.mutex, NULL) != 0){
        fprintf(stderr, "mutex init error!\n");
        return EXIT_FAILURE;
    }
    if (pthread_cond_init(&buffer.cond_var, NULL) != 0){
        fprintf(stderr, "cond_var init error!\n");
        return EXIT_FAILURE;
    }
    /*thread init*/
    if (pthread_create(&tid[0], NULL, producer_thread, &buffer) != 0){
        fprintf(stderr, "thread creation error!\n");
        return EXIT_FAILURE;
    }

    for (int i=1; i<NTHREADS; i++){
        param[i].id = i;
        param[i].buffer = &buffer;
        if(pthread_create(&tid[i], NULL, consumer_thread, &param[i]) != 0){
            fprintf(stderr, "thread creation error!\n");
            return EXIT_FAILURE;
        }
    }

    //thread join
    for (int i=0; i<NTHREADS; i++)
        pthread_join(tid[i], NULL);
    return EXIT_SUCCESS;
}

void *producer_thread(void *arg){
    TBuffer *prod_buffer = (TBuffer*) arg;
    while(true){
        pthread_mutex_lock(&prod_buffer->mutex);
        while(prod_buffer->empty == false)
            pthread_cond_wait(&prod_buffer->cond_var, &prod_buffer->mutex);     //blocca il thread chiamante sulla condizione
        printf("Producer: Inserire una stringa: ");
        fgets(prod_buffer->string, sizeof(prod_buffer->string), stdin);  
        prod_buffer->empty = false;
        pthread_cond_broadcast(&prod_buffer->cond_var);    //risveglia il thread chiamante
        pthread_mutex_unlock(&prod_buffer->mutex);
    }
}

void *consumer_thread(void *arg){
    TParam *param = (TParam*) arg;
    while(true){
        pthread_mutex_lock(&param->buffer->mutex);
        while(param->buffer->empty == true)
            pthread_cond_wait(&param->buffer->cond_var, &param->buffer->mutex);
        printf("Consumer %d, \t %s\n", param->id, param->buffer->string);
        param->buffer->empty = true;
        pthread_cond_broadcast(&param->buffer->cond_var);    //risveglia il thread chiamante
        pthread_mutex_unlock(&param->buffer->mutex);
        sleep(10);
    }
}
