#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"
#include "heap.h"

ELEMENT **V = NULL;
HEAP *pHeap = NULL;
int n = 0;



    char instr[50];
    while(scanf("%s", instr) != EOF) {
        if(strcmp(instr, "Stop") == 0) {
            printf("Instruction: Stop\n");
            break;
        }
        else if(strcmp(instr, "Read") == 0) {
            printf("Instruction: Read\n");
            FILE* infile = fopen(argv[1], "r");
            if(!infile) { fprintf(stderr, "Error: cannot open input file\n"); continue; }

            fscanf(infile, "%d", &n);
            V = (ELEMENT**) malloc((n+1)*sizeof(ELEMENT*));
            for(int i=1; i<=n; i++) {
                V[i] = (ELEMENT*) malloc(sizeof(ELEMENT));
                V[i]->index = i;
                fscanf(infile, "%lf", &V[i]->key);
                V[i]->pos = 0;
            }
            fclose(infile);

            pHeap = (HEAP*) malloc(sizeof(HEAP));
            pHeap->capacity = n;
            pHeap->size = 0;
            pHeap->H = (int*) malloc((n+1)*sizeof(int));
        }
        else if(strcmp(instr, "PrintArray") == 0) {
            printf("Instruction: PrintArray\n");
            if(!V) { fprintf(stderr, "Error: array is NULL\n"); continue; }
            for(int i=1; i<=n; i++)
                printf("%d %lf %d\n", i, V[i]->key, V[i]->pos);
        }
        else if(strcmp(instr, "PrintHeap") == 0) {
            printf("Instruction: PrintHeap\n");
            if(!pHeap) { fprintf(stderr, "Error: heap is NULL\n"); continue; }
            printf("Capacity = %d, size = %d\n", pHeap->capacity, pHeap->size);
            for(int i=1; i<=pHeap->size; i++)
                printf("H[%d] = %d\n", i, pHeap->H[i]);
        }
        else if(strcmp(instr, "BuildHeap") == 0) {
            printf("Instruction: BuildHeap\n");
            pHeap->size = n;
            for(int i=1; i<=n; i++) pHeap->H[i] = i;
            BuildHeap(pHeap, V);
        }
        else if(strncmp(instr, "Insert", 6) == 0) {
            int idx; scanf("%d", &idx);
            printf("Instruction: Insert %d\n", idx);
            if(idx < 1 || idx > n) { fprintf(stderr, "Error: index out of bound\n"); continue; }
            if(V[idx]->pos != 0) { fprintf(stderr, "Error: V[index] already in the heap\n"); continue; }
            Insert(pHeap, V, idx);
        }
        else if(strcmp(instr, "ExtractMin") == 0) {
            printf("Instruction: ExtractMin\n");
            if(!pHeap) { fprintf(stderr, "Error: heap is NULL\n"); continue; }
            if(pHeap->size == 0) { fprintf(stderr, "Error: heap is empty\n"); continue; }
            ExtractMin(pHeap, V);
        }
        else if(strncmp(instr, "DecreaseKey", 11) == 0) {
            int idx; double newKey;
            scanf("%d %lf", &idx, &newKey);
            printf("Instruction: DecreaseKey %d %lf\n", idx, newKey);
            if(idx < 1 || idx > n || newKey >= V[idx]->key) { fprintf(stderr, "Error: invalid call to DecreaseKey\n"); continue; }
            if(V[idx]->pos == 0) { fprintf(stderr, "Error: V[index] not in the heap\n"); continue; }
            DecreaseKey(pHeap, V, idx, newKey);
        }
        else if(strcmp(instr, "Write") == 0) {
            printf("Instruction: Write\n");
            FILE* outfile = fopen(argv[2], "w");
            if(!outfile) { fprintf(stderr, "Error: cannot open output file\n"); continue; }
            for(int i=1; i<=n; i++)
                fprintf(outfile, "%d %lf %d\n", i, V[i]->key, V[i]->pos);
            fclose(outfile);
        }
        else {
            printf("Warning: Invalid instruction\n");
        }
    }
    return 0;
}
