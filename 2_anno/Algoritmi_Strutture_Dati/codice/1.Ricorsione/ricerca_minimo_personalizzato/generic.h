#include<stdbool.h>
#include<string.h>
#include<stdio.h>

struct miotipo {
    int a;
    char *b;
};
typedef struct miotipo TInfo;

void print_info(TInfo info);
bool equal(TInfo x, TInfo y);
bool less(TInfo x, TInfo y);
bool greater(TInfo x, TInfo y);
