#include <stdint.h>
#include <stdio.h>

typedef struct{
    int *key;
    int priority;
} Node;

void insert(Node heap[], int *size, int *key, int priority){
    int i = *size;
    heap[i].key = key;
    heap[i].priority = priority;
    (*size)++;
    while (i>0){
    }
}

int main(int argc, char const *argv[])
{
    printf("=== Day 18: Task Scheduler (Min Heap) ===\r\n");
    return 0;
}
