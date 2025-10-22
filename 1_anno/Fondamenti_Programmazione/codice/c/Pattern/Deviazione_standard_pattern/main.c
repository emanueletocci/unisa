/*Calcolo deviazione standard*/

#include <stdio.h>
#include <math.h>
void media_dev (float n, float *m, float *ds);
int main(){
    float m, ds;
    int n;
    printf("Inserire numero valori: \t");
    scanf("%d", &n);
    media_dev (n, &m, &ds);
    printf("La media è: %f \n La deviazione standard è: %f", m, ds);
}

void media_dev (float n, float *m, float *ds){
    float sum=0, sum_q=0, curr;
    int i;
    for (i=0; i<n; i++){
        printf("\n Inserire valore: \t");
        scanf("%f", &curr);
        sum=sum+curr;
        sum_q= sum_q + curr*curr;
    }
    *m=sum/n;
    *ds= 1/n * (sqrt(n*sum_q-sum*sum));
    return;
}