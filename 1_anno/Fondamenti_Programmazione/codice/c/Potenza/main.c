/*
Esercizio 1
Dati due numeri interi N1 e N2, scrivere una funzione che restituisca il risultato di N1^N2;
Scrivere un adeguato main di prova.
Si ricorda che se N2=0 allora N1^N2=1 e se N2<0 allora N1^N2=(1/N1)
-N2
.

La funzione potenza(..)
• prende in ingresso due valori interi
• restituisce in uscita un valore reale.
Il passaggio di entrambi i parametri è per valore perché non devono essere modificati
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float potenza (float N1, float N2);

int main() {
    float N1, N2, R;
    printf ("Inserire valore base ed esponente: \t");
    scanf ("%f %f", &N1,&N2);
    R = potenza (N1, N2);
    printf ("\n Il valore di %.2f ^ %.2f e\' %f", N1, N2, R);
    return 0;

}

float potenza (float N1, float N2){
    double R;
    if (N2==0)
        R = 1;
    else if (N2<0)
        R= pow (1/N1, N2);
    else
        R = pow (N1,N2);
    return R;
}
