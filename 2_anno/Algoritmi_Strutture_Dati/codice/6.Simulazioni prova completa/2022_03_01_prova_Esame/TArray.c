/*
 * TArray: array dinamico
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TArray.h"

#define GROWING_DELTA 10
#define SHRINKING_DELTA 20

/* Crea un array dinamico .
 * PRE :
 * initial_length >= 0
 */
TArray array_create(int initial_length) {
    TArray a;
    a.item = (TInfo *) malloc(initial_length * sizeof (TInfo));
    assert(initial_length == 0 || a.item != NULL);
    a.length = initial_length;
    a.size = initial_length;
    return a;
}

void array_destroy(TArray *a) {
    free(a->item);
    a->item = NULL;
    a->length = 0;
    a->size = 0;
}

/* Ridimensiona un array dinamico .
 * PRE :
 * new_length >=0
 */
void array_resize(TArray *a, int new_length) {
    if (new_length > a->size ||
            new_length < a->size - SHRINKING_DELTA) {
        int new_size = new_length + GROWING_DELTA;
        a->item = realloc(a->item, new_size * sizeof (TInfo));
        assert(new_size == 0 || a->item != NULL);
        a->size = new_size;
    }
    a->length = new_length;
}

void array_print(TArray *a) {
    for (int i = 0; i < a->length; ++i)
        info_print(a->item[i]);
    printf("\n");
}

/* FUNZIONI DI UTILITA' */

// Aggiunta di un elemento in coda all'array

void array_insert(TArray *a, TInfo info) {
    array_resize(a, a->length + 1);
    a->item[a->length - 1] = info;
}

// Lettura di un elemento in posizione pos

TInfo array_get(TArray *a, int pos) {
    return a->item[pos];
}

// Lettura della lunghezza dell'array

int array_length(TArray *a) {
    return a->length;
}

// Inserimento di un elemento in posizione pos con ridimensionamento automatico

void array_set(TArray *a, int pos, TInfo info) {
    if (pos >= a->length)
        array_resize(a, pos + 1);
    a->item[pos] = info;
}
