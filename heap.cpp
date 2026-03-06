#include <stdio.h>
#include "heap.h"

void swap(HEAP* pHeap, ELEMENT **V, int i, int j) {
    int tmp = pHeap->H[i];
    pHeap->H[i] = pHeap->H[j];
    pHeap->H[j] = tmp;

    // update pos
    V[pHeap->H[i]]->pos = i;
    V[pHeap->H[j]]->pos = j;
}

void MinHeapify(HEAP* pHeap, ELEMENT **V, int i) {
    int l = 2*i;
    int r = 2*i + 1;
    int smallest = i;

    if (l <= pHeap->size && V[pHeap->H[l]]->key < V[pHeap->H[smallest]]->key)
        smallest = l;
    if (r <= pHeap->size && V[pHeap->H[r]]->key < V[pHeap->H[smallest]]->key)
        smallest = r;
    if (smallest != i) {
        swap(pHeap, V, i, smallest);
        MinHeapify(pHeap, V, smallest);
    }
}

void BuildHeap(HEAP* pHeap, ELEMENT **V) {
    for(int i=1; i<=pHeap->size; i++)
        V[pHeap->H[i]]->pos = i;

    for(int i=pHeap->size/2; i>=1; i--)
        MinHeapify(pHeap, V, i);
}

void Insert(HEAP* pHeap, ELEMENT **V, int index) {
    pHeap->size++;
    pHeap->H[pHeap->size] = index;
    V[index]->pos = pHeap->size;

    // Percolate up
    int i = pHeap->size;
    while(i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key) {
        swap(pHeap, V, i, i/2);
        i = i/2;
    }
    printf("Element V[%d] inserted into the heap\n", index);
}

int ExtractMin(HEAP* pHeap, ELEMENT **V) {
    if (pHeap->size < 1) return -1;
    int minIndex = pHeap->H[1];
    V[minIndex]->pos = 0;

    pHeap->H[1] = pHeap->H[pHeap->size];
    V[pHeap->H[1]]->pos = 1;
    pHeap->size--;
    MinHeapify(pHeap, V, 1);
    return minIndex;
}

void DecreaseKey(HEAP* pHeap, ELEMENT **V, int index, double newKey) {
    V[index]->key = newKey;

    int i = V[index]->pos;
    while(i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key) {
        swap(pHeap, V, i, i/2);
        i = i/2;
    }
}
