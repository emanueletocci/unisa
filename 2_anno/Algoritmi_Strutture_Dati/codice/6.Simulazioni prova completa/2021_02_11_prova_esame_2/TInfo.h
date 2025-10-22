//
// Created by emanueletocci on 1/17/24.
//

#ifndef INC_2021_02_11_PROVA_ESAME_2_TINFO_H
#define INC_2021_02_11_PROVA_ESAME_2_TINFO_H

#include <stdbool.h>

typedef int TKey;

typedef struct {
    char titolo[50];
} TValue;

typedef struct SInfo {
    TKey key;
    TValue value;
} TInfo;

bool info_equal(TInfo, TInfo);
bool info_greater(TInfo, TInfo);
bool info_less(TInfo, TInfo);
void info_print(TInfo);

#endif

