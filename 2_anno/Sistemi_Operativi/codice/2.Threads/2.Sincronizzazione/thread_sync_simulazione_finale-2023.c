/*๏ Si realizzi un programma in C che implementi il problema produttore/consumatore con i threads
sincronizzati mediante mutex con variabili condition.

๏ Il programma gestisce un buffer che contiene una singola parola (una stringa); il buffer può essere
vuoto (non è presente la stringa) oppure pieno (è presente la stringa); non è prevista la possibilità
che il buffer contenga più di una stringa.

๏ Un thread Produttore aspetta che il buffer sia vuoto; quindi legge da tastiera una parola e la inserisce
nel buffer (che così diventa pieno); quindi il Produttore ricomincia da capo

๏ Un thread Consumatore1 aspetta che il buffer sia pieno e contenga una parola che comincia per una
vocale; in tal caso il Consumatore1 stampa la parola a video, svuota il buffer e ricomincia da capo

๏ Un thread Consumatore2 aspetta che il buffer sia pieno e contenga una parola che non comincia per
una vocale; in tal caso il Consumatore2 stampa a video un messaggio che indica la lunghezza della
parola, svuota il buffer e ricomincia da capo
๏ Si faccia uso della seguente struttura dati per gestire il buffer:

typedef struct {
    char parola[MAX_PAROLA]; // La parola contenuta nel buffer
    bool pieno; // true se il buffer contiene una parola
    pthread_mutex_t mutex; //mutex
    pthread_cond_t condition; // condition variable
} TBuffer;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PAROLA 100

typedef struct {
    char parola[MAX_PAROLA]; // la parola contenuta nel buffer
    bool pieno; // true se il buffer contiene una parola
    pthread_mutex_t mutex; // mutex
    pthread_cond_t condition; // variabile condition
} TBuffer;

/* Prototipi delle thread functions */
void *Produttore(void *param);
void *Consumatore1(void *param);
void *Consumatore2(void *param);
bool begin_with_vowel(char *s);

int main(int argc, char *argv[]) {
    TBuffer buffer;
    pthread_mutex_init(&buffer.mutex, NULL);
    pthread_cond_init(&buffer.condition, NULL);
    buffer.pieno=false;
    pthread_t tid[3];
    pthread_create(&tid[0], NULL, Produttore, &buffer);
    pthread_create(&tid[1], NULL, Consumatore1, &buffer);
    pthread_create(&tid[2], NULL, Consumatore2, &buffer);

    for(int i=0; i<3; i++)
        pthread_join(tid[i], NULL);

    return EXIT_SUCCESS;
}

void *Produttore(void *param) {
    TBuffer *p = (TBuffer*) param;
        while(true){
            pthread_mutex_lock(&p->mutex);
            while (p->pieno)
                pthread_cond_wait(&p->condition, &p->mutex);
            printf("Inserire parola: \t");
            scanf("%s", p->parola);
            p->pieno=true;
            pthread_mutex_unlock(&p->mutex);
            pthread_cond_broadcast(&p->condition);
        }
}

void *Consumatore1(void *param) {
    TBuffer *p = (TBuffer*) param;
        while(true){
            pthread_mutex_lock(&p->mutex);
            while (!p->pieno)
                pthread_cond_wait(&p->condition, &p->mutex);
            if(begin_with_vowel(p->parola)){
                printf("Cons1: \t %s \n", p->parola);
                p->pieno=false;
            }
            pthread_mutex_unlock(&p->mutex);
            pthread_cond_broadcast(&p->condition);
        }
}

//inizio per consonante
void *Consumatore2(void *param) {
    TBuffer *p = (TBuffer*) param;
        while(true){
            pthread_mutex_lock(&p->mutex);
            while (!p->pieno)
                pthread_cond_wait(&p->condition, &p->mutex);
            if(!begin_with_vowel(p->parola)){
                printf("Cons2: \t %s \n", p->parola);
                p->pieno=false;
            }
            pthread_mutex_unlock(&p->mutex);
            pthread_cond_broadcast(&p->condition);
        }    
}

bool begin_with_vowel(char *s){
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i=0; i<5; i++){
        if ((s[0]==vowels[i]) || (s[0]==toupper(vowels[i])))
            return true;
    }
    return false;
}