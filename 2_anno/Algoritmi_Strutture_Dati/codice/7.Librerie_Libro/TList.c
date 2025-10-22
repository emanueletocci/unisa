/*
 * TList: lista ordinata
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TList.h"

/* operazioni sui nodi */

TNode *nodeCreate(TInfo info) {
    TNode *new = malloc(sizeof (TNode));
    if (new != NULL) {
        new->info = info;
        new->link = NULL;
    }
    return new;
}

void nodeDestroy(TNode *node) {
    free(node);
}

/* operazioni sulle liste */

TList listCreate() {
    return NULL;
}

TList listDestroy(TList list) {
    TNode *node;
    while (list != NULL) {
        node = list;
        list = list->link;
        nodeDestroy(node);
    }
    return list;
}

void listPrint(TList list) {
    if (list != NULL) {
        infoPrint(list->info);
        listPrint(list->link);
    } else
        printf("\n");
}

TNode *listSearch(TList list, TInfo info) {
    if (list == NULL || infoGreater(list->info, info))
        return NULL;
    if (infoEqual(list->info, info))
        return list;
    return listSearch(list->link, info);
}

TList listInsert(TList list, TInfo info) {
    if (list == NULL || infoGreater(list->info, info)) {
        TNode *newnode = nodeCreate(info);
        assert(newnode != NULL);
        newnode->link = list;
        return newnode;
    }
    list->link = listInsert(list->link, info);
    return list;
}

TList listDelete(TList list, TInfo info) {
    if (list == NULL || infoGreater(list->info, info))
        return list;
    if (infoEqual(list->info, info)) {
        TList m = list->link;
        nodeDestroy(list);
        return m;
    }
    list->link = listDelete(list->link, info);
    return list;
}