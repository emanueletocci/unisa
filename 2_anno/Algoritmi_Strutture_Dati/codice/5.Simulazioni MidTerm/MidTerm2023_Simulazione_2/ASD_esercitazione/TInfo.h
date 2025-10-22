/*
 * TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

typedef int TInfo;

int info_equal(TInfo, TInfo);
int info_greater(TInfo, TInfo);
int info_less(TInfo, TInfo);
void info_print(TInfo);

#endif

