/*-------------------------------------------------------------------
 * Completare il programma fornito, completando il main e
 * implementando la funzione worker_thread.
 * Il main deve creare 100 thread figli, a cui deve passare
 * come parametri un intero da 1 a 100 (diverso per ogni thread figlio)
 * e un buffer che può contenere un singolo numero intero.
 * Una volta che i thread figli sono stati creati, il main deve
 * eseguire il seguente algoritmo:
 *         1. Ripeti per 100 volte i passi da 2 a 4.
 *           2. Aspetta che il buffer sia pieno.
 *           3. Preleva il valore contenuto nel buffer e stampalo a video
 *           4. Rendi il buffer vuoto.
 *
 * I thread figli, che eseguono la funzione worker_thread, devono svolgere
 * il seguente algoritmo:
 *           1. Aspetta 3 secondi.
 *           2. Aspetta che il buffer sia vuoto.
 *           3. Inserisci il numero ricevuto come parametro nel buffer.
 *           4. Rendi il buffer pieno.
 *
 * È necessario gestire in maniera appropriata la sincronizzazione dei
 * thread (incluso il main) nell'accesso al buffer.
 *
 * ESEMPIO
 * Lanciando il programma, l'ouput deve essere simile al seguente:
 *    Ho ricevuto il numero: 1
 *    Ho ricevuto il numero: 94
 *    Ho ricevuto il numero: 59
 *    Ho ricevuto il numero: 19
 *    Ho ricevuto il numero: 22
 *            . . . ( altri valori omessi per brevità ) . . .
 *    Ho ricevuto il numero: 39
 *    Ho ricevuto il numero: 40
 *    Ho ricevuto il numero: 51
 *    Ho ricevuto il numero: 56
 *
 *
 * Per testare il programma cliccare sul seguente link:
 *
 * https://onlinegdb.com/SHjR5haaA
 *
 * Una volta collegati, premere il pulsante FORK THIS di fianco al
 * pulsante RUN in alto a sinistra. Inserire nella finestra principale
 * il codice sorgente completo, inserire i parametri da passare sulla
 * linea comando nella casella CommandLine Arguments e cliccare sul
 * pulsante RUN per visualizzare il risultato dell'esecuzione.
 --------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_WORKERS 100
#define SLEEP_TIME 3

/* Tipo da usare per il buffer */
typedef struct {
    int valore;   /* Valore contenuto nel buffer */
    bool pieno;   /* true se il buffer contiene un valore */
    pthread_mutex_t mutex; /* Mutex per l'accesso al buffer */
    pthread_cond_t  cond;  /* Condition per l'accesso al buffer */
} TBuffer;

/* Tipo da usare per passare i parametri ai thread figli */
typedef struct {
    int numero;   /* Numero assegnato al thread */
    TBuffer *Ptrbuffer; /* Puntatore al buffer */
} TWorkerParam;


/* Prototipo della funzione dei thread figli */
void *worker_thread(void *param);

int main(int argc, char *argv[])
{
    TBuffer buffer;
    TWorkerParam param[NUM_WORKERS];
    if(pthread_mutex_init(&buffer.mutex, NULL) != 0){
        fprintf(stderr, "mutex init error!\n");
        return EXIT_FAILURE;
    }

    if(pthread_cond_init(&buffer.cond, NULL) !=0){
        fprintf(stderr, "condvar init error!\n");
        return EXIT_FAILURE;
    }

    pthread_t tid[NUM_WORKERS];
    for(int i=0; i<NUM_WORKERS; i++){
        param[i].numero = i;
        param[i].Ptrbuffer = &buffer;
        if (pthread_create(&tid[i], NULL, worker_thread, &param[i]) != 0){
            fprintf(stderr, "thread creation error!\n");
            return EXIT_FAILURE;
        }
    }
    buffer.pieno = false;

    // consumatore
    for (int i=0; i<NUM_WORKERS; i++){
        pthread_mutex_lock(&buffer.mutex);
        while (buffer.pieno == false)
            pthread_cond_wait(&buffer.cond, &buffer.mutex);
        printf("%d. \t Ho ricevuto il numero %d \n", i+1, buffer.valore);
        buffer.pieno = false;
        pthread_cond_broadcast(&buffer.cond);
        pthread_mutex_unlock(&buffer.mutex);
    }
    return EXIT_SUCCESS;
}

// produttore
void *worker_thread(void *param) {
    TWorkerParam* arg = (TWorkerParam*) param;
    while(true){
        sleep(SLEEP_TIME);
        pthread_mutex_lock(&arg->Ptrbuffer->mutex);
        while (arg->Ptrbuffer->pieno == true)
            pthread_cond_wait(&arg->Ptrbuffer->cond, &arg->Ptrbuffer->mutex);
        arg->Ptrbuffer->valore = arg->numero;
        arg->Ptrbuffer->pieno = true;
        pthread_cond_broadcast(&arg->Ptrbuffer->cond);
        pthread_mutex_unlock(&arg->Ptrbuffer->mutex);
    }
    return NULL;
}








