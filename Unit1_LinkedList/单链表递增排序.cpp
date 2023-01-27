#include<iostream>
using namespace std;

typedef int ElemType;
struct LinkNode {
    ElemType data;          // 数据域的内容
    struct LinkNode* next;  // 指针域的内容
};

void CreateListTail(LinkNode*& L, ElemType a[], int n) {
    // 首先创建一个头节点
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode* tail = L;
    for (int i = 0; i < n; ++i) {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = a[i];
        tail->next = s;
        // s->next = NULL; 这个操作不需要
        tail = s;
    }
    tail->next = NULL;  // 将尾节点的指针域置空
}


void DisplayList(LinkNode* L) {
    LinkNode* pt = L->next;
    while (pt != NULL) {
        cout << "data: " << pt->data << endl;
        pt = pt->next;
    }
}

// 带头结点的单链表递增排列
void sort(LinkNode* L) {
    // 1. 定义指针pt，从第二个元素开始遍历，因为头结点和首结点构成的链表一定是有序的
    LinkNode* pt = L->next->next;
    // 2. 定义指针temp，保存当前节点的后面一个结点
    LinkNode* temp = NULL;
    // 将首结点的指针域置为NULL
    L->next->next = NULL;
    // 遍历开始
    while (pt != NULL) {
        // 保存pt指针指向的下一个结点
        temp = pt->next;
        // 重新定义指针newPt开始从第一个结点开始遍历
        LinkNode* newPt = L->next;
        // 定义指针newPre
        LinkNode* newPre = L;
        // 遍历开始
        while (newPt != NULL && newPt->data < pt->data) {
            newPre = newPt;
            newPt = newPt->next;
        }
        if (newPt == NULL) {
            newPre->next = pt;
            pt->next = NULL;
        } else {
            pt->next = newPt;
            newPre->next = pt;
        }
        pt = temp;
    }
}

int main() {
    LinkNode* L = NULL;
    int a[] = {4, 3, 2, 1};
    CreateListTail(L, a, 4);
    sort(L);
    DisplayList(L);
}