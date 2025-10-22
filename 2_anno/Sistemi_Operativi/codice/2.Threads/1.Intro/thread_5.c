/*Scrivere in C un programma che prenda un numero intero n come parametro
sulla linea di comando, e costruisca un array di n float con i valori 1,2,…,n
๏ Il programma crea due thread secondari, a ciascuno dei quali passa metà
dell’array (il primo thread riceve gli elementi di indice da 0 a n/2 escluso, e il
secondo gli elementi di indice da n/2 a n escluso)
๏ Ciascun thread secondario calcola, per ciascun elemento dell’array che ha
ricevuto, la radice quadrata (usando sqrt) e la memorizza nello stesso
elemento dell’array.
๏ Il thread principale aspetta la terminazione dei due thread secondari e
stampa il valore modificato dell’array.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct {
    float *array;
    int n;
} TParam;

void* square_root (void *arg){
    TParam* p = (TParam*) arg;
    for (int i=0; i<p->n ; i++)
        p->array[i] = sqrt(p->array[i]);
    return NULL;
}

int main(int argc, char* argv[]){
    if (argc!=2){
        puts("Devi specificare un numero intero come parametro!");
        return 1;
    }
    int n = atoi(argv[1]);
    float *array = malloc(n*sizeof(float));

    //riempimento array
    for (int i=0; i<n; i++)
        array[i] = i+1.0;

    pthread_t tid[2];
    TParam param[2];
    param[0].array = array;
    param[0].n = n/2;
    param[1].array = array + n/2;
    param[1].n = n - n/2;

    for (int i=0; i < 2; i++){
        if (pthread_create(&tid[i], NULL, square_root, &param[i]) != 0){
            puts("Errore creazione thread");
            return 2;
        }
    }
    for (int i=0 ; i<2; i++){
        if (pthread_join(tid[i], NULL) != 0){
            puts("Errore join thread");
            return 2;
        }
    }
    puts("Radici quadrate calcolate:");
    for (int i=0 ; i<n ; i++)
        printf("%g\n", array[i]);

    free(array);
    return 0;
}
