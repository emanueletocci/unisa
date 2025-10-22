#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fill (int *vet, int dim){
    for (int i=0; i<dim ; i++){
        printf("\n Inserire il %d numero: \t", i+1);
        scanf("%d", (vet+i));
    }
}

int search_min (int *vet, int dim, int min_index) {
    if (dim == 0)
        return min_index;
    if (vet[dim-1]<=vet[min_index])
        min_index = dim -1;
    return search_min(vet, dim-1, min_index);
}

int main() {
    int dim, *vet, min_index;
    printf("Questo programma ricerca il minimo all' interno di un insieme di numeri. \n Quanti numeri si vogliono inserire? \t");
    scanf("%d", &dim);
    dim = abs(dim);             //Converto il numero in positivo per evitare problemi

    vet = malloc(dim*sizeof(int));
    fill (vet, dim);
    min_index = 0;
    min_index = search_min (vet, dim, min_index);
    printf("\n Il minimo e': %d , in posizione %d", vet[min_index], min_index);
    free (vet);
    return 0;
}
