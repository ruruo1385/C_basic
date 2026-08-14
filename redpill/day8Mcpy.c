#include <stdio.h>
#include <stdint.h>

void *custom_memmove(void *dest, void *src, size_t n){
    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;
    if (d == s || n ==0){
        return dest;
    }
    if(d<s || d>= s+ n){
        for (size_t i = 0 ; i < n; i++){
            d[i] = s[i];
        }
    }else{
        for (size_t i = n; i > 0; i--)
        {
            d[i-1] = s[i-1];
        }
    }
    return dest;
}
void printer(uint8_t *data, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        printf("%02x", data[i]);
    }
    printf("\n");
}
void test_data(uint8_t *data){
    for (int i = 0; i < 10; i++)
    {
        data[i] = i + 1;
    }
}
int main(int argc, char const *argv[])
{
    uint8_t data[10];
    test_data(data);
    printf("=== Day 8: Safe Memcpy (memmove) Implementation ===\r\n");
    printf("[Initial] ");
    printer(data, 10);
    printf("\nTest 1: Overlap (Dest > Src) -> Shift Right 2 bytes\r\n");
    custom_memmove(&data[2],&data[0], 5);
    printf("[Result ] ");
    printer(data,10);
    printf(">> Success!\r\n\r\n");
    test_data(data);
    printf("[Initial] ");
    printer(data, 10);
    printf("Test 2: Overlap (Dest < Src) -> Shift Left 2 bytes\r\n");
    custom_memmove(&data[0], &data[2],5);
    printf("[Result ] ");
    printer(data,10);
    printf(">> Success!\r\n");
    return 0;
}
