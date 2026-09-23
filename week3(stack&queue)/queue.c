#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int front;
    int reer;
    int size;
    int capacity;
    int *data;
} Queue;

void createqueue(Queue *queue){
    queue->front = 0;
    queue->reer = 0;
    queue->size = 0;
    queue->capacity = 1;
    queue->data = malloc(sizeof(int));
}

bool empty(Queue *queue){
    if(queue->size==0) return true;
    return false;
}

bool isfull(Queue *queue){
    return queue->size == queue->capacity;
}

void extend(Queue *queue){
    int *newdata = malloc(sizeof(int)*queue->capacity*2);
    for(int i=0;i<queue->size;i++){
        newdata[i] = queue->data[(queue->front+i)%queue->capacity];
    }
    free(queue->data);
    queue->data = newdata;
    queue->capacity *= 2;
    queue->front = 0;
    queue->reer = queue->size;
}

void push(Queue *queue,int val){
    if(isfull(queue)) extend(queue);
    queue->data[queue->reer] = val;
    queue->reer = (queue->reer+1)%queue->capacity;
    queue->size++;
}

void getfront(Queue *queue,int *val){
    if(empty(queue)) return;
    *val = queue->data[queue->front];
}

void pop(Queue *queue){
    if(empty(queue)) return;
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
}

void finish(Queue *queue){
    free(queue->data);
    queue->data = NULL;
    queue->capacity = 0;
    queue->size = 0;
}

int main(){

    return 0;
}