/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   utilita.h
 * Author: Fabrizio
 *
 * Created on 22 ottobre 2023, 17:55
 */

#ifndef UTILITA_H
#define UTILITA_H

#include"TInfo.h"
#include"TList.h"
#include"TQueue.h"
#include"TStack.h"

TList listInsertLast(TList, TInfo);

void printArray(int*, int);

void printQueue(TQueue);

void print_stack(TStack);

#endif /* UTILITA_H */