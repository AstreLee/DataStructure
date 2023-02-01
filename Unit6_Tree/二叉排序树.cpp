#include <iostream>
using namespace std;

typedef struct node {
    int data;  // ������
    node* lchild, *rchild;  // ����ָ����
} BSTNode;

// ����������������
// ���������������û�йؼ�����ͬ�Ľ�㣬��ô����ÿ�β������ʱ��ʹӸ���㿪ʼ
// ���������Ľ��Ҫô�ȸ�����Ҫô�ȸ����С�����ܵ��������������������������Ƕ�
// ����ͬ���Ĳ�����ֱ��ָ��ΪNULL������BST����Ľ��һ����Ҷ�ӽ��
// ���ָ�����Ҫ�����ã�Ϊʲô�������֪����
bool insertBST(BSTNode* &bt, int k) {
    if (bt == NULL) {
        bt = (BSTNode*)malloc(sizeof(BSTNode));
        bt->data = k;
        bt->lchild = bt->rchild = NULL;
        return true;
    } else if (bt->data < k) {
        return insertBST(bt->rchild, k);
    } else if (bt->data > k) {
        return insertBST(bt->lchild, k);
    } else {
        return false;
    }
}

// ��������������ͬ��������ɵĲ�ͬ˳������й����Ķ����������ǲ�һ����
// ����1 2 3 4 5 6 7 8���������Ķ������������ֻ���ҷ�֧�������Ļ����ҵ�Ч�ʺܵ�
BSTNode* createBST(int* arr, int n) {
    BSTNode* bt = NULL;
    for (int i = 0; i < n; ++i) {
        insertBST(bt, arr[i]);
    }
    return bt;
}

// �����������Ĳ���
BSTNode* searchBST(BSTNode* bt, int k) {
    if (bt == NULL || bt->data == k) {
        return bt;
    } else if (bt->data > k) {
        return searchBST(bt->lchild, k);
    } else {
        return searchBST(bt->rchild, k);
    }
}

// Ѱ���Խ��p��Ϊ������BST�е������
BSTNode* maxNode(BSTNode* p) {
    while (p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

// Ѱ���Խ��p��Ϊ������BST�е���С���
BSTNode* minNode(BSTNode* p) {
    while (p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

// ɾ��������ָ�����
bool destoryBST(BSTNode* &bt, int k) {
    if (bt == NULL)  return false;
    if (bt->data < k) {
        return destoryBST(bt->rchild, k);
    } else if (bt->data > k) {
        return destoryBST(bt->lchild, k);
    } else {
        delete1(bt);
        return true;
    }
}

// �����ɾ���㷨
void delete1(BSTNode* &p) {
    BSTNode* temp;
    // ������Ϊ�յ�ʱ�����ʱ�����Ҷ�ӽ�����������Ϊ�յ����
    if (p->rchild == NULL) {
        temp = p;
        p = p->lchild;
        free(temp);
    } else if (p->lchild == NULL) {  // ������Ϊ�գ���������Ϊ��
        temp = p;
        p = p->rchild;
        free(temp);
    } else {
        // ������������������Ϊ��
        delete2(p, p->lchild);
    }
}

void delete2(BSTNode* p, BSTNode* &r) {
    // Ѱ�������������ֵ����滻p����ֵ��Ȼ��ɾ��������ֵ���
    // ����ҵ�����������������ֵ���ɾ��ʱ������Ƶ�ָ������ı仯
    // ���Եڶ�������Ҫ����ָ�����������
    BSTNode* temp;
    if (r->rchild != NULL) {
        delete2(p, r->rchild);
    } else {
        p->data = r->data;
        temp = r;
        r = r->lchild;
        free(temp);
    }
}