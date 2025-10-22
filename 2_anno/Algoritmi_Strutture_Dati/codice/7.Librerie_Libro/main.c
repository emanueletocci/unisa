/* 
 * File:   main.c
 * Author: Fabrizio Torre
 *
 * Created on 19 ottobre 2023, 23.10
 */

#include <stdio.h>
#include <stdlib.h>
#include"TStack.h"
#include"TQueue.h"
#include"TList.h"

void revStack(TQueue *queue){
    TStack tmp_stack = stackCreate();
    
    //sversamento nello stack
    while (!queueIsEmpty(queue)){
        stackPush(&tmp_stack,queueRemove(queue));
    }
    
    while(!stackIsEmpty(&tmp_stack)){
        queueAdd(queue, stackPop(&tmp_stack));
        
    }
}

TQueue* revRec(TQueue *queue){
    if (queueIsEmpty(queue)){
        return queue;
    }
    
    TInfo front = queueRemove(queue);
    revRec(queue);
    queueAdd(queue, front);
    return queue;
}


void printQueue (TQueue queue){
    while(!queueIsEmpty(&queue)){
        printf("%d ", queueFront(&queue));
        queueRemove(&queue);
    }
    
}

void rev(TQueue *queue){
    TArray array = arrayCreate(0);
    while(!queueIsEmpty(queue)){
        arrayAdd(&array, queueRemove(queue));
    }
    for (int i=arrayLength(&array) - 1; i>= 0; i--){
        queueAdd(queue, arrayGet(&array, i));
    }
}

    
/*Scrivere una funzione rev() in linguaggio C che ricevuto in input una
 *coda, la restituisca con gli elementi in ordine inverso.
 * 
 */
int main(int argc, char** argv) {
    int dim;
    TQueue queue = queueCreate(0);

    printf("Da quanti elementi sara' composta la coda? \t");
    scanf("%d", &dim);
    
    //riempimento coda
    for (int i=0;i<dim;i++){            
        int temp;
        printf("\nInserire %d elemento della coda \t", i+1);
        scanf("%d", &temp);
        queueAdd(&queue, temp); 
    }
    
    printf("\nStampo la coda: \n");
    printQueue(queue);
    
    printf("\nInverto l'ordine degli elementi usando lo stack...\n");
    revStack(&queue);
    printQueue(queue);
    revStack(&queue);       //riporto la coda allo stato di partenza

    printf("\nInverto l'ordine degli elementi usando una funzione ricorsiva...\n");
    revRec(&queue);
    printQueue(queue);
    revRec(&queue);     //riporto la coda allo stato iniziale
    
    printf("\nInverto l'ordine degli elementi ...\n");
    rev(&queue);
    printQueue(queue);

    
    //Deallocazione
    queueDestroy(&queue);
    
    return (EXIT_SUCCESS);
}

