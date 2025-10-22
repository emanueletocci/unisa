#include <stdio.h>
#include <math.h>
void main(void){
    float base, altezza, area, perimetro, diagonale;
    printf("Questo programma calcola area, perimetro del rettangolo dati in input la dimensione dei lati \n");
    printf("Inserire dimensione base e altezza: \t");
    scanf ("%f %f", &base, &altezza);
    area= base*altezza;
    perimetro= (base + altezza)*2;
    diagonale= sqrt(pow(altezza,2)+pow(altezza,2));
    printf("\nLa dimensione dell'area del rettangolo è: %f \t", area);
    printf("\nLa dimensione del perimetro del rettangolo è: %f \t", perimetro);
    printf("\nLa dimensione della diagonale è:  %f \t", diagonale);
    return;
}