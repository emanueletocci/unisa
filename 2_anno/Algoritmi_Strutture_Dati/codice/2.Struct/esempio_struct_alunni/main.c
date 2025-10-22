//
//  main.c
//  Struct
//
//  Created by Emanuele Tocci on 19/09/23.
//



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef  struct SAlunno {
    char nome[30];
    char cognome[30];
    int voto;
} TAlunno;

int main(void) {
    TAlunno Alunni[20];
    char cogn_ricerca[30];
    int n;
    printf("Quanti alunni vuoi inserire? \t");
    scanf("%d",&n);
    for (int i = 0 ; i<n; i++){
        printf("\nInserisci nome : \t");
        scanf("%s",Alunni[i].nome);
        printf("\nInserisci cognome : \t");
        scanf("%s",Alunni[i].nome);
        printf("\n Inserisci voto: \t");
        scanf("%d",&Alunni[i].voto);
    }
    printf ("Inserisci cognome da ricercare: \t");
    scanf("%s",cogn_ricerca);

    for (int x=0; x<n; x++){
        if(strcmp(cogn_ricerca, Alunni[x].cognome)==0){
            printf("\n %d Cognome : \t %s", (x+1) ,Alunni[x].cognome);
        }
    }
}
