#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include "generic.h"

void print_info(TInfo info) {
    printf("\n %d %s",info.a,info.b);
}

bool equal(TInfo x, TInfo y) {
    if (x.a==y.a && strcmp(x.b,y.b)==0) return true;
    return false;
}

bool less(TInfo x, TInfo y) {
    if (x.a<y.a) return true;
    if (x.a>y.a) return false;
    if (strcmp(x.b,y.b)<0) return true;
    return false;
}

bool greater(TInfo x, TInfo y) {
    if (x.a>y.a) return true;
    if (x.a<y.a) return false;
    if (strcmp(x.b,y.b)>0) return true;
    return false;
}
