//
// Created by emanueletocci on 1/19/24.
//

#ifndef INC_2023_04_19_PROVA_ESAME_TLIST_H
#define INC_2023_04_19_PROVA_ESAME_TLIST_H

/* Operazioni su THLNode e TList ---------------------- */
#include "TInfo.h"
typedef struct SHLNode THLNode;
struct SHLNode {
    TInfo2 info;
    THLNode *link;
};
typedef THLNode* TList;

TList list_create();
TList list_destroy(TList);
TList list_insert(TList, TInfo2);
THLNode *list_search(TList, TInfo2);
TList list_delete(TList, TInfo2);
void list_print(TList);

#endif /* LIST_H */
