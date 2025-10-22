#include <stdio.h>
int main()
{
    int anno, mese, giorni;
    printf("Questo programma indica, dato un mese e un anno, quanti giorni lo compongono \n");
    do{
        printf("Inserire anno e mese: \t");
        scanf("%d %d",&anno, &mese);
        if ((mese>12) || (mese<1))
            printf("\n ERRORE! Inserire un numero compreso fra 1 e 12 \n");
        else if ((anno<0))
            printf ("E' stato inserito un anno negativo! \n\n");
    } while (mese >12 || mese <1 || anno<0);

    switch (mese)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            giorni = 31;
            printf ("\n Il mese %d è composto da %d giorni", mese, giorni);
            break;
        case 4: case 6: case 9: case 11:
            giorni = 30;
            printf ("\n Il mese %d è composto da %d giorni", mese, giorni);
            break;
        case 2:
            if (anno%4==0 && anno%100!=0 || anno%400==0)
                giorni = 29;
            else    
                giorni = 28;
            break;
        default:
            printf("\nInserire un numero compreso fra 1 e 12");
    }
    return 0;
}