#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

int isearch(int i,Node *head){
    Node* p=head;
    for (int j=0;j<i;j++){
        p=p->next;
    }
    return p->data;
}
int main(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    Node* tail=head;
    for(int i=0;i<10;i++){
        Node* newnode=(Node*)malloc(sizeof(Node));
        newnode->data=i;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
    for(int i=0;i<10;i++){
        printf("%d ",isearch(i,head));
    }
    return 0;
}