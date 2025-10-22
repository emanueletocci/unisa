#include <stdio.h>
int main(){
    int x, y,z, max;
    printf("Questo programma \n");
    printf("Inserire tre numeri: \t");
    scanf("%d %d %d", &x, &y, &z);
    if (x>y)
        max= x;
    else 
        max= y;
    if (max<z)
        max=z;
    printf(" \nIl valore massimo è: %d \t", max);

}
