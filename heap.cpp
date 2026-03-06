#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "data_structures.h"

// BuildHeap: convert V into a valid min-heap
void BuildHeap(HEAP* pHeap, ELEMENT **V) {
    if(pHeap->size == 0) return;

    for(int i=1; i<=pHeap->size; i++) {
        pHeap->H[i] = i;
        V[i]->pos = i;
    }

    for(int i=pHeap->size/2; i>=1; i--) {
        int parent = i;
        while(2*parent <= pHeap->size) {
            int left = 2*parent;
            int right = 2*parent+1;
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
    if(index <= 0 || V[index] == NULL) return;

    pHeap->size++;
    pHeap->H[pHeap->size] = index;
    V[index]->pos = pHeap->size;

    int i = pHeap->size;
    while(i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i/2];
        pHeap->H[i/2] = temp;

        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[i/2]]->pos = i/2;

        i = i/2;
    }

    printf("Element V[%d] inserted into the heap\n", index);
}

// ExtractMin: remove smallest element
void ExtractMin(HEAP* pHeap, ELEMENT **V) {
    int minIndex = pHeap->H[1];
    V[minIndex]->pos = 0;

    pHeap->H[1] = pHeap->H[pHeap->size];
    V[pHeap->H[1]]->pos = 1;
    pHeap->size--;

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

// DecreaseKey: reduce key and bubble up
void DecreaseKey(HEAP* pHeap, ELEMENT **V, int index, double newKey) {
    V[index]->key = newKey;
    int i = V[index]->pos;

    while(i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i/2]]->key) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i/2];
        pHeap->H[i/2] = temp;

        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[i/2]]->pos = i/2;

        i = i/2;
    }
}
