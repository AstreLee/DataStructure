#include <iostream>
using namespace std;

typedef int ElemType;
struct LinkNode {
    ElemType data;          // 数据域的内容
    struct LinkNode* next;  // 指针域的内容
};

// 尾插法创建链表
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

// 快慢指针寻找中间元素
LinkNode* findMidElem(LinkNode* L) {
    LinkNode* slow = L->next;
    LinkNode* fast = L->next->next;
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    LinkNode* L = NULL;
    int a[5] = {1, 2, 3, 4, 5};
    CreateListTail(L, a, 5);
    cout << findMidElem(L)->data << endl;
    return 0;
}