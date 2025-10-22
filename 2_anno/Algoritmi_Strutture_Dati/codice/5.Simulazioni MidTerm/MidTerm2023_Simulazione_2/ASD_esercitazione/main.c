/* 
 * File:   main.c
 * Author: Fabrizio Torre
 *
 * Created on 19 ottobre 2023, 23.10
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"TStack.h"
#include"TQueue.h"
#include"TList.h"
#include"utilita.h"


/*
 * ESERCIZIO 1:
 * Implementare la funzione ricorsiva TList list_insert_before_first_odd(TList *list, TInfo x)
 * che, applicata ad una lista di interi, inserisca un nuovo valore ‘x’ 
 * immediatamente prima del primo valore dispari; se la lista non contiene elementi dispari, 
 * la funzione inserisce ‘x’ come ultimo elemento della lista. 
 * 
 * Esempi:
 * lista: 11 12 13 14 - n: 72 --> 72 11 12 13 14
 * lista: 12 13 14 20 - n: 39 --> 12 39 13 14 20
 * lista: 7 10 14 18  - n: 10 --> 10 7 10 14 18
 * lista: 2 10 14 18  - n: 42 --> 2 10 14 18 42
 */
TList list_delete_first_odd(TList);

/*
 * ESERCIZIO 2:
 * Implementare la funzione iterativa void array_rotate(TArray *, int)
 * che, ricevuti un array ed un valore n, ruoti l'array di n posizioni.
 *
 * Precondizione:
 *  - arraylist correttamente inizilizzato
 *  - n >= 0
 * 
 * Esempi:
 * array: 0 3 6 9 12 14 18 20 22 25 27
 * n = 4
 * dalla 4a posizione i valori dell'array sono: 12 14 18 20 22 25 27
 * prima della 4a posizione i valori dell'array sono: 0 3 6 9
 * dopo aver ruotato, l'array è: 12 14 18 20 22 25 27 0 3 6 9
 */
void array_rotate(TArray *, int);


/*
 * ESERCIZIO 3:
 * Implementare la funzione iterativa TQueue queue_get_even_elements(TQueue *)
 * che ricevuta una coda restituisca una nuova coda contenente gli elementi
 * in posizione pari della prima. La funzione lascia la prima coda inalterata. 
 * 
 * Se la coda in input è vuota la funzione restituirà una coda vuota.
 * 
 * Si consiglia di utilizzare una seconda coda di appoggio.
 * Provare a fornire anche un’implementazione ricorsiva della funzione.
 * 
 * Esempi:
 *    INPUT:  queue1:11 14 15 12 18 19 13 16 17 20 
 *    OUTPUT: queue2:14 12 19 16 20 
 */
TQueue queue_get_even_elements(TQueue *);

/*
 * ESERCIZIO 4:
 * Implementare la funzione iterativa TInfo stack_remove_min_value(TStack *)
 * che ricevuto in ingresso uno stack restituisca il suo elemento minimo.
 * 
 * Si consiglia di utilizzare un secondo stack di appoggio.
 * Provare a fornire anche un’implementazione ricorsiva della funzione.
 * 
 * PRECONDIZIONE
 * - lo stack non deve essere vuoto
 * 
 * Esempi:
 * stack: 1 3 2 5 4 7  --> Valore minimo dello stack: 1  --> stack: 3 2 5 4 7
 * stack: 3 2 5 4 7    --> Valore minimo dello stack: 2  --> stack: 3 5 4 7 
 * stack: 3 5 4 7      --> Valore minimo dello stack: 3  --> stack: 5 4 7
 */
TInfo stack_remove_min_value(TStack *);

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
    lista1 = list_insert(lista1, 13);
    lista1 = list_insert(lista1, 14);

    lista2 = list_insert(lista2, 20);
    lista2 = list_insert(lista2, 12);
    lista2 = list_insert(lista2, 13);
    lista2 = list_insert(lista2, 14);

    lista3 = list_insert(lista3, 10);
    lista3 = list_insert(lista3, 18);
    lista3 = list_insert(lista3, 14);
    lista3 = list_insert(lista3, 7);

    lista4 = list_insert(lista4, 10);
    lista4 = list_insert(lista4, 18);
    lista4 = list_insert(lista4, 14);
    lista4 = list_insert(lista4, 2);

    printf("Stampo lista1: ");
    list_print(lista1);
    printf("\nStampo lista1 dopo cancellazione: ");
    lista1 = list_delete_first_odd(lista1);
    list_print(lista1);

    printf("\nStampo lista2: ");
    list_print(lista2);
    printf("\nStampo lista2 dopo cancellazione: ");
    lista2 = list_delete_first_odd(lista2);
    list_print(lista2);

    printf("\nStampo lista3: ");
    list_print(lista3);
    printf("\nStampo lista3 dopo cancellazione: ");
    lista3 = list_delete_first_odd(lista3);
    list_print(lista3);

    printf("\nStampo lista4: ");
    list_print(lista4);
    printf("\nStampo lista4 dopo cancellazione: ");
    lista4 = list_delete_first_odd(lista4);
    list_print(lista4);

    TArray array1 = array_create(0);
    int ruota_da = 4;

    array_insert(&array1, 0);
    array_insert(&array1, 3);
    array_insert(&array1, 6);
    array_insert(&array1, 9);
    array_insert(&array1, 12);
    array_insert(&array1, 14);
    array_insert(&array1, 18);
    array_insert(&array1, 20);
    array_insert(&array1, 22);
    array_insert(&array1, 25);
    array_insert(&array1, 27);

    printf("\n\\-------------------------------------------------------\\\n");

    printf("\nStampo array1\n");
    array_print(&array1);

    printf("\nStampo array1 dopo una rotazione di %d elementi\n", ruota_da);
    array_rotate(&array1, ruota_da);
    array_print(&array1);


    TQueue queue1 = queue_create(0);
    TQueue queue2;
    queue_add(&queue1, 11);
    queue_add(&queue1, 14);
    queue_add(&queue1, 15);
    queue_add(&queue1, 12);
    queue_add(&queue1, 18);
    queue_add(&queue1, 19);
    queue_add(&queue1, 13);
    queue_add(&queue1, 16);
    queue_add(&queue1, 17);
    queue_add(&queue1, 20);

    queue2 = queue_get_even_elements(&queue1);
    printf("\n\\-------------------------------------------------------\\\n");
    printf("\nStampo queue1:");
    while (!queue_is_empty(&queue1)) {
        info_print(queue_remove(&queue1));
    }
    printf("\nStampo queue2:");
    printQueue(queue2);

    TStack stack = stack_create();
    stack_push(&stack, 7);
    stack_push(&stack, 4);
    stack_push(&stack, 5);
    stack_push(&stack, 2);
    stack_push(&stack, 3);
    stack_push(&stack, 1);
    printf("\n\n\\-------------------------------------------------------\\\n");
    printf("\nElementi dello stack:\n");
    print_stack(stack);
    printf("\nValore minimo dello stack: %d\n", stack_remove_min_value(&stack));
    printf("Elementi dello stack dopo aver rimosso il valore minimo:\n");
    print_stack(stack);

    printf("\nValore minimo dello stack: %d\n", stack_remove_min_value(&stack));
    printf("Elementi dello stack dopo aver rimosso il valore minimo:\n");
    print_stack(stack);

    printf("\nValore minimo dello stack: %d\n", stack_remove_min_value(&stack));
    printf("Elementi dello stack dopo aver rimosso il valore minimo:\n");
    print_stack(stack);

    return (EXIT_SUCCESS);
}

TList list_delete_first_odd(TList) {
    /*
     * INSERIRE IL CODICE QUI
     */
}

void array_rotate(TArray *array, int ruota_da) {
    for (int i=0; i<ruota_da; i++){
        TInfo temp;
        temp = array_get(array, i);
        
        for(int j = 0; j<array_length(array) -1; j++){
            array_set(array, j, array_get(array, j+1));
        }
        array_set(array, i , temp);

    }
}
    
    


TQueue queue_get_even_elements(TQueue *queue) {
    
}

TInfo stack_remove_min_value(TStack *stack) {
    /*
     * INSERIRE IL CODICE QUI
     */
}