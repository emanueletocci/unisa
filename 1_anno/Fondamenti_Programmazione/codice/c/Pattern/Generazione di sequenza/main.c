/* Scrivere un programma che, chiesto all’utente di inserire un numero n > 1 (se così non fosse
richiede all’utente la frazione finchè non venga rispettato il vincolo), generi una sequenza di
lunghezza n di numeri naturali positivi e calcoli la somma dei valori pari inferiori a una soglia T.*/

#include <stdio.h>

void generazione (int n);
int main (){
    int n;
    do{
        printf("Quando deve essere lunga la sequenza generata? \n");
        scanf ("%d",&n);
        if (n<1)
            printf("ERRORE! Il numero inserito é minore di 1 \n");
    }
    while (n<1);
    generazione (n);
}

void generazione (int n){
    int i, curr, prec, somma, T;
    printf("Inserire il valore di soglia T \n");
    scanf("%d",&T);
    curr=0;
    somma=0;
    prec=curr;
    for (i=1; i<=n; i++){
        curr = i+prec;                  //generazione sequenza
        printf("%d\t", curr);
        prec=curr;
        if(((curr%2)==0)&&(curr<T))   
            somma=somma+curr;           //Aggiornamento accumulatore
    }
    printf("\nLa somma dei valori pari, minori di %d, e\': \t %d", T, somma);
    
}

