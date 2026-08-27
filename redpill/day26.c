#include <stdint.h>
#include <stdio.h>

#define BUF_SIZE 5
int head = 0;
int tail = 0;
int count = 0;
int buffer[BUF_SIZE];
volatile int empty = BUF_SIZE;
volatile int full = 0; 

void produce(int item){
    if(empty == 0){
        printf(">> [Buffer Full!] Producer waits... (Count: %d)\n", count);
        return;
    }
    empty--;
    buffer[head] = item;
    head = (head + 1) %BUF_SIZE;
    count++;
    full++;
    printf("[PROD] Produced Item %d (Head: %d, Count: %d)\n",item, head, count);
}
void consume(void){
    if(count == 0){
        printf("  >> [Buffer Empty!] Consumer waits... (Count: %d)\n",count);
        return;
    }
    full--;
    int item = buffer[tail];
    tail = (tail+1)%BUF_SIZE;
    count--;
    empty++;
    printf("[CONS] Consumed Item %d (Tail: %d, Count: %d)\n",item,tail,count);
}
int main(int argc, char const *argv[])
{

    printf("=== Day 26: Producer-Consumer Simulation ===\n");
    printf("Buffer Size: %d\n\n", BUF_SIZE);


    produce(1);
    produce(2);

    consume();

    produce(3);
    produce(4);
    produce(5);
    produce(6);

    produce( 7);
    produce(8);

    consume();

    produce( 7);

    consume();
    return 0;
}

