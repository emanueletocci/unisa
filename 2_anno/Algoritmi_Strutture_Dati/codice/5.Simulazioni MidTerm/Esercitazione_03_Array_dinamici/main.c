/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Fabrizio
 *
 * Created on 15 ottobre 2023, 20.39
 */

#include <stdio.h>
#include <stdlib.h>
#include "TArray.h"
#include "TInfo.h"

void addElementPosArray(TArray *, int, TInfo);
void arrayPrintRec(TArray *);
void arrayCumulate(TArray *);

/*
 * 
 */
int main() {
    TArray a = arrayCreate(6);
    TInfo value = 10;
    int index = 4;
    a.item[0] = 1;
    a.item[1] = 5;
    a.item[2] = 7;
    a.item[3] = 0;
    a.item[4] = 9;
    a.item[5] = 3;


    printf("Array: ");
    arrayPrint(&a);
    printf("\n");
    arrayCumulate(&a);
    printf("Array cumulato: ");
    arrayPrintRec(&a);
    printf("\n");
    addElementPosArray(&a, index, value);
    printf("Array dopo l'aggiunta di un elemento: ");
    arrayPrintRec(&a);
    printf("\n");

}

void arrayCumulate(TArray *a) {
    if (a->length == 1)
        return;
    else{  
        a->length--;
        arrayCumulate(a);
        a->length++;
        a->item[a->length-1]=(a->item[a->length-2]+a->item[a->length-1]);

    }
}

void arrayPrintRec(TArray *a) {
    if (a->length == 1 ){
        infoPrint(a->item[a->length-1]);
        return;
    }
    else{
        a->length--;
        arrayPrintRec(a);
        a->length++;
        infoPrint(a->item[a->length-1]);
        return;
    }
       
}

void addElementPosArray(TArray *a, int index, TInfo value) {
arrayResize(a, a->length+1);
for(int i = a->length - 1 ; i > index; i--){
    a->item[i] = a->item[i-1];
}
a->item[index] = value;
}