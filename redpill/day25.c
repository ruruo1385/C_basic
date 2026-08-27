#include <stdio.h>
#include <stdint.h>

#define WSIZE 5
typedef struct{
    float buffer[WSIZE];
    float sum;
    float avg;
    int index;
    int count;
}movingAvg;
void filterInit(movingAvg *filter){
    filter->index = 0;
    filter->count = 0;
    filter->avg = 0.0f;
    filter->sum = 0.0f;
    for (int i = 0; i<WSIZE; i++){
        filter->buffer[i] = 0.0f;
    }
}

float filterMove(movingAvg *filter, float input){
    //on first 
    if(filter->count == 0){
        filter->buffer[filter->index] = input;
        filter->sum += input;
        filter->count++;
        filter->index = (filter->index+1)%WSIZE;
        filter->avg = filter->sum/ filter->count;
        return filter->avg;
    }
    //check min max and return
    float min = filter->avg * 0.5f;
    float max = filter->avg * 1.5f;
    if(input < min || input > max){
        return filter->avg;
    }
    //if buffer isnt full
    if(filter->count < WSIZE){
        filter->buffer[filter->index] = input;
        filter->sum += input;
        filter->count++;
    }else{
        //if buffer is full remove the oldest
        filter->sum -=  filter->buffer[filter->index];
        filter->buffer[filter->index] = input;
        filter->sum += input;
    }
    filter->index = (filter->index+1)%WSIZE;
    filter->avg = filter->sum / filter->count;
    return filter->avg;
}
int main(int argc, char const *argv[])
{
    movingAvg filter;

    filterInit(&filter);

    float input[] =
    {
        20.0f,
        22.0f,
        18.0f,
        25.0f,
        15.0f,
        20.0f,
        21.0f,
        19.0f,
        20.5f,
        20.0f
    };

    int size = sizeof(input) / sizeof(input[0]);


    printf("=== Day 25: Moving Average Filter (Sliding Window) ===\n");
    printf("Window Size: %d\n\n", WSIZE);

    printf("Step | Raw Input | Filtered Output\n");
    printf("-----+-----------+----------------\n");


    for (int i = 0; i < size; i++)
    {
        float result =
            filterMove(&filter, input[i]);

        printf("%4d | %9.1f | %13.1f\n",
               i + 1,
               input[i],
               result);
    }

    return 0;
}
