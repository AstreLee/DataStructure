#include<iostream>

typedef int ElemType;
typedef struct DNode {
    ElemType data;  // ������
    struct DNode* prior;  // ָ��ǰ�����
    struct DNode* next;  // ָ���̽��
} DLinkNode;

// ͷ�巨����˫����
void createListHead(DLinkNode*& L, ElemType a[], int n) {
    // ���ȸ�Lͷ������洢�ռ�
    L = (DLinkNode*)malloc(sizeof(DLinkNode));
    // ��ͷ�ڵ��prior��nextָ��ȫ����ΪNULL
    L->prior = L->next = NULL;
    // ������ʼ��ֵ
    for (int i = 0; i < n; ++i) {
        DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        if (L->next != NULL) {  // ע����������ǵ�һ��ͷ��Ļ���L->next��NULL
            L->next->prior = s;
        }
        L->next = s;
        s->prior = L;
    }
}

// β�巨����˫����
void createListTail(DLinkNode*& L, ElemType a[], int n) {
    // ���ȸ�Lͷ������洢�ռ�
    L = (DLinkNode*)malloc(sizeof(DLinkNode));
    // ��ͷ�ڵ��prior��nextָ��ȫ����ΪNULL
    L->prior = L->next = NULL;
    // ����βָ��
    DLinkNode* tail = L;
    // ����
    for (int i = 0; i < n; ++i) {
        DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];
        tail->next = s;
        s->prior = tail;
        tail = s;
    }
    tail->next = NULL;
}

bool listInsert(DLinkNode* L, int i, ElemType e) {
    if (i < 1)  return false;
    int count = 0;
    DLinkNode* pt = L;
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    if (pt == NULL) return false;
    else {
        DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = pt->next;
        if (pt->next != NULL) {
            pt->next->prior = s;
        }
        s->prior = pt;
        pt->next = s;
        return true;
    }
}

bool listDelete(DLinkNode* L, int i, ElemType& e) {
    if (i < 1)  return false;
    int count = 0;
    DLinkNode* pt = L;
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    if (pt == NULL) return false;
    else {
        if (pt->next == NULL)  return false;
        DLinkNode* temp = pt->next;
        e = temp->data;
        pt->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prior = pt;
        }
        free(temp);
        return true;
    }
}