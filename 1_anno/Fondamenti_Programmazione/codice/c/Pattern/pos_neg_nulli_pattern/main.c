/*• Si scriva un programma in linguaggio C dati N numeri interi letti da tastiera calcolare quanti sono i 
numeri: positivi, nulli, negativi.

Nota: il valore di N è inserito da tastiera. 
*/

//pattern: accumulazione su sequenza di lunghezza nota senza memorizzazione 

#include <stdio.h>

int main(){
    int curr, i, n, nacc_p, nacc_n, nacc_z;
    printf("Da quanti numeri é composta la sequenza? \t");
    scanf("%d",&n);                         //lettura del coefficiente n
    nacc_p=0;                                 //inizializzazione contatore positivi
    nacc_n=0;                                 //inizializzazione contatore negativi
    nacc_z=0;                                 //inizializzazione contatore nulli
    
    for(i=0;i<n;i++){ 
        printf("\nInserire un numero: \t");
        scanf("%d",&curr);                      // lettura del valore corrente
        if(curr>0)
            nacc_p++;
        else if(curr==0)
            nacc_z++;
        else
            nacc_n++;   
    }
    
    printf("\n Numeri positivi: \t %d \n Numeri Nulli: \t %d \n Numeri Negativi: \t %d", nacc_p, nacc_z, nacc_n);
    
}