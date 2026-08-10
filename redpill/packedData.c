#include <stdio.h>
#include <stdint.h>
//16bit 전송 -> RGB565를 RGB888으로 
//제약 조건 : 비트 마스킹과 쉬프트
#define MASK_RED 0xF800 // 1111 1000 0000 0000 => 0001 1111 => 1111 1000
#define MASK_GREEN 0x07E0 // 0000 0111 1110 0000
#define MASK_BLUE 0x001F  // 0000 0000 0001 1111

void parse_rgb565(uint16_t pixel){
    //separate 16 bit to rgb setting
    uint8_t r_raw = (pixel & MASK_RED)>>11;
    uint8_t g_raw = (pixel & MASK_GREEN)>>5;
    uint8_t b_raw = (pixel & MASK_BLUE);
    // set them in rgb888 format
    uint8_t r8 = (r_raw << 3);
    uint8_t g8 = (g_raw << 2);
    uint8_t b8 = (b_raw << 3);

    printf("Input: 0x%04x\r\n",pixel);
    printf("[Raw Value] R: %2d (0x%02x), G: %2d (0x%02x), B: %2d (0x%02x)\r\n",
        r_raw,r_raw, g_raw,g_raw,b_raw, b_raw);
    printf("[8-bit Ext] R: %3d,      G: %3d,      B: %3d\r\n", r8,g8,b8);
    printf("--------------------------------------------------\r\n");
}


int main(int argc, char const *argv[])
{
    printf("=== Day 3: Packed Data Parsing (RGB565) ===\r\n");
    parse_rgb565(0xFFFF);
    parse_rgb565(0xF000);
    parse_rgb565(0x07E0);
    parse_rgb565(0x1234);

    return 0;
}
