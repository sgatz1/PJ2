#include <stdio.h>
#include "heap.h"

void swap(ELEMENT **V, HEAP *heap, int i, int j)
{
    int temp = heap->H[i];
    heap->H[i] = heap->H[j];
    heap->H[j] = temp;

    V[heap->H[i]]->pos = i;
    V[heap->H[j]]->pos = j;
}

void heapify(ELEMENT **V, HEAP *heap, int i)
{
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= heap->size &&
       V[heap->H[left]]->key < V[heap->H[smallest]]->key)
        smallest = left;

    if(right <= heap->size &&
       V[heap->H[right]]->key < V[heap->H[smallest]]->key)
        smallest = right;

    if(smallest != i)
    {
        swap(V, heap, i, smallest);
        heapify(V, heap, smallest);
    }
}

void buildHeap(ELEMENT **V, HEAP *heap)
{
    for(int i = heap->size/2; i >= 1; i--)
        heapify(V, heap, i);
}

void insertHeap(ELEMENT **V, HEAP *heap, int index)
{
    heap->size++;
    int i = heap->size;

    heap->H[i] = index;
    V[index]->pos = i;

    while(i > 1 &&
        V[heap->H[i]]->key < V[heap->H[i/2]]->key)
    {
        swap(V, heap, i, i/2);
        i = i/2;
    }
}

void extractMin(ELEMENT **V, HEAP *heap)
{
    int minIndex = heap->H[1];

    swap(V, heap, 1, heap->size);
    heap->size--;

    heapify(V, heap, 1);

    V[minIndex]->pos = 0;
}

void decreaseKey(ELEMENT **V, HEAP *heap, int index, double newKey)
{
    int i = V[index]->pos;
    V[index]->key = newKey;

    while(i > 1 &&
          V[heap->H[i]]->key < V[heap->H[i/2]]->key)
    {
        swap(V, heap, i, i/2);
        i = i/2;
    }
}
