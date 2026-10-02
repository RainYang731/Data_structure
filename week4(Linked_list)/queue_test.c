#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node{
    node *nxt;
    int value;
};

node *createnode(int value){
    node *tmp = malloc(sizeof(node));
    if(!tmp) return NULL;
    tmp->nxt = NULL;
    tmp->value = value;
    return tmp;
}

void push(node **reer,node **head,int value,int *size){
    node *tmp = createnode(value);
    if(!tmp){
        printf("fail\n");
        return;
    }
    if(*reer) (*reer)->nxt = tmp;
    *reer = tmp;
    if(!*head) *head = tmp;
    (*size)++;
    return;
}

void pop(node **reer,node **head,int *size){
    if(!*head){
        printf("fail\n");
        return;
    }
    node *tmp = *head;
    *head = (*head)->nxt;
    if(!*head) *reer = NULL;
    free(tmp);
    (*size)--;
}
int front(node *head,int *out){
    if(!head){
        printf("fail\n");
        return 0;
    }
    *out = head->value;
    return 1;
}
void freequeue(node **head, node **rear){
    while(*head){
        node *now = *head;
        *head = now->nxt;
        free(now);
    }
    *rear = NULL;
}
int main(){
    node *head = NULL, *rear = NULL;
    int size = 0, v;

    push(&rear, &head, 1, &size);
    push(&rear, &head, 2, &size);
    push(&rear, &head, 3, &size);
    if(front(head, &v)) printf("front=%d\n", v);   // 1

    pop(&rear, &head, &size);
    if(front(head, &v)) printf("front=%d\n", v);   // 2

    pop(&rear, &head, &size);
    pop(&rear, &head, &size);
    pop(&rear, &head, &size);                      // fail

    push(&rear, &head, 9, &size);
    if(front(head, &v)) printf("front=%d size=%d\n", v, size);  // 9, 1

    return 0;
}