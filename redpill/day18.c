#include <stdint.h>
#include <stdio.h>

#define MAX_TASK 100
typedef struct{
    int id;
    int priority;
    int order;
} Task;
typedef struct{
    Task heap[MAX_TASK];
    int size;
    int orderCount;
} MinHeap;
int comparePriority(Task a, Task b){
    if (a.priority != b.priority)
    {
        return a.priority < b.priority;
    }
    return a.order < b.order;
}
void heapInit(MinHeap *h){
    h->size = 0;
    h->orderCount =0;
}
void swap(Task *a, Task *b){
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *h, int id, int priority){
    if(h->size >= MAX_TASK){
        printf("Heap FULL\n");
        return;
    }
    int index = h->size;
    h->heap[index].id = id;
    h->heap[index].priority = priority;
    h->heap[index].order = h->orderCount++;
    h->size++;
    while(index >0){
        int parent = (index - 1) /2;
        if(comparePriority(h->heap[parent],h->heap[index])){
            break;
        }
        swap(&h->heap[parent],&h->heap[index]);
        index = parent;
    }
}

Task pop(MinHeap *h){
    Task result = h->heap[0];
    h->heap[0] = h->heap[h->size -1];
    h->size--;
    int index = 0;
    while(1){
        int left = index * 2 + 1;
        int right = index *2 + 2;
        int smallest = index;
        if(left<h->size && comparePriority(h->heap[left],h->heap[smallest])){
            smallest = left;
        }
        if(right < h->size && comparePriority(h->heap[right],h->heap[smallest])){
            smallest = right;
        }
        if(smallest == index){
            break;
        }
        swap(&h->heap[index],&h->heap[smallest]);
        index = smallest;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    MinHeap heap;
    heapInit(&heap);
    printf("=== Day 18: Task Scheduler (Min Heap) ===\r\n");
    push(&heap, 1, 50);
    push(&heap, 2, 10);
    push(&heap, 3, 5);
    push(&heap, 5, 0);
    push(&heap, 4, 100);
    printf("Tasks pushed: (1, 50), (2, 10), (3, 5), (5, 0), (4, 100)\n");
    printf("Processing Tasks...\n\n");
    while(heap.size > 0){
        Task task = pop(&heap);
        printf(">> Executing Task %d (Priority %d)\n",task.id, task.priority);
    }
    return 0;
}
