#include <iostream>
#include <stack>
#include "singleList.h"
using namespace std;

// ����һ���õݹ飬���ֵ�������ıȽ��Ƽ�
void reverseList_1(Lnode* L) {
    // �ݹ����
    if (L == NULL) {
        return;
    }
    reverseList_1(L->next);
    cout << L->data << " ";
}

// ��������ʹ��ͷ�巨����һ���µ�����
Lnode* reverseList_2(Lnode* L) {
    // ����һ��ͷ���ָ������L
    Lnode* head = (Lnode*)malloc(sizeof(Lnode));
    head->next = L;
    // ��ʼͷ��
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

// ��������ʹ��ջ�ռ䱣���Ѿ��������Ľ��
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
    // ����������
    int arr[] = {1, 2, 3, 4, 5, 6};
    Lnode* L = initWithoutHead(arr, 6);
    // reverseList_1(L);
    // displayList(reverseList_2(L));
    reverseList_3(L);
    return 0;
}