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
    LinkNode* tail = (LinkNode*)malloc(sizeof(LinkNode));
    tail = L;
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


// 题目要求：L=(a1, b1, a2, b2, ..., an, bn)，要求将链表拆分成两部分：L1和L2
// 其中L1 = (a1, a2, a3, ...); L2 = (bn, bn-1, ...)，实际上就是尾插和头插
void split(LinkNode* &L, LinkNode* &L1, LinkNode* &L2) {
    // L1的头结点就用原来的
    L1 = L;
    // 由于L1采用的是尾插法，所以还需要一个尾指针tail
    LinkNode* tail = L1;
    // 定义L2的头结点
    L2 = (LinkNode*)malloc(sizeof(LinkNode));
    // 将L2的头结点指针域赋值为NULL
    L2->next = NULL;
    // 定义指针pt从第一个结点开始进行遍历
    LinkNode* pt = L->next;
    // 定义临时变量temp，头插的时候保存下一个结点
    LinkNode* temp = NULL;
    // 头插法
    // 遍历开始
    while (pt != NULL) {
        // 首先采用尾插法将结点插入L1
        tail->next = pt;
        tail = pt;
        // 指针移动
        pt = pt->next;
        // 然后采用头插法将结点插入L2，当然头插会s->next = L2->next，指针域会被
        // 破坏，所以这里我们要提前保存下来
        temp = pt->next;
        // 开始头插
        pt->next = L2->next;
        L2->next = pt;
        // 恢复pt，准备下一次循环
        pt = temp;
    }
    // 最后的尾结点tail指针域赋值为NULL
    tail->next = NULL;
}

int main() {
    LinkNode* L = NULL;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CreateListTail(L, a, 10);
    LinkNode* L1 = NULL;
    LinkNode* L2 = NULL;
    split(L, L1, L2);
    cout << "L1：" << endl;
    DisplayList(L1);
    cout << "---" << endl;
    DisplayList(L2);
}