#include <stdio.h>
//3개 한번에 비교?
void swapper(int *pa, int *pb, int *pc){
    int temp;
    if( *pa > *pb && *pa> *pc){
        //abc
        if(*pb > *pc){
        }
        //acb
        else{
            temp = *pb;
            *pb = *pc;
            *pc = temp;
        }
    }//bac, bca
    else if(*pb > *pa && *pb > *pc){
        //bac
        if(*pa > *pc){
            temp = *pa;
            *pa = *pb;
            *pb = temp;
        //bca
        }else{
            temp = *pa;
            *pa = *pb;
            *pb = *pc;
            *pc = temp;
        }
    }else{
        // cba
        if(*pb > *pa){
            temp = *pa;
            *pa = *pc; 
            *pc = temp;
        }//cab
        else{
            temp = *pa;
            *pa = *pc;
            *pc = *pb;
            *pb = temp;
        }
    }
}
//2개씩 비교
void swap(int* pa, int* pb)    // 매개변수로 포인터 선언
{
    int temp;                  // 교환을 위한 임시 변수

    temp = *pa;                // temp에 pa가 가리키는 변수의 값 저장
    *pa = *pb;                 // pa가 가리키는 변수에 pb가 가리키는 변수의 값 저장
    *pb = temp;                // pb가 가리키는 변수에 temp 값 저장
}
int main(int argc, char const *argv[])
{
   int a, b, c;
    int *pa ,*pb, *pc;
    printf("실수값 3개 입력");
    scanf("%d, %d, %d", &a, &b, &c);
    pa = &a;
    pb = &b;
    pc = &c;
    swapper(&a, &b, &c);
    printf("%d, %d, %d", a,b,c);
    /* int a, b, c;
    int *pa ,*pb, *pc;
    printf("실수값 3개 입력");
    scanf("%d, %d, %d", &a, &b, &c);
    if(b<c) swap(&b,&c);
    if(a<b) swap(&a, &b);
    if(a<c) swap(&a,&c); 
    printf("%d, %d, %d", a,b,c); */
    return 0;
}
