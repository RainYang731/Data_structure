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
    tmp->value = value;
    tmp->nxt = NULL;
    return tmp;
}

void nodeinsert(int value,int pos,node **head,int *size){
    if(pos > *size || pos<0){
        printf("nen\n");
        return;
    }
    node *tmp = createnode(value);
    if(!tmp) return;
    if(pos==0){
        tmp->nxt = *head;
        *head = tmp;
    }else{
        node *prev = *head;
        for(int i=0;i<pos-1;i++) prev = prev->nxt;
        tmp->nxt = prev->nxt;
        prev->nxt = tmp;
    }
    (*size)++;
    return;
}

void nodedel(int pos,node **head,int *size){
    if(pos>=*size || pos < 0){
        printf("neh\n");
        return;
    }
    if(pos == 0){
        node *now = *head;
        *head = (*head)->nxt;
        free(now);
    }else{
        node *prev = *head,*now;
        for(int i=0;i<pos-1;i++) prev = prev->nxt;
        now = prev->nxt;
        prev->nxt = now->nxt;
        free(now);
    }
    (*size)--;
}

void query(node *head){
    while(head!=NULL){
        printf("%d ",head->value);
        head = head->nxt;
    }
    printf("\n");
    return;
}

void freelist(node **head){
    node *now = *head;
    while(now){
        node *next = now->nxt;
        free(now);
        now = next;
    }
    *head = NULL;
}
int main(){
    node *head = NULL;
    int size = 0;

    nodeinsert(10, 0, &head, &size);  // 10
    nodeinsert(30, 1, &head, &size);  // 10 30
    nodeinsert(20, 1, &head, &size);  // 10 20 30
    nodeinsert(5,  0, &head, &size);  // 5 10 20 30
    query(head); printf("size=%d\n", size);

    nodeinsert(99, -1, &head, &size); // nen
    nodeinsert(99, 5,  &head, &size); // nen

    nodedel(0, &head, &size);         // 10 20 30
    nodedel(2, &head, &size);         // 10 20
    nodedel(1, &head, &size);         // 10
    query(head); printf("size=%d\n", size);

    nodedel(1, &head, &size);         // neh
    nodedel(0, &head, &size);         // 空
    query(head); printf("size=%d\n", size);

    freelist(&head);
    return 0;
}