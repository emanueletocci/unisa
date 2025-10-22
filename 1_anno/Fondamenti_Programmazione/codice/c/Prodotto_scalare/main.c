#include <stdio.h>
#include <stdlib.h>
#define DIM 50

void leggi_array (int riempi, int v[]);
float prodotto_scalare (float a[], float b[], float riempi);

int main() {
    int vet1[DIM], vet2[DIM], vet_somma[DIM];
    int riempi;
    printf("Questo programma calcola il prodotto scalare fra due vettori \n Da quanti elementi è composto il vettore? \n");
    scanf("%d", &riempi);
    printf("\n Riempio il primo array");
    leggi_array (riempi, vet1);
    printf("\n Riempio il secondo array");
    leggi_array (riempi, vet2);
    prodotto_scalare (riempi, vet1, vet2, vet_somma); 
    stampa_array (vet_somma, riempi);
    return 0;
}

void leggi_array (int riempi, int v[]){
    int i;
    for (i=0; i<riempi; i++){
        printf("\n Elemento %d \t", i);
        scanf("%d", &v[i]);
    }
    return;
}

