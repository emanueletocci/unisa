//
// Created by emanueletocci on 1/24/24.
//

#ifndef TEST_NUOVI_HEADERS_THT_H
#define TEST_NUOVI_HEADERS_THT_H

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