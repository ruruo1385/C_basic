#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct Debounce{
    int stable;
    int counter;
    int N;
};
void debounceInit(struct Debounce *db, int n){
    db->stable = 0;
    db->counter = 0;
    db->N = n;
}
int debounce(struct Debounce *db, int input){
    if(input == db->stable){
        db->counter =0;
    }else{
        
        db->counter++;
        if(db->counter >= db->N){
            db->stable = input;
            db->counter = 0;
            printf(">> [State Changed] to %d\n", db->stable);
        }
    }
    return db->stable;
}

int main(int argc, char const *argv[])
{
    int input[] = {0, 0, 1, 0, 1, 1, 1, 1, 1, 0};
    int size = sizeof(input) / sizeof(input[0]);

    struct Debounce db;

    debounceInit(&db, 3);

    printf("Step | Raw Input | Counter | Output\n");
    printf("-----+-----------+---------+--------\n");

    for (int i = 0; i < size; i++) {

        int output = debounce(&db, input[i]);

        printf("%4d | %9d | %7d | %6d\n",
            i + 1,
            input[i],
            db.counter,
            output);
    }


    return 0;
}
