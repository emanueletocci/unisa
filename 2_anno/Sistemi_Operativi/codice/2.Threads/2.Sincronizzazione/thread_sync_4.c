/*
Si realizzi un programma in C che crea un thread secondario che funge da produttore, mentre il
main funge da consumatore.

๏ Il buffer condiviso consente di memorizzare una sola stringa

๏ Il produttore legge una parola da tastiera e la inserisce nel buffer, poi ricomincia da capo.

๏ Il main, in un ciclo infinito, preleva la parola dal buffer e ne stampa la lunghezza
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BUF_SIZE 100

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond_var;
    char string[500];
    bool presente;
} TParam;

void* produttore (void *arg){
    TParam* param = (TParam*) arg;
    while(true){
        pthread_mutex_lock(&param->mutex);
        while(param->presente)
            pthread_cond_wait(&param->cond_var, &param->mutex);
        puts("Inserire una parola da tastiera...");
        scanf("%s", param->string);
        param->presente = true;
        pthread_cond_signal(&param->cond_var);  //risveglio thread in attesa sulla variabile condition
        pthread_mutex_unlock(&param->mutex);
    }
    return NULL;
}

int main (int argc, char *argv[]){
    TParam param;
    param.presente = false;
    //mutex & cond_var init
    pthread_mutex_init(&param.mutex, NULL);
    pthread_cond_init(&param.cond_var, NULL);
    
    // thread creation
    pthread_t tid;
    if (pthread_create(&tid, NULL, produttore, &param)){
        fprintf(stderr, "thread creation error!\n");
        exit(1);
    }

    //consumatore
    while(true){
        pthread_mutex_lock(&param.mutex);
        while(!param.presente)
            pthread_cond_wait(&param.cond_var, &param.mutex);
        printf("La parola inserita %s e' lunga: %d\n", param.string, strlen(param.string));
        param.presente = false;   
        pthread_cond_signal(&param.cond_var);
        pthread_mutex_unlock(&param.mutex);
    }

    pthread_join(tid, NULL);
    return 0;
}
