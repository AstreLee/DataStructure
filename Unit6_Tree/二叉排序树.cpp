#include <iostream>
using namespace std;

typedef struct node {
    int data;  // 数据域
    node* lchild, *rchild;  // 左、右指针域
} BSTNode;

// 二叉排序树插入结点
// 假设二叉排序树中没有关键字相同的结点，那么我们每次插入结点的时候就从根结点开始
// 这个待插入的结点要么比根结点大，要么比根结点小，不管到左子树还是右子树接下来我们都
// 进行同样的操作，直到指针为NULL，所以BST插入的结点一定是叶子结点
// 这个指针必须要用引用，为什么，想想就知道了
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

// 创建二叉树，相同的数字组成的不同顺序的序列构建的二叉排序树是不一样的
// 比如1 2 3 4 5 6 7 8构建出来的二叉查找树就是只有右分支，这样的话查找的效率很低
BSTNode* createBST(int* arr, int n) {
    BSTNode* bt = NULL;
    for (int i = 0; i < n; ++i) {
        insertBST(bt, arr[i]);
    }
    return bt;
}

// 二叉排序树的查找
BSTNode* searchBST(BSTNode* bt, int k) {
    if (bt == NULL || bt->data == k) {
        return bt;
    } else if (bt->data > k) {
        return searchBST(bt->lchild, k);
    } else {
        return searchBST(bt->rchild, k);
    }
}

// 寻找以结点p作为子树的BST中的最大结点
BSTNode* maxNode(BSTNode* p) {
    while (p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

// 寻找以结点p作为子树的BST中的最小结点
BSTNode* minNode(BSTNode* p) {
    while (p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

// 删除二叉树指定结点
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

// 具体的删除算法
void delete1(BSTNode* &p) {
    BSTNode* temp;
    // 右子树为空的时候，这个时候包括叶子结点和左子树不为空的情况
    if (p->rchild == NULL) {
        temp = p;
        p = p->lchild;
        free(temp);
    } else if (p->lchild == NULL) {  // 左子树为空，右子树不为空
        temp = p;
        p = p->rchild;
        free(temp);
    } else {
        // 左子树和右子树都不为空
        delete2(p, p->lchild);
    }
}

void delete2(BSTNode* p, BSTNode* &r) {
    // 寻找左子树的最大值结点替换p结点的值，然后删除这个最大值结点
    // 最后找到了这个左子树的最大值结点删除时由于设计到指针变量的变化
    // 所以第二个参数要传递指针变量的引用
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