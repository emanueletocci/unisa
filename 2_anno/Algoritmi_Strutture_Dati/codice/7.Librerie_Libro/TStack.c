/*
 * TStack: implementazione di uno stack attraverso un array dinamico
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TStack.h"

TStack stackCreate(void) {
    TStack s;
    s.array = arrayCreate(0);
    return s;
}

void stackDestroy(TStack *stack) {
    arrayDestroy(&stack->array);
}

void stackPush(TStack *stack, TInfo x) {
    arrayResize(&stack->array, stack->array.length + 1);
    stack->array.item[stack->array.length - 1] = x;
}

TInfo stackPop(TStack *stack) {
    TInfo x = stack->array.item[stack->array.length - 1];
    arrayResize(&stack->array, stack->array.length - 1);
    return x;
}

TInfo stackTop(TStack *stack) {
    return stack->array.item[stack->array.length - 1];
}

int stackIsEmpty(TStack *stack) {
    return stack->array.length == 0;
}
