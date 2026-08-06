#include <stdio.h>
#include "hello.h"//현재 폴더에 있는 친구들은 "" 
int x =0;
int y(int x);
int main(int a, int b){
    //data type : int . char
    int c = 100; 
    char d = 'd';
    char e[] = "abcde"; //이게 str
    float f = 1.0;
    double g = 1.0;
    printf("hello world\r\n");
    printf("result %d\r\n", y(2));
    return 0;
}

int y(int x){
    return x*2;
}