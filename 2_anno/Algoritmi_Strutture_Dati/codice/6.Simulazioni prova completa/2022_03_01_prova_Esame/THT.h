#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "TList.h"


typedef struct SHashTable THashTable;

typedef struct SHashTable {
    TList *bucket;
    int n_bucket;
} THashTable;

/* Operazioni su THashTable */

THashTable *hashtable_create(int n);
void hashtable_destroy(THashTable* ht);
void hashtable_insert(THashTable* ht, TKey key, TValue value);
void hashtable_delete(THashTable* ht, TKey key);
TValue *hashtable_search(THashTable* ht, TKey key);
void hashtable_print(THashTable* ht);
void hashtable_print_structure(THashTable* ht);
#endif
