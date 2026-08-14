#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void matrix_maker(int row, int col){
    int **array;
    //행 포인터
    array = malloc(sizeof(int*)*row);
    //한번에 연속되게 메모리 할당
    array[0] = malloc(sizeof(int)*row*col);
    //세팅
    for (int i = 1; i < row; i++)
    {
        array[i] = array[0] + i * col;
    }
    int value = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] = value ++;
        }
        
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    free(array[0]);
    free(array);
    printf(">> Memory successfully freed.\r\n");
}
int main(int argc, char const *argv[])
{
    printf("=== Day 10: Dynamic 2D Array Allocation ===\r\n");
    printf("Generated Matrix (3x4):\r\n");
    matrix_maker(3,4);
    return 0;
}
