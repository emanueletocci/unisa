#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int somma;
    int numero;
} TParam;

void* calcola_somma(void* arg);

int main(int argc, char* argv[]){
    TParam p;
    if (argc!=2){
        puts("Devi specificare un numero intero come parametro!");
        return 1;
    }
    p.numero = atoi(argv[1]);

    pthread_t tid;
    if (pthread_create(&tid, NULL, calcola_somma, &p) != 0){
        puts("Errore creazione thread");
        return 2;
    }

    pthread_join(tid, NULL);
    printf("Somma = %d\n", p.somma);
    return 0;
}

void* calcola_somma (void *arg){
    TParam* param = (TParam*) arg;
    int n = param->numero;
    int i;
    param->somma = 0;
    for (size_t i = 1; i <= n; i++)
    {
        param->somma += i;
    }
    return NULL;
}