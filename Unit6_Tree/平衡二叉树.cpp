#include <cmath>
#include <iostream>
using namespace std;

typedef struct node {
    int data;
    node* lchild;
    node* rchild;
    node* parent;
} AVLNode;

AVLNode* root = NULL;

void LL(AVLNode* node) {
    AVLNode* lson = node->lchild;
    lson->parent = node->parent;
    if (node->parent == NULL)
        root = lson;
    else {
        if (node->data > node->parent->data) {
            node->parent->rchild = lson;
        } else {
            node->parent->lchild = lson;
        }
    }
    if (lson->rchild != NULL) {
        lson->rchild->parent = node;
    }
    node->lchild = lson->rchild;
    node->parent = lson;
    lson->rchild = node;
}

void RR(AVLNode* node) {
    AVLNode* rson = node->rchild;
    rson->parent = node->parent;
    if (node->parent == NULL)
        root = rson;
    else {
        if (node->data < node->parent->data) {
            node->parent->lchild = rson;
        } else {
            node->parent->rchild = rson;
        }
    }
    if (rson->lchild != NULL) {
        rson->lchild->parent = node;
    }
    node->rchild = rson->lchild;
    node->parent = rson;
    rson->lchild = node;
}

void LR(AVLNode* node) {
    RR(node->lchild);
    LL(node);
}

void RL(AVLNode* node) {
    LL(node->rchild);
    RR(node);
}

int getHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    } else {
        return getHeight(node->lchild) > getHeight(node->rchild)
                   ? getHeight(node->lchild) + 1
                   : getHeight(node->rchild) + 1;
    }
}

int getNodeFactor(AVLNode* node) {
    return getHeight(node->lchild) - getHeight(node->rchild);
}

void insert(int element, AVLNode*& node, AVLNode*& parent) {
    if (node == NULL) {
        node = (AVLNode*)malloc(sizeof(AVLNode));
        node->data = element;
        node->parent = parent;
        node->lchild = node->rchild = NULL;
        AVLNode* p = parent;
        int factor = getNodeFactor(p);
        while (factor >= -1 && factor <= 1) {
            p = p->parent;
            if (p == NULL)
                break;
            factor = getNodeFactor(p);
        }
        if (factor == 2) {
            if (element < p->lchild->data)
                LL(p);
            else
                LR(p);
        }
        if (factor == -2) {
            if (element < p->rchild->data)
                RL(p);
            else
                RR(p);
        }
    } else if (element >= node->data)
        insert(element, node->rchild, node);
    else
        insert(element, node->lchild, node);
}

void midOrder(AVLNode* node) {
    if (node != NULL) {
        midOrder(node->lchild);
        cout << node->data << " ";
        midOrder(node->rchild);
    }
}

void createAVL() {
    root = (AVLNode*)malloc(sizeof(AVLNode));
    for (int i = 1; i <= 9; i++) {
        int element;
        cin >> element;
        if (i == 1) {
            root->data = element;
            root->lchild = root->parent = root->rchild = NULL;
            continue;
        }
        insert(element, root, root->parent);
    }
}

int main() {
    createAVL();
    midOrder(root);
    return 0;
}