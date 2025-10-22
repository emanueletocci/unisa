#include <stdio.h>
#include <math.h>

int main (){
    int N, i, NUM, somma=0;
    printf("\nSu quanti bit deve essere effettuata la conversione? \t");
    scanf("%d", &N);
    int binario [N], decimale [N];

    for (i=0; i<N; i++){
        do{
            printf("\nInserire la cifra %d: \t", i);
            scanf("%d", &NUM);
            if ((NUM!=0)&&(NUM!=1))
                printf("\nE' stato inserito un valore non valido ");
        }
        while ((NUM!=0)&&(NUM!=1));
        binario[i]= NUM;
        decimale [i]= (NUM* pow(2, i));
        somma=somma+decimale[i];

    }
    printf ("\nIl numero convertito in decimale è: \t %d", somma);
}