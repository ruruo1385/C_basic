#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//링크 리스트 위한 스트럭트
typedef struct Timer{
    int id;
    int delta;
    void (*callback)(int id);
    struct  Timer *next;
}Timer;
Timer *head = NULL;

//callback
void timer_callback(int id){
    printf("[Event] Timer %d expired! Action executed.\n", id);
}
void setTimer(int id, int ms){
    Timer *new_t = malloc(sizeof(Timer));
    if (new_t == NULL)
    {
        return;
    }
    new_t->id = id;
    new_t->delta = ms;
    new_t->callback = timer_callback;
    new_t->next = NULL;
    //리스트가 비어 있다면
    if(head == NULL){
        head = new_t;
        return;
    }
    int remaining = ms;
    Timer *current = head;
    Timer *previous = NULL;
    //새 타이머 위치 찾기
    while(current != NULL && remaining >= current->delta){
        remaining -= current->delta;
        previous = current;
        current = current->next;
    }
    new_t->delta = remaining;
    //기존 다음 타이머 델타 보정
    if(current!=NULL){
        current->delta -= remaining;
    }
    //헤드 앞에 삽입
    if(previous == NULL){
        new_t->next = head;
        head = new_t;
    }else{
        //중간 또는 끝에
        new_t->next = current;
        previous->next = new_t;
    }
}
void tick(int tick_count){
    //헤드가 없으면 리턴
    if (head == NULL){
        return;
    }
    //있으면 하나 빼고
    head->delta--;
    //델타 값이 0 이상이면 프린트
    if (head->delta > 0)
    {
        printf("Tick %d: Rem Head dt: %d\n",
               tick_count,
               head->delta);
    }
    //헤드 값이 0일때 
    while (head != NULL && head->delta <= 0)
    {
        Timer *expired = head;

        head = head->next;

        printf("Tick %d: >> [Event] Timer %d expired! Action executed.\n",
               tick_count,
               expired->id);

        expired->callback(expired->id);

        free(expired);

        if (head != NULL)
        {
            printf("Rem Head dt: %d\n", head->delta);
        }
    }
}
void printTimers(void)
{
    Timer *current = head;

    printf("[Timer List] ");

    while (current != NULL)
    {
        printf("(ID:%d, dt:%d)", current->id, current->delta);

        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }

    printf(" -> NULL\n");
}
int main(int argc, char const *argv[])
{
    setTimer(1, 5);
    printTimers();

    setTimer(2, 10);
    printTimers();

    setTimer(3, 25);
    printTimers();

    printf("\n>> Start Ticking...\n");

    for (int i = 1; i <= 25; i++)
    {
        tick(i);
    }
    if (head == NULL)
    {
        printf("All timers cleared.\n");
    }

    return 0;
}
