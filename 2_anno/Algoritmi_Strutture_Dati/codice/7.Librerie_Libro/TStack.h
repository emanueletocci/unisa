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
TStack stackCreate(void);

/* Distrugge uno stack
 */
void stackDestroy(TStack *);

/* Inserisce un elemento
 * PRE:
 * lo stack non e’ pieno
 */
void stackPush(TStack *, TInfo);

/* Preleva un elemento
 */
TInfo stackPop(TStack *);

/* Elemento in cima
 * PRE:
 * lo stack non e’ vuoto
 */
TInfo stackTop(TStack *);

/* Verifica se lo stack e’ vuoto
 */
int stackIsEmpty(TStack *);

#endif