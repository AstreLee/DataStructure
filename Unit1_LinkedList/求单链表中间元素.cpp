#include <iostream>
using namespace std;

typedef int ElemType;
struct LinkNode {
    ElemType data;          // �����������
    struct LinkNode* next;  // ָ���������
};

// β�巨��������
void CreateListTail(LinkNode*& L, ElemType a[], int n) {
    // ���ȴ���һ��ͷ�ڵ�
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode* tail = L;
    for (int i = 0; i < n; ++i) {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = a[i];
        tail->next = s;
        // s->next = NULL; �����������Ҫ
        tail = s;
    }
    tail->next = NULL;  // ��β�ڵ��ָ�����ÿ�
}

// ����ָ��Ѱ���м�Ԫ��
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