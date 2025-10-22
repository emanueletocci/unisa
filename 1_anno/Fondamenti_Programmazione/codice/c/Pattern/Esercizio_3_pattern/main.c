#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void array_leggi(int vet[], int dim_log);
int cerca_somma (int p[], int n, int*valore);
int stampa_max(int p[], int n, int *pos_secondo);

int main()
{
    int vet[MAX];
    int dim, trovato, pos, val;
   
    printf("Inserisci la dim del vettore minore di: %d\n", MAX);
    scanf("%d", &dim);
    array_leggi(vet, dim);
    
    trovato = cerca_somma(vet, dim, &val);   
    
    if(trovato==1)
        printf("Il valore trovato uguale alla somma degli altri valori dell'array è %d \n", val);
    else
        printf("Nessun valore dell'array è uguale alla somma degli altri valori dell'array");
   
   val = stampa_max(vet, dim, &pos);   
     printf ("\nIl secondo valore massimo è : %d in posizione %d\n", val, pos);
    
return 0;

}

/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   interi diversi da 0; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione logica di vet (passata tramite il parametro dim_log).
*/

//pattern: lettura e memorizzazione sequenza di lunghezza nota con memorizzazione
void array_leggi(int vet[], int dim_log){
    int i;
    for (i=0;i<=dim_log-1;i++){
        do{
            printf("\n Inserire il %d elemento (diverso da 0) da memorizzare: \t",i+1);
            scanf ("%d",&vet[i]);
        }
        while (vet[i]==0);
    }
}


/* Il sottoprogramma dato in input un array di interi, 
verifica se c’è una cella il cui contenuto è uguale alla 
somma del contenuto di tutte le altre celle. 
 * Se ci sono più celle restituisce  la prima trovata 
 * attraverso la variabile val passata per rferimento.
*/

//pattern: selezione su sequenza di lunghezza nota 
int cerca_somma (int p[], int n, int*val){
    
    /*SEZIONE DICHIARATIVA*/
    int acc, flag, i, pos;
    
    /*SEZIONE DI INIZIALIZZAZIONE*/
    acc=0;
    flag=0;
    pos=0;
    
    
    /*SEZIONE ESECUTIVA*/
    printf ("\nVerifico presenza valore pari alla somma");
    for (i=0;i<=n-1;i++){
        acc=acc+p[i];           // Somma totale
        //printf ("\nLa somma di tutti gli elementi del vettori vale: \t %d",acc);        //test
    }
    
    for (i=0;((i<=n-1) && (flag==0));i++){
        if (p[i]==acc-p[i]){
            *val=p[i];
            pos=i;
            flag=1;
            //printf ("\n TROVATO!");                                                   //test
        }
    }
    return flag;
}

/* Il sottoprogramma dato in input un array di interi,
 stampare il valore del massimo valore contenuto nell’array e 
 restituisce in output il primo valore trovato che è il secondo valore più grande, 
 la cui posizione è passata per riferimento attraverso la variabile pos_secondo.
*/
int stampa_max(int p[], int n, int *pos_secondo){
    int flag, pos, i, max, max_secondo;
    
    /* Inizializzazione delle variabili*/
    
    flag = 0;
    pos=-1;
    *pos_secondo=-1;
    max = p[0];
    max_secondo = p[0];
    
    
    for (i=0; i<= n-1; i++){
        /*Ricerca del massimo all'interno della sequenza*/
        if (max<p[i]){
            max=p[i];
            pos = i;
            printf("\n max = %d", max); //test
        }
        /*Ricerca del secondo massimo nella sequenza*/
    }
    
    for (i=0 ; (i<= n-1); i++){
        if (i==pos)
            continue;
        if (max_secondo < p[i])
        {
                max_secondo=p[i];
                *pos_secondo=i;
                printf("\n max_secondo = %d", max_secondo); //test
        }  
    }
    printf ("\n Il massimo valore presente nella sequenza e\': \t %d e si trova in posizione %d", max, pos); 
    return max_secondo;
}