#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void riempimento (int *vet, int dim){
    for (int i = 0 ; i < dim ; i++){
        printf("\nInserire elemento %d: \t", i);
        scanf("%d", (vet+i));
    }
}

void stampa (int *vet, int dim){
    printf("\nStampo il vettore inizializzato: \n");
    for (int i=0; i<dim ; i++){
        printf("%d \t", vet[i]);
    }
}

int sommaDispari(int *vet, int dim, int pos) {
    if (pos >= dim)
        return 0;
    else return vet[pos] + sommaDispari(vet, dim, pos+2);

}

int minimo (int *vet, int dim, int min) {
    if (dim == 1)
        return min;
    else if (vet[dim - 1] <= min) {
        min = vet[dim - 1];
    }
    return minimo(vet, dim - 1, min);
}
int tuttiMaggioriDi(int *vet, int dim, int k){
    if (dim == 1) {
        if (vet[dim-1] >= k)
            return 1;               //TRUE
        else if (vet[dim-1] < k)
            return 0;               //FALSE
    }
    else
        tuttiMaggioriDi(vet, dim-1, k);
}

int main() {
    int dim, *vet, k;
    printf("Quanti elementi si vogliono inserire nel vettore?\t");
    scanf("%d", &dim);
    vet = malloc(dim*sizeof(int));
    assert (vet!= NULL);
    riempimento(vet,dim);
    stampa(vet, dim);
    printf("\nLa somma degli elementi in posizione dispari e': %d", sommaDispari(vet, dim, 1));
    printf("\nIl valore minimo all'interno del vettore e' : %d", minimo(vet, dim, vet[0]));
    printf("\nInserire un numero per verificare se gli elementi del vettore sono maggiori di esso: \t ");
    scanf("%d", &k);
    if (tuttiMaggioriDi(vet, dim, k) == 1)
        printf("\nTRUE, tutti gli elementi del vettore sono maggiori del numero inserito");
    else if (tuttiMaggioriDi(vet, dim, k) == 0)
        printf("\nFALSE, non tutti gli elementi del vettore sono maggiori del numero inserito");
    free(vet);
    return 0;
}
