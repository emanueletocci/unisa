#ifndef BST_H
#define BST_H

    #include <stdbool.h>
    #include "TInfo.h"
    typedef struct SBSTNode TBSTNode;

    struct SBSTNode {
        TInfo info;
        TBSTNode* right;
        TBSTNode* left;
    };

    
    typedef TBSTNode* TBST;

    TBST bst_create();
    TBST bst_insert(TBST tree, TInfo info);
    void bst_print(TBST tree);
    TInfo* bst_search(TBST tree, TInfo info);
    TInfo* bst_partial_search(TBST tree, TInfo info, int max);
    TBST bst_delete(TBST tree, TInfo info);
    void bst_destroy(TBST);
     	
    TInfo* bst_min(TBST tree);
    TInfo* bst_max(TBST tree);

#endif /* BST_H */