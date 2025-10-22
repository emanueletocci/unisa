/* Questo programma utilizza il design pattern "accumulazione su sequenza senza memorizzazione con tappo" ed effettua la media dei numeri pari della sequenza */
#include <stdio.h>
#define c 0

int main(){
    int i, curr;            
    float media, acc;             //nacc sostituita dalla variabile i
    printf("Inserire un numero intero: \t");
    scanf ("%d",&curr);
    
    acc=0;
    i=0;
    while ((curr!=c)&&(curr>0)){
        if(curr%2==0){
            acc=acc+curr;
            i++;
        }
        printf("Inserire un numero intero: \t");
        scanf ("%d",&curr);
    }  
    media=acc/i;
    printf("La media della sequenza e\': \t %f",media);
}