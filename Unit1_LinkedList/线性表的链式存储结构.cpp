#include <iostream>
using namespace std;

typedef int ElemType;
struct LinkNode {
    ElemType data;          // �����������
    struct LinkNode* next;  // ָ���������
};

// ���庯��
void CreateListHead(LinkNode*& L, ElemType a[], int n);  // ͷ�巨
void CreateListTail(LinkNode*& L, ElemType a[], int n);  // β�巨
void InitList(LinkNode*& L);                             // ��ʼ������
void DestoryList(LinkNode* L);                           // ��������
bool IsListEmpty(LinkNode* L);  // �ж������Ƿ�Ϊ��
int LengthOfList(LinkNode* L);  // ��������ĳ���
void Display(LinkNode* L);      // ������Ա�
bool GetElemByIndex(LinkNode* L, int i, ElemType& e);  // �����±귵�ض�ӦԪ��
bool GetElem(LinkNode* L, ElemType e, int& i);  // ����ָ��Ԫ�ض�Ӧ�±�
bool InsertNodeByIndex(LinkNode* L, int i, ElemType e);  // ��ָ��λ�ô�����Ԫ��
bool DelNodeByIndex(LinkNode* L,
                    int i,
                    ElemType& e);  // ɾ��ָ��λ��Ԫ�أ����һ�ȡ���Ԫ��
int LocateElem(LinkNode* L, ElemType e);  // ��ȡԪ���������еĶ�Ӧλ��
bool ListInsert(LinkNode* L, int i, ElemType e); // ��������Ԫ��
bool ListDelete(LinkNode* L, int i, ElemType& e);  // ɾ��Ԫ��



// ͷ�巨
void CreateListHead(LinkNode*& L, ElemType a[], int n) {
    // ���ȴ���һ��ͷ�ڵ�
    L = (LinkNode*)malloc(sizeof(LinkNode));
    // ����һ��ָ��������ˣ�����������ν����ֻ����Ϊһ��ͷ�ڵ㣬��һ��ܹؼ�����Ȼ���ǵ��������Ͳ���NULL
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = a[i];
        // ���������Ǻ��Ĵ���
        s->next = L->next;
        L->next = s;
    }
}

// β�巨
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

// ��ʼ������
void InitList(LinkNode*& L) {
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
}

// ��������
void DestoryList(LinkNode* L) {
    LinkNode* pre = L;  // ָ��preָ��ͷ���
    LinkNode* pt = L->next;  // ָ��ptָ���׽��
    while (pt != NULL) {
        free(pre);
        pre = pt;
        pt = pt->next;
    }
    free(pre);  // ����β���
}

// �ж������Ƿ�Ϊ��
bool IsListEmpty(LinkNode* L) {
    return L->next == NULL;
}

// ����������
int LengthOfList(LinkNode* L) {
    int count = 0;
    LinkNode* pt = L->next;
    while (pt != NULL) {
        ++count;
        pt = pt->next;
    }
    return count;
}

// �������
void DisplayList(LinkNode* L) {
    LinkNode* pt = L->next;
    while (pt != NULL) {
        cout << "data: " << pt->data << endl;
        pt = pt->next;
    }
}

// �������ж�Ӧλ�õ�Ԫ��ֵ
bool GetElemByIndex(LinkNode* L, int i, ElemType& e) {
    // ���ڲ���˳�������ֱ�ӱ��������Ա�ĳ��ȣ������������Ȳ���֪����ֻ�ܱ���
    if (i < 1)  return false;  // λ���쳣����
    int count = 1;  // ͳ�Ƶ�ǰ�������ڼ������
    LinkNode* pt = L->next;  // ptָ�븺�������ָ���׽��
    while (count < i && pt != NULL) {  // ��û�б�������������û�жϵ�����¼���
        pt = pt->next;
        ++count;
    }
    // ѭ�����������ֿ��ܵ����
    // ���һ��û�б�����λ��i������Ѿ�����
    if (pt == NULL)  return false;
    // ��������Ѿ��ҵ��˶�Ӧλ�õ�Ԫ��
    e = pt->data;
    return true;
}

// Ѱ��Ԫ���������еĶ�Ӧλ��
int LocateElem(LinkNode* L, ElemType e) {
    LinkNode* pt = L->next;
    int pos = 1;  // pos��¼��ǰ�������˵ڼ���Ԫ��
    while (pt != NULL && pt->data != e) {
        pt = pt->next;
        ++pos;
    }
    // ����ͬ�����������
    // ���һ�������������Ҳû�ҵ�
    if (pt == NULL)  return -1;
    // ������������������֮����Ѿ��ҵ���
    return pos;
}

// ��������Ԫ��
bool ListInsert(LinkNode* L, int i, ElemType e) {
    // ���Ƚ��г����쳣����
    if (i < 1)  return false;
    int count = 0;  // ��ʾ��ǰ�Ѿ��������˼������
    LinkNode* pt = L;  // ָ��pt�������
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    // ��������ͬ�����������
    if (pt == NULL) return false;
    else {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = pt->next;
        pt->next = s;
        return true;
    }
}

// ɾ������Ԫ��
bool ListDelete(LinkNode* L, int i, ElemType& e) {
    // ɾ��λ���쳣����
    if (i < 1)  return false;
    int count = 0;  // count��¼��ǰ�������Ľ����
    LinkNode* pt = L;
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    // ������ʱ��ͬ�����������
    if (pt == NULL)  return false;
    else {
        // ���ɾ����λ�������һ��Ԫ�غ���һ��λ�õĻ�
        if (pt->next == NULL)  return false;
        // ����Ļ����Ǿ�����ɾ��
        LinkNode* pre = pt;
        pt = pt->next;
        pre->next = pt->next;
        free(pt);
        return true;
    }
}