/*
 * Scrivere una funzione void hashtable_increase(THashTable *ht, TKey key) tale
 * che, se esiste un valore associato con la chiave key ne incrementa di 1 il
 * valore, altrimenti inserisce nella tabella hash il dato (key, 1)
 * 
 * Scrivere una funzione void hashtable_decrease(THashTable *ht, TKey key) tale
 * che, se esiste un valore associato con la chiave key ne decrementa di 1 il
 * valore. Se il valore diventa 0 allora il dato viene rimosso dalla hashtable
 * 
 * Scrivere un'applicazione che chiede all'utente una chiave e se ne vuole 
 * incrementare o decrementare il valore. A seconda della scelta chiama una 
 * delle funzioni realizzate e stampa il numero di volte che ciascuna chiave 
 * appare nella hash table
 */

#include <stdio.h>
#include <stdlib.h>
#include "THT.h"

void hashtable_increase(THashTable *, TKey);

void hashtable_decrease(THashTable *, TKey);

int main(int argc, char** argv) {

    THashTable *ht = hashtable_create(13);
    int op, val;

    while (1) {
        printf("\nOperazione (1=incrementa, 2=decrementa, 0=exit) ");
        scanf("%d", &op);
        if (op == 0)
            break;
        printf("Inserisci chiave: ");
        scanf("%d", &val);
        if (op == 1)
            hashtable_increase(ht, val);
        else if (op == 2)
            hashtable_decrease(ht, val);
        printf("\nValori in tabella:\n");
        hashtable_print(ht);
    }
    hashtable_destroy(ht);
    return (EXIT_SUCCESS);
}

void hashtable_increase(THashTable *ht, TKey key) {
    TValue  *V = hashtable_search (ht, key);
    if (V == NULL)
        hashtable_insert(ht, key, 1);
    else 
        (*V)++;
}

void hashtable_decrease(THashTable *ht, TKey key) {
    TValue  *V = hashtable_search (ht, key);
    if (V == NULL)
        return;
    else if (*V == 0)
        hashtable_delete(ht, key);
    else 
        (*V)--;
}