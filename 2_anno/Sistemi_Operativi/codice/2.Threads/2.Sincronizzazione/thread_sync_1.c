/* 
๏ Realizzare un programma che crea due thread secondari. Il primo thread
secondario deve calcolare la somma dei numeri interi da 1 a 50, e il secondo la
somma dei numeri interi da 51 a 100. Entrambi i thread secondari devono
aggiungere la somma calcolata a una variabile somma (inizializzata a 0) fornita dal
thread principale
๏ Il thread principale aspetta la terminazione dei due thread secondari e stampa il
valore della variabile somma
๏ I thread secondari devono gestire correttamente la sincronizzazione nell'accedere
alla variabile condivisa somma
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS 2
#define START1 1
#define END1 50 
#define START2 51
#define END2 100 

typedef struct {
    int start;
    int end;
    int *psomma;
    pthread_mutex_t *mutex;
} TParam;

void* calcola_somma(void* arg);

int main(int argc, char* argv[]){
    int somma = 0;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid[THREADS];
    TParam param[THREADS];
    param[0].start = START1;
    param[0].end = END1;
    param[0].psomma = &somma;
    param[0].mutex = &mutex;
    param[1].start = START2;
    param[1].end = END2;
    param[1].psomma = &somma;
    param[1].mutex = &mutex;

    for (int i=0; i < THREADS; i++) {
        if (pthread_create(&tid[i], NULL, calcola_somma, &param[i])!=0) {
            printf("Errore nella creazione thread\n");
            return 1;
        }
    }

    /*for separati per create e join !! */

    for (int i=0; i < THREADS; i++)
        pthread_join(tid[i], NULL);
    printf("La somma è: %d\n", somma);
    return 0;
}
   
   
void *calcola_somma(void *arg) {
    TParam *p = (TParam *)arg;
    int i;
    int s = 0;
    for(i = p->start; i <= p->end; i++)
        s += i;

    /*inizio sezione critica*/
    pthread_mutex_lock(p->mutex);
    *p->psomma += s;
    pthread_mutex_unlock(p->mutex);
    /*fine sezione critica*/
    return NULL;
}