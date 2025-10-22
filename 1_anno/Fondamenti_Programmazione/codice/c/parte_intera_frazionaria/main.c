
/* 
 * File:   main.c
 * Author: emanueletocci
 *
 * Created on 29 novembre 2022, 17.51
 */
#include <stdio.h>
#include <stdlib.h>

void decomp (float x_2, int *x_int, float *x_float);
int main() {
    float x;
    printf("Questo programma restituisce la parta intera e quella decimale di un numero. \n Inserire numero: \t");
    scanf ("%f", &x);
    decomp (float x);
    return (EXIT_SUCCESS);
}

void decomp (float x_2, int *x_int, float *x_float){
    *x_int = x_2;

}

