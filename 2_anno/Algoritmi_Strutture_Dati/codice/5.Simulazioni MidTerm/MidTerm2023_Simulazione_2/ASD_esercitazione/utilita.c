/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"utilita.h"
#include "TQueue.h"
#include "TStack.h"

TList listInsertLast(TList list, TInfo info) {
    if (list == NULL) {
        TNode *newnode = node_create(info);
        assert(newnode != NULL);
        newnode->link = list;
        return newnode;
    }
    list->link = listInsertLast(list->link, info);
    return list;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void printQueue(TQueue q) {
    while (!queue_is_empty(&q))
        printf("%d ", queue_remove(&q));
}

void print_stack(TStack stack) {
    while (!stack_is_empty(&stack)) {
        info_print(stack_pop(&stack));
    }
}