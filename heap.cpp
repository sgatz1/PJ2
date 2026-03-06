#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "data_structures.h"

// Swap helper
void swap(HEAP* pHeap, ELEMENT **V, int i, int j) {
    int temp = pHeap->H[i];
    pHeap->H[i] = pHeap->H[j];
    pHeap->H[j] = temp;
    V[pHeap->H[i]]->pos = i;
    V[pHeap->H[j]]->pos = j;
}

// Heapify down
void Heapify(HEAP* pHeap, ELEMENT **V, int i) {
    int left = 2*i;
    int right = 2*i + 1;
    int smallest = i;

    if(left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key)
        smallest = left;
    if(right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key)
        smallest = right;
    if(smallest != i) {
        swap(pHeap, V, i, smallest);
        Heapify(pHeap, V, smallest);
    }
}

// Heapify up
void BubbleUp(HEAP* pHeap, ELEMENT **V, int i) {
    while(i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key) {
        swap(pHeap, V, i, i/2);
        i = i/2;
    }
}

void BuildHeap(HEAP* pHeap, ELEMENT **V) {
    for(int i = pHeap->size/2; i >= 1; i--) {
        Heapify(pHeap, V, i);
    }
}

void Insert(HEAP* pHeap, ELEMENT **V, int index) {
    pHeap->size++;
    int i = pHeap->size;
    pHeap->H[i] = index;
    V[index]->pos = i;
    BubbleUp(pHeap, V, i);
}

void ExtractMin(HEAP* pHeap, ELEMENT **V) {
    if(pHeap->size == 0) return;
    int minIndex = pHeap->H[1];
    V[minIndex]->pos = 0;
    pHeap->H[1] = pHeap->H[pHeap->size];
    V[pHeap->H[1]]->pos = 1;
    pHeap->size--;
    Heapify(pHeap, V, 1);
}

void DecreaseKey(HEAP* pHeap, ELEMENT **V, int index, double newKey) {
    V[index]->key = newKey;
    BubbleUp(pHeap, V, V[index]->pos);
}
