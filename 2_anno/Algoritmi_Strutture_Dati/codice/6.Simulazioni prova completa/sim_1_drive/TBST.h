//
// Created by emanueletocci on 1/24/24.
//

#ifndef SIM_1_DRIVE_TBST_H
#define SIM_1_DRIVE_TBST_H

#include "TInfo.h"

struct SBSTnode {
    TInfo info;
    struct SBSTnode *left;
    struct SBSTnode *right;
};

typedef struct SBSTnode TBSTnode;
typedef TBSTnode *TBST;

TBSTnode *BSTnodeCreate(TInfo);
void BSTnodeDestroy(TBSTnode*);
TBST BSTcreate ();
TBST BSTdestroy (TBST);
TBST BSTsearch (TBST, TInfo);
TBST BSTmin (TBST);
TBST BSTmax (TBST);
TBST BSTinsert (TBST, TInfo);
TBST BSTdelete (TBST, TInfo);
void BSTprint(TBST);

#endif

