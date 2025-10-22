#include <stdio.h>

int main (){
    float x1, x2, y1, y2, m, p;
    printf ("Inserire coordinate del primo punto nel formato (x,y): \t");
    scanf("%f %f", &x1, &y1 );
    printf ("\nInserire coordinate del secondo punto nel formato (x,y): \t");
    scanf("%f %f", &x2, &y2 );
    m=(y2-y1)/(x2-x1);
    p=y1-m*x1;
    printf("\nIl coefficiente angolare della retta %f è \t", m);
    printf("\L'intercetta della retta %f è: \t", p);
    return 0;
}