//
// Created by emanueletocci on 1/19/24.
//

#ifndef INC_2023_04_19_PROVA_ESAME_THT_H
#define INC_2023_04_19_PROVA_ESAME_THT_H

#include "TBST.h"


typedef struct SHashTable THashTable;

typedef struct SHashTable {
    TList *bucket;
    int n_bucket;
} THashTable;

/* Operazioni su THashTable */

THashTable *hashTable_create(int n);
void hashTable_destroy(THashTable* ht);
TValue *hashTable_search(THashTable* ht, TKey key);
void hashTable_insert(THashTable* ht, TKey key, TValue value);
void hashTable_delete(THashTable* ht, TKey key);
void hashTable_print(THashTable* ht);
void hashTable_partial_print(THashTable *ht, TBST t, int max);
#endif