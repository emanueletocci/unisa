#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void leggi_e_stampa_valore_assoluto_sequenza_con_terminazione(int terminatore);
void leggi_e_stampa_il_quadrato_perfetto_lunghezza_nota(int lunghezza);
double media_elementi_positivi_sequenza(int lunghezza);
bool minimo_sequenza_numeri_naturali_con_terminatore(int terminatore, int *sel, int *pos);

int main()
{
    int t, lungh, p;
    int s;
    printf("Lettura e stampa a video i valori assoluti di numeri interi\n Inserire terminatore: \t");    
    scanf("%d", &t);                                                                //lettura del tappo
    leggi_e_stampa_valore_assoluto_sequenza_con_terminazione(t);

    printf("\nLettura e stampa a video dei quadrati perfetti\n");
    printf("Digitare di seguito la lunghezza della sequenza: ");
    scanf("%d", &lungh);
    leggi_e_stampa_il_quadrato_perfetto_lunghezza_nota(lungh);

    printf("Calcolo del valor medio del quandrato dei numeri di una sequenza, considerando solo gli elementi positivi multipli di 5\n");
    printf("Il valor medio e': %lf\n", media_elementi_positivi_sequenza(lungh) );
  
    printf("Ricerca del minimo in una sequenza di numeri naturali\n");
    printf("Digitare il terminatore della sequenza: ");
    scanf("%d", &t);
    if(minimo_sequenza_numeri_naturali_con_terminatore(t, &s, &p)){
        printf("Elemento minimo della sequenza: %d\n", s);
        printf("Posizione dell'elemento trovato: %d\n", p);
    }else{
        printf("Nessun elemento trovato\n");
    }
    return 0;
}

/*  Il sottoprogramma genera e visualizza sullo standard output (sul monitor)
    il valore assoluto della sequenza di numeri interi di lunghezza non nota 
    che termina con un tappo passato come parametro.
*/

void leggi_e_stampa_valore_assoluto_sequenza_con_terminazione(int terminatore){
    int curr, k=1;
    printf("\nInserire 1 numero o premere %d per terminare: \t", terminatore);
    scanf ("%d", &curr);
    while (curr!=terminatore){
        if (curr<0)
            printf("|%d|= \t %d", curr, curr*(-1));
        else
            printf("|%d|= \t %d", curr, curr);
        k++;
        printf("\nInserire %d numero o premere %d per terminare: \t", k, terminatore);
        scanf ("%d", &curr);
    }
}

/*  Il sottoprogramma genera e visualizza sullo standard output (sul monitor)
    i quadrati perfetti della sequenza di numeri interi di lunghezza nota 
    il cui valore è passato come parametro.
*/

void leggi_e_stampa_il_quadrato_perfetto_lunghezza_nota(int lunghezza){
    int curr;
    
    
    

    
}

/*  Il sottoprogramma calcola e restuisce come output 
    la media del quadrato di una sequenza di lunghezza nota, 
    di numeri positivi che sono multipli di 5.
*/

//pattern accumulazione su sequenza di lunghezza nota senza memorizzazione

double media_elementi_positivi_sequenza(int n){
    int curr, i, nacc;
    float acc;
    
    acc=0;
    nacc=0;
    
    for(i=1;i<=n;i++){
        printf("\n Inserire il %d numero: \t",i);
        scanf ("%d",&curr);
        if (curr%5==0){
            acc=acc+curr*curr;
            nacc++;
        }
    }
    acc=acc/nacc;
    return acc;

}


/* Il sottoprogramma seleziona il minimo valore in una sequenza
   di numeri interi naturali di lunghezza non nota che termina con un tappo passato come parametro.
   Il minimo (denominato sel) e la sua posizione nella sequenza (denominata pos) 
   sono restituiti dal sottoprogramma. Il programma restituisce true se è presente un valore minimo, 
   altrimenti false.
   
*/
bool minimo_sequenza_numeri_naturali_con_terminatore(int terminatore, int *sel, int *pos){
    bool flag;
    int curr, i;
    
    printf("\n Inserire il 1 numero: \t");
    scanf ("%d",&curr);
    flag = false;
    *pos=0;
    *sel=999999;
    i=1;
    
    while (curr != terminatore && curr>=0){
        if (curr<*sel){
            *sel=curr;
            *pos=i;
            flag=true;
            printf ("\n Minimo locale trovato!");
  
        }
        i++;
        printf("\n Inserire il %d numero: \t",i);
        scanf ("%d",&curr);
    }
    return flag;

}