#include <stdio.h>
//for loop
int sum(int n){
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += i;
    }
    return result;
}
//while loop
long long sum4(int n){
    long long result = 0;
    int i = 0;
    while (i<n)
    {
        result = result + i;
        i++;
    }
    return result;
}
//recursive
int sum2(int n){
    if(n==0){
        return 0;
    }
    return n+sum2(n-1);
}
//gauss
long long sum3(long long n){
    return (long long)((n)*(n+1))/2;
}
int main(int argc, char const *argv[])
{
    long long input=1000000000000;
    printf("입력 : ");
    //scanf("%d", &input);
    long long  result=sum3(input);
    printf("%I64d",result);
    return 0;
}
