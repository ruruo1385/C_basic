#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct{
    char a;
    //
    int b;
    double c;
}Sample;

#define C_OFFSET(type,mem) ((size_t)&(((type *)0)->mem))

int main(int argc, char const *argv[])
{
    printf("=== Day 12: offsetof Implementation ===\r\n");
    printf("Struct Size: 16 bytes\r\n");
    printf("[Standard] Offset of a: %d\r\n",offsetof(Sample, a));
    printf("[Standard] Offset of b: %d\r\n",offsetof(Sample, b));
    printf("[Standard] Offset of c: %d\r\n",offsetof(Sample, c));
    printf("-----------------------------------\r\n");
    printf("[My Macro] Offset of a: %d\r\n", C_OFFSET(Sample, a));
    printf("[My Macro] Offset of b: %d\r\n",C_OFFSET(Sample, b));
    printf("[My Macro] Offset of c: %d\r\n",C_OFFSET(Sample, c));
    return 0;
}
