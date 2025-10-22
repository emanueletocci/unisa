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
TQueue queueCreate(int initialCapacity);

/* Distrugge una coda
 */
void queueDestroy(TQueue *queue);

/* Accoda un elemento
 */
void queueAdd(TQueue *queue, TInfo x);

/* Preleva un elemento
 * PRE:
 * la coda non e’ vuota
 */
TInfo queueRemove(TQueue *queue);

/* Primo elemento
 * PRE:
 * la coda non e’ vuota
 */
TInfo queueFront(TQueue *queue);

/* Verifica se la coda e’ vuota
 */
int queueIsEmpty(TQueue *queue);

#endif