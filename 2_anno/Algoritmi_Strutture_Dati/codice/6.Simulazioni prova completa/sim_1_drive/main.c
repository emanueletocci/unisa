/*
 * La segreteria di una Universita' deve riorganizzare alcuni elenchi di studenti
 * tra cui elenco1 (un BST) ed elenco2 (una HT). In ciascuna struttura uno studente
 * è rappresentato dalla matricola (campo chiave), dal nome e dal cognome.
 *
 * Si dovrà realizzare un programma che sposti tutti gli studenti con matricola
 * pari in elenco1 e tutti gli studenti con matricola dispari in elenco2 rimuovendo
 * gli eventuali duplicati. Inoltre si dovranno copiare in elenco3 (un Array Dinamico)
 * lo studente con matricola dispari più bassa e lo studente con matricola dispari
 * più alta. Per realizzare tale programma occorre sviluppare le seguenti funzioni.
 *
 * 1) HTtoBSTeven(ht, bst): copia da ht a bst tutti gli studenti con matricola pari
 *    rimuovendoli da ht. Se uno studente di ht già esiste in bst esso non verrà
 *    duplicato (ma verrà comunque rimosso da ht).
 *
 * 2) BSTtoHTodd(bst, ht): funzione RICORSIVA che copia da bst a ht tutti gli
 *    studenti con matricola dispari rimuovendoli da bst. Se uno studente di bst
 *    già esiste in ht esso non verrà duplicato (ma verrà comunque rimosso da bst).
 *
 * 3) HTextremes(ht, arr): copia nell'array dinamico arr (inizialmente vuoto) lo
 *    studente di ht con la matricola piu' bassa (in posizione 0) e lo studente di
 *    ht con la matricola piu' alta (in posizione 1). Al termine arr sarà composto
 *    da 2 elementi se ht non è vuota, da 0 elementi in caso contrario.
 *
 * Lo scheletro delle funzioni e' gia' presente nel file main.c. La funzione main
 * è già fornita ed include del codice di test che riempie le strutture con i dati
 * di alcuni studenti e richiama le funzioni necessarie. E' altresi' fornito il codice
 * delle strutture dati richieste. Si suggerisce di testare le funzioni anche con
 * valori diversi da quelli forniti.
 */

#include <stdio.h>
#include <string.h>
#include "THT.h"
#include "TBST.h"
#include "TArray.h"

TBST HTtoBSTeven(THT* ht, TBST bst) {
    for (int i=0 ; i < ht->n_bucket ; i++) {
        for (TList list = ht->bucket[i]; list != NULL; list = list->link) {
            if ((list->info.key % 2) == 0) {
                if(BSTsearch(bst, list->info) == NULL)
                    bst = BSTinsert(bst, list->info);
                HTdelete(ht,list->info.key);

            }
        }
    }
    return bst;
}

TBST BSTtoHTodd(TBST bst, THT* ht) {
    if (bst == NULL)
        return bst;

    bst->left = BSTtoHTodd(bst->left, ht);
    bst-> right = BSTtoHTodd(bst->right, ht);
    if((bst->info.key % 2) == 1) {                          //se la matricola e' dispari inserisci in HT e rimuovi da BST
        if (HTsearch(ht, bst->info.key) == NULL)            //l'elemento non e' presente
            HTinsert(ht, bst->info.key, bst->info.value);
        bst = BSTdelete(bst, bst->info);
    }
    return bst;
}

void HTextremes(THT* ht, TArray* arr) {
    TBST tree = BSTcreate();
    for ( int i = 0 ; i < ht->n_bucket ; i++){
        for (TList list = ht->bucket[i] ; list!=NULL ; list = list->link){
            tree = BSTinsert(tree , list->info);
        }
    }
    arrayAdd(arr, BSTmin(tree)->info);  //aggiungi il minimo
    arrayAdd(arr, BSTmax(tree)->info);  //aggiungi il minimo

}

int main() {
    TBST elenco1 = BSTcreate();
    elenco1 = BSTinsert(elenco1, (TInfo) {1321, "Mario", "Rossi"});
    elenco1 = BSTinsert(elenco1, (TInfo) {2372, "Antonio", "Bianchi"});
    elenco1 = BSTinsert(elenco1, (TInfo) {3432, "Lucia", "Verdi"});
    elenco1 = BSTinsert(elenco1, (TInfo) {4223, "Camilla", "Neri"});
    elenco1 = BSTinsert(elenco1, (TInfo) {1445, "Aldo", "Giallini"});
    elenco1 = BSTinsert(elenco1, (TInfo) {2234, "Carlo", "Aranci"});
    elenco1 = BSTinsert(elenco1, (TInfo) {1238, "Maria", "Scarlatti"});
    elenco1 = BSTinsert(elenco1, (TInfo) {6643, "Luigi", "Turchesi"});
    elenco1 = BSTinsert(elenco1, (TInfo) {1111, "Giovanni", "Argento"});

    THT *elenco2 = HTcreate(5);
    HTinsert(elenco2, 3357, (TValue) {"Nicola", "Grigetti"});
    HTinsert(elenco2, 7675, (TValue) {"Costanza", "Violetti"});
    HTinsert(elenco2, 4222, (TValue) {"Filippa", "Azzurri"});
    HTinsert(elenco2, 1445, (TValue) {"Aldo", "Giallini"});
    HTinsert(elenco2, 3233, (TValue) {"Anna", "Indaco"});
    HTinsert(elenco2, 3321, (TValue) {"Luigi", "Rosi"});
    HTinsert(elenco2, 1111, (TValue) {"Giovanni", "Argento"});
    HTinsert(elenco2, 3432, (TValue) {"Lucia", "Verdi"});
    HTinsert(elenco2, 1238, (TValue) {"Maria", "Scarlatti"});

    printf("Studenti in elenco1 (BST):\n");
    BSTprint(elenco1);
    printf("\nStudenti in elenco2 (HT):\n");
    HTprint(elenco2);

    elenco1 = HTtoBSTeven(elenco2, elenco1);
    elenco1 = BSTtoHTodd(elenco1, elenco2);

    printf("\nStudenti in elenco1 (BST) dopo lo spostamento\n(solo matricole pari senza duplicati):\n");
    BSTprint(elenco1);
    printf("\nStudenti in elenco2 (HT) dopo lo spostamento\n(solo matricole dispari senza duplicati):\n");
    HTprint(elenco2);

    TArray elenco3 = arrayCreate(0);
    HTextremes(elenco2, &elenco3);
    printf("\nStudenti in elenco3 (Array Dinamico)\n(matricola dispari più bassa e più alta):\n");
    arrayPrint(&elenco3);

    BSTdestroy(elenco1);
    HTdestroy(elenco2);
    arrayDestroy(&elenco3);

    return 0;
}
