#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct node {
    ElemType data;  // 数据元素
    node* lchild;   // 指向左孩子结点
    node* rchild;   // 指向右边孩子结点
} BTNode;

// 顺序创建二叉树
void createBt(BTNode*& t, ElemType a[], int n, int pos) {
    if (pos <= n) {
        // 初始化根结点
        t = (BTNode*)malloc(sizeof(BTNode));
        // 给根结点数据域和指针域赋值
        t->data = a[pos];
        t->lchild = t->rchild = NULL;
        createBt(t->lchild, a, n, 2 * pos);      // 创建左子树
        createBt(t->rchild, a, n, 2 * pos + 1);  // 创建右子树
    }
}

// 销毁二叉树，只能使用后续遍历的方式删除结点，试想一下如果采用先序或者中序遍历的话
// 那么结点free过后子树不也丢了么
void destoryBt(BTNode* t) {
    if (t != NULL) {
        destoryBt(t->lchild);
        destoryBt(t->rchild);
        free(t);
    }
}

// 查找值为x的结点
BTNode* findNode(BTNode* t, ElemType x) {
    BTNode* temp = NULL;
    if (t == NULL)
        return NULL;
    else if (t->data == x)
        return t;
    else {
        temp = findNode(t->lchild, x);
        if (temp != NULL)
            return temp;
        else
            return findNode(t->rchild, x);
    }
}

// 求二叉树的高度
int height(BTNode* t) {
    if (t == NULL)
        return 0;
    else
        return height(t->lchild) > height(t->rchild) ? height(t->lchild) + 1
                                                     : height(t->rchild) + 1;
}

// 遍历二叉树(先序)
void preOrder(BTNode* t) {
    if (t != NULL) {
        cout << t->data << " ";
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

// 遍历二叉树(中序)
void midOrder(BTNode* t) {
    if (t != NULL) {
        midOrder(t->lchild);
        cout << t->data << " ";
        midOrder(t->rchild);
    }
}

// 遍历二叉树(后序)
void postOrder(BTNode* t) {
    if (t != NULL) {
        postOrder(t->lchild);
        postOrder(t->rchild);
        cout << t->data << " ";
    }
}

// 获取二叉树中所有结点数
int getNodesNum(BTNode* t) {
    if (t == NULL)  return 0;
    else return getNodesNum(t->lchild) + getNodesNum(t->rchild) + 1;  // 左子树的个数加上右子树的个数再加上根节点
}

// 输出一个二叉树中的所有叶子结点
void displayLeafNodes(BTNode* t) {
    if (t == NULL)  return;
    else {
        // 采用先序遍历的思想，先判断根节点是不是叶子结点，再去处理左右子树
        // 实际上采用后序遍历也是可以的，但是不如先序遍历那么明朗
        if (t->lchild == NULL && t->rchild == NULL) {
            cout << t->data << " ";
        }
        displayLeafNodes(t->lchild);
        displayLeafNodes(t->rchild);
    }
}

// 获取结点值为x的元素所在的层数
int levelOfx(BTNode* t, ElemType x, int h) {
    int temp;
    if (t == NULL)  return -1;
    if (t->data == x)  return h;
    else {
        // 在左子树中寻找
        temp = levelOfx(t->lchild, x, h + 1);
        // 如果找到了就直接返回
        if (temp != -1)  return temp;
        // 否则左子树没有找到就去寻找右子树
        return levelOfx(t->rchild, x, h + 1);
    }
}

// 获取二叉树第k层的结点个数
void getLevelK(BTNode* t, int h, int k, int& n) {
    if (t == NULL || h > k)  return;
    if (h == k)  ++n;
    else {
        getLevelK(t->lchild, h + 1, k, n);
        getLevelK(t->rchild, h + 1, k, n);
    }
}

// 判断两颗二叉树是否相似
bool like(BTNode* t1, BTNode* t2) {
    bool like1, like2;
    if (t1 == NULL && t2 == NULL)  return true;
    else if (t1 == NULL || t2 == NULL)  return false;
    else {
        like1 = like(t1->lchild, t2->lchild);
        like2 = like(t1->rchild, t2->rchild);
        return like1 && like2;
    }
}

// 设计一个算法求出一个结点x的所有祖先结点
bool ancestor(BTNode* t, int x) {
    if (t == NULL)  return false;
    else if (t != NULL && t->lchild->data == x || t != NULL && t->rchild->data == x) {
        cout << t->data << " ";
        return true;
    } else if (ancestor(t->lchild, x) || ancestor(t->rchild, x)) {
        cout << t->data << " ";
        return true;
    }
    return false;
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    BTNode* t = NULL;
    createBt(t, a, 8, 1);
    // cout << height(t) << endl;
    // cout << getNodesNum(t) << endl;
    // displayLeafNodes(t);
    // cout << levelOfx(t, 8, 1) << endl;
    int n;
    getLevelK(t, 1, 4, n);
    cout << n << endl;
    return 0;
}