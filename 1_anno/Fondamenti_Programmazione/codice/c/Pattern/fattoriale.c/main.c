#include <stdio.h>
int fattoriale_semplice (int n);
void fattoriale_pattern (int n);
int fattoriale_ricorsivo (int n);

int main(){
    int n, fattoriale;
    printf("Inserire il numero per cui si vuole calcolare la sequenza di fattoriali \t");
    scanf ("%d",&n);
    fattoriale= fattoriale_semplice(n);
    printf("Il fattoriale di %d e\' %d \n\n", n, fattoriale); 
    printf("Ricalcolo il fattoriale usando una funzione ricorsiva \n");
    fattoriale = fattoriale_ricorsivo(n);
    printf("Il fattoriale di %d e\' %d \n\n", n, fattoriale); 
    printf("Genero la sequenza di fattoriali\n");
    fattoriale_pattern(n);

}

int fattoriale_semplice (int n){
    int fattoriale=1;
    
    if (n==0){
        fattoriale=1;
    }
    else if (n>0)
    {
        while (n>0){
            fattoriale = fattoriale*n;
            n--;
        }
    }

    else{
        printf("Impossibile calcolare il fattoriale di un numero negativo");
    }
    return fattoriale;
}

int fattoriale_ricorsivo(int n){
    int fattoriale =1;

    if (n==0){
        fattoriale=1;
    }
    else if (n>0)
    {
        fattoriale=n*fattoriale_ricorsivo(n-1);
    }
    else{
        printf("Impossibile calcolare il fattoriale di un numero negativo");
    }    

    return fattoriale;
}


void fattoriale_pattern(int n){
    int i, fattoriale, fattoriale_precedente;
    fattoriale =1;
    fattoriale_precedente=fattoriale; 
    for (i=1; i<=n;i++){
        fattoriale=i*fattoriale_precedente;
        printf("%d!= %d \n", i, fattoriale);
        fattoriale_precedente=fattoriale;
    }
    return;
}

