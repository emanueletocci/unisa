#include <stdio.h>
#include <stdlib.h>
/*Scrivere una funzione ricorsiva che calcoli il MCD tra due numeri*/

int mcd(int x, int y){
    if (y == 0)
        return x;
    else {
        return mcd(y, x%y);
    }
}

int prodotto(int x, int y){
    if (x == 1 || y == 1)
        return x + y - 1;
    else{
        return y + prodotto(x-1, y);
    }
}

int main() {
    int x,y;
    printf("Questo programma calcola il MCD e il prodotto tra 2 numeri. \n Inserire numero 1: \t");
    scanf("%d",&x);
    printf("\nInserire il numero 2: \t");
    scanf("%d",&y);

    printf("\nMCD= \t %d" ,mcd(x,y));
    printf("\nx*y= \t %d" ,prodotto(x,y));
    return 0;
}
