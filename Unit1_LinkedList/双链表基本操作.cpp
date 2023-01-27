#include<iostream>

typedef int ElemType;
typedef struct DNode {
    ElemType data;  // 数据域
    struct DNode* prior;  // 指向前驱结点
    struct DNode* next;  // 指向后继结点
} DLinkNode;

// 头插法建立双链表
void createListHead(DLinkNode*& L, ElemType a[], int n) {
    // 首先给L头结点分配存储空间
    L = (DLinkNode*)malloc(sizeof(DLinkNode));
    // 将头节点的prior和next指针全部置为NULL
    L->prior = L->next = NULL;
    // 遍历开始赋值
    for (int i = 0; i < n; ++i) {
        DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        if (L->next != NULL) {  // 注意这里如果是第一次头插的话，L->next是NULL
            L->next->prior = s;
        }
        L->next = s;
        s->prior = L;
    }
}

// 尾插法建立双链表
void createListTail(DLinkNode*& L, ElemType a[], int n) {
    // 首先给L头结点分配存储空间
    L = (DLinkNode*)malloc(sizeof(DLinkNode));
    // 将头节点的prior和next指针全部置为NULL
    L->prior = L->next = NULL;
    // 定义尾指针
    DLinkNode* tail = L;
    // 遍历
    for (int i = 0; i < n; ++i) {
        DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];
        tail->next = s;
        s->prior = tail;
        tail = s;
    }
    tail->next = NULL;
}

bool listInsert(DLinkNode* L, int i, ElemType e) {
    if (i < 1)  return false;
    int count = 0;
    DLinkNode* pt = L;
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    if (pt == NULL) return false;
    else {
        DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = pt->next;
        if (pt->next != NULL) {
            pt->next->prior = s;
        }
        s->prior = pt;
        pt->next = s;
        return true;
    }
}

bool listDelete(DLinkNode* L, int i, ElemType& e) {
    if (i < 1)  return false;
    int count = 0;
    DLinkNode* pt = L;
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    if (pt == NULL) return false;
    else {
        if (pt->next == NULL)  return false;
        DLinkNode* temp = pt->next;
        e = temp->data;
        pt->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prior = pt;
        }
        free(temp);
        return true;
    }
}