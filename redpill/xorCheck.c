#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t calcSum(uint8_t *n, size_t length){
    uint8_t checksum = 0;
    while(length --){
        checksum ^= *n;
        n++;
    }
    return checksum;
}
bool verify(uint8_t *n, size_t length){
    uint8_t arr[] = {0x01, 0x04, 0x10, 0x20, 0x30, 0x40};
    uint8_t checker = calcSum(arr, sizeof(arr));
    uint8_t ver = calcSum(n, length);
    uint8_t sub = ver ^ checker;
    if(sub == 0){
        printf(">>> Verification SUCCESS (Result : 0x%02x)\r\n", sub);
        return true;
    }else{
        printf(">>> Verification FAIL (Result: 0x%02x)\r\n", sub);
        printf("Error detected! Discarding packet.\r\n");
        return false;
    }

}
int main(int argc, char const *argv[])
{
    uint8_t n[] = {0x01, 0x04, 0x10, 0x20, 0x30, 0x40};
    uint8_t noise[] = {0x01, 0x04, 0xEF, 0x20, 0x30, 0x40};
    printf("=== Day 7: XOR Checksum Calculation ===\r\n");
    printf("[TX] Sending Packet...\r\n");
    printf("Data : 0x01 0x04 0x10 0x20 0x30 0x40\r\n");
    printf("Calculated Checksum: 0x%02x\r\n",calcSum(n, sizeof(n)));
    printf("[RX] Receiving Normal Packet...\r\n");
    verify(n, sizeof(n));
    printf("[RX] Receiving Corrupted Packet (Noise injected)...\r\n");
    printf("Corrupted Data: 0x01 0x04 0xEF 0x20 0x30 0x40 0x04 \r\n");
    verify(noise, sizeof(noise));
    /* code */
    return 0;
}
