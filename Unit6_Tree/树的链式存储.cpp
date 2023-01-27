#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct node {
    ElemType data;  // ����Ԫ��
    node* lchild;   // ָ�����ӽ��
    node* rchild;   // ָ���ұߺ��ӽ��
} BTNode;

// ˳�򴴽�������
void createBt(BTNode*& t, ElemType a[], int n, int pos) {
    if (pos <= n) {
        // ��ʼ�������
        t = (BTNode*)malloc(sizeof(BTNode));
        // ��������������ָ����ֵ
        t->data = a[pos];
        t->lchild = t->rchild = NULL;
        createBt(t->lchild, a, n, 2 * pos);      // ����������
        createBt(t->rchild, a, n, 2 * pos + 1);  // ����������
    }
}

// ���ٶ�������ֻ��ʹ�ú��������ķ�ʽɾ����㣬����һ������������������������Ļ�
// ��ô���free����������Ҳ����ô
void destoryBt(BTNode* t) {
    if (t != NULL) {
        destoryBt(t->lchild);
        destoryBt(t->rchild);
        free(t);
    }
}

// ����ֵΪx�Ľ��
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

// ��������ĸ߶�
int height(BTNode* t) {
    if (t == NULL)
        return 0;
    else
        return height(t->lchild) > height(t->rchild) ? height(t->lchild) + 1
                                                     : height(t->rchild) + 1;
}

// ����������(����)
void preOrder(BTNode* t) {
    if (t != NULL) {
        cout << t->data << " ";
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

// ����������(����)
void midOrder(BTNode* t) {
    if (t != NULL) {
        midOrder(t->lchild);
        cout << t->data << " ";
        midOrder(t->rchild);
    }
}

// ����������(����)
void postOrder(BTNode* t) {
    if (t != NULL) {
        postOrder(t->lchild);
        postOrder(t->rchild);
        cout << t->data << " ";
    }
}

// ��ȡ�����������н����
int getNodesNum(BTNode* t) {
    if (t == NULL)  return 0;
    else return getNodesNum(t->lchild) + getNodesNum(t->rchild) + 1;  // �������ĸ��������������ĸ����ټ��ϸ��ڵ�
}

// ���һ���������е�����Ҷ�ӽ��
void displayLeafNodes(BTNode* t) {
    if (t == NULL)  return;
    else {
        // �������������˼�룬���жϸ��ڵ��ǲ���Ҷ�ӽ�㣬��ȥ������������
        // ʵ���ϲ��ú������Ҳ�ǿ��Եģ����ǲ������������ô����
        if (t->lchild == NULL && t->rchild == NULL) {
            cout << t->data << " ";
        }
        displayLeafNodes(t->lchild);
        displayLeafNodes(t->rchild);
    }
}

// ��ȡ���ֵΪx��Ԫ�����ڵĲ���
int levelOfx(BTNode* t, ElemType x, int h) {
    int temp;
    if (t == NULL)  return -1;
    if (t->data == x)  return h;
    else {
        // ����������Ѱ��
        temp = levelOfx(t->lchild, x, h + 1);
        // ����ҵ��˾�ֱ�ӷ���
        if (temp != -1)  return temp;
        // ����������û���ҵ���ȥѰ��������
        return levelOfx(t->rchild, x, h + 1);
    }
}

// ��ȡ��������k��Ľ�����
void getLevelK(BTNode* t, int h, int k, int& n) {
    if (t == NULL || h > k)  return;
    if (h == k)  ++n;
    else {
        getLevelK(t->lchild, h + 1, k, n);
        getLevelK(t->rchild, h + 1, k, n);
    }
}

// �ж����Ŷ������Ƿ�����
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

// ���һ���㷨���һ�����x���������Ƚ��
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