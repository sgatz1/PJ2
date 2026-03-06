#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

void BuildHeap(HEAP* pHeap, ELEMENT **V);
void Insert(HEAP* pHeap, ELEMENT **V, int index);
void ExtractMin(HEAP* pHeap, ELEMENT **V);
void DecreaseKey(HEAP* pHeap, ELEMENT **V, int index, double newKey);

#endif
