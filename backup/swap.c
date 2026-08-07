//pointer
#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap2(void *a, void *b){
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}
void swap3(void *a, void *b, int data_t){
    printf("a: %d, b: %d", *(char*)a, *(int*)b);
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}
int main(int argc, char const *argv[])
{   
    int a=1, b=2;
    swap(&a,&b);
    printf("a: %d, b: %d", a, b);
    return 0;
}
