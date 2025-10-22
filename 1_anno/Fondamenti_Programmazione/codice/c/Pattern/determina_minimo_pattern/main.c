/* Leggere da input un insieme di numeri interi >= 0 e procedere con la lettura finché la somma degli
elementi sia minore o uguale di un valore soglia T.
Non si conosce in anticipo la quantità di valori da leggere; il valore di T è fornito in ingresso prima
della sequenza di valori.*/

//pattern: accumulazione su sequenza senza memorizzazione con tappo

#include <stdio.h>
int main(){
    int curr, i, T;
    float acc;
    acc=0; //somme
    i=1; //conteggio numero di accumulazioni, sostituisce nacc
    
    printf("Questo programma legge da input un insieme di numeri positivi e ne effettua la somma fino ad una soglia T inserita dall'utente. \n Inserire soglia limite: \t");
    scanf("%d", &T);
    printf("\nInserire valore corrente (positivo): \t");
    scanf("%d", &curr);
    while ((curr!=T)&&(acc<=T)){
        acc=acc+curr;       //somma dei valori
        //printf("\n La somma parziale vale: \t %f \n i= %d", acc,i);   verifica
        i++;                 //conteggio accumulazioni
        printf("\nInserire valore corrente (positivo): \t");
        scanf("%d", &curr);
    }
    printf("\nLa somma é pari a: \t %f", acc);
    
}