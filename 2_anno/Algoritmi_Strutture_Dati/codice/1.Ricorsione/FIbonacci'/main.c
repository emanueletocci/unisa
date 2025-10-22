#include <stdio.h>
/*
 * Implementazione ricorsiva fibonacci
 *
 *  F(n) = F (n − 1) + F (n − 2 )
 * */
int fibonacci (int n){
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci (n-2);
}
int main() {
    int n;
    printf("Inserire un numero: \t");
    scanf("%d", &n);
    printf("F(%d) = %d", n , fibonacci(n));
    return 0;
}
