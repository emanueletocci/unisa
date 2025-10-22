/*
 * TArray: array dinamico
 */

#ifndef TARRAY_H
#define TARRAY_H

#include "TInfo.h"

struct SArray {
    TInfo *item; /* elementi dell'array */
    int length; /* riempimento */
    int size; /* dimensione allocata */
};
typedef struct SArray TArray;

TArray array_create(int length);
void array_destroy(TArray *a);
void array_resize(TArray *a, int length);
void array_print(TArray *a);
void array_insert(TArray *a, TInfo info);
int array_length(TArray *a);
void array_set(TArray *a, int pos, TInfo info);
TInfo array_get(TArray *a, int pos);

#endif