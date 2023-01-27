#include <iostream>
#include <string>
using namespace std;

int count = 0;
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

// 方法一：使用快慢指针
LinkNode* findLastK(LinkNode* L, int k) {
    LinkNode* slow = L->next;
    LinkNode* fast = L->next;
    for (int i = 0; i < k; ++i) {
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 方法二：先遍历到链表尾，然后回溯
LinkNode* findLastK1(LinkNode* L, int k) {
    if (L == NULL)  return NULL;
    LinkNode* temp = findLastK1(L->next, k);
    ++count;
    if (count == k)  return L;
    return temp;
}

int main() {
    string s;
    LinkNode* L = NULL;
    int a[5] = {1, 2, 3, 4, 5};
    CreateListTail(L, a, 5);
    cout << findLastK1(L, 1)->data << endl;
    return 0;
}