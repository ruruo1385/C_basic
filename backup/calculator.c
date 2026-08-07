#include <stdio.h>
//사칙연산, input output : scanf
int main(void){
    //firmware단에서는 warning도 안나오게 하라
    int a,b;
    char op;
    printf("int :");
    scanf("%d %c %d", &a,&op,&b);
    
    switch(op){
        case '+':
            printf("%d %c %d = %d", a,op,b, a+b);
            break;
        case '-':
            printf("%d %c %d = %d", a,op,b, a-b);
            break;
        case '*':
            printf("%d %c %d = %d", a,op,b, a*b);
            break;
        case '/':
            if(b == 0){
                printf("%s","Cannot divide by 0");
                break;
            }
            printf("%d %c %d = %f", a,op,b, (float)a/(float)b);
            break;
    }

    /* if(op == '*'){
        printf("%d %c %d = %d", a,op,b, a*b);
    }else if(op == '+'){
        printf("%d %c %d = %d", a,op,b, a+b);
    }else if(op == '-'){
        printf("%d %c %d = %d", a,op,b, a-b);
    }else if(op == '/'){
        if(b == 0){
            printf("%s","Cannot divide by 0");
            return 0;
        }
        printf("%d %c %d = %d", a,op,b, a/b);
    } */
    
    return 0;
}