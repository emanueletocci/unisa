#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void crea_torri (int num_dischi, int **t1, int **t2, int **t3){
    *t1 = calloc(num_dischi, sizeof(int));
    *t2 = calloc(num_dischi, sizeof(int));
    *t3 = calloc(num_dischi, sizeof(int));
    return;
}

void inizializzazione (int num_dischi, int *t1){
    for (int i=0 ; i<num_dischi ; i++){
        *(t1+i)=i+1;
    }
    return;
}

void stampa_torri ( int num_dischi, int *t1, int *t2, int *t3) {
    for (int i = 0; i < num_dischi; i++) {
        printf("%d \t %d \t %d \n", *(t1 + i), *(t2 + i), *(t3 + i));
    }
    return;
}

void hanoi (int num_dischi, int *t1, int *t2, int *t3, char A, char B, char C){
    if (num_dischi == 1){
        printf("\n%c -> %c", A, C);
        return;
    }
    hanoi(num_dischi-1, t1 , t3, t2, A, C, B);
    printf("\n%c -> %c",A, C);
    hanoi(num_dischi-1, t2, t1, t3, B, A, C);
    return;
}

void clear (int *t1, int *t2, int *t3){
    free(t1);
    free(t2);
    free(t3);
    return;
}
int main() {
    int num_dischi ,*t1 ,*t2, *t3;
    do {
        printf("Inserire numero dischi: \t");
        scanf("%d", &num_dischi);
        if (num_dischi<=0)
            printf("\n ERRORE! Il numero deve essere positivo!");
    }
    while(num_dischi<=0);
    crea_torri(num_dischi ,&t1, &t2, &t3);
    inizializzazione(num_dischi, t1);
    stampa_torri (num_dischi, t1, t2, t3);
    printf ("Per risolvere il rompicapo sono necessarie %d mosse:", (int) pow(2, num_dischi) -1);
    hanoi (num_dischi, t1, t2, t3, 'A', 'B', 'C');
    clear (t1, t2, t3);
    return 0;
}