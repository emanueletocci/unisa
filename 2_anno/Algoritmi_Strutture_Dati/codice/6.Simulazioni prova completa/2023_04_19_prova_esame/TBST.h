//
// Created by emanueletocci on 1/19/24.
//

#ifndef INC_2023_04_19_PROVA_ESAME_TBST_H
#define INC_2023_04_19_PROVA_ESAME_TBST_H


#include <stdbool.h>
#include "TInfo.h"
typedef struct SBSTNode TBSTNode;

struct SBSTNode {
    TInfo1 info;
    TBSTNode* right;
    TBSTNode* left;
};


typedef TBSTNode* TBST;

TBST bst_create();
TBST bst_insert(TBST tree, TInfo1 info);
void bst_print(TBST tree);
TInfo1* bst_search(TBST tree, TInfo1 info);
TInfo1* bst_partial_search(TBST tree, TInfo1 info, int max);
TBST bst_delete(TBST tree, TInfo1 info);
void bst_destroy(TBST);

TInfo1* bst_min(TBST tree);
TInfo1* bst_max(TBST tree);

#endif /* BST_H */
