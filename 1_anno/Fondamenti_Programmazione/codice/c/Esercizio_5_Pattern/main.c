#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int array_leggi(int vet[], int dim_fis);
int conta_in_intervallo (int vett[], int r, int min, int max);
int array_cerca(int vett[], int r, int *x, int *conta);

int main()
{
    int vet[MAX];
    int i_min, riemp, somma, min, max, x, n, conta=0;

    n=-1;
    riemp = array_leggi(vet, MAX);
    printf("la dimensione del vettore è: %d\n", riemp);
       
    while(n<0){
        printf("Inserisci i valori dell'intervallo [min, max]\n");
        printf("min= ");
        scanf("%d", &min);
        printf("max= ");
        scanf("%d", &max);
        n = conta_in_intervallo (vet, riemp, min, max);
        printf("n: %d\n", n);
        if(n<0)
            printf("gli intervalli non sono corretti\n");
    }
    printf("il numero di elementi appartenenti all'intervallo sono: %d\n", n);
    if (array_cerca(vet, riemp, &x, &conta))
        printf("il numero di elementi uguali a %d è: %d", x, conta);
    else 
        printf("Non ci sono  elementi uguali a %d", x);
}


/* si chiede all'utente di inserire il numero di elementi del vettore vet e 
poi di memorizzare i suoi elementi.
Il sottoprogramma restituisce la dimensione del vettore*/
int array_leggi(int vet[],  int dim_fis){
    int i, dim_logica;
    printf ("\n Da quanti elementi e\' composta la sequenza? \t");
    scanf("%d",&dim_logica);
    for (i=0;i<dim_logica;i++){
        printf("\nLettura elemento di indice %d: \t", i);
        scanf("%d",&vet[i]);
    }
    return dim_logica;
}

/* Si chiede d'implementare un sottoprogramma che partendo da una sequenza memorizzata 
all'interno di un array vett e la sua dimensione logica specificata attraverso il parametro r
sia in grado di restuire il numero di elementi nel vettore 
che si trovano nell'intervallo [min, max] (min e max compresi).
Il sottoprogramma restisce un valore negativo se il valore di min è maggiore del valore di max.
*/
int conta_in_intervallo (int vett[], int r, int min, int max){
    int i;
    float nacc;
    
    for(i=0; i<=r; i++){
        if((vett[i]<=max)&&(vett[i]>=min)){
            nacc++;
        }
    }
 }

/*Il sottoprogramma chiede all’utente di inserire un numero (x) compreso tra 1-100 
e ricerca tale numero nel vettore. Per ogni occorrenza stampa la posizione 
in cui è stato trovato e conta il numero di elementi trovati (conta) .
Il sottoprogramma restituisce 1 se ha trovato almeno un elemento, 0 altrimenti*/
int array_cerca(int vett[], int r, int *val, int *conta){
    int i, flag, pos;
    flag=0;
    pos=0;
    
    printf("\n Inserire un valore compreso tra 1 e 100 da ricercare nel vettore: \t");
    scanf("%d",&*val);
    
    for(i=0;i<r;i++){
        if(vett[i]==*val){
            pos=i;
            flag=1;
            *conta++;
        }
    }
    return flag;
    
}

