#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"   // This already defines TAG_HEAP and HEAP

// Only declare the functions here, no struct definition
void BuildHeap(HEAP* pHeap, ELEMENT **V);
void Insert(HEAP* pHeap, ELEMENT **V, int index);
void ExtractMin(HEAP* pHeap, ELEMENT **V);
void DecreaseKey(HEAP* pHeap, ELEMENT **V, int index, double newKey);
