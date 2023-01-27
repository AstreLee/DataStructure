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

// ��ͷ���ĵ������������
void sort(LinkNode* L) {
    // 1. ����ָ��pt���ӵڶ���Ԫ�ؿ�ʼ��������Ϊͷ�����׽�㹹�ɵ�����һ���������
    LinkNode* pt = L->next->next;
    // 2. ����ָ��temp�����浱ǰ�ڵ�ĺ���һ�����
    LinkNode* temp = NULL;
    // ���׽���ָ������ΪNULL
    L->next->next = NULL;
    // ������ʼ
    while (pt != NULL) {
        // ����ptָ��ָ�����һ�����
        temp = pt->next;
        // ���¶���ָ��newPt��ʼ�ӵ�һ����㿪ʼ����
        LinkNode* newPt = L->next;
        // ����ָ��newPre
        LinkNode* newPre = L;
        // ������ʼ
        while (newPt != NULL && newPt->data < pt->data) {
            newPre = newPt;
            newPt = newPt->next;
        }
        if (newPt == NULL) {
            newPre->next = pt;
            pt->next = NULL;
        } else {
            pt->next = newPt;
            newPre->next = pt;
        }
        pt = temp;
    }
}

int main() {
    LinkNode* L = NULL;
    int a[] = {4, 3, 2, 1};
    CreateListTail(L, a, 4);
    sort(L);
    DisplayList(L);
}