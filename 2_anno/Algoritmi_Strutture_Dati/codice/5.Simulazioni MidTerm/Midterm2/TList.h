/*
 * TList: lista ordinata
 */

#ifndef TLIST_H
#define TLIST_H

#include "TInfo.h"

struct SNode {
    TInfo info;
    struct SNode *link;
};
typedef struct SNode TNode;
typedef TNode *TList;

/* Crea ed alloca un nodo
 * PRE: nessuna
 */
TNode *node_create(TInfo);

/* Distrugge e dealloca un nodo
 * PRE: nessuna
 */
void node_destroy(TNode*);

/* Crea e restituisce una lista vuota
 * PRE: nessuna
 */
TList list_create();

/* Distrugge la lista list, deallocandone tutti gli elementi
 * PRE: nessuna
 * NOTA: consuma il parametro list
 */
TList list_destroy(TList);

/* Visita la lista list dalla testa alla coda stampando gli elementi
 * PRE: nessuna
 */
void list_print(TList);

/* Cerca l’elemento di valore info nella Lista list. Ritorna il
 * riferimento all’elemento se e’ presente, altrimenti ritorna NULL.
 * PRE: list e’ ordinata
 */
TNode *list_search(TList, TInfo);

/* Inserisce l’elemento di valore info nella lista list, preservando
 * l’ordinamento ; restituisce la lista risultante .
 * PRE: list e’ ordinata
 * NOTA: consuma il parametro list; inoltre se l’elemento da inserire
e’ gia ’ presente, esso viene duplicato .
 */
TList list_insert(TList, TInfo);

/* Cancella l ’elemento di valore info nella lista list, preservando
 * l’ordinamento ; restituisce la lista risultante .
 * PRE: list e’ ordinata
 * NOTA: consuma il parametro list; se l’elemento da cancellare non
e’ presente, la lista resta inalterata .
 */
TList list_delete(TList, TInfo);

#endif

