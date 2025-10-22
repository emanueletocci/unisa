/*Questo programma selezione il valore minimo e quello massimo all'interno di una sequenza. Utilizza il pattern "selezione su sequenza con tappo senza memorizzazione"*/
#include <stdio.h>
#define C -1
#define INF 1000000

int massimo (void);
int minimo (void);

int main(){
    int max, min;
    printf("\n Cerco il valore massimo all'interno della sequenza.");
    max=massimo();
    printf("\n Cerco il valore minimo all'interno della sequenza.");
    min=minimo();
    printf("\nIl valore massimo all'interno della sequenza e\': \t %d", max);
    printf("\nIl valore minimo all'interno della sequenza e\': \t %d", min);
    return 0;
}


int massimo (){
    int curr, i, flag, pos, sel;
    sel= 0;
    flag=0;
    pos=0;
    i=1;
    printf("\nInserire valore corrente : \t");
    scanf ("%d",&curr);
    while (curr!=C){
        if(sel<curr){
            sel=curr;
            pos=i;
            flag=1;
            printf ("\n sel=%d \n pos=%d",sel,pos);
        
        }
        printf("\nInserire il valore corrente: \t");
        scanf ("%d",&curr);
        i++;
    }
    if (flag==0)
        printf("\nValore massimo NON trovato!");
    else
        return sel;
}

int minimo (){
    int curr, i, flag, pos, sel;
    flag=0;
    pos=0;
    curr=INF;
    sel=curr;
    i=0;
    while (curr!=C){
        if(sel>=curr){
            sel=curr;
            pos=i;
            flag=1;
            printf ("\n sel=%d \n pos=%d",sel,pos);
        }
          
        printf("\nInserire il valore corrente: \t");
        scanf ("%d",&curr);
        i++;
    }
    if (flag==0)
        printf("\nValore minimo NON trovato!");
    else
        return sel;
}