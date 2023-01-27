#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct linknode{
    ElemType data;  // ������
    struct linknode* next;  // ָ���� 
}LinkStNode;

// ��ʼ��ջ
void initStack(LinkStNode*& s) {
    s = (LinkStNode*)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

// ����ջ�ռ�
void destoryStack(LinkStNode* s) {
    LinkStNode* pre = s;
    LinkStNode* pt = s->next;
    while (pt != NULL) {
        free(pre);
        pre = pt;
        pt = pt->next;
    }
    free(pre);
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(LinkStNode* s) {
    return s->next == NULL;
}

// ��ջ
void push(LinkStNode* s, ElemType e) {
    // ���ȴ������
    LinkStNode* pt = (LinkStNode*)malloc(sizeof(LinkStNode));
    // ������������ֵ
    pt->data = e;
    // �������Ϊͷ������
    pt->next = s->next;
    // ��ͷ���ָ���²���Ľ��
    s->next = pt;
}

// ��ջ
bool pop(LinkStNode* s, ElemType& e) {
    // ��ջ��Ȼ�������������п���Ϊ�գ���������������Ҫ�ж�һ��
    if (isEmpty(s))  return false;
    e = s->next->data;
    s->next = s->next->next;
    return true;
}

// ȡջ��Ԫ��
bool getTop(LinkStNode* s, ElemType& e) {
    if (isEmpty(s))  return false;
    e = s->next->data;
    return true;
}
