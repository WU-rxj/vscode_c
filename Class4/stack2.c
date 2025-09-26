#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>

typedef struct stacknode{
    int data;
    struct stacknode* next;
}stacknode, *stacknodeptr;

_Bool isempty(stacknodeptr *top){
    if(*top==NULL){
        return 1;
    }else{
        return 0;
    }
}

void initstack(stacknodeptr *top){
    *top=NULL;
}

void push(stacknodeptr *top, int x){
    stacknodeptr newnode=(stacknodeptr)malloc(sizeof(stacknode));
    newnode->data=x;
    newnode->next=*top;
    *top=newnode;
}

void pop(stacknodeptr *top, int *x){

    if(isempty(top)){
        return;
    }
    stacknodeptr temp=*top;
    *top=(*top)->next;
    *x=temp->data;
    free(temp);
}

void clear(stacknodeptr *top){
    stacknode *temp;
    while(!isempty(top)){
        temp=*top;
        *top=(*top)->next;
        free(temp);
    }
}
