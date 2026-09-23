#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct{
    int *data;
    int top;
    int capacity;
} Stack;

void Createstack(Stack *stack){
    stack->top = -1;
    stack->capacity = 1;
    stack->data = malloc(sizeof(int)*1);
}

bool empty(Stack *stack){
    return stack->top < 0;
}

bool ISfull(Stack *stack){
    return stack->top >= stack->capacity-1;
}

void extend(Stack *stack){
    stack->data = realloc(stack->data, sizeof(int) * stack->capacity*2);
    stack->capacity *= 2;
}

void push(Stack *stack,int a){
    if(ISfull(stack)) extend(stack);
    stack->top++;
    stack->data[stack->top] = a;
}

bool pop(Stack *stack,int *value){
    if(empty(stack)) return -1;
    *value = stack->data[stack->top];
    stack->top--;
    return 1;
}

void finish(Stack *stack){
    free(stack->data);
    stack->data = NULL;
}

int main(){
    return 0;
    
}