#include<iostream>
using namespace std;

typedef struct node {
    char data;  // ������
    int ltag, rtag;  // ���ұ�־
    node* lchild;  // ���ӽ��
    node* rchild;  // �Һ��ӽ��
} TBTNode;

TBTNode* pre = NULL;  // ����ȫ�ֱ���preָ��ղŷ��ʹ��Ľ�㣬��ʼ��ָ��root�����

void threadBiTree(TBTNode* & p) {
    if (p != NULL) {
        threadBiTree(p->lchild);  // ������������
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        } else {
            p->ltag = 0;
        }
        if (pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        } else {
            pre->rtag = 0;
        }
        pre = p;
        threadBiTree(p->rchild);  // ������������
    }
}

TBTNode* createThread(TBTNode* b) {
    TBTNode* root = (TBTNode*)malloc(sizeof(TBTNode));
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = b;  // ��ָ���ʼ��ָ������
    if (b == NULL) {
        root->lchild = root;
    } else {
        root->lchild = b;
        pre = root;
        threadBiTree(b);
        pre->rchild = root;
        pre->rtag = 1;
        root->rchild = pre;
    }
}


void ThInOrder(TBTNode* tb) {
    TBTNode* p = tb->lchild;  // pָ��������ĸ����
    while (p != tb) {  // ���������е����һ������ָ�����㣬�������ѭ����һ���������
        // һֱ����Ѱ�ҵ���һ�����
        while (p->ltag == 0) {
            p = p->lchild;
        }
        // �����һ�����ֵ
        cout << p->data << " ";
        // ����ǰ�ڵ����ָ������������ָ��������
        // ����������Ļ�(ע�⻹��Ҫ����p->rchild != tb����Ϊ���һ�����ָ��ľ��Ǹ����root)
        while (p->rtag == 1 && p->rchild != tb) {
            p = p->rchild;
            cout << p->data << " ";
        }
        p = p->rchild;  // ��������ͬ���Ĳ���
    }
}