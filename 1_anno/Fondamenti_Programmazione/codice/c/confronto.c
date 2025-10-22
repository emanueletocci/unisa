#include <stdio.h>
int main(){
    int x, y, temp;
    printf("Questo programma effettua il confronto fra due numeri. Se il primo numero è minore del secondo i numeri vengono scambiati \n");
    printf("Inserire due valori interi: \t");
    scanf("%d %d", &x, &y);
    if (x<=y){
        temp=x;
        x=y;
        y=temp;
    }
    printf("il valore del primo numero è: \t %d \n Il valore del secondo numero è: \t %d", x, y);   
}