#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

typedef struct TAG_HEAP {
    int capacity;
    int size;
    int *H;       // indices into ELEMENT array
} HEAP;

void BuildHeap(HEAP* pHeap, ELEMENT **V);
void Insert(HEAP* pHeap, ELEMENT **V, int index);
void ExtractMin(HEAP* pHeap, ELEMENT **V);
void DecreaseKey(HEAP* pHeap, ELEMENT **V, int index, double newKey);
