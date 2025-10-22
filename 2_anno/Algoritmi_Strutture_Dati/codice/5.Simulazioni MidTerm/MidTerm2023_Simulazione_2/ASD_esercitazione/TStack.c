/*
 * TStack: implementazione di uno stack attraverso un array dinamico
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TStack.h"

TStack stack_create(void) {
    TStack s;
    s.array = array_create(0);
    return s;
}

void stack_destroy(TStack *stack) {
    array_destroy(&stack->array);
}

void stack_push(TStack *stack, TInfo x) {
    array_resize(&stack->array, stack->array.length + 1);
    stack->array.item[stack->array.length - 1] = x;
}

TInfo stack_pop(TStack *stack) {
    TInfo x = stack->array.item[stack->array.length - 1];
    array_resize(&stack->array, stack->array.length - 1);
    return x;
}

TInfo stack_top(TStack *stack) {
    return stack->array.item[stack->array.length - 1];
}

int stack_is_empty(TStack *stack) {
    return stack->array.length == 0;
}
