/*
 * File:   main.c
 * Author: Fabrizio Torre
 *
 * Created on 19 ottobre 2023, 23.10
 */

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include"TStack.h"
#include"TQueue.h"
#include"TList.h"

/*
 * ESERCIZIO 1
 * Implementare la funzione ricorsiva TList list_delete_kth_occurence(TList list, TInfo x, int k)
 * che riceve come parametri una lista, un valore ‘x’ e un valore ‘k’.
 * Se la lista contiene almeno ‘k’ elementi uguali a ‘x’,
 * la funzione cancella il k-esimo di tali valori;
 * se la lista non contiene ‘k’ elementi uguali a ‘x’,
 * la funzione lascia la lista inalterata.
 *
 * Esempi:
 *   lista: 11 12 12 43 - x: 12 - k: 2  OUTPUT Lista modificata: 11 12 43
 *   lista: 12 14 20 42 - x: 20 - k: 1  OUTPUT Lista modificata: 12 14 42
 *   lista: 8 8 8 11 11 11 - x: 11 - k: 3  OUTPUT Lista modificata: 8 8 8 11 11
 *   lista: 10 14 18 34 - x: 18 - k: 2  OUTPUT Lista modificata: 10 14 18 34
 */
TList list_delete_kth_occurence(TList list, TInfo x, int k);

/*
 * ESERCIZIO 2
 * Implementare la funzione iterativa void transfer_odd_stack(TStack *destination, TStack source)
 * che ricevute in ingresso due pile source e destination
 * copi in destination gli elementi dispari di source in modo che
 * gli elementi di destination risultino avere lo stesso ordinamento che avevano in source.
 *
 * Si consiglia di utilizzare uno stack di appoggio.
 *
 * N.B.: è vietato utilizzare i dettagli implementativi interni delle strutture dati.
 *
 * Esempi:
 * source: 3|4|2|2|4|3 TOP  destination: 3|3 TOP
 * source: 0|1|2|3|4|5|6 TOP  destination 1|3|5 TOP
 */
void transfer_odd_stack(TStack *destination, TStack source);

void stack_print ( TStack stack );

void stack_print_ref ( TStack *stack );

/*
 *
 */
int main(int argc, char** argv) {
    TList lista1 = list_create();
    TList lista2 = list_create();
    TList lista3 = list_create();
    TList lista4 = list_create();

    lista1 = list_insert(lista1, 11);
    lista1 = list_insert(lista1, 12);
    lista1 = list_insert(lista1, 43);
    lista1 = list_insert(lista1, 12);

    lista2 = list_insert(lista2, 20);
    lista2 = list_insert(lista2, 42);
    lista2 = list_insert(lista2, 12);
    lista2 = list_insert(lista2, 14);

    lista3 = list_insert(lista3, 8);
    lista3 = list_insert(lista3, 11);
    lista3 = list_insert(lista3, 8);
    lista3 = list_insert(lista3, 11);
    lista3 = list_insert(lista3, 8);
    lista3 = list_insert(lista3, 11);

    lista4 = list_insert(lista4, 10);
    lista4 = list_insert(lista4, 18);
    lista4 = list_insert(lista4, 34);
    lista4 = list_insert(lista4, 14);

    printf("\nStampo le liste non modificate\n");
    list_print(lista1);
    list_print(lista2);
    list_print(lista3);
    list_print(lista4);

    int x, k;
    printf("\nInserire x: \t");
    scanf("%d", &x);
    printf("\nInserire k: \t");
    scanf("%d", &k);

    lista1 = list_delete_kth_occurence(lista1, x, k);
    lista2 = list_delete_kth_occurence(lista2, x, k);
    lista3 = list_delete_kth_occurence(lista3, x, k);
    lista4 = list_delete_kth_occurence(lista4, x, k);

    printf("\nStampo le liste modificate\n");
    list_print(lista1);
    list_print(lista2);
    list_print(lista3);
    list_print(lista4);

    /*
     * EFFETTUA UNA STAMPA DELLA LISTA.
     * CHIAMA LA FUNZIONE PER CANCELLARE ELEMENTO.
     * STAMPA NUOVAMENTE LA LISTA PER VERIFICARE CHE LA CANCELLAZIONE SIA ANDATA A BUON FINE
     */

    TStack stackSorgente = stack_create();
    TStack stackSorgente2 = stack_create();
    TStack stackDestinazione = stack_create();

    for (int i = 0; i < 7; i++)
        stack_push(&stackSorgente, i);

    printf("\nStampo stack 1: \n");
    stack_print(stackSorgente);
    transfer_odd_stack(&stackDestinazione, stackSorgente);
    printf("\nStack 1 aggiornato: \n");
    stack_print_ref(&stackDestinazione);


    stack_push(&stackSorgente2, 3);
    stack_push(&stackSorgente2, 4);
    stack_push(&stackSorgente2, 2);
    stack_push(&stackSorgente2, 2);
    stack_push(&stackSorgente2, 4);
    stack_push(&stackSorgente2, 3);

    /*
     * CHIAMA LA FUNZIONE transfer_odd_stack .
     * SCRIVI IL CODICE PER STAMPARE GLI ELEMENTI DEI DUE STACK
     */

    printf("\nStampo stack 2: \n");
    stack_print(stackSorgente2);
    transfer_odd_stack(&stackDestinazione, stackSorgente2);
    printf("\nStack 2 aggiornato: \n");
    stack_print_ref(&stackDestinazione);

    return (EXIT_SUCCESS);
}

TList list_delete_kth_occurence(TList list, TInfo x, int k) {

    if ((list == NULL) || (k < 0))
        return list;

    if (info_equal(list -> info, x)) {
        k--;
        if (k == 0)
            list = list_delete(list, list->info);
    }
    list->link = list_delete_kth_occurence(list -> link ,x, k);
    return list;
}

void transfer_odd_stack(TStack *destination, TStack source) {
    TStack s_tmp = stack_create();
    while(!stack_is_empty(&source)){
        TInfo info_tmp = stack_pop(&source);
        if (info_tmp % 2 == 1)
            stack_push(&s_tmp, info_tmp);
    }
    while (!stack_is_empty(&s_tmp)){
        stack_push(destination, stack_pop(&s_tmp));
    }

}

//stampad dello stack senza modifica
void stack_print ( TStack stack ){
    while (!stack_is_empty(&stack))
        info_print(stack_pop(&stack));
}

//stampa dello stack con eliminazione dei valori originali
void stack_print_ref ( TStack *stack ){
    while (!stack_is_empty(stack))
        info_print(stack_pop(stack));
}