/*
 * TInfo: tipo elementare
 */

#include <stdio.h>
#include <string.h>
#include "TInfo.h"

int infoEqual (TInfo info1, TInfo info2) {
    return info1.key == info2.key;
}

int infoGreater (TInfo info1, TInfo info2) {
    return info1.key > info2.key;
}

int infoLess (TInfo info1, TInfo info2) {
    return info1.key < info2.key;
}

void infoPrint (TInfo info) {
    printf ("(%d: %s %s)\n", info.key, info.value.nome, info.value.cognome);
}

unsigned int keyHash (TKey key) {
    return key;
}
