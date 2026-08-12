#include <stdio.h>
#include <stdint.h>



void print_binary(uint32_t data){
    for (int i = 31; i >= 0; i--)
    {   
        uint32_t bit = (data>>i)&1;
        printf("%u", bit);
        if(i % 4 == 0){
            printf(" ");
        }
    }
    printf("\n");
}
int rotateR(uint32_t i, int n){
    return (i>>n ) | (i << (32 - n));
}
int rotateL(uint32_t i, int n){
    return (i << n ) | (i >> (32 - n));
}
int main(int argc, char const *argv[])
{
    printf("=== Day 6: Circular Shift (Rotate) ===\r\n");
    printf("[Init] Hex: 0xF0000000\r\n");
    printf("       Bin: ");
    print_binary(0xF0000000);
    printf("[ROL 4] Hex: 0x%08x\r\n", rotateL(0xF0000000,4));
    printf("       Bin: ");
    print_binary( rotateL(0xF0000000,4 ));
    printf("       (MSB bits moved to LSB)\r\n");
    printf("[ROR 4] Hex: 0x%08x\r\n", rotateR(rotateL(0xF0000000, 4),4));
    printf("       Bin: ");
    print_binary(rotateR(rotateL(0xF0000000,4),4));
    printf("       (Restored to original)\r\n");
    printf("[Test 2] Data: 0x12345678 -> ROR 8 -> 0x%08x",rotateR(0x12345678 , 8));

    return 0;
}
