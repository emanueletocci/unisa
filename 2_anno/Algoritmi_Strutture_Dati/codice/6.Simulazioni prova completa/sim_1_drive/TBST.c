#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "TInfo.h"
#include "TBST.h"

/* operazioni sui nodi */

TBSTnode *BSTnodeCreate (TInfo info) {
    TBSTnode *node = malloc (sizeof(TBSTnode));
    assert (node != NULL);
    node->info = info;
    node->left = node->right = NULL;
    return node;
}

void BSTnodeDestroy (TBSTnode* node) {
    free (node);
}

/* operazioni sugli alberi */

TBST BSTcreate () {
    return NULL;
}

TBST BSTdestroy (TBST tree) {
    if (tree == NULL)
        return NULL;
    BSTdestroy(tree->left);
    BSTdestroy(tree->right);
    BSTnodeDestroy (tree);
    return NULL;
}

TBST BSTsearch (TBST tree, TInfo info) {
    if (tree == NULL || infoEqual(info, tree->info))
        return tree;
    if (infoGreater(info, tree->info))
        return BSTsearch(tree->right, info);
    else
        return BSTsearch(tree->left, info);
    return tree;
}

TBST BSTmin (TBST tree) {
    if (tree == NULL || tree->left == NULL)
        return tree;
    return BSTmin (tree->left);
}

TBST BSTmax (TBST tree) {
    if (tree == NULL || tree->right == NULL)
        return tree;
    return BSTmax (tree->right);
}

TBST BSTinsert (TBST tree, TInfo info) {
    if (tree == NULL)
        return BSTnodeCreate(info);
    if (infoGreater(info, tree->info))
        tree->right = BSTinsert(tree->right, info);
    else
        tree->left = BSTinsert(tree->left, info);
    return tree;
}

TBST BSTdelete (TBST tree, TInfo info) {
    if (tree == NULL)
        return NULL;
    if (infoGreater(info, tree->info))
        tree->right = BSTdelete(tree->right, info);
    else if (infoLess(info, tree->info))
        tree->left = BSTdelete(tree->left, info);
    else { // trovato il nodo da rimuovere
        if (tree->left == NULL) {
            TBST right = tree->right;
            BSTnodeDestroy(tree);
            tree = right;
        } else if (tree->right == NULL) {
            TBST left = tree->left;
            BSTnodeDestroy(tree);
            tree = left;
        } else {
            TBST min = BSTmin(tree->right);
            tree->info = min->info;
            tree->right = BSTdelete(tree->right, min->info);
        }
    }
    return tree;
}

int BSTheight(TBST tree) {
    if (tree == NULL)
        return -1;
    int l = BSTheight(tree->left);
    int r = BSTheight(tree->right);
    if (l > r)
        return l + 1;
    return r + 1;
}

void BSTprint (TBST tree) {
    if (tree != NULL) {
        BSTprint(tree->left);
        BSTprint(tree->right);
        infoPrint(tree->info);

    }
}
