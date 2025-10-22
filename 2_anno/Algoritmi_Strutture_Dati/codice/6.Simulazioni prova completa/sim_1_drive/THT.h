//
// Created by emanueletocci on 1/24/24.
//

#ifndef SIM_1_DRIVE_THT_H
#define SIM_1_DRIVE_THT_H

#include "TList.h"

typedef struct {
    TList *bucket;
    int n_bucket;
} THT;

THT *HTcreate (int n);
void HTdestroy (THT* ht);
void HTinsert (THT* ht, TKey key, TValue value);
void HTdelete (THT* ht, TKey key);
TValue *HTsearch (THT* ht, TKey key);
void HTprint(THT* ht);
void HTprintStructure(THT* ht);

#endif