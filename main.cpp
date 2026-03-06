#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"
#include "heap.h"
#include "util.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr,"Usage: ./PJ2 <I-File> <O-File>\n");
        fprintf(stderr,"<I-File> is the input file\n");
        fprintf(stderr,"<O-File> is the output file\n");
        return 0;
    }

    ELEMENT **V = NULL;
    HEAP *heap = NULL;

    char instruction[100];

    int n = 0;

    while(scanf("%s",instruction) != EOF)
    {

        if(strcmp(instruction,"Stop")==0)
        {
            printf("Instruction: Stop\n");
            break;
        }

        else if(strcmp(instruction,"Read")==0)
        {
            printf("Instruction: Read\n");

            FILE *fp = fopen(argv[1],"r");

            if(!fp)
            {
                fprintf(stderr,"Error: cannot open input file\n");
                continue;
            }

            fscanf(fp,"%d",&n);

            V = (ELEMENT**)malloc((n+1)*sizeof(ELEMENT*));

            for(int i=1;i<=n;i++)
            {
                V[i] = (ELEMENT*)malloc(sizeof(ELEMENT));

                double key;
                fscanf(fp,"%lf",&key);

                V[i]->index = i;
                V[i]->key = key;
                V[i]->pos = 0;
            }

            fclose(fp);

            heap = (HEAP*)malloc(sizeof(HEAP));
            heap->capacity = n;
            heap->size = 0;
            heap->H = (int*)malloc((n+1)*sizeof(int));
        }

        else if(strcmp(instruction,"PrintArray")==0)
        {
            printf("Instruction: PrintArray\n");

            if(V == NULL)
            {
                fprintf(stderr,"Error: array is NULL\n");
                continue;
            }

            printArray(V,n);
        }

        else if(strcmp(instruction,"PrintHeap")==0)
        {
            printf("Instruction: PrintHeap\n");

            if(heap == NULL)
            {
                fprintf(stderr,"Error: heap is NULL\n");
                continue;
            }

            printHeap(V,heap);
        }

        else if(strcmp(instruction,"BuildHeap")==0)
        {
            printf("Instruction: BuildHeap\n");

            heap->size = n;

            for(int i=1;i<=n;i++)
            {
                heap->H[i] = i;
                V[i]->pos = i;
            }

            buildHeap(V,heap);
        }

    }

    return 0;
}
