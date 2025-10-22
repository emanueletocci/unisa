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

TArray arrayCreate(int length);
void arrayDestroy(TArray *a);
void arrayResize(TArray *a, int length);
void arrayPrint(TArray *a);

#endif