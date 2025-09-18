#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

/*
Args:
* head:pointer of the head node.
Return:
* True or false.
Description:
* Create an empty linked list with a head node.
* The "next" field of the head node should point to NULL.
*/

typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node* next;
}Node;

void PrintList(Node* head){
        Node *p = head->next;
        if (p == NULL) {
                printf("Empty List");
        }
        while (p != NULL) {
                printf("%d ", p->data);
                p = p->next;
        }
        printf("\n");
}

_Bool CreateEmptyList(Node** head){
	*head=(Node*)malloc(sizeof(Node));
    if(*head==NULL) return false;
    (*head)->next=NULL;
	(*head)->data=0;
	return true;
}


/*
Args:
* addr: pointer of an array.
* n: length of the array.
* head:pointer of the head node.
Return:
* True or false.
Description:
* Initialize a linked list with an array.
*/
_Bool CreateList(DataType *addr, unsigned int n, Node** head){
    *head=malloc(sizeof(Node));
    if(*head==NULL) return false;
    (*head)->next=NULL;
    Node* tail=*head;
    for(unsigned int i=0;i<n;i++){
        Node* newnode=malloc(sizeof(Node));
        if(newnode==NULL) return false;
        newnode->data=addr[i];
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
	return true;
}


/*
Args:
* head: pointer of the head node.
Returns:
* True or false.
Description:
* Destroy the linked list.
* Release all allocated memory.
*/
_Bool DestroyList(Node *head){
    Node* p=head;
    while(p!=NULL){
        Node* q=p;
        p=p->next;
        free(q);
    }
    head=NULL;
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the inserted data.
* data: the inserted data.
Returns:
* True or false.
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 0, 6), the linked
* list will be "head->6->3->5->2".
*/
_Bool ListInsert(Node *head, unsigned int index, DataType e){
	Node* p=head;
	for(unsigned int i=0;i<index;i++){
		p=p->next;
	}
	Node* newnode=malloc(sizeof(Node));
	if(newnode==NULL) return false;
	newnode->data=e;
	newnode->next=p->next;
	p->next=newnode;
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the deleted data.
* e:The deleted data.
Returns:
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 2), the linked
* list will be "head->3->5".
*/
_Bool ListDelete(Node *head, unsigned int index, DataType* e){
	Node* p=head;
	for(unsigned int i=0;i<index;i++){
		p=p->next;
	}
	Node* q=p->next;
	p->next=q->next;
	free(q);
	return true;
}

int main(){
    int n;
    scanf("%d", &n);
    int ops[10000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ops[i]);
    }
    int data[10000];
    int data_cnt = 0;
    // 预读第三行所有数据
    for (int i = 0; i < n; i++) {
        if (ops[i] == 3 || ops[i] == 4) {
            scanf("%d", &data[data_cnt++]);
            scanf("%d", &data[data_cnt++]);
        }
    }

    Node *head = NULL;
    int data_idx = 0;
    int del_val;
    int arr[10000]={0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < n; i++) {
        switch (ops[i]) {
            case 1:
                CreateEmptyList(&head);
                break;
            case 2:
                CreateList(arr, 10, &head);
                break;
            case 3:
                {
                    int idx = data[data_idx++];
                    DataType val = data[data_idx++];
                    ListInsert(head, idx, val);
                }
                break;
            case 4:
                {
                    unsigned int idx = data[data_idx++];
                    data_idx++;
                    ListDelete(head, idx, &del_val);
                }
                break;
            case 5:
                DestroyList(head);
                head = NULL;
                break;
        }
        PrintList(head);
    }
    return 0;
}
