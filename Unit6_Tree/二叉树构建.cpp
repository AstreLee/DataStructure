#include<iostream>
using namespace std;


typedef int ElemType;
typedef struct node {
    ElemType data;  // 数据元素
    node* lchild;   // 指向左孩子结点
    node* rchild;   // 指向右边孩子结点
} BTNode;


// 先序、中序序列创建二叉树
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

// 中序、后序创建二叉树
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