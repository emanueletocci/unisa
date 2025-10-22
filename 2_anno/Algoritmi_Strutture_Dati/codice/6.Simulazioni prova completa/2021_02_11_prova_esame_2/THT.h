//
// Created by emanueletocci on 1/17/24.
//

#ifndef INC_2021_02_11_PROVA_ESAME_2_THT_H
#define INC_2021_02_11_PROVA_ESAME_2_THT_H

#include "TList.h"

typedef struct SHashTable {
    int bucket_number;
    TList *bucket;
} THashTable;

THashTable *hashtable_create(int n);
void hashtable_destroy(THashTable* ht);
void hashtable_insert(THashTable* ht, TKey key, TValue value);
void hashtable_delete(THashTable* ht, TKey key);
TValue *hashtable_search(THashTable* ht, TKey key);
void hashtable_print(THashTable* ht);
void hashtable_print_structure(THashTable* ht);

#endif