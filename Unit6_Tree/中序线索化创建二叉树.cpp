#include<iostream>
using namespace std;

typedef struct node {
    char data;  // 数据域
    int ltag, rtag;  // 左、右标志
    node* lchild;  // 左孩子结点
    node* rchild;  // 右孩子结点
} TBTNode;

TBTNode* pre = NULL;  // 定义全局变量pre指向刚才访问过的结点，初始化指向root根结点

void threadBiTree(TBTNode* & p) {
    if (p != NULL) {
        threadBiTree(p->lchild);  // 线索化左子树
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
        threadBiTree(p->rchild);  // 线索化右子树
    }
}

TBTNode* createThread(TBTNode* b) {
    TBTNode* root = (TBTNode*)malloc(sizeof(TBTNode));
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = b;  // 右指针初始化指向子树
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
    TBTNode* p = tb->lchild;  // p指向二叉树的根结点
    while (p != tb) {  // 由于序列中的最后一个结点会指向根结点，所以这个循环是一定会结束的
        // 一直左下寻找到第一个结点
        while (p->ltag == 0) {
            p = p->lchild;
        }
        // 输出第一个结点值
        cout << p->data << " ";
        // 看当前节点的右指针是线索还是指向右子树
        // 如果是线索的话(注意还需要加上p->rchild != tb，因为最后一个结点指向的就是根结点root)
        while (p->rtag == 1 && p->rchild != tb) {
            p = p->rchild;
            cout << p->data << " ";
        }
        p = p->rchild;  // 右子树是同样的操作
    }
}