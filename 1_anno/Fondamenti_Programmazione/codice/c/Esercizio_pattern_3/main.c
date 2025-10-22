#include <stdio.h>
#include <stdbool.h>

void leggi_e_stampa_sequenza_numeri_pos_maggiori_di_x(int x, int n);
int leggi_e_stampa_quanti_multipli_di_x(int terminatore, int x);
int ultimo_negativo_pari(int n, int *sel, int *pos);

int main()
{
    int t, lungh, p;
    int s, x;           

    printf("Lettura e stampa a video di una sequenza di numeri positivi maggiori di x\n");
    printf("Digitare di seguito il numero x e la lunghezza lungh: ");       //x=curr 
    scanf("%d %d", &x, &lungh);
    leggi_e_stampa_sequenza_numeri_pos_maggiori_di_x(x, lungh);

    printf("\nDigitare di seguito il numero per terminare la sequenza: ");
    scanf("%d", &t);
    printf("\nLettura e stampa quanti numeri sono multipli di x\n");
    printf("\n I numeri maggiori di %d sono: \t %d\n",t, leggi_e_stampa_quanti_multipli_di_x(t, x));

    printf("Cerca l'ultimo elemento negativo pari della sequenza \n");
    
    if(ultimo_negativo_pari(lungh, &s, &p)){
        printf("ultimo negativo della sequenza: %d\n", s);
        printf("Posizione dell'elemento trovato: %d\n", p);
    }else{
        printf("Nessun elemento trovato\n");
    }
    return 0;
}


/*  Il sottoprogramma genera e visualizza sullo standard output (sul monitor)
    la sequenza di numeri interi di lunghezza nota 
    maggiore di x passato come parametro insieme alla lunghezza.
*/
void leggi_e_stampa_sequenza_numeri_pos_maggiori_di_x(int x, int n){
    int curr;
    int i;
    for(i=1; i<=n; i++){      
        printf("Inserisci il prossimo numero\n ");
        scanf("%d", &curr);
        if(curr>x){
            printf("%d è maggiore di %d\n", curr,x);      
        } 
    }
}   



/*  Il sottoprogramma calcola e restuisce come output il numero
    di elementi di una sequenza di numeri positivi di lunghezza non nota
    che sono multipli di x passato come parametro, insieme al carattere terminatore.
*/
int leggi_e_stampa_quanti_multipli_di_x(int terminatore, int x){
    int nacc, curr;
    nacc=0;      //contatore 

    printf("\nInserire un valore maggiore di %d : \t",x);
    scanf("%d",&curr);

    while (curr!=terminatore){
        if(curr%x == 0){
            nacc++;
            printf("nacc= \t %d",nacc);
        }
    printf("\nInserire un valore maggiore di %d : \t",x);
    scanf("%d",&curr);

    }
    return nacc;
}


/* Il sottoprogramma seleziona l'ultimo elemento negativo pari in una sequenza
   di numeri interi di lunghezza nota passato come parametro.
   L'ultimo elemento negativo pari (denominato sel) e la sua posizione nella sequenza (denominata pos) sono passati
   come parametri al sottoprogramma. Il programma restituisce 1 se è presente 
   almeno un elemento negativo pari, altrimenti 0.
   
*/
int ultimo_negativo_pari(int n, int *sel, int *pos){
    int curr, i, flag;
    *sel = 0;
    flag=0;
    *pos=0;
    for (i=1;i<=n;i++){
        printf("\n Inserire valore corrente: \t");
        scanf("%d",&curr);
        if((curr < 0 ) && (curr % 2 == 0)){
            *sel=curr;
            *pos=i;
            flag=1;
        }
    }
    return flag;
}