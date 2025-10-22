/* Questo programma utilizza il design pattern "accumulazione su sequenza senza memorizzazione con tappo" per effettuare la media di n numeri */

#include <stdio.h>
#define c 0

int main(){
    int i;            
    float curr, media, acc;             //nacc sostituita dalla variabile i
    printf("Inserire un numero: \t");
    scanf ("%f",&curr);
    
    acc=0;
    i=1;
    while ((curr!=c)&&(curr>0)){
        acc=acc+curr;
        i++;
        printf("Inserire un numero: \t");
        scanf ("%f",&curr);
    }  
    media=acc/i;
    printf("La media della sequenza e\': \t %f",media);
}