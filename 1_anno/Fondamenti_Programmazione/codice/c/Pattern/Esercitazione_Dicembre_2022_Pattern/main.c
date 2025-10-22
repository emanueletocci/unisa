#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

int array_leggi(int vet[], int dim_fis);
int distanza_L1 (int p[], int q[], int n);
void posizione_piu_vicino (int vet[], int riemp, int val, int *pos);

int main()
{
    int vet[MAX], vet2[MAX];
    int riemp1, riemp2, val, pos;
    int dist=0;

    printf("\n Riempio il primo vettore...");
    riemp1 = array_leggi(vet, MAX);
    printf("\nLa dimensione del vettore vet è: %d\n", riemp1);

    printf("\n Riempio il secondo vettore...");
    riemp2 = array_leggi(vet2, MAX);
    printf("\nLa dimensione del vettore vet2 è: %d\n", riemp2);

    if(riemp1==riemp2){
      dist = distanza_L1 (vet, vet2, riemp1);   
      printf("\nLa distanza di Manhattan è: %d\n", dist);
    }
    else
      printf("\n0Non è possibile calcolare la distanza di Manhattan\n");

    printf ("\nInserisci il valore da usare per trovare l'elemento più vicino: \t");
    scanf ("%d", &val);
    posizione_piu_vicino(vet, riemp1, val, &pos);
    printf("\nLa posizione nell'array vet dell'elemento che soddisfa la condizione è: \t %d", pos);

return 0;

}

/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   interi non negativi; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione fisica di vet (passata tramite il parametro dim_fis) oppure quando l'utente
   digita un valore negativo. Il sottoprogramma restituisce la dimensione logica di vet.
*/

//pattern lettura e memorizzazione su sequenza di lunghezza non nota con memorizzazione
    int array_leggi(int vet[], int dim_fis){
        int curr, riemp;
        riemp=0;
        printf ("\n Inserire il 1 valore della sequenza: \t");
        scanf ("%d",&curr);
        while (riemp != dim_fis && curr>0){
            vet[riemp]=curr;
            riemp++;
            printf ("\n Inserire il %d valore della sequenza: \t", riemp+1);
            scanf ("%d",&curr);
            printf ("curr= %d", curr);  //test
            if (riemp == dim_fis)
                printf ("\n É stata raggiunta la massima dimensione disponibile");
            else if (curr<0)
                printf ("\n Inserito numero negativo");
        }
        return riemp;  
}


/* Il sottoprogramma calcola la distanza L1 (distanza Manhattan) tra due punti p e q,
   definiti in uno spazio n-dimensionale, sulla base della seguente formula:
   
   d(p,q) = ( |p_0 - q_0| + |p_1 - q_1| + ... + |p_{n-1} - q_{n-1}| )

   Il sottoprogramma riceve come parametri gli array p e q, di pari dimensione
   logica passata tramite il parametro n; restituisce in output la distanza 
   calcolata.   
*/
    
    //pattern: accumulazione su sequenza di lunghezza noto con memorizzazione
int distanza_L1 (int p[], int q[], int n){
    int i, nacc;
    float acc;
    
    acc=0; //distanza "parziali"
    nacc = 0; //accumulazioni effettuate
    
    for (i=0;i<n;i++){
        acc = acc + (abs(p[i]-q[i]));
    }
    return acc;
}


/* Il sottoprogramma determina la posizione nell'array vet dell'elemento
   che soddisfa la seguente condizione:
        min={|vet[i] - val|}, per i = 0, 1, ..., riemp-1
   Il parametro riemp rappresenta la dimensione logica dell'array vet.
   Nel caso vi siano più elementi nell'array vet per i quali è soddisfatta la suddetta 
   condizione, il sottoprogramma restituisce l'elemento con indice di posizione minore.
   Al termine dell'esecuzione del sottoprogramma *pos contiene l'indice 
   della posizione trovata.
*/

//pattern: selezione su sequenza di lunghezza nota con memorizzazione

void posizione_piu_vicino(int vet[], int riemp, int val, int *pos){
    int i;
    bool flag = false;
    *pos = -1;
    
    for (i=0;i<riemp;i++){
        if (((*pos==-1)||(abs(vet[*pos]-val)) < (abs(vet[i]-val)))){
            *pos = i;
            flag = true;   
        }       
    }
}
