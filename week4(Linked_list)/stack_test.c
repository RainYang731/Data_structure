#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node{
    node *prev;
    int value;  
};
node *createnode(int value){
    node *tmp = malloc(sizeof(node));
    if(!tmp) return NULL;
    tmp->prev = NULL;
    tmp->value = value;
    return tmp;
}

void push(int value,node **head){
    node *tmp = createnode(value);
    if(!tmp){
        printf("fail\n");
        return;
    }
    tmp->prev = *head;
    *head = tmp;
    return;
}

void pop(node **head){
    node *tmp = *head;
    if(!tmp){
        printf("fail\n");
        return;
    }
    *head = (*head)->prev;
    free(tmp);
    return;
}

void freestack(node *head){
    node *now;
    while(head){
        now = head;
        head = head->prev;
        free(now);
    }
    return;
}
int query(node *head,int *value){
    if(!head){
        printf("fail\n");
        return 0;
    }
    *value = head->value;
    return 1;
}

int main(){
    node *head = NULL;
    int v;

    push(1, &head); push(2, &head); push(3, &head);
    if(query(head, &v)) printf("top=%d\n", v);   // top=3

    pop(&head);
    if(query(head, &v)) printf("top=%d\n", v);   // top=2

    pop(&head); pop(&head);
    pop(&head);                                  // fail(空 stack)
    query(head, &v);                             // fail

    freestack(head);
    return 0;
}