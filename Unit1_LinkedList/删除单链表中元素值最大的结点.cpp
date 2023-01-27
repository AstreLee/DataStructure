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


void DisplayList(LinkNode* L) {
    LinkNode* pt = L->next;
    while (pt != NULL) {
        cout << "data: " << pt->data << endl;
        pt = pt->next;
    }
}

// ɾ��������Ԫ��ֵ���Ľ��
void delMaxNode(LinkNode* L) {
    // 1. ����preָ��ָ��ǰ��һ�����
    LinkNode* pre = L;
    // 2. ����ptָ�����
    LinkNode* pt = L->next;
    // 3. ����maxPtָ��ָ��Ԫ��ֵ���Ľ�㣬���ڼ����׽�����Ԫ��ֵ���Ľ��
    LinkNode* maxPt = L->next;
    // 4. ����maxPreָ��ָ��Ԫ��ֵ���Ľ���ǰһ�����
    LinkNode* maxPre = L;
    
    // ������ʼ
    while (pt != NULL) {
        if (pt->data > maxPt->data) {
            maxPt = pt;
            maxPre = pre;
        }
        pre = pt;
        pt = pt->next;
    }

    // �ӵ�������ɾ�����
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