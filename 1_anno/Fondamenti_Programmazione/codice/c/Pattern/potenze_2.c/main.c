/*
Generazione della sequenza di potenze successive di 2 fino al valore massimo max inserito dall'utente

*/
#include <stdio.h>
void potenze(int max);

int main(){
    int max;
    printf("Inserire il valore massimo \t \n");
    scanf("%d", &max);
    potenze (max);

}

void potenze(int max){
    int potenza, potenza_precedente, k;
    potenza =1;
    potenza_precedente= potenza;
    k=1;
    while (2*potenza <max){
        potenza=2*potenza_precedente;
        printf("2^%d = %d \n", k, potenza);
        potenza_precedente=potenza;
        k++;

    }
}