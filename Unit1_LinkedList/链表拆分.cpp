#include<iostream>
using namespace std;

typedef int ElemType;
struct LinkNode {
    ElemType data;          // �����������
    struct LinkNode* next;  // ָ���������
};

void CreateListTail(LinkNode*& L, ElemType a[], int n) {
    // ���ȴ���һ��ͷ�ڵ�
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode* tail = (LinkNode*)malloc(sizeof(LinkNode));
    tail = L;
    for (int i = 0; i < n; ++i) {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = a[i];
        tail->next = s;
        // s->next = NULL; �����������Ҫ
        tail = s;
    }
    tail->next = NULL;  // ��β�ڵ��ָ�����ÿ�
}


void DisplayList(LinkNode* L) {
    LinkNode* pt = L->next;
    while (pt != NULL) {
        cout << "data: " << pt->data << endl;
        pt = pt->next;
    }
}


// ��ĿҪ��L=(a1, b1, a2, b2, ..., an, bn)��Ҫ�������ֳ������֣�L1��L2
// ����L1 = (a1, a2, a3, ...); L2 = (bn, bn-1, ...)��ʵ���Ͼ���β���ͷ��
void split(LinkNode* &L, LinkNode* &L1, LinkNode* &L2) {
    // L1��ͷ������ԭ����
    L1 = L;
    // ����L1���õ���β�巨�����Ի���Ҫһ��βָ��tail
    LinkNode* tail = L1;
    // ����L2��ͷ���
    L2 = (LinkNode*)malloc(sizeof(LinkNode));
    // ��L2��ͷ���ָ����ֵΪNULL
    L2->next = NULL;
    // ����ָ��pt�ӵ�һ����㿪ʼ���б���
    LinkNode* pt = L->next;
    // ������ʱ����temp��ͷ���ʱ�򱣴���һ�����
    LinkNode* temp = NULL;
    // ͷ�巨
    // ������ʼ
    while (pt != NULL) {
        // ���Ȳ���β�巨��������L1
        tail->next = pt;
        tail = pt;
        // ָ���ƶ�
        pt = pt->next;
        // Ȼ�����ͷ�巨��������L2����Ȼͷ���s->next = L2->next��ָ����ᱻ
        // �ƻ���������������Ҫ��ǰ��������
        temp = pt->next;
        // ��ʼͷ��
        pt->next = L2->next;
        L2->next = pt;
        // �ָ�pt��׼����һ��ѭ��
        pt = temp;
    }
    // ����β���tailָ����ֵΪNULL
    tail->next = NULL;
}

int main() {
    LinkNode* L = NULL;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CreateListTail(L, a, 10);
    LinkNode* L1 = NULL;
    LinkNode* L2 = NULL;
    split(L, L1, L2);
    cout << "L1��" << endl;
    DisplayList(L1);
    cout << "---" << endl;
    DisplayList(L2);
}