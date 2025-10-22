#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int somma;
void* calcola_somma(void* arg);

int main(int argc, char* argv[]){
    if (argc!=2){
        puts("Devi specificare un numero intero come parametro!");
        return 1;
    }
    int numero = atoi(argv[1]);
    pthread_t tid;
    if (pthread_create(&tid, NULL, calcola_somma, &numero) != 0){
        puts("Errore creazione thread");
        return 2;
    }

    pthread_join(tid, NULL);
    printf("Somma = %d\n", somma);
    return 0;
}

void* calcola_somma (void *arg){
    int* pnumero = (int*) arg;
    int n = *pnumero;
    int i;
    somma = 0;
    for (int i = 1; i <= n; i++)
        somma += i;
    return NULL;
}