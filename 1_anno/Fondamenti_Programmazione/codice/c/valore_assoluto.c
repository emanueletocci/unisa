#include <stdio.h>
int main (){
    printf("Questo programma calcola il valore assoluto \n");
    float x, modulo;
    printf("Inserire il primo numero: \t");
    scanf("%f", &x);
    if(x>=0)
        modulo=x;
    else
        modulo=-x;
    printf("\n Il valore assoluto del numero %f è \t %f", x, modulo);

}
