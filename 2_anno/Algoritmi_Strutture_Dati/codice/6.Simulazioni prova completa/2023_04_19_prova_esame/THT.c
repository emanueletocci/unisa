#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "TInfo.h"
#include "TList.h"
#include "THT.h"
#include "TBST.h"

unsigned int key_hash(TKey);

unsigned int key_hash(TKey key) {
    //const char* k1 = key;
    unsigned int hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    //printf("Hash: %s -> %u\n", k1, hash%10);
    return hash;
}

/* 
 * Operazioni su THashTable
 */


THashTable *hashTable_create(int n) {
    THashTable *ht = malloc(sizeof (THashTable));
    assert(ht != NULL);

    ht->bucket = malloc(n * sizeof (TList));
    assert(ht->bucket != NULL);

    for (int i = 0; i < n; i++)
        ht->bucket[i] = list_create();
    ht->n_bucket = n;
    return ht;
}

void hashTable_destroy(THashTable* ht) {
    for (int i = 0; i < ht->n_bucket; i++)
        ht->bucket[i] = list_destroy(ht->bucket[i]);
    free(ht->bucket);
    free(ht);
}

TValue *hashTable_search(THashTable* ht, TKey key) {
    unsigned h = key_hash(key) % ht->n_bucket;
    TInfo2 info;
    strcpy(info.key, key);
    THLNode* node = list_search(ht->bucket[h], info);
    if (node != NULL)
        return &node->info.value;
    return NULL;
}

void hashTable_insert(THashTable* ht, TKey key, TValue value) {
    unsigned h = key_hash(key) % ht->n_bucket;
    TInfo2 info;
    strcpy(info.key, key);
    info.value = value;
    THLNode* node = list_search(ht->bucket[h], info);
    if (node != NULL)
        node->info.value = value;
    else
        ht->bucket[h] = list_insert(ht->bucket[h], info);
}

void hashTable_print(THashTable* ht) {
    for (int i = 0; i < ht->n_bucket; i++)
        for (THLNode *node = ht->bucket[i]; node != NULL; node = node->link)
            info2_print(node->info);
}