#include <stdint.h>
#include <stdio.h>
#define MAX  8
typedef struct{
    uint8_t buffer[MAX];
    int head;
    int tail;
}RingBuffer;
void bufInit(RingBuffer *rb){
    rb->head = 0;
    rb->tail = 0;
}
void* put(RingBuffer *rb, int val){
    //헤드위치가 테일 위치면
    if ((rb->head + 1) % MAX == rb->tail) {
        return 0;
    }
    //tail에 값 넣기
    rb->buffer[rb->head] = val;
    rb->head = (rb->head + 1) % MAX;
    return 1;
}
void* get(RingBuffer *rb, uint8_t *val){
    *val = rb->buffer[rb->tail];
    rb->tail = (rb->tail +1) % MAX;
}
// ---- 테스트 코드 ----
int main() {
    RingBuffer uart_rx_buf;
    uint8_t temp;

    bufInit(&uart_rx_buf);

    printf("--- Phase 1: Filling Buffer ---\n");
    // 버퍼 사이즈가 8이므로, 한 칸 비우면 최대 7개 저장 가능
    for (int i = 1; i <= 8; i++) {
        if (put(&uart_rx_buf, i)) {
            printf("Put: %d (Head: %d, Tail: %d)\n", i, uart_rx_buf.head, uart_rx_buf.tail);
        } else {
            printf("Fail to Put: %d (Buffer Full!)\n", i);
        }
    }

    printf("\n--- Phase 2: Reading Buffer ---\n");
    // 3개만 읽어봄
    for (int i = 0; i < 3; i++) {
        if (get(&uart_rx_buf, &temp)) {
            printf("Get: %d (Head: %d, Tail: %d)\n", temp, uart_rx_buf.head, uart_rx_buf.tail);
        }
    }

    printf("\n--- Phase 3: Writing again (Wrap around) ---\n");
    // 읽어서 공간이 생겼으므로 다시 쓰기 가능 (인덱스가 0으로 돌아가는지 확인)
    if (put(&uart_rx_buf, 99)) {
         printf("Put: 99 (Head: %d, Tail: %d)\n", uart_rx_buf.head, uart_rx_buf.tail);
    }

    return 0;
}
