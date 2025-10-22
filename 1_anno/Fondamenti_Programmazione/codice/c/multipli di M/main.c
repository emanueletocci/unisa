#include <stdio.h>
#define k 1000
int multipli(int m, int n, int v[]);

int main()
{
    int n,m,v[k];
    int i=0;
    int j;
    printf("Inserire N \t");
    scanf("%d", &n);
    printf("\nInserire M \t");
    scanf("%d", &m);
    j=multipli(m,n,v);
    printf("\nI multipli sono %d\n", j);
    for(i=0;i<j;i++)
    {
        printf("%d ", v[i]);
    }
    return 0;
}


int multipli(int m, int n, int v[]){
    int i;
    int j=0;
    for(i=1;i<=n;i++)
    {
        if(i%m==0)
        {
            v[j]=i;
            j++;
        }
    
    }
    return(j);
}