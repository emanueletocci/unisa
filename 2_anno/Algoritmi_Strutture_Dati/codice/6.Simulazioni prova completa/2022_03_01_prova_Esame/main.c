/*
 * Una struttura ospedaliera deve riorganizzare alcuni elenchi di pazienti 
 * tra cui elenco1 (un Binary Search Tree) ed elenco2 (una Hash Table).
 * In ciascuna struttura, un paziente
 * e' rappresentato da un ID (campo chiave di tipo TKey, ossia un intero),
 * dal nome e dal cognome (di tipo TValue, ossia due stringhe).
 * In tutte le strutture coinvolte, i pazienti con esenzione dal ticket
 * vengono indicati con uno 0 finale nel loro ID.
 * 
 * Si dovra' realizzare un programma che sposti tutti i pazienti con esenzione
 * (ID la cui ultima cifra sia 0) da elenco1 ad elenco2, rimuovendo
 * gli eventuali duplicati in conseguenza del travaso. Inoltre, si dovranno copiare in elenco3 (un TArray)
 * tutti i pazienti di elenco2 con ID compreso tra min e max, rimuovendoli anche da elenco2.
 * Bisogna anche rimuovere da elenco1 il paziente con ID piu' grande.
 *
 * Per la PROVA FINALE, implementare solo le prime 3 funzioni.
 * Per la PROVA COMPLETA, bisogna anche stampare i pazienti con esenzione
 * in ordine crescente di ID (funzione 4).
 *
 * Per realizzare tale programma occorre sviluppare le seguenti funzioni.
 *    
 * 1) BSTtoHT_exemption(bst, ht): funzione RICORSIVA che copia da bst a ht tutti i 
 *    pazienti con ID la cui ultima cifra sia 0, rimuovendoli da bst.
 *    Considerando l'ID, se un paziente di bst gia' esiste in ht esso non verra'
 *    duplicato (ma verra' comunque rimosso da bst).
 * 
 * 2) HTtoArray_range(ht, array, min, max): funzione ITERATIVA che copia da ht ad array 
 *    tutti i pazienti con ID compreso tra min e max e, inoltre, li rimuove da ht.
 *
 * 3) BSTremoveLast(bst): funzione RICORSIVA che rimuove da bst l'ultimo 
 *    elemento in ordine di ID (ossia il paziente con ID massimo). 
 *    Restituisce il bst aggiornato.
 * 
 * 4) printOrderedArray(array): funzione ITERATIVA che stampa in ordine crescente di ID
 *    solo i pazienti con esenzione. Si possono utilizzare strutture dati di appoggio.
 *    Ad esempio, visite in order anche a spese della complessita' computazionale.
 *  
 * 
 * I prototipi delle funzioni sono gia' presenti nel file main.c. La funzione main 
 * e' gia' fornita e include del codice di test che riempie le strutture con i dati 
 * di alcuni pazienti e richiama le funzioni necessarie. E' altresi' fornito il codice 
 * delle strutture dati richieste. Si suggerisce di testare le funzioni anche con 
 * valori diversi da quelli forniti.
 * Rendere il codice modulare e generale, sfruttando il tipo TInfo.
 *
 */

/* *************
 * COGNOME: .............
 * NOME: ................
 * MATRICOLA: ...........
 */

#include <stdio.h>
#include "THT.h"
#include "TBST.h"
#include "TArray.h"

TBST BSTtoHT_exemption(TBST bst, THashTable* ht) {
    if (bst == NULL)
        return NULL;

    bst->left = BSTtoHT_exemption(bst->left, ht);
    bst->right = BSTtoHT_exemption(bst->right, ht);

    if ((bst -> info.key % 10) == 0) {                              //se l'ultima cifra e' 0
        hashtable_insert(ht, bst->info.key, bst->info.value);       //copio il valore trovato nell'HT
        bst = bst_delete(bst, bst->info);                                 //cancello l'elemento copiato dal bst
    }
    return bst;
}

void HTtoArray_range(THashTable* ht, TArray* array, TKey min, TKey max) {
    for(int i = 0 ; i < ht->n_bucket ; i++){
        for (TList list = ht -> bucket[i]; list != NULL; list = list->link){
            if((list->info.key >= min ) && (list->info.key <= max)) {
                array_insert(array, list->info);
            }
        }
    }
    for (int i=0; i < array->length; i++){
        hashtable_delete(ht, array->item[i].key);
    }
}

TBST BSTremoveLast(TBST bst) {
    if (bst == NULL)
        return NULL;
    if (bst -> right == NULL){
        bst = bst_delete(bst, bst->info);
        return bst;
    }
    bst->right = BSTremoveLast(bst->right);
    return bst;
}

void printOrderedArray_exemptions(TArray* array) {
    TList list = list_create();

    for (int i=0 ; i < array->length ; i++){
        if(array->item[i].key % 10 == 0)
            list = list_insert(list, array->item[i]);
    }
    list_print(list);

}

int main() {
    TBST elenco1 = bst_create();
    elenco1 = bst_insert(elenco1, (TInfo){1320, "Mario", "Rossi"});
    elenco1 = bst_insert(elenco1, (TInfo){2370, "Antonio", "Bianchi"});
    elenco1 = bst_insert(elenco1, (TInfo){3432, "Lucia", "Verdi"});
    elenco1 = bst_insert(elenco1, (TInfo){4223, "Camilla", "Neri"});
    elenco1 = bst_insert(elenco1, (TInfo){4443, "Aldo", "Giallini"});
    elenco1 = bst_insert(elenco1, (TInfo){4230, "Carlo", "Aranci"});
    elenco1 = bst_insert(elenco1, (TInfo){1238, "Maria", "Scarlatti"});
    elenco1 = bst_insert(elenco1, (TInfo){2644, "Luigi", "Turchesi"});
    elenco1 = bst_insert(elenco1, (TInfo){1110, "Giovanni", "Argento"});

    THashTable *elenco2 = hashtable_create(3);
    hashtable_insert(elenco2, 3351, (TValue){"Nicola", "Grigetti"});
    hashtable_insert(elenco2, 7675, (TValue){"Costanza", "Violetti"});
    hashtable_insert(elenco2, 4260, (TValue){"Filippa", "Azzurri"});
    hashtable_insert(elenco2, 4443, (TValue){"Aldo", "Giallini"});
    hashtable_insert(elenco2, 3233, (TValue){"Anna", "Indaco"});
    hashtable_insert(elenco2, 6320, (TValue){"Luigi", "Rosi"});
    hashtable_insert(elenco2, 1110, (TValue){"Giovanni", "Argento"});
    hashtable_insert(elenco2, 5430, (TValue){"Lucia", "Verdi"});
    hashtable_insert(elenco2, 1238, (TValue){"Maria", "Scarlatti"});
    hashtable_insert(elenco2, 3450, (TValue){"Biagio", "Verdini"});

    printf("Pazienti in elenco1 (BST):\n");
    bst_print(elenco1);
    printf("\nPazienti in elenco2 (HT):\n");
    hashtable_print(elenco2);

    elenco1 = BSTtoHT_exemption(elenco1, elenco2);

    printf("\nPazienti in elenco1 (BST) dopo lo spostamento:\n");
    bst_print(elenco1);
    printf("\nPazienti in elenco2 (HT) dopo lo spostamento:\n");
    hashtable_print(elenco2);

    TArray elenco3 = array_create(0);
    TKey min = 2000, max = 6000;
    HTtoArray_range(elenco2, &elenco3, min, max);

    printf("\nPazienti in elenco3 (Array) compresi fra %d e %d:\n", min, max);
    array_print(&elenco3);

    printf("\nPazienti in elenco2 (HT) dopo lo spostamento:\n");
    hashtable_print(elenco2);

    printf("\nPazienti in elenco1 (BST dopo aver rimosso l'elemento con ID massimo):\n");
    elenco1 = BSTremoveLast(elenco1);
    bst_print(elenco1);

    printf("\nPazienti con esenzione in elenco3 (Array) in ordine:\n");
    printOrderedArray_exemptions(&elenco3);

    bst_destroy(elenco1);
    hashtable_destroy(elenco2);
    array_destroy(&elenco3);

    return 0;
}