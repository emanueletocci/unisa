/*
 * TInfo: tipo elementare
 */

#include <stdio.h>
#include "TInfo.h"

void info_print(TInfo info) {
    printf("(%d: %s)\n", info.key, info.value.titolo);
}

bool info_equal(TInfo a, TInfo b) {
    return a.key == b.key;
}

bool info_less(TInfo a, TInfo b) {
    return a.key < b.key;
}

bool info_greater(TInfo a, TInfo b) {
    return a.key > b.key;
}