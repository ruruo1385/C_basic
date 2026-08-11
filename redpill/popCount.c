#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
//비트를 하나씩 확인하면서 1의 개수를 세는거
int calcNaive(uint32_t n){
    int count = 0;
    while (n > 0){
        if (n & 1){
            count ++;
        }
        n >>= 1;
    }
    return count;
}
// n & (n-1)을 사용해서 오른쪽의 1 비트를 제거한다
int calcKern(uint32_t n){
    int count = 0;
    while (n > 0){
        n = n & (n-1);
        count ++;
    }
    return count;
}
//비트를 그룹으로 나눈다
int calcSwar(uint32_t n){
    //2비트
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    //4비트
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    //8비트
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    //16비트
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    //32비트
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}

void printer(){
    uint32_t n[] = {0x00000000,0x00000007, 0x12345678, 0xFFFFFFFF};
    for( int i = 0; i < sizeof(n) / sizeof(n[0]); i++){
        printf("Case %d: Input 0x%08X\r\n", i , n[i]);
        printf("[Naive]    :   %2d\r\n", calcNaive(n[i]));
        printf("[Kernighan]:   %2d  (Recommended Logic)\r\n", calcKern(n[i]));
        printf("[SWAR]     :   %2d  (Strict Loop-free)\r\n", calcSwar(n[i]));
        printf("[Built-in] :   %2d\r\n", __popcnt(n[i]));
        printf("-------------------------\r\n");
    }
    
}
int main(int argc, char const *argv[])
{
    printf("=== Day 5: Population Count (Counting Set Bits) ===\r\n");
    printer();
    /* code */
    return 0;
}
