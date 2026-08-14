#include <stdio.h>
#include <stdint.h>

struct human{
    char name[10];
    int age;
};
void byteSwap(void *a, void *b, size_t size){
    unsigned char *A = a;
    unsigned char *B = b;
    for (size_t i = 0; i < size; i++)
    {
        unsigned char tmp = A[i];
        A[i] = B[i];
        B[i] = tmp;
    }
}
void printer(){
    struct human h1 = {"Kim",1};
    struct human h2 = {"Lee",2};
    double a = 3.151519;
    double b = 99.99000;
    int c = 10;
    int d = 20;
    byteSwap(&c,&d, sizeof(c));
    byteSwap(&a,&b,sizeof(a));
    byteSwap(&h1, &h2, sizeof(h1));
    printf("[Int] Before: 10, 20\r\n");
    printf("[Int] After : %d, %d\r\n", c, d);
    printf("[Double] Before: 3.15159, 99.99000\r\n");
    printf("[Double] After : %f, %f\r\n", a,b );
    printf("[Struct] Before: Kim(1), Lee(2)\r\n");
    printf("[Struct] After : %s(%d), %s(%d)\r\n", h1.name, h1.age, h2.name, h2.age);
}
int main(int argc, char const *argv[])
{
    printf("=== Day 9: Generic Swap Implementation ===\r\n");
    printer();
    return 0;
}
