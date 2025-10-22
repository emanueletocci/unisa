#include <stdio.h>
int main(){
    int c1, c2, c3;
    printf("Questo programma classifica i triangoli dati in input i tre lati \n");
    printf ("Inserire i 3 lati: \t");
    scanf ("%d %d %d", &c1, &c2, &c3);
    if ((c1 == c2) && (c2==c3))
        printf("Il triangolo è equilatero");
    else if ((c1==c2)|| (c2==c3))
        printf("Il triangolo è isoscele");
    else 
        printf("Il triangolo è scaleno");
    return 0;
}