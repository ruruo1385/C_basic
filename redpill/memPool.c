#include <stdio.h>
#include <stdint.h>

// 설정: 블록 크기와 개수
#define BLOCK_SIZE  32
#define POOL_SIZE   10

// 메모리 블록 구조체 (Free List 관리를 위한 연결 리스트 노드)
// 할당되지 않았을 때는 다음 빈 블록을 가리키는 포인터로 사용됨
typedef struct Block {
    struct Block* next;
} Block;

// 메모리 풀 컨텍스트
typedef struct {
    // 실제 메모리 공간 (바이트 배열)
    // 정렬(Alignment)을 위해 uint64_t나 align 속성을 사용할 수 있음
    uint8_t memory_area[POOL_SIZE * BLOCK_SIZE]; 
    
    // 현재 사용 가능한 첫 번째 블록을 가리키는 포인터
    Block* free_list;
    
    // 디버깅용: 현재 사용 중인 블록 수
    int used_count;
} MemoryPool;

// 1. 초기화: 모든 메모리를 쪼개서 연결 리스트로 연결
void pool_init(MemoryPool* pool) {
        pool->used_count = 0;
    //풀사이즈 안에 블럭 사이즈 만큼
    for(int i =0; i <POOL_SIZE; i++){
        Block* curr = (Block*)&pool->memory_area[i*BLOCK_SIZE];
        //마지막 아니면 다음블록 연결
        if(i < POOL_SIZE - 1 ){
            curr->next = (Block*)&pool->memory_area[(i+1)*BLOCK_SIZE];
        }else{
            curr -> next = NULL;
        }
    }
    //가장 첫번째 블록 가르키기
    pool->free_list = (Block*)&pool->memory_area[0];
}

// 2. 할당: Free List의 헤드(Head)를 떼어줌 (Pop)
void* pool_alloc(MemoryPool* pool) {
    //첫번째가 없으면 널 리턴

    if(pool->free_list == NULL){
        return NULL;
    }
    Block* allo = pool->free_list;
    //첫번째 포인터에 다음거를 설정
    pool->free_list = pool->free_list->next;
    pool->used_count ++;
    return(allo);
}

// 3. 해제: 반환된 블록을 Free List의 헤드에 다시 붙임 (Push)
void pool_free(MemoryPool* pool, void* ptr) {
    Block* block = (Block*)ptr;
    block ->next = pool->free_list;
    pool->free_list = block;
    pool->used_count --;
}

// 테스트 코드
int main() {
    MemoryPool my_pool;
    pool_init(&my_pool);

    // 3개 할당
    void* p1 = pool_alloc(&my_pool);
    void* p2 = pool_alloc(&my_pool);
    void* p3 = pool_alloc(&my_pool);
    printf("[Init] Memory Pool Initialized (10 blocks of 32 bytes)\r\n");
    printf("Allocated: %p, %p, %p\n", p1, p2, p3);
    printf("Used Blocks: %d\n", my_pool.used_count);

    // 1개 해제 (p2)
    printf("Freeing %p...\n", p2);
    pool_free(&my_pool, p2); // 이제 p2가 free_list의 head가 됨
    
    // 다시 1개 할당 (p2와 같은 주소가 나와야 함 - LIFO 특성)
    void* p4 = pool_alloc(&my_pool);
    printf("Re-allocated: %p (Should be same as old p2)\n", p4);

    return 0;
}