#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "TInfo.h"
#include "TBST.h"

/* operazioni sui nodi */

TBTNode *binarytree_node_create(TInfo info)
{
    TBTNode *node = (TBTNode *) malloc(sizeof(TBTNode));

    assert(node != NULL);
    node->info = info;
    node->left = node->right = NULL;

    return node;
}

void binarytree_node_destroy(TBTNode *node)
{
    if (node) {
        free(node);
    }
}

/* operazioni sugli alberi - versione ricorsiva */


/* Distrugge l'albero binario, deallocandone tutti gli elementi
 * PRE: nessuna
 * NOTA: consuma il parametro bt
 */
TBinaryTree binarytree_destroy(TBinaryTree bt)
{
    /* Caso base: Albero vuoto oppure con un solo elemento */
    if (bt == NULL)
        return NULL;

    if ((bt->left == NULL) && (bt->right == NULL)) {
        free(bt);

        return NULL;
    }
    /* Fase di divide at impera */
    bt->left = binarytree_destroy(bt->left);
    /* Fase di divide at impera */
    bt->right = binarytree_destroy(bt->right);
    /* Fase di combina */
    binarytree_node_destroy(bt);

    return NULL;
}

TBinaryTree binarytree_search(TBinaryTree bt, TInfo info)
{
    /* Caso base: Albero vuoto oppure la root e' l'elemento cercato */
    if ((bt == NULL) || info_equal(bt->info, info))
        return bt;

    if (info_greater(info, bt->info))
        /* Fase di divide at impera */
        return binarytree_search(bt->right, info);
    else
        /* Fase di divide at impera */
        return binarytree_search(bt->left, info);
}

TBTNode *binarytree_search_min(TBinaryTree bt)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL)
        return NULL;

    if (bt->left == NULL)
        return bt;

    /* Fase di divide at impera */
    TBinaryTree min = binarytree_search_min(bt->left);
    /* Fase di combina */
    return min;
}

TBTNode *binarytree_search_max(TBinaryTree bt)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL)
        return NULL;

    if (bt->right == NULL)
        return bt;

    /* Fase di divide at impera */
    TBinaryTree max = binarytree_search_max(bt->right);
    /* Fase di combina */
    return max;
}

TBinaryTree binarytree_insert(TBinaryTree bt, TInfo info)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL) {
        return binarytree_node_create(info);
    }
    if (info_greater(info, bt->info)) {
        /* Fase di divide at impera */
        bt->right = binarytree_insert(bt->right, info);
    } else {
        /* Fase di divide at impera */
        bt->left = binarytree_insert(bt->left, info);
    }

    return bt;
}

TBinaryTree binarytree_delete(TBinaryTree bt, TInfo info)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL)
        return NULL;

    if (info_greater(bt->info, info)) {
        /* ricorsione per cancellazione genitori */
        bt->left = binarytree_delete(bt->left, info);
        return bt;
    } else if (info_less(bt->info, info)) {
        bt->right = binarytree_delete(bt->right, info);
        return bt;
    }


    /* cancellazione di bt */
    // se un figlio è vuoto
    if (bt->left == NULL) {
        TBinaryTree temp = bt->right;
        binarytree_node_destroy(bt); // Cancellazione di una foglia
        return temp;
    } else if (bt->right == NULL) { // Cancellazione di un nodo con
        // il solo figlio sinistro
        TBinaryTree temp = bt->left;
        binarytree_node_destroy(bt);
        return temp;
    } else { // se esistono left & right
        TBinaryTree father = bt;
        TBinaryTree son    = bt->right;
        // cerca il figlio
        while (son->left) {
            father = son;
            son    = son->left;
        }
        /* cancella il figlio che è sempre left, quindi rendiamo right il left del genitore */
        if (father != bt) {
            father->left = son->right;
        } else {
            father->right = son->right; // se non ci sono figli assegniamo il figlio right al padre right
        }
        // assegniamo il dato a bt
        bt->info = son->info;
        // cancelliamo il figlio
        binarytree_node_destroy(son);
        // restituiamo bt
        return bt;
    }
}

void binarytree_visit(TBinaryTree tree)
{
    if (tree != NULL) {
        binarytree_visit(tree->left);
        info_print(tree->info);
        binarytree_visit(tree->right);
    }
}

/* Visita l'albero binario in post -ordine
 * PRE: nessuna
 */
void binarytree_visit_post_order(TBinaryTree bt)
{

    if (bt != NULL) {
        binarytree_visit(bt->left);
        binarytree_visit(bt->right);
        info_print(bt->info);
    }
}

/* Visita l'albero binario in pre -ordine
 * PRE: nessuna
 */
void binarytree_visit_pre_order(TBinaryTree bt)
{
    if (bt != NULL) {
        info_print(bt->info);
        binarytree_visit(bt->left);
        binarytree_visit(bt->right);
    }
}

int binarytree_count_nodes(TBinaryTree bt)
{
    if (bt == NULL)
        return 0;

    return 1 + binarytree_count_nodes(bt->left) + binarytree_count_nodes(bt->right);
}

int binarytree_count_leaves(TBinaryTree bt)
{
    int count_left, count_right;
    /* Caso base: Albero vuoto oppure albero con un solo elemento */
    if (bt == NULL)
        return 0;

    if ((bt->left == NULL) && (bt->right == NULL))
        return 1;

    return binarytree_count_leaves(bt->left) + binarytree_count_leaves(bt->right);
}

bool binarytree_is_empty(TBinaryTree tree)
{
    return (tree == NULL);
}

/* PRE: l ’albero non e’ vuoto
 */
int binarytree_depth(TBinaryTree tree)
{
    assert(tree != NULL);
    /* Caso base: foglia */
    if (tree->left == NULL && tree->right == NULL)
        return 0;
    else if (tree->left == NULL) /* Solo sottoalbero destro */
        return 1 + binarytree_depth(tree->right);
    else if (tree->right == NULL) /* Solo sottoalbero sinistro */
        return 1 + binarytree_depth(tree->left);
    else { /* Nodo completo */
        /* Fase di divide et impera */
        int depth_left  = binarytree_depth(tree->left);
        int depth_right = binarytree_depth(tree->right);
        /* Fase di combina */
        if (depth_left > depth_right)
            return 1 + depth_left;
        else
            return 1 + depth_right;
    }
}

/* funzioni utili a visualizzare la struttura di un albero binario di interi
 * (valgono solo per TInfo = int)
 */
int binarytree_height(TBinaryTree tree)
{
    if (tree == NULL)
        return 0;

    int l = binarytree_height(tree->left);
    int r = binarytree_height(tree->right);
    if (l > r)
        return l + 1;
    return r + 1;
}
