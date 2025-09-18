#include<stdio.h>

#define MAX 100
typedef struct {
    int data[MAX];
    int size;
} SeqList;

int InitList(SeqList* L) {
    L->size = 0;
    return 1;
}

void PrintList(SeqList L) {
    printf("%d\n",L.size);
}
int main() {
    SeqList L;
    InitList(&L);
    for (int i = 0; i < 10; i++) {
        L.data[L.size++] = i;
    }
    PrintList(L);
    return 0;
}