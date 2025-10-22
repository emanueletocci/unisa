/*
Si realizzi un programma in C che crea due thread secondari
๏ Il primo thread incrementa una variabile intera conteggio ogni 3 secondi, stampando il suo
valore ad ogni incremento
๏ Il secondo thread aspetta che la variabile conteggio raggiunga il valore 10; quando ciò
accade, la rimette a 0 e stampa un messaggio; dopodiché ricomincia da capo.
๏ Il thread principale resta in attesa (infinita) che i due thread secondari terminino.
๏ NOTA BENE: questo non è un problema produttore/consumatore; ma anche in questo caso
abbiamo:
๏ l’accesso a una risorsa condivisa (la variabile conteggio) da parte dei due thread
๏ l’attesa di una condizione che dipende dal valore della risorsa condivisa, da parte del
secondo thread
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#define THREADS 2
#define DELAY 3
#define LIMITE 10

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond_var;
    int conteggio;
} TParam;

void* incrementa_conteggio (void *arg){
    TParam *param = (TParam*) arg;
    //SEZIONE CRITICA
    while(1){
        pthread_mutex_lock(&param->mutex);      //blocco il mutex
        param->conteggio ++;
        printf("Ho incrementato \"conteggio\": \t conteggio = %d \n", param->conteggio);
        pthread_cond_signal(&param->cond_var);  //risveglio thread in attesa sulla variabile condition
        pthread_mutex_unlock(&param->mutex);    //sblocco il mutex
        sleep(DELAY);
    }
}

void* controlla_limite (void *arg){
    TParam *param = (TParam*) arg;
    while(1){
        pthread_mutex_lock(&param->mutex);
        while (param->conteggio < LIMITE)
            pthread_cond_wait(&param->cond_var, &param->mutex);
        param->conteggio = 0;
        printf("Ho azzerato \"conteggio\" \t conteggio = %d \n", param->conteggio);
        pthread_mutex_unlock(&param->mutex);
    }
}   

int main (int argc, char *argv[]){
    TParam param;
    param.conteggio = 0;

    //mutex & cond_var init
    pthread_mutex_init(&param.mutex, NULL);
    pthread_cond_init(&param.cond_var, NULL);
    
    // thread creation
    pthread_t tid[THREADS];
    if (pthread_create(&tid[0], NULL, incrementa_conteggio, &param)){
        fprintf(stderr, "thread creation error!\n");
        exit(1);
    }
       
    if (pthread_create(&tid[1], NULL, controlla_limite, &param)){
        fprintf(stderr, "thread creation error!\n");
        exit(1);
    }
    for (int i = 0 ; i<THREADS; i++)
        pthread_join(tid[i], NULL);
    return 0;
}
