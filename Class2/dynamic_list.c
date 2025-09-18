#include <stdio.h>
#include <stdlib.h>

# define INIT_SIZE 100
# define INCREMENT 10
typedef struct {
    int *data;// 存储空间基址
    int size;// 当前长度
    int capacity;// 当前分配的存储容量
} SqList;
int InitList(SqList *L) {
    L->data = (int *)malloc(INIT_SIZE * sizeof(int));
    if (!L->data) return 0;// 存储分配失败
    L->size = 0;
    L->capacity = INIT_SIZE;
    return 1;
}
int getElem(SqList L, int i, int *e) {
    if (i < 1 || i > L.size) return 0;// i值不合法
    *e = L.data[i - 1];
    return 1;
}
int listInsert(SqList *L, int i, int e) {
    if (i < 1 || i > L->size + 1) return 0;// i值不合法
    if (L->size >= L->capacity) {// 当前存储空间已满，增加分配
        int *newbase = (int *)realloc(L->data, (L->capacity + INCREMENT) * sizeof(int));
        if (!newbase) return 0;// 存储分配失败
        L->data = newbase;// 新基址
        L->capacity += INCREMENT;// 增加存储容量
    }
    for (int j = L->size; j >= i; j--) {// 插入位置及之后的元素右移
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;// 插入e
    L->size++;// 表长增1
    return 1;
}
int listDelete(SqList *L, int i, int *e) {
    if (i < 1 || i > L->size) return 0;// i值不合法
    *e = L->data[i - 1];
    for (int j = i; j < L->size; j++) {// 删除位置及之后的元素左移
        L->data[j - 1] = L->data[j];
    }
    L->size--;// 表长减1
    return 1;
}
int clearList(SqList *L) {
    L->size = 0;
    return 1;
}
int main(){
    SqList L;
    InitList(&L);//初始化
    for(int i = 0; i < 10; i++){
        L.data[L.size++] = i;
    }
    printf("size: %d\n", L.size);
    free(L.data);
    return 0;
}