#include <iostream>
#include <stack>
#include "singleList.h"
using namespace std;

// 方法一：用递归，这种倒序输出的比较推荐
void reverseList_1(Lnode* L) {
    // 递归出口
    if (L == NULL) {
        return;
    }
    reverseList_1(L->next);
    cout << L->data << " ";
}

// 方法二：使用头插法构建一个新的链表
Lnode* reverseList_2(Lnode* L) {
    // 声明一个头结点指向链表L
    Lnode* head = (Lnode*)malloc(sizeof(Lnode));
    head->next = L;
    // 开始头插
    Lnode* pt = L->next;
    L->next = NULL;
    Lnode* q = NULL;
    while (pt != NULL) {
        q = pt->next;
        pt->next = head->next;
        head->next = pt;
        pt = q;
    }
    return head->next;
}

// 方法三：使用栈空间保存已经遍历过的结点
void reverseList_3(Lnode* L) {
    stack<Lnode*> s;
    while (L != NULL) {
        s.push(L);
        L = L->next;
    }
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main() {
    // 创建单链表
    int arr[] = {1, 2, 3, 4, 5, 6};
    Lnode* L = initWithoutHead(arr, 6);
    // reverseList_1(L);
    // displayList(reverseList_2(L));
    reverseList_3(L);
    return 0;
}