#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
typedef struct
{
    uint32_t id;
    char name[16];
    float value;
}SensorData;

void hexdump(char *title[] ,void* b,int size){
    unsigned char* p = (unsigned char*) b;
    printf("%s: \r\n", title);
    for (int offset = 0; offset < size; offset +=16){
        printf("    %04x", offset);
        for (int i = 0; i < 16; i++){
            if(offset+i < size){
                printf("%02x ",p[offset+i]);
            }else{
                printf(" ");
            }
        }for (int i = 0; i < 16; i++){
            if(offset+i < size){
                unsigned char c = p[offset+i];
                if(isprint(c)){
                    printf("%c",c);
                }
            }else{
                printf(".");
            }
        }
        printf("\r\n");
    }
}
int main(int argc, char const *argv[])
{
    // 테스트 1: 단순 문자열
    char my_text[] = "Hello Embedded World! This is Hexdump.";
    hexdump("String Dump", my_text, sizeof(my_text));
  
    // 테스트 2: 구조체 (엔디안 확인 가능)
    SensorData sensor = { 0x12345678, "Sensor A", 3.14f };
    hexdump("Struct Dump", &sensor, sizeof(sensor)); 
    return 0;
}
