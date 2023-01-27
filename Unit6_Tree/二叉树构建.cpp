#include<iostream>
using namespace std;


typedef int ElemType;
typedef struct node {
    ElemType data;  // ����Ԫ��
    node* lchild;   // ָ�����ӽ��
    node* rchild;   // ָ���ұߺ��ӽ��
} BTNode;


// �����������д���������
BTNode* createBiTree(char* pre, char* in, int n) {
    if (n <= 0)  return NULL;
    BTNode* p = (BTNode*)malloc(sizeof(BTNode));
    p->data = *pre;
    char* c = NULL;
    for (c = in; c < in + n; ++c) {
        if (*c == *pre)  break;
    }
    int k = c - in;
    p->lchild = createBiTree(pre + 1, in, k);
    p->rchild = createBiTree(pre + k + 1, c + 1, n - k - 1);
    return p;
}

// ���򡢺��򴴽�������
BTNode* createBiTree(char* post, char* in, int n) {
    if (n == NULL)  return NULL;
    BTNode* p = (BTNode*)malloc(sizeof(BTNode));
    p->data = *(post + n - 1);
    char* c = NULL;
    for (c = in; c < in + n; ++c) {
        if (*c == *(post + n - 1))  break;
    }
    int k = c - in;
    p->lchild = createBiTree(post + 1, in, k);
    p->rchild = createBiTree(post + k - 1, c + 1, n - k - 1);
    return p;
}