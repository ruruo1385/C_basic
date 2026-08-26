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
void bitmapAlloc(int index){
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
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
