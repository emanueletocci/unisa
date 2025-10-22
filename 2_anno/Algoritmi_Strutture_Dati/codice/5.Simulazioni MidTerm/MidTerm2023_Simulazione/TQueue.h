/*
 * TQueue: implementazione di una coda attraverso un array dinamico
 */

#ifndef TQUEUE_H
#define TQUEUE_H

#include "TArray.h" 

/* Definizione della struttura dati */
typedef struct {
    int n; // numero di elementi
    int front; // indice front
    int back; // indice back
    TArray a;
} TQueue;

/* Crea una coda
 * PRE:
 * initial_capacity >=0
 */
TQueue queue_create(int initialCapacity);

/* Distrugge una coda
 */
void queue_destroy(TQueue *queue);

/* Accoda un elemento
 */
void queue_add(TQueue *queue, TInfo x);

/* Preleva un elemento
 * PRE:
 * la coda non e’ vuota
 */
TInfo queue_remove(TQueue *queue);

/* Primo elemento
 * PRE:
 * la coda non e’ vuota
 */
TInfo queue_front(TQueue *queue);

/* Verifica se la coda e’ vuota
 */
int queue_is_empty(TQueue *queue);

#endif