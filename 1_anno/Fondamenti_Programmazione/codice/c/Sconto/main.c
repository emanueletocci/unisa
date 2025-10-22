
#include <stdio.h>
#include <stdlib.h>

float calcolo_sconto (float prezzo, float sconto);
int main() {
    float prezzo, sconto, prezzo_finale;
    printf("Questo programma calcola il prezzo da pagare di un articolo dato il prezzo originale e lo sconto \n Inserire prezzo prodotto ");
    scanf ("%f", &prezzo);
    printf("\n Inserire lo sconto \n");
    scanf ("%f", &sconto);
    prezzo_finale= calcolo_sconto (prezzo, sconto);
    printf ("L'importo da pagare è: %f", prezzo_finale);

    return (EXIT_SUCCESS);
}

float calcolo_sconto (float prezzo, float sconto){
    float prezzo_finale;
    prezzo_finale= prezzo - ((prezzo*sconto)/100);
    return (prezzo_finale);
}
