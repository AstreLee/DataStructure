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

// 删除链表中元素值最大的结点
void delMaxNode(LinkNode* L) {
    // 1. 定义pre指针指向前面一个结点
    LinkNode* pre = L;
    // 2. 定义pt指针遍历
    LinkNode* pt = L->next;
    // 3. 定义maxPt指针指向元素值最大的结点，现在假设首结点就是元素值最大的结点
    LinkNode* maxPt = L->next;
    // 4. 定义maxPre指针指向元素值最大的结点的前一个结点
    LinkNode* maxPre = L;
    
    // 遍历开始
    while (pt != NULL) {
        if (pt->data > maxPt->data) {
            maxPt = pt;
            maxPre = pre;
        }
        pre = pt;
        pt = pt->next;
    }

    // 从单链表中删除结点
    maxPre->next = maxPt->next;
    free(maxPt);
}

int main() {
    LinkNode* L = NULL;
    int a[] = {-7, 0, 6, 12, -87, 9, 13, 8, 9, 10};
    CreateListTail(L, a, 10);
    delMaxNode(L);
    DisplayList(L);
}