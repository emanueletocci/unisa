#include <stdio.h>
#define MAX 100

int array_leggi(int vet[]);
void array_visita(int vet[], int riemp);
int array_somma(int vet[], int riemp);
int array_minimo(int vet[], int riemp, int *min);

int main() {

    int vet[MAX];
    int i_min, riemp, somma, min;

    // Lettura del vettore
    riemp = array_leggi(vet);
    printf("La dimensione del vettore è: %d", riemp);

    // Visita (stampa il lettore letto)
    array_visita(vet, riemp);
    printf("Lettura dell'array completata.");

    // accumulazione (somma degli elementi del vettore)
    somma = array_somma(vet, riemp);
    printf("La somma degli elementi è: %d", somma);

    // selezione (restituisco l'indice del minimo e salva il minimo in min)
    i_min = array_minimo(vet, riemp, &min);
    printf("Il minimo tra gli elementi è: %d (indice: %d)", min, i_min);

    return 0;
}

int array_leggi (int vet[]){
    int i;  //contatore
    int riemp;  //Riempimento vettore

    //lettura coefficienti
    printf("numero elementi del vettore");
    scanf("%d",&riemp);

    //Generazione della sequenza

    for (i=0; i<riemp; i++){
        printf("Lettura dell' elemento di indice %d:",i);
        //aggiornamento vettore
        scanf("%d", &vet[i]);
    }
    return riemp;
}

//stampa il vettore letto
void array_visita(int vet[], int riemp){
    int i;
    for(i=0; i<riemp; i++){
        printf("vet[%d]= %d \n",i, vet[i]);
    }

}

int array_somma(int vet[], int riemp){
    int i;
    int acc;

    acc=0;
    for(i=0; i<riemp;i++)
        acc=acc+vet[i];
    return acc;
}

int array_minimo(int vet[], int riemp, int *min){
    int i;
    int pos;
    pos = 0;

    *min = vet[pos];
    for(i=0; i<riemp; i++){
        if (vet[i]< *min){
            *min = vet[i];
            pos = i;
        }
    }
    return pos;
}