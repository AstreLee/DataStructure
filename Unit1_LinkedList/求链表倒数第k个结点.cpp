#include <iostream>
#include <string>
using namespace std;

int count = 0;
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

// ����һ��ʹ�ÿ���ָ��
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

// ���������ȱ���������β��Ȼ�����
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