#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "data_structures.h"

// BuildHeap: converts array V into a valid min-heap in pHeap
void BuildHeap(HEAP* pHeap, ELEMENT **V) {
    // Only elements 1..pHeap->size are in heap
    for (int i = 1; i <= pHeap->capacity; i++) {
        V[i]->pos = 0; // reset all positions
    }

    for (int i = 1; i <= pHeap->size; i++) {
        pHeap->H[i] = i;
        V[i]->pos = i;
    }

    for (int i = pHeap->size / 2; i >= 1; i--) {
        int parent = i;
        while (2*parent <= pHeap->size) {
            int left = 2*parent;
            int right = 2*parent + 1;
            int smallest = parent;

            if(left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key)
                smallest = left;
            if(right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key)
                smallest = right;

            if(smallest != parent) {
                int temp = pHeap->H[parent];
                pHeap->H[parent] = pHeap->H[smallest];
                pHeap->H[smallest] = temp;

                V[pHeap->H[parent]]->pos = parent;
                V[pHeap->H[smallest]]->pos = smallest;

                parent = smallest;
            } else break;
        }
    }
}

// Insert: adds V[index] to the heap
void Insert(HEAP* pHeap, ELEMENT **V, int index) {
    pHeap->size++;
    int i = pHeap->size;
    pHeap->H[i] = index;
    V[index]->pos = i;

    // Bubble up
    while(i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i/2];
        pHeap->H[i/2] = temp;

        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[i/2]]->pos = i/2;

        i = i/2;
    }

    printf("Element V[%d] inserted into the heap\n", index); // output required by Gradescope
}

// ExtractMin: removes the minimum element from the heap
void ExtractMin(HEAP* pHeap, ELEMENT **V) {
    int minIndex = pHeap->H[1];
    V[minIndex]->pos = 0;

    pHeap->H[1] = pHeap->H[pHeap->size];
    V[pHeap->H[1]]->pos = 1;
    pHeap->size--;

    // Bubble down
    int i = 1;
    while(2*i <= pHeap->size) {
        int left = 2*i;
        int right = 2*i+1;
        int smallest = i;

        if(left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key)
            smallest = left;
        if(right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key)
            smallest = right;

        if(smallest != i) {
            int temp = pHeap->H[i];
            pHeap->H[i] = pHeap->H[smallest];
            pHeap->H[smallest] = temp;

            V[pHeap->H[i]]->pos = i;
            V[pHeap->H[smallest]]->pos = smallest;

            i = smallest;
        } else break;
    }
}

// DecreaseKey: lowers the key of V[index] and repositions it
void DecreaseKey(HEAP* pHeap, ELEMENT **V, int index, double newKey) {
    V[index]->key = newKey;
    int i = V[index]->pos;

    // Bubble up
    while(i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i/2];
        pHeap->H[i/2] = temp;

        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[i/2]]->pos = i/2;

        i = i/2;
    }
}
