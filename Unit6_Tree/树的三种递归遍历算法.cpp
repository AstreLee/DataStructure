#include <iostream>
using namespace std;
typedef struct node{
    int data;  
    node* lchild;  
    node* rchild;  
} TreeNode;

void CreateBiTree(TreeNode* node, int* arr, int i, int n);
void Preorder_traversal(TreeNode* pt);
void Inorder_traversal(TreeNode* pt);
void Postorder_traversal(TreeNode* pt);

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = arr[1];
    root->lchild = root->rchild = NULL;
    CreateBiTree(root, arr, 1, 7);

    cout << "ÏÈÐò£º" << endl;
    Preorder_traversal(root);
    cout << endl;

    cout << "ÖÐÐò£º" << endl;
    Inorder_traversal(root);
    cout << endl;

    cout << "ºóÐò£º" << endl;
    Postorder_traversal(root);
    
    return 0;
}

void CreateBiTree(TreeNode* node, int* arr, int i, int n) {
    if (2 * i <= n) {
        node->lchild = (TreeNode*)malloc(sizeof(TreeNode));
        node->lchild->data = arr[2 * i];
        node->lchild->lchild = node->lchild->rchild = NULL;
        CreateBiTree(node->lchild, arr, 2 * i, n);
    }
    if (2 * i + 1 <= n) {
        node->rchild = (TreeNode*)malloc(sizeof(TreeNode));
        node->rchild->data = arr[2 * i + 1];
        node->rchild->lchild = node->rchild->rchild = NULL;
        CreateBiTree(node->rchild, arr, 2 * i + 1, n);
    }
}


void Preorder_traversal(TreeNode* pt) {
    if(pt != NULL) {
        cout << pt->data << " ";
        Preorder_traversal(pt->lchild);
        Preorder_traversal(pt->rchild);
    }
}


void Inorder_traversal(TreeNode* pt) {
    if(pt != NULL) {
        Inorder_traversal(pt->lchild);
        cout << pt->data << " ";
        Inorder_traversal(pt->rchild);
    }
}


void Postorder_traversal(TreeNode* pt) {
    if(pt != NULL) {
        Postorder_traversal(pt->lchild);
        Postorder_traversal(pt->rchild);
        cout << pt->data << " ";
    }
}