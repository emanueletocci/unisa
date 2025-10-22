#include <stdio.h>
#include <stdlib.h>
#include "TBST.h"


TBinaryTree BST_remove_duplicates(TBinaryTree bst) {
    if (bst == NULL)
        return NULL;
    BST_remove_duplicates(bst->left);
    BST_remove_duplicates(bst->right);
    bst -> left = binarytree_delete( bst->left, bst->info);
    return bst;
}

int main(int argc, char** argv) {

    TBinaryTree tree = binarytree_create();

    tree = binarytree_insert(tree, 7); //inserire 6 per testare oneChild
    tree = binarytree_insert(tree, 6);
    tree = binarytree_insert(tree, 1);
    tree = binarytree_insert(tree, 10);
    tree = binarytree_insert(tree, 8);
    tree = binarytree_insert(tree, 9);
    tree = binarytree_insert(tree, 18);
    tree = binarytree_insert(tree, 1);
    tree = binarytree_insert(tree, 16);
    tree = binarytree_insert(tree, 21);
    tree = binarytree_insert(tree, 7);
    tree = binarytree_insert(tree, 3);
    tree = binarytree_insert(tree, 7);
    tree = binarytree_insert(tree, 24);
    tree = binarytree_insert(tree, 7);
    tree = binarytree_insert(tree, 1);
    tree = binarytree_insert(tree, 16);
    tree = binarytree_insert(tree, 8);
    tree = binarytree_insert(tree, 9);

    printf("\nStampo l' albero a video:\n");
    binarytree_print_structure(tree);

    printf("\nStampo l' albero senza duplicati:\n");
    BST_remove_duplicates(tree);
    binarytree_print_structure(tree);

}
