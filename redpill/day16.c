#include <stdio.h>
#include <stdlib.h>
struct  Node
{
    int data;
    struct Node *next;
};
struct Node *reverse(struct Node *head){
    struct Node *current = head, *prev = NULL, *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(struct Node *node){
    while(node != NULL){
        printf("%d",node->data);
        if(node->next){
            printf(" -> ");
        }
        node = node->next;
    }
}
struct Node *create(int n){
    struct Node *head = NULL;
    struct Node *tail = NULL;
    for(int i = 1; i <= n; i++){
        struct Node *n_node = malloc(sizeof(struct Node));
        if (n_node == NULL) {
            return head;
        }
        n_node->data = i;
        n_node->next = NULL;
        if(head == NULL){
            head = n_node;
            tail = n_node;
        }else{
            tail->next = n_node;
            tail= n_node;
        }
    }
    return head;
}
int main(int argc, char const *argv[])
{
    struct Node *head = create(5);
    printList(head);
    printf("\r\n");
    head = reverse(head);

    printList(head);
    free(head);
    return 0;
}
