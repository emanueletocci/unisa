/* Visita senza memorizzazione di una sequenza che termina con un tappo C*/

#include <stdio.h>
#define C -1

int main (){
    int curr;   //valore corrente della sequenza
    printf("Inserire valore corrente \n");
    scanf("%d",&curr);
    
    while(curr!=C){
        printf("%d", curr);
        printf("\nInserire valore corrente \n");
        scanf("%d",&curr);
    }
    return 0;
}