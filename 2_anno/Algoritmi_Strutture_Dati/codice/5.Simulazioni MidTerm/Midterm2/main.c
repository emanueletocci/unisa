/* 
 * File:   main.c
 * Author: Fabrizio Torre
 *
 * Created on 19 ottobre 2023, 23.10
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include"TStack.h"
#include"TQueue.h"
#include"TList.h"
/* 
 * ESERCIZIO 1
 * Definire una funzione ricorsiva int sono_dispari(Tlist list)
 * che ricevuta una lista come argomento restituisca 1 se la lista contiene
 * un numero dispari di elementi; 0 altrimenti. 
 * La funzione non deve contare il numero degli elementi
 * (ossia non deve calcolare la lunghezza della lista, e nemmeno usare una
 * funzione ausiliaria che faccia questo conto).
 * 
 * Esempi:
 *   sonoDispari [5;3;7] = true
 *   sonoDispari [5;3;7;1] = false

 */
int sono_dispari(TList list);

/*
 * ESERCIZIO 2
 * Implementare la funzione iterativa void queue_swap_front_back(TQueue *queue)
 * che ricevuta una coda di numeri interi, scambi la testa (front)
 * con la coda (back) lasciando il resto della coda inalterata.
 * 
 * Precondizione:
 *  - La coda deve avere almeno 2 valori
 * 
 * Suggerimento: utilizzare le strutture di appoggio (es: una TQueue) ritenute opportune
 * 
 * N.B.: è vietato utilizzare i dettagli implementativi interni delle strutture dati.
 * 
 * Esempi:
 *   Input:  11 12 13 14 15 16 17 18 19 20
 *   Output: 20 12 13 14 15 16 17 18 19 11
 */
void queue_swap_first_last(TQueue *q);
void queue_swap_first_last_v2(TQueue *q);
/*
 * 
 */
int main(int argc, char** argv) {
    TList lista1 = list_create();

    lista1 = list_insert(lista1, 5);
    lista1 = list_insert(lista1, 3);
    lista1 = list_insert(lista1, 7);

    printf("\nStampo la lista : \n");
    list_print(lista1);

    if(sono_dispari(lista1) == 1)
        printf("\nLa lista contiene un numero dispari di elementi");
    else
        printf("\nLa lista contiene un numero pari di elementi");

    TQueue q = queue_create(0);

    printf("\nPopolo la coda con i seguenti valori: ");
    for (TInfo i = 11; i < 21; i++) {
        queue_add(&q, i);
        info_print(i);
    }

    if ((sizeof(q)/sizeof(TInfo)) >= 2) {
//        queue_swap_first_last(&q);
        queue_swap_first_last_v2(&q);
    }
    printf("\nStampo la coda aggiornata: \n");

    queue_print(q);

    return (EXIT_SUCCESS);
}

int sono_dispari(TList list) {
/*
 *     if (list == NULL)
        return 0;
    return (1 + sono_dispari(list->link))%2;
 *
 */

    if (list == NULL)
        return 0;
    return !sono_dispari(list->link);
}

/*
void queue_swap_first_last_v2(TQueue *q) {
    TQueue q_tmp = queue_create(0);         //creo una coda di appoggio
    TInfo front_tmp = queue_remove(q);      //rimuovo il front e lo salvo in una variabile temporanea
    TStack s_tmp = stack_create();          //creo uno stack di appoggio per invertire la coda

    while (!queue_is_empty(q)) {
        TInfo temp = queue_remove(q);
        queue_add(&q_tmp, temp);    //riverso la coda in qualla di appoggio
        stack_push(&s_tmp, temp);    //riverso la coda di appoggio nello stack per invertirla e rimuovere il back
    }

    TInfo back_tmp = stack_pop(&s_tmp);             //salvo il back della coda
    TStack s2_tmp = stack_create();                 //creo uno stack di appoggio per invertire nuovamente la coda

    while (!stack_is_empty(&s_tmp)){
        stack_push(&s2_tmp, stack_pop(&s_tmp));
    }
    queue_add(q,back_tmp);                          //aggiungo il back alla coda

    while (!stack_is_empty(&s2_tmp))
        queue_add(q, stack_pop(&s2_tmp));
    queue_add(q,front_tmp);
}
*/
void queue_swap_first_last_v2(TQueue *q) {

}
