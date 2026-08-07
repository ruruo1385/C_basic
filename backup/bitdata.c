#include <stdio.h>
#include <stdint.h>
//특정 비트 제어 매크로 구현
#define BIT_SET(var,pos)((var)|=(1UL<<(pos))) //비트연산 OR 연산
#define BIT_CLEAR(var,pos)((var) &= ~(1UL<<(pos)))//바꾸고 싶은 곳만 0으로 + and 연산
#define BIT_TOGGLE(var, pos)((var) ^= (1UL<<(pos)))//xor
#define BIT_CHECK(var,pos)((var) & (1UL<<(pos))) //check

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
int main(int argc, char const *argv[])
{
    uint32_t data = 0x12345678;
    //BIT_SET(data,0); 위의 bit set을 풀어쓰면 이렇게
    //((data)|=(1UL<<(1)));
    //BIT_CLEAR(data,3);
    //BIT_TOGGLE(data,0);
    //BIT_TOGGLE(data,3);
    //int bit_status = BIT_CHECK(data,0);
    int bit_status=BIT_CHECK(data,3);
    printf("=== Day 1: Bitwise Macro Test ===\r\n");
    printf("[Init] Hex: 0x%x | Bin: ", data);
    print_binary(data);
    printf("[SET]    Target: Bit 0\n");
    printf("Result Hex: 0x%x | Bin: ", BIT_SET(data,0));
    print_binary(BIT_SET(data,0));
    printf("[CLEAR]  Target: Bit 4\n");
    printf("Result Hex: 0x%x | Bin: ", BIT_CLEAR(data,4));
    print_binary(BIT_CLEAR(data,4));
    printf("[TOGGLE] Target: Bit 3\n");
    printf("Result Hex: 0x%x | Bin: ", BIT_TOGGLE(data,3));
    print_binary(BIT_TOGGLE(data,3));
    printf("[CHECK] Bit 3 is currently %d", bit_status);
    return 0;
}
