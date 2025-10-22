#include <stdio.h>
#include <stdlib.h>
#include "TBST.h"

bool confronta_binarytree(TBinaryTree, TBinaryTree);

void attraversa_dispari(TBinaryTree);
void attraversa_pari(TBinaryTree);

void binarytree_print_between(TBinaryTree, TInfo, TInfo);

TBTNode* lowest_common_ancestor(TBinaryTree, TInfo, TInfo);

void second_largest_util(TBinaryTree, int*);
void second_largest_util_iterative(TBinaryTree);

void second_largest(TBinaryTree);


int one_child(TBinaryTree);

TBTNode *binarytree_parent(TBinaryTree bt, TBTNode *node);

TBinaryTree binarytree_invert(TBinaryTree tree);

int main(int argc, char** argv) {

    TBinaryTree tree = binarytree_create();
    TBinaryTree tree2 = binarytree_create();
    TBinaryTree tree3 = binarytree_create();

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

    tree2 = binarytree_insert(tree2, 10);
    tree2 = binarytree_insert(tree2, 20);
    tree2 = binarytree_insert(tree2, 30);
    tree2 = binarytree_insert(tree2, 15);
    tree2 = binarytree_insert(tree2, 5);
    tree2 = binarytree_insert(tree2, 14);
    tree2 = binarytree_insert(tree2, 18);
    tree2 = binarytree_insert(tree2, 1);
    tree2 = binarytree_insert(tree2, 16);
    tree2 = binarytree_insert(tree2, 21);
    tree2 = binarytree_insert(tree2, 7);
    tree2 = binarytree_insert(tree2, 3);

    printf("\nStampo il primo albero a video:\n");
    binarytree_print_structure(tree);

    printf("\n\nStampo il secondo albero a video:\n");
    binarytree_print_structure(tree2);

    /*
     * confronta_binarytree
     */
    printf("\n\nConfronto i due alberi binari:\n");
    if (confronta_binarytree(tree, tree2))
        printf("i due alberi sono uguali\n");
    else
        printf("i due alberi non sono uguali\n");

    /*
     * attraversa_pari
     */
    printf("\nNodi di livello pari: ");
    attraversa_pari(tree);


    /*
     * binarytree_print_between
     * TInfo min = 7, max = 15;
     */
    TInfo min = 1, max = 6;
    printf("\n\nElementi tra %d e %d: ", min, max);
    binarytree_print_between(tree, min, max);

    /*
     * lowest_common_ancestor
     */
    printf("\n\nCerco il primo antenato comune tra %d e %d.", min, max);
    TBTNode *n = lowest_common_ancestor(tree, min, max);
    if (n != NULL)
        printf("\nPrimo antenato comune tra %d e %d: %d", min, max, n->info);
    else
        printf("\nNon ci sono antenati comuni tra %d e %d", min, max);

    /*
     * secondLargest
     */
    printf("\n\nIl secondo nodo con valore maggiore è: ");
    second_largest(tree);

    /*
     * oneChild
     */
    printf("\n\nIl numero di nodi con un solo figlio è: %d", one_child(tree));

    /*
     * binarytree_parent
     */
    int i = 9;
    printf("\n\nCerco il padre di %d:\n", i);
    n = binarytree_parent(tree, binarytree_search(tree, i));
    if (n != NULL)
        printf("il padre di %d è: %d\n", i, n->info);
    else
        printf("%d non appartiene all'albero\n", i);


    /*
     * binarytree_invert
     */
    TBinaryTree tree_inverted, tree2_inverted;
    
    printf("\n\nInverto e stampo il primo albero a video: \n");
    tree_inverted = binarytree_invert(tree);
    if (tree_inverted != NULL)   
        binarytree_print_structure(tree_inverted);
    else
        printf("\nL'albero e' vuoto.");
    
    printf("\n\nInverto e stampo il secondo albero a video: \n");
    tree2_inverted = binarytree_invert(tree2);
    if (tree2_inverted != NULL)   
        binarytree_print_structure(tree2_inverted);
    else
        printf("\nL'albero e' vuoto.");
     
    tree = binarytree_destroy(tree);
    tree2 = binarytree_destroy(tree2);

    return (EXIT_SUCCESS);
}

bool confronta_binarytree(TBinaryTree t1, TBinaryTree t2) {
    if (t1 == NULL && t2 == NULL){
        if (info_equal(t1->info, t2-> info))
            return 1;   //gli alberi sono uguali
        else 
            return 0;
    }
    else if (t1 == NULL || t2 == NULL)
        return 0;
    
    return confronta_binarytree(t1->left, t2 -> left) && confronta_binarytree (t1 -> right, t2 -> right);
    
}

void attraversa_pari(TBinaryTree t) {
    if (t == NULL)
        return;
    info_print(t->info);
    attraversa_dispari(t->left);
    attraversa_dispari(t->right);    
}
    

void attraversa_dispari(TBinaryTree t) {
    if (t == NULL)
        return;   
    attraversa_pari(t->left);
    attraversa_pari(t->right);    

    }

void binarytree_print_between(TBinaryTree bt, TInfo min, TInfo max) {
    if (bt == NULL)
        return;
    
    else if (min <= bt-> info)
        binarytree_print_between (bt-> left, min, max);        
    
    if ((min <= bt-> info) && (max>=bt->info)){
        info_print(bt->info);
        binarytree_print_between (bt -> right, min, max);
    }

}

TBTNode* lowest_common_ancestor(TBinaryTree bt, TInfo info1, TInfo info2) {
    //Inserire codice
}

/* 
 * Una funzione di utilita' per trovare il 2° elemento più grande in un albero BST.
 */
void second_largest_util_iterative(TBinaryTree root) {
    TBTNode* max_ptr = binarytree_search_max (root);
    int max = max_ptr -> info;
    int max_tmp;
    
    if (max_ptr -> left != NULL){                                        //Il massimo ha il figlio sinistro
        max_ptr = max_ptr -> left;                                       // entro nel sottoalbero sinistro
        max = max_ptr -> info;                                           // il secondo massimo e' l'elemento sinistro del sottoalbero
    }      
    
    else {                                                                //Il massimo e' una foglia, bisogna scorrere il sottoalbero destro
        while (!binarytree_is_empty (root)){
            if (max > root -> info){
                    max_tmp = root -> info;                               // salvo la radice
                    root = root-> right;                                  // scendo nel sottoalbero destro
                }
            else if (max < root -> info){
                max_tmp = root -> info;
                root = root -> left;
            }        
            else 
                break;       
        }
        max = max_tmp;
    }  
    info_print (max);
}

void second_largest_util(TBinaryTree root, int *c){
    if(root!=NULL){
        second_largest_util(root->right,c);
        if(root != NULL)
            *c=*c+1;
        if((*c)==2)
            info_print(root->info);
        second_largest_util(root->left,c);  
    }
}


/*
 *  Funzione per trovare il 2° elemento più grande in un albero BST.
 */
void second_largest(TBinaryTree bt) {
    // Inizializza il conteggio dei nodi visitati a 0

    int c = 0;

    // Si noti che c è passato per riferimento
    printf("\nRisolvo iterativamente.");
    second_largest_util_iterative(bt);
    printf("\nRisolvo ricorsivamente.");
    second_largest_util(bt, &c);
}

int one_child(TBinaryTree bt) {
    int count_left, count_right;
    if(bt == NULL)
        return 0;
    else if (((bt -> right != NULL )&& (bt-> left == NULL))||(bt-> left != NULL) && (bt -> right == NULL))      //ha un solo figlio
        return 1;
    else
    {
        count_left = one_child(bt->left);
        count_right = one_child(bt->right);
        return count_left + count_right;
    }
}


TBTNode *binarytree_parent(TBinaryTree bt, TBTNode *node) {
    //ricerca padre
    if (bt == NULL)
        return NULL;     
    else if ((bt -> right == node) || (bt-> left == node))
        return bt;
    else {
        if (node-> info <= bt -> info)
            binarytree_parent (bt -> left, node);        
        else if (node -> info > bt -> info)
            binarytree_parent (bt -> right, node);
    }
}


TBinaryTree binarytree_invert(TBinaryTree tree) {
    if (tree == NULL)
        return NULL;
    else {
        binarytree_invert(tree->right);
        binarytree_invert(tree->left);
        TBTNode * temp = tree->left;
        tree->left = tree -> right;
        tree->right = temp;
        return tree;
    }
}

