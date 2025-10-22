/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: emanueletocci
 *
 * Created on 29 novembre 2022, 17.21
 */

#include <stdio.h>
#include <stdlib.h>

int swap(int *x_2, int *y_2);
int main() {
    int x, y;
    printf("Scambio di variabili \n");
    printf("Inserire il valore delle variabili: \n");
    scanf ("%d %d", &x, &y);
    swap (&x,&y);
    printf("Il valore delle due variabili è: %d \t %d", x, y);
    return (EXIT_SUCCESS);
}

int swap(int *x_2, int *y_2){
    int temp;
    temp = *x_2;
    *x_2 = *y_2;
    *y_2=temp;
    return (0);
} 

