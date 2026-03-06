#include <stdio.h>
#include "util.h"

void printArray(ELEMENT **V, int n)
{
    for(int i=1;i<=n;i++)
        printf("%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
}

void printHeap(ELEMENT **V, HEAP *heap)
{
    printf("Capacity = %d, size = %d\n", heap->capacity, heap->size);

    for(int i=1;i<=heap->size;i++)
        printf("H[%d] = %d\n", i, heap->H[i]);
}
