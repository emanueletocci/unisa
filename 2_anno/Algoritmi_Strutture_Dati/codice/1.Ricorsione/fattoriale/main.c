#include <stdio.h>

/*
* Implementazione ricorsiva fattoriale di un numero
*
* !n = n(n-1)!
*/

int fattoriale (int num){
    if (num == 0)
        return 1;
    else if (num <0)
        return -1;
    else
        return num* fattoriale(num-1);
}

int main() {
    int num;
    printf ("Inserire numero: \t");
    scanf ("%d", &num);

    printf("!%d = %d", num, fattoriale(num));
    return 0;
}
