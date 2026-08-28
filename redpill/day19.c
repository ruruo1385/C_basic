#include <stdint.h>
#include <stdio.h>
#define STACK_LIMIT 4096

char *stack_start;
void recursive(int depth){
    char local;
    if(depth == 0){
        stack_start = &local;
    }
    size_t usage = (size_t)(stack_start - &local);
    printf("Current Stack Usage: %zu bytes\n",usage);
    if(usage > STACK_LIMIT){
        printf("Soft Limit Exceeded\n");
        printf("Limit: 4096, Used: %zu\n", usage);
        return;
    }
    recursive(depth + 1);
}

int main(int argc, char const *argv[])
{
    printf("Soft Limit: %d bytes\n",STACK_LIMIT);
    recursive(0);
    printf("\n>> System survived. Returned safely to main.\n");
    /* code */
    return 0;
}

