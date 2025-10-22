//
// Created by emanueletocci on 1/24/24.
//

#ifndef SIM_1_DRIVE_TINFO_H
#define SIM_1_DRIVE_TINFO_H

typedef int TKey;

typedef struct {
    char nome[20];
    char cognome[20];
} TValue;

typedef struct {
    TKey key;
    TValue value;
} TInfo;

int infoEqual (TInfo, TInfo);
int infoGreater (TInfo, TInfo);
int infoLess (TInfo, TInfo);
void infoPrint (TInfo);
unsigned int keyHash (TKey);

#endif

