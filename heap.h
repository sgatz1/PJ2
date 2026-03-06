#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

void heapify(ELEMENT **V, HEAP *heap, int i);
void buildHeap(ELEMENT **V, HEAP *heap);
void insertHeap(ELEMENT **V, HEAP *heap, int index);
void extractMin(ELEMENT **V, HEAP *heap);
void decreaseKey(ELEMENT **V, HEAP *heap, int index, double newKey);

#endif
