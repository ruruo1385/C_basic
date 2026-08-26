#include <stdio.h>
#include <stdint.h>

#define SIZE 2
#define TOTAL (SIZE * 8)
uint8_t bitmap[SIZE] = {0};
void bitmapAlloc(int index){
    int byte = index / 8;
    int bit = index % 8;
    return (bitmap[byte] >> bit) & 1;
}
void bitmapFree(int index){
    int byte = index / 8;
    int bit = index % 8;
    bitmap[byte] &= ~(1<<bit);
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
