/*Realizzare un programma che legge in input un insieme di valori interi e ne calcola la somma. Si termina quando si legge un valore ==0
 Pattern: Accumulazione su sequenza senza memorizzazione*/

#include <stdio.h>
#define C 0
int main(){
    int curr, i, acc, nacc;
    acc=0;  //somma dei valori
    i=1; //numero di accumulazioni effettuate
    printf("Inserire un numero: \t");
    scanf("%d",&curr);
    while (curr!=C){
        acc=acc+curr;
        i++;
        printf("Inserire un numero: \t");
        scanf("%d",&curr);
    }
    printf("La somma dei numeri inseriti e\': \t %d", acc);
}