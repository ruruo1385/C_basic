#include <stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{   
    int count;
    printf("Input Number : ");
    scanf("%d",  &count);
    int pn_count = 0;
    for (int i = 2; i < count; i++)
    {   
        int pn = 1;
        for (int j = 2; j < sqrt(i); j++){  
            if (i%j == 0){
                pn=0;
                break;
            }
        }
        if(pn){
            printf("%10d",i);
            pn_count++;
            if (pn_count%5==0)
            {
                printf("\r\n");
            }
            
        }
    }
    printf("find count : %d", pn_count);
    return 0;
}
