/*▪ 
Si scriva un programma in linguaggio C dati N numeri interi letti da tastiera calcolare e stampare su 
schermo se la sequenza dei numeri inseriti è: crescente, decrescente né crescente né decrescente.

Nota: il valore di N è inserito da tasti*/

//pattern: visita sequenza di lunghezza nota senza memorizzazione

#include <stdio.h>
int main(){
    int curr, i, prec, n, flag;
    flag=0;                                                               // variabile controllo tipologia sequenza
    printf("Questo programma analizza una sequenza di numeri inseriti dall'utente e determina se tale sequenza é crescente, decrescente oppure nessuna delle due.");
    do{ 
        printf("\nQuanti numeri si vogliono inserire (inserire un numero positivo)? \t");
        scanf("%d",&n);                                                         //lettura coefficiente n, lunghezza sequenza

        if (n==1)
            printf("\nUna sequenza é composta da piú di 1 valore! Il numero inserito deve essere positivo");
    }
    while ((n<0)||(n==1));
    printf("\nInserire 1 numero: \t");   
    scanf("%d",&curr);  
    prec=curr; 
    
    for(i=2; i<=n; i++){          
        printf("\nInserire %d numero: \t",i);           
        prec=curr;  // lettura valore corrente
        scanf("%d",&curr);  
        //printf("\ncurr = \t %d \n prec= \t %d", curr, prec);                                                  //test
        if ((prec<curr)&&(flag!=3)){ 
            flag=1;
            //printf("\n prec <= curr, CRESCENTE \n flag= \t %d", flag);                                      //test
        }
        else if ((prec>curr)&&(flag!=1)){
            flag=2;
            //printf("\n prec >= curr, DECRESCENTE \n flag= \t %d", flag);                                    //test
        }
        else{
            flag=3;
            //printf("\n flag= \t %d", flag);                                                                 //test
        }
    }
    if (flag==1)
        printf("\n La sequenza é crescente");
    else if (flag==2)
        printf("\n La sequenza é decrescente");
    else if (flag==3)
        printf("\n La sequenza non é ne crescente ne decrescente");
    return 0;
}

