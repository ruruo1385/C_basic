#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool is_little_endian();
uint32_t swap_endian(uint32_t val);

int main(int argc, char const *argv[])
{
    uint32_t network_data=0x12345678;
    printf("=== Day 2: Endianness Conversion ===\n");
    printf("Received Data (Hex): 0x%x\n",network_data);
    if(is_little_endian()){
        printf("[System Check] This system is Little Endian\n");
        printf("-> Need to swap bytes to match Host Order.\n");
        uint32_t host_data = swap_endian(network_data);
        printf("Original (Network): %x\r\n",network_data);
        printf("Converted (Network): %x\r\n",host_data);
        uint8_t* ptr =  (uint8_t*)&host_data;
        printf("Memory Dump: [%02x] [%02x] [%02x] [%02x] (Low Addr -> High Addr)\r\n",
            ptr[0],ptr[1],ptr[2],ptr[3]); 
    }
    return 0;
}

bool is_little_endian()
{
    uint32_t num=0x01;
    uint8_t* first_byte = (uint8_t*)&num;
    if(first_byte[0]==1){
        return true;
    }
    else{
        false;
    }
    
}
uint32_t swap_endian(uint32_t val){
    //비트연산만 가지고 swap
    return ((val>>24)&0x000000FF | 
            (val>>8)& 0x0000FF00 |
            (val<<8)& 0x00FF0000 |
            (val<<24)&0xFF000000
    );
}