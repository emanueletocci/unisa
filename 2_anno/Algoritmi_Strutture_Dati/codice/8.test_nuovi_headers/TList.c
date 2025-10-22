/*
 * TList: lista ordinata
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TList.h"

/* operazioni sui nodi */
TNode *node_create(TInfo info)
{
    TNode *new = (TNode *) malloc(sizeof(TNode));
    if (new != NULL) {
        new->info = info;
        new->link = NULL;
    }

    return new;
}

void node_destroy(TNode *node)
{
    if (node) {
        free(node);
    }
}

/*
a cosa serve questa funzione????
 */
TList list_create(TList *list, TInfo info)
{
    return NULL;
}

TList list_destroy(TList list)
{
    TNode *node;

    while (list != NULL) {
        node = list;
        list = list->link;
        node_destroy(node);
    }

    return list;
}

void list_print(TList list)
{
    if (list != NULL) {
        info_print(list->info);
        list_print(list->link);
    } else
        printf("\n");
}

TNode *list_search(TList list, TInfo info)
{
    if (list == NULL || info_greater(list->info, info))
        return NULL;
    if (info_equal(list->info, info))
        return list;

    return list_search(list->link, info);
}

TList list_insert(TList list, TInfo info)
{
    if (list == NULL || info_greater(list->info, info)) {
        TNode *newnode = node_create(info);
        assert(newnode != NULL);
        newnode->link = list;

        return newnode;
    }
    list->link = list_insert(list->link, info);

    return list;
}

TList list_delete(TList list, TInfo info)
{
    if (list == NULL || info_greater(list->info, info))
        return list;
    if (info_equal(list->info, info)) {
        TList m = list->link;
        node_destroy(list);

        return m;
    }
    list->link = list_delete(list->link, info);

    return list;
}

TNode *list_search_at_index(TList list, int index)
{
    TNode *p = list;

    for (int i = 0; p != NULL && i < index; i++) {
        p = p->link;
    }

    return p;
}

TNode *list_insert_at_index(TList list, TInfo info, int k)
{
    TNode *prec, *curr, *newnode;
    int curr_place;

    curr    = list;
    newnode = node_create(info);
    if (newnode == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }

    if (k == 0) {
        newnode->link = list;

        return newnode;
    }
//se hai un'inizializzazione di un indice, una condizione e un incremento dell'indice perché usare un while???
    for (curr_place = 1; (curr != NULL) && (curr_place < k - 1); curr_place++) {
        curr = curr->link;
    }

    if (curr != NULL) {
        newnode->link = curr->link;
        curr->link    = newnode;
    }

    return list;
}

TNode *list_search_unordered(TList list, TInfo info)
{
    TNode *curr = list;

    while (curr != NULL && !info_equal(info, curr->info)) {
        curr = curr->link;
    }

    return curr;
}

TList list_delete_unordered(TList list, TInfo info)
{
    if (list == NULL)
        return list;

    if (info_equal(list->info, info)) {
        TList m = list->link;

        node_destroy(list);

        return m;
    }
    list->link = list_delete(list->link, info);

    return list;
}
