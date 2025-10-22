#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int array_leggi(int vet[], int dim_fis);
int array_verifica_ordinato (int vet[], int r);
int array_cerca_multipli(int vet[], int r, int *x, int *conta);

int main()
{
    int vet[MAX];
    int riemp, x, n, conta=0;

    riemp = array_leggi(vet, MAX);
    printf("la dimensione del vettore è: %d\n", riemp);
    
    n = array_verifica_ordinato (vet, riemp);
    if(n<0)
        printf("Il vettore è ordinato in maniera crescente.\n");
    else
    	  printf("Il vettore non è ordinato in maniera crescente.\n");

    if (array_cerca_multipli(vet, riemp, &x, &conta))
        printf("\nIl numero di multipli di %d è: %d", x, conta);
    else 
        printf("\nNon ci sono multipli di %d", x);
}


/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   interi non negativi; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione fisica di vet oppure quando viene inserito il valore 999. 
   Il sottoprogramma restituisce la dimensione logica di vet.*/

//pattern: lettura e memorizzazione con tappo
int array_leggi(int vet[],  int dim_fis){
    int curr, riemp;

    riemp=0;

    do { 
        printf("\n Inserire il %d elemento (positivo) della sequenza o 999 per uscire : \t" , riemp+1);
        scanf ("%d",&curr);
        if (curr<0){ 
            printf ("\n É stato inserito un numero negativo, la sequenza deve essere composta da soli positivi.");
        }
    }
    while (curr<0);

    while ((curr!=999) && (riemp<dim_fis)){
        vet[riemp]=curr;
        riemp++;

        do { 
            printf("\n Inserire il %d elemento della sequenza: \t" , riemp+1);
            scanf ("%d",&curr);
            if (curr<0){ 
                printf ("\n É stato inserito un numero negativo, la sequenza deve essere composta da soli positivi.");
            }
        }
        while (curr<0);
    }

    return riemp;
}

/* Si chiede d'implementare un sottoprogramma che partendo da una sequenza memorizzata 
all'interno di un array vet e la sua dimensione logica specificata attraverso il parametro r
verifica che l'array sia ordinato in maniera crescente.
Il sottoprogramma restisce un valore negativo se l'array è ordinato in maniera crescente.
*/

//pattern: visita di sequenza
int array_verifica_ordinato (int vet[], int r){
    int i, flag;
    flag = 0;

    for (i=0;(i<=r-1)&&(flag!=1);i++){
        if ((vet[i]<vet[i+1])&&vet[i+1]<=r){
            flag = -1;
        }
        else
            flag = 1;
    }
        return flag;
    }

/*Il sottoprogramma chiede all’utente di inserire un numero (x) compreso tra 1-100 
e ricerca i multipli di tale numero nel vettore. Per ogni occorrenza stampa la posizione 
in cui è stato trovato e conta il numero di elementi trovati (conta).
Il sottoprogramma restituisce 1 se ha trovato almeno un elemento, 0 altrimenti*/

//pattern: selezione + accumulazione

int array_cerca_multipli (int vet[], int r, int *val, int *conta){
    int i, flag, pos;
    
    flag = 0;
    pos = 0;

    do{
        printf("\n Inserire un valore x compreso tra 1 e 100 di cui ricercare un multiplo nella sequenza: \t");
        scanf ("%d",&*val);
        if (*val<1 || *val>100)
            printf ("\n É stato inserito un numero al di fuori del range richiesto");
    }
    while (*val<1 || *val>100);

    for (i=0;i<=r-1;i++){
        if (vet[i]%*val==0){
            flag =1;
            pos = i;
            printf ("\n É stato trovato un multiplo in posizione %d", pos);
            *conta=*conta+1;
            //printf ("\nconta = %d", *conta);     //test
        }
    }
    return flag;

}
