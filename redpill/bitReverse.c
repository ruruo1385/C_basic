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
void reversal(){
    uint8_t input[] = {0xD2,0x0F,0xAA,0x12};
    uint8_t arr[] = {0x4B, 0xF0,0x55,0x48};
    uint8_t sum;
    uint8_t oneEight, twoSeven, threeSix, fourFive;
    //각 위치 별로 스왑
    for(int i =0 ; i < sizeof(arr); i++ ){
        oneEight = ((input[i] & 0x80) >> 7) | ((input[i] & 0x01) << 7);
        twoSeven = ((input[i] & 0x40) >> 5) | ((input[i] & 0x02)<<5);
        threeSix = ((input[i] & 0x20) >> 3) | ((input[i] & 0x04)<<3);
        fourFive = ((input[i] & 0x10) >> 1) | ((input[i] & 0x08)<<1);
        sum = oneEight | twoSeven | threeSix | fourFive;
        printf("Input: 0x%02x",input[i]);
        print_binary(input[i]);
        printf("Output: 0x%02x",sum);
        print_binary(sum);
        if(sum == arr[i]){
            printf("Verify: OK\r\n");
        }else{
            printf("Verify: False\r\n");
        }
    }
    
}

int main(int argc, char const *argv[])
{
    printf("=== Day 4: Bitwise Reverse (Mirroring) ===\r\n");
    reversal();

    return 0;
}
