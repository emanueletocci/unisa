#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int array_leggi(int vet[], int dim_fis);
int rip_max (int p[], int n, int* v);
void stampa_una_volta (int vet[], int n);

int main()
{
    int vet[MAX];
    int riemp1, val, quant;
    int dist=0;

    riemp1 = array_leggi(vet, MAX);
    printf("La dimensione del vettore vet è: %d\n", riemp1);

    val = rip_max(vet, riemp1, &quant);   
      printf("Il primo numero intero che compaie più volte per %d volte, è: %d\n", quant, val);

    printf ("Gli elementi che appaiono una volta nell'array sono:\n");
    stampa_una_volta(vet, riemp1);

return 0;

}

/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   interi diversi da 0; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione fisica di vet (passata tramite il parametro dim_fis) oppure quando l'utente
   digita il valore 0. Il sottoprogramma restituisce la dimensione logica di vet.
*/
int array_leggi(int vet[], int dim_fis){
    int curr, riemp;
    
    /* Inzizializzazione */
    riemp =0;
    
    /*Parte Esecutiva*/
    printf ("\nInserire il %d elemento della sequenza o 0 per uscire: \t ", riemp+1);
    scanf("%d",&curr);
    if (curr == 0)
        printf ("\nÉ stato inserito 0... sequenza nulla");
    while (riemp<= dim_fis && curr != 0){
        vet[riemp]=curr;  
        riemp++;
        printf ("\nInserire il %d elemento della sequenza o 0 per uscire: \t ", riemp+1);
        scanf("%d",&curr);
    }
    return riemp;
}


/* Il sottoprogramma dato in input un array di interi, 
stampa il numero che compare più volte all’interno dell’array, 
qualora ci siano più numeri che compaiano lo stesso numero di volte 
restituisce in output quello che compare per primo.
*/
int rip_max (int p[], int n, int* v){
    int i, j, flag, pos, nacc;
    
    // Inizializzazione
    
    flag = 0;
    pos = 0;
    nacc=0;
    
    /*Fase Esecutiva*/
    
    for (i=0; i<=n-1;i++){
        for (j=0;j<=n-1; j++){
            if (p[i]==p[j])
                nacc++;      
        }
    }
    return nacc;
}

/* Il sottoprogramma dato in input un array di interi,
stampa solo i numeri che appaiono nell’array 
una volta soltanto.
*/
void stampa_una_volta(int p[], int n){
  printf("ERRORE! sottoprogramma non ancora implementato\n");
}