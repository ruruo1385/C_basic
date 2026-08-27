#include <stdio.h>
#include <stdint.h>

#define SIZE 2
#define TOTAL (SIZE * 8)
uint8_t bitmap[SIZE] = {0};
int checkAlloc(int index){
    int byte = index / 8;
    int bit = index % 8;
    return (bitmap[byte] >> bit) & 1;
}
void setBit(int index){
    int byte = index / 8;
    int bit = index % 8;
    bitmap[byte] |= (1<<bit);
    printf(">> Index %d allocated. (Byte %d, Bit %d set)\n",
           index, byte, bit);
}
int bitmapAlloc(void){
    for(int i =0; i < TOTAL; i++){
        if(!checkAlloc(i)){
            setBit(i);
            return i;
        }
    }
    return -1;
}
void bitmapFree(int index){
    int byte = index / 8;
    int bit = index % 8;
    bitmap[byte] &= ~(1<<bit);
    printf(">> Index %d freed. (Byte %d, Bit %d cleared)\n",
           index, byte, bit);
}
void printBitmap(void)
{
    printf("[Bitmap Visual] ");

    for (int i = 0; i < SIZE; i++)
    {
        for (int bit = 0; bit < 8; bit++)
        {
            printf("%d", (bitmap[i] >> bit) & 1);
        }

        if (i < SIZE - 1)
            printf(" | ");
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    printf("=== Day 17: Bitmap Manager ===\n\n");

    // 0 ~ 7까지 할당
    for (int i = 0; i < 8; i++)
    {
        bitmapAlloc();
    }

    printBitmap();

    printf("\nFreeing index 2...\n");

    bitmapFree(2);

    printBitmap();

    printf("\nAllocating again (expecting index 2)...\n");

    bitmapAlloc();

    printBitmap();
    return 0;
}
