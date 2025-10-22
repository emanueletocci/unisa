//
// Created by emanueletocci on 1/17/24.
//

#ifndef INC_2021_02_11_PROVA_ESAME_CP_TARRAY_H
#define INC_2021_02_11_PROVA_ESAME_CP_TARRAY_H

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
#endif //INC_2021_02_11_PROVA_ESAME_CP_TARRAY_H
