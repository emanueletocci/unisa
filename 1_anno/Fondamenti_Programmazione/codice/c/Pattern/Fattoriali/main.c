/* Realizza un programma che genera la sequenza dei fattoriali dei primi n numeri naturali, partendo dal primo elemento noto della sequenza generare 1!=1.
    Si ricorda che n!=n(n-1)!*/

#include <stdio.h>
#include <stdlib.h>
void fattoriale (int n);
int main (){
    int n;
    printf("Questo programma calcola la sequenza dei fattoriali dei primi n numeri naturali\n");
    printf("Quanti fattoriali si vogliono calcolare? \t");
    scanf ("%d", &n);
    fattoriale(n);
    
}


void fattoriale (int n){
    int i, curr, prec;
    curr=1;
    printf("0! \t = \t %d \n",curr);
    prec=curr;
    //calcolo sequenza fattoriali da 1 a n
    for(i=1;i<=n; i++){
        curr= i*prec;
        printf("%d! \t = \t %d \n",i, curr);
        prec=curr;
    }
    return;
}