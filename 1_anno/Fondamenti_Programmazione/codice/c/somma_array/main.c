#include <stdio.h>
#include <stdlib.h>
#define DIM 50

void leggi_array (int riempi, int v[]);
void somma (int riempi, int vet1[], int vet2[], int vet_somma[]);
void stampa_array (int vet_somma[], int riempi);

int main() {
    int vet1[DIM], vet2[DIM], vet_somma[DIM];
    int riempi;
    printf("Questo programma calcola la somma tra due vettori");
    printf("Da quanti elementi è composto il vettore? \n");
    scanf("%d", &riempi);
    printf("\n Riempio il primo array");
    leggi_array (riempi, vet1);
    printf("\n Riempio il secondo array");
    leggi_array (riempi, vet2);
    somma (riempi, vet1, vet2, vet_somma); 
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

void somma (int riempi, int vet1[], int vet2[], int vet_somma[]){
    int i;
    for (i=0; i<riempi; i++){
        printf("\n Elemento %d", i);
        vet_somma[i]=vet1[i]+vet2[i];
    }
    return;
}


void stampa_array (int vet_somma[], int riempi){
    int i;
    printf(" Stampo il vettore somma \n");
    for (i=0; i<riempi; i++)
        printf("Elemento %d: %d",i, vet_somma[i]);
    return;
}




