#include <stdio.h>
#include <stdint.h>

int add(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a - b;
}
int mult(int a, int b){
    return a * b;
}
int div(int a, int b){
    if(b == 0){
        printf("cannot divide by 0");
        return 0;
    }else{
        return a / b;
    }
}
typedef enum{
    ADD = 0, SUB, MULT, DIV, EXIT
} Op;
int main(int argc, char const *argv[])
{
    Op ope;
    int a, b;
    int (*func[])(int, int) = {add, sub, mult, div};
    while(1){
        printf("=== Day 11: Function Pointer Array Calculator ===\r\n");
        printf("Select (0:Add, 1:Sub, 2:Mul, 3:Div, 4:Exit):");
        scanf( "%d" , (int*)&ope);
        if( ope == EXIT){
          break;
        }
        printf("Input two integers: ");
        scanf("%d %d", &a, &b);
        printf(">> Result: %d\r\n", func[ope](a,b));
    }
    
    return 0;
}
