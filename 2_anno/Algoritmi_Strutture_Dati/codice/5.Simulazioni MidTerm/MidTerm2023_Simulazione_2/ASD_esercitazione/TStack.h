/*
 * TStack: implementazione di uno stack attraverso un array dinamico
 */

#ifndef TSTACK_H
#define TSTACK_H

#include "TInfo.h"
#include "TArray.h"

typedef struct {
    TArray array;
} TStack;

/* Crea uno stack
 */
TStack stack_create(void);

/* Distrugge uno stack
 */
void stack_destroy(TStack *);

/* Inserisce un elemento
 * PRE:
 * lo stack non e’ pieno
 */
void stack_push(TStack *, TInfo);

/* Preleva un elemento
 */
TInfo stack_pop(TStack *);

/* Elemento in cima
 * PRE:
 * lo stack non e’ vuoto
 */
TInfo stack_top(TStack *);

/* Verifica se lo stack e’ vuoto
 */
int stack_is_empty(TStack *);

#endif