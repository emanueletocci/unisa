/* Questo programma calcola la media dei numeri di una sequenza n, che occupano solamente i posti pari e siano maggiori di un valore v. Utilizza il pattern "Accumulazione su sequenza di lunghezza nota senza memorizzazione"*/

#include <stdio.h>
int main(){
    int curr, i, n, nacc, v;
    float media, acc;
    printf("Questo programma calcola la media dei numeri di posizione pari, minori di una certa soglia \"v\". \n Da quanti elementi é composta la sequenza? \t");
    scanf("%d",&n);
    printf("\n Inserire la soglia \" v \": \t");
    scanf("%d",&v);
    
    acc=0;  //accumulatore, somma i numeri di posizione pari
    nacc=0;  //contatore, memorizza il numero delle accumulazioni, usato per calcolare la media
    i=0; // contatore, memorizza le posizioni dei numeri della sequenza
    
    for(i=0;i<n;i++){
        printf("\nInserire %d numero della sequenza: \t",i);
        scanf("%d", &curr );
        if ((i%2==0)&&(curr>v)){
            acc=acc+curr;
            nacc++;
        }
        printf("\nIl valore acc: \t %f", acc);            //controllo valori acc
    }
    printf("\nIl valore nacc: \t %d", nacc);            //controllo valori nacc
    media= acc/nacc;
    printf("\nLa media dei numeri in posizione pari e\': \t %f", media);
            
    
}