#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int array_leggi(int vet[], int dim_fis);
int trova_ricorrenze_massimo (int vet[], int n, int * pos, int *conta_max);
void somma_array (int a1[], int a2[], int a3[], int n, int val);

int main()
{
    int vet[MAX], vet2[MAX], vet3[MAX];
    int riemp1, riemp2, conta_max, max, val, pos;

    riemp1 = array_leggi(vet, MAX);
    printf("La dimensione del vettore vet è: %d\n", riemp1);
    max = trova_ricorrenze_massimo (vet, riemp1, &pos, &conta_max);
    printf("Il massimo %d nel vettore si trova nella posizione %d e il numero di occorrenze è: %d\n ", max, pos, conta_max);

    riemp2 = array_leggi(vet2, MAX);
    printf("La dimensione del vettore vet2 è: %d\n", riemp2);

    printf ("Inserisci un valore necessario per la ricerca nel vettore:");
    scanf ("%d", &val);

    if(val>=0){
      somma_array (vet, vet2, vet3, riemp1, val);
    }
    else
      printf("Il valore inserito non è corretto\n");

return 0;

}

/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   reali diversi da zero; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione fisica di vet (passata tramite il parametro dim_fis) oppure quando la 
   somma dei numeri immessi è maggiore di 50. Il sottoprogramma restituisce la dimensione logica di vet.

*/
int array_leggi(int vet[], int dim_fis){
  int curr, riemp, acc;
  
  riemp = 0;
  acc = 0;
  
  printf("\n Inserire il %d valore: \t",riemp+1);
  scanf ("%d",&curr);
  
  while (riemp<dim_fis && acc < 50){
      vet[riemp]=curr;
      acc=acc+curr;
      //printf ("\n acc= %d ", acc);  //test
      riemp++;
      printf("\n Inserire il %d valore \t",riemp+1);
      scanf("%d",&curr); 


  }
  return riemp;
}


/* 

Il sottoprogramma calcola il massimo di un vettore e conta 
quante volte è contenuto tale valore nel vettore. Il sottoprogramma restituisce l'elemento massimo. 
Al termine dell'esecuzione del sottoprogramma *conta_max contiene le occorrenze del valore massimo, 
e *pos contiene la posizione del massimo nel vettore.

N.B.= La variabile conta la faremo incrementare di 1 se trova lo stesso valore, 
mentre la inizializziamo a zero se trova un nuovo massimo.

*/
int trova_ricorrenze_massimo (int vet[], int n, int *pos, int *conta_max){
    int i, flag, max;
    
    flag=0;
    *pos=0;
    *conta_max=1;
    max = vet[0];
    
    for (i=0; i<=n-1; i++){     /*Ricerca massimo */
        if (vet[i]> max){
            max=vet[i];
            *pos=i;
            flag=1;
            if (max == vet[i])
                *conta_max++; 
        }
    }
        return max;
    }



/* Il sottoprogramma prende in ingresso tre array a1, a2, a3. La funzione,
per ogni posizione i calcola la somma tra a1[i] e a2[i] e se il risultato è maggiore di val 
(passato come parametro al sottoprogramma) salva il risultato in a3[i], altrimenti mette un valore negativo.

*/

void somma_array (int a1[], int a2[], int a3[], int n, int val){
    int i, somma;

    /*Riempimento primop vettore*/
    printf ("\n Riempio il primo vettore");
    for (i=0; i<=n-1; i++){
        printf ("\n Inserire il %d elemento del 1 vettore: \t", i+1);
        scanf("%d", &a1[i]); 
    }
  
    /*Riempimento secondo vettore*/
    printf ("\n Riempio il primo vettore");
    for (i=0; i<=n-1; i++){
        printf ("\n Inserire il %d elemento del 2 vettore: \t", i+1);
        scanf("%d", &a1[i]);    
    }
    
    for (i=0; i<=n-1; i++){
        somma = a1[i]+a2[i];
        
        if(somma>val){
            a3[i]=somma;
        }
        else{
            a3[i]=-1;
        }
    }
}
