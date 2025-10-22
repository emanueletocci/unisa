/* 
 * COGNOME: .............
 * NOME: ................
 * MATRICOLA: ...........
 * 
 * Una biblioteca deve riorganizzare alcuni elenchi di libri tra cui elenco1 
 * (un BST) ed elenco2 (una HT). In ciascuna struttura un libro è rappresentato 
 * da un codice ISBN numerico (campo chiave) e da un titolo. 
 * 
 * Si dovrà realizzare un programma che copi in elenco1 tutti gli elementi di
 * elenco2 (evitando duplicati) e che generi un nuovo elenco (elenco3) che contiene
 * i primi n libri di elenco2 (in ordine di ISBN). Da elenco3 verranno poi 
 * rimossi tutti i libri con ISBN pari. Per realizzare tale programma occorre 
 * sviluppare le seguenti funzioni.
 * 
 * 1) HT_to_BST(ht, bst): copia in bst tutti gli elementi di ht. Restituisce il
 *    bst aggiornato.
 * 
 * 2) BST_remove_duplicates(bst): funzione RICORSIVA che rimuove tutti i libri 
 *    duplicati (con lo stesso codice ISBN) da bst. Restituisce il bst aggiornato.
 *
 * 3) BST_first_to_list(bst, list, n): copia da bst a list i primi n libri di bst 
 *    in ordine crescente di ISBN (i.e. gli n libri con ISBN più piccolo). Se n 
 *    eccede il numero di elementi di bst, verranno copiati in list tutti gli 
 *    elementi di bst. Restituisce la lista aggiornata. NB. non è un caso che 
 *    n sia passato per riferimento
 * 
 * 4) list_delete_even(list): funzione RICORSIVA che elimina da list tutti i 
 *    libri con ISBN pari. Restituisce la lista aggiornata.
 * 
 * Lo scheletro delle funzioni è già presente nel file main.c. La funzione main 
 * è già fornita ed include del codice di test che riempie le strutture con i dati 
 * di alcuni libri e richiama le funzioni necessarie. E' altresì fornito il codice 
 * delle strutture dati richieste. Si suggerisce di testare le funzioni anche con 
 * valori diversi da quelli forniti. 
 * 
 * Libri in elenco1 (BST):
 * (1111: Anna Karenina)
 * (1238: L'amore ai tempi del colera)
 * (1321: Le mille e una notte)
 * (1445: Il processo)
 * (2234: Madame Bovary)
 * (2372: Orgoglio e pregiudizio)
 * (3432: Finzioni)
 * (4223: Delitto e castigo)
 * (6643: Il vecchio e il mare)
 * 
 * Libri in elenco2 (HT):
 * (9090: Le metamorfosi)
 * (1445: Il processo)
 * (7675: Alla ricerca del tempo perduto)
 * (1111: Anna Karenina)
 * (3321: L'uomo senza qualità)
 * (3432: Finzioni)
 * (4222: Moby-Dick)
 * (3357: Il rosso e il nero)
 * (3233: Pippi Calzelunghe)
 * 
 * Riverso elenco2 in elenco1 e rimuovo i duplicati.
 * Libri in elenco1 (BST):
 * (1111: Anna Karenina)
 * (1238: L'amore ai tempi del colera)
 * (1321: Le mille e una notte)
 * (1445: Il processo)
 * (2234: Madame Bovary)
 * (2372: Orgoglio e pregiudizio)
 * (3233: Pippi Calzelunghe)
 * (3321: L'uomo senza qualità)
 * (3357: Il rosso e il nero)
 * (3432: Finzioni)
 * (4222: Moby-Dick)
 * (4223: Delitto e castigo)
 * (6643: Il vecchio e il mare)
 * (7675: Alla ricerca del tempo perduto)
 * (9090: Le metamorfosi)
 * 
 * Riverso in elenco3 i primi 6 libri di elenco1 e rimuovo i codici pari.
 * Libri in elenco3 (Lista):
 * (1111: Anna Karenina)
 * (1321: Le mille e una notte)
 * (1445: Il processo)
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "THT.h"
#include "TBST.h"
#include "TArray.h"


TBinaryTree HT_to_BST(THashTable *ht, TBinaryTree bst) {
    for (int i = 0; i < ht->bucket_number; i++) {
        for (TNode *node = ht->bucket[i]; node != NULL; node = node->link)
            bst = binarytree_insert(bst , node -> info);
    }
    return bst;
}

TBinaryTree BST_remove_duplicates(TBinaryTree bst) {
    if (bst == NULL)
        return NULL;
    BST_remove_duplicates(bst->left);
    BST_remove_duplicates(bst->right);
    bst->left= binarytree_delete( bst->left, bst->info);
    return bst;
}

TList BST_first_to_list(TBinaryTree bst, TList list, int *n) {

    if(bst!=NULL && *n>0){
        list=BST_first_to_list(bst->left,list,n);
        if(*n>0){
            list = list_insert(list,bst->info);
            (*n)--;
        }
        list = BST_first_to_list(bst->right,list,n);
    }
    return list;
}

TList list_delete_even(TList list) {
    if (list == NULL)
        return NULL;
    list -> link = list_delete_even(list->link);

    if ((list->info.key % 2) == 0) {
        list = list_delete(list, list->info);
    }
    return list;
}
int main() {
    TBinaryTree elenco1 = NULL;
    elenco1 = binarytree_insert(elenco1, (TInfo){1321, "Le mille e una notte"});
    elenco1 = binarytree_insert(elenco1, (TInfo){2372, "Orgoglio e pregiudizio"});
    elenco1 = binarytree_insert(elenco1, (TInfo){3432, "Finzioni"});
    elenco1 = binarytree_insert(elenco1, (TInfo){4223, "Delitto e castigo"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1445, "Il processo"});
    elenco1 = binarytree_insert(elenco1, (TInfo){2234, "Madame Bovary"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1238, "L'amore ai tempi del colera"});
    elenco1 = binarytree_insert(elenco1, (TInfo){6643, "Il vecchio e il mare"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1111, "Anna Karenina"});

    THashTable *elenco2 = hashtable_create(5);
    hashtable_insert(elenco2, 3357, (TValue){"Il rosso e il nero"});
    hashtable_insert(elenco2, 7675, (TValue){"Alla ricerca del tempo perduto"});
    hashtable_insert(elenco2, 4222, (TValue){"Moby-Dick"});
    hashtable_insert(elenco2, 1445, (TValue){"Il processo"});
    hashtable_insert(elenco2, 3233, (TValue){"Pippi Calzelunghe"});
    hashtable_insert(elenco2, 3321, (TValue){"L'uomo senza qualità"});
    hashtable_insert(elenco2, 1111, (TValue){"Anna Karenina"});
    hashtable_insert(elenco2, 9090, (TValue){"Le metamorfosi"});
    hashtable_insert(elenco2, 3432, (TValue){"Finzioni"});

    printf("Libri in elenco1 (BST):\n");
    binarytree_visit(elenco1);
    printf("\nLibri in elenco2 (HT):\n");
    hashtable_print(elenco2);

    printf("\nRiverso elenco2 in elenco1 e rimuovo i duplicati.\nLibri in elenco1 (BST):\n");
    elenco1 = HT_to_BST(elenco2, elenco1);
    elenco1 = BST_remove_duplicates(elenco1);
    binarytree_visit(elenco1);

    int n = 6;
    TList elenco3 = NULL;
    printf("\nRiverso in elenco3 i primi %d libri di elenco1 ", n);
    printf("\nLibri in elenco3 (Lista):\n");
    elenco3 = BST_first_to_list(elenco1, elenco3, &n);
    list_print(elenco3);
    printf("\nRimuovo i libri con ISBN pari: \n");
    elenco3 = list_delete_even(elenco3);
    list_print(elenco3);

    binarytree_destroy(elenco1);
    hashtable_destroy(elenco2);
    list_destroy(elenco3);
    return 0;
}