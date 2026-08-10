//입력: 8bit 정수
//출력: 순서 반전 비트
//제약 조건: LUT를 사용하지 않고 O(1)비트 연산으로 구현
#include <stdio.h>
#include <stdint.h>


void print_binary(uint8_t data){
    printf(" ( ");
    for (int i = 7; i >= 0; i--)
    {   
        uint8_t bit = (data>>i)&1;
        printf("%u", bit);
        if(i % 4 == 0){
            printf(" ");
        }
    }
    printf(") "); 
    printf("\n");
}
void reversal(uint8_t bit){
    //1101 0010 -> 1101 0010 & 1111 0000 = 0000 1101 | 1101 0010 & 0000 1111 = 0010 0000
    uint8_t sum;
    uint8_t oneEight, twoSeven, threeSix, fourFive;
    //각 위치 별로 스왑
    oneEight = ((bit & 0x80) >> 7) | ((bit & 0x01) << 7);
    twoSeven = ((bit & 0x40) >> 5) | ((bit & 0x02)<<5);
    threeSix = ((bit & 0x20) >> 3) | ((bit & 0x04)<<3);
    fourFive = ((bit & 0x10) >> 1) | ((bit & 0x08)<<1);
    sum = oneEight | twoSeven | threeSix | fourFive;
    printf("Input: 0x%2x",bit);
    print_binary(bit);
    printf("Output: 0x%2x",sum);
    print_binary(sum);
}

int main(int argc, char const *argv[])
{
    printf("=== Day 4: Bitwise Reverse (Mirroring) ===\r\n");
    reversal(0xD2);
    reversal(0x0F);
    reversal(0xAA);
    reversal(0x12);

    return 0;
}
