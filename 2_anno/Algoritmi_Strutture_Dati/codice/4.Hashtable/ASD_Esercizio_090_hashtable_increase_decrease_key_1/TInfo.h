/*
 * TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

#include <stdbool.h>

typedef int TKey;
typedef int TValue;

typedef struct SInfo {
    TKey key;
    TValue value;
} TInfo;

bool info_equal(TInfo, TInfo);
bool info_greater(TInfo, TInfo);
bool info_less(TInfo, TInfo);
void info_print(TInfo);

#endif

