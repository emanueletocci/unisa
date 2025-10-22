#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define DIM 100

void* tid_print(void* arg);

int main(int argc, char* argv[]){
    if (argc!=2){
        puts("Devi specificare un numero intero come parametro!");
        return 1;
    }
    int numero = atoi(argv[1]);

    pthread_t tid[DIM];
    int arg[DIM];
    for (int i = 0; i < numero; i++){
        arg[i]=i;
        if (pthread_create(tid, NULL, tid_print, &arg[i]) != 0){
            puts("Errore creazione thread");
            return 2;
        }
    }
    for (int i = 0; i < numero; i++){
        pthread_join(tid[i], NULL);
        return 0;
    }
}

void* tid_print (void *arg){
    int* index = (int*) arg;
    printf("Indice: %d\n", *index);
    return NULL;
}