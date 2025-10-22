/*
 * TQueue: implementazione di una coda attraverso un array dinamico
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TQueue.h"

TQueue queue_create(int initialCapacity) {
    TQueue q;
    q.n = q.front = q.back = 0;
    q.a = array_create(initialCapacity);
    return q;
}

void queue_destroy(TQueue *q) {
    q->n = q->front = q->back = 0;
    array_destroy(&q->a);
}

void queue_add(TQueue *queue, TInfo x) {
    if (queue->n == queue->a.length) { // occorre ridimensionare l'array
        int oldLength = queue->a.length;
        array_resize(&queue->a, oldLength * 2 + 1);
        if (queue->n > 0 && queue->front >= queue->back) { // occorre spostare gli ultimi elementi
            int n = oldLength - queue->front; // numero di elementi da spostare
            for (int i = 1; i <= n; i++)
                queue->a.item[queue->a.length - i] = queue->a.item[oldLength - i];
            queue->front = queue->a.length - n; // aggiorna front
        }
    }
    queue->a.item[queue->back] = x;
    queue->back = (queue->back + 1) % queue->a.length;
    queue->n++;
}

TInfo queue_remove(TQueue *queue) {
    TInfo x = queue->a.item[queue->front];
    queue->front = (queue->front + 1) % queue->a.length;
    queue->n--;
    return x;
}

TInfo queue_front(TQueue *queue) {
    return queue->a.item[queue->front];
}

int queue_is_empty(TQueue *queue) {
    return queue->n == 0;
}