#include <iostream>
#include <stack>
using namespace std;

typedef struct node {
    int data;      // 数据域
    node* lchild;  // 左指针域
    node* rchild;  // 右指针域
} TreeNode;

// 函数声明
void CreateBiTree(TreeNode*& pt, int* arr, int pos, int n);  // 创建二叉树
void Preorder_traversal(TreeNode* pt);   // 前序非递归遍历二叉树
void Inorder_traversal(TreeNode* pt);    // 中序非递归遍历二叉树
void Postorder_traversal(TreeNode* pt);  // 后序非递归遍历二叉树

int main() {
    // 创建一维数组
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    // 创建根节点
    TreeNode* root = NULL;
    // 调用函数创建二叉树
    CreateBiTree(root, arr, 1, 7);
    // 非递归先序
    cout << "非递归先序遍历如下所示：" << endl;
    Preorder_traversal(root);
    cout << endl;
    // 非递归中序
    cout << "非递归中序遍历如下所示：" << endl;
    Inorder_traversal(root);
    cout << endl;
    // 非递归后序
    cout << "非递归后序遍历如下所示：" << endl;
    Postorder_traversal(root);
    cout << endl;

    // over
    return 0;
}

// 注意这里必须使用指针的引用，和递归算法中创建二叉树的算法注意对比
void CreateBiTree(TreeNode*& pt, int* arr, int pos, int n) {
    if (pos <= n) {
        // 数组允许创建节点我们就继续
        pt = (TreeNode*)malloc(sizeof(TreeNode));
        pt->data = arr[pos];
        pt->lchild = pt->rchild = NULL;
        // 递归创建左子树
        CreateBiTree(pt->lchild, arr, 2 * pos, n);
        // 递归创建右子树
        CreateBiTree(pt->rchild, arr, 2 * pos + 1, n);
    }
}

// 定义先序非递归算法
void Preorder_traversal(TreeNode* pt) {
    // 由于我们需要从根节点开始一直遍历到左子树为空或者都遍历过为止
    // 所以我们需要栈空间保存已经遍历过的节点
    // 首先创建栈空间
    stack<TreeNode*> s;
    while (!s.empty() || pt != NULL) {
        // 首先一直遍历左子树直到为空
        while (pt != NULL) {
            // 当然在遍历的过程中就可以打印节点值了
            cout << pt->data << " ";
            // 然后pt节点入栈
            s.push(pt);
            // 然后更新pt指针
            pt = pt->lchild;
        }
        // 首先取出栈顶元素
        TreeNode* pr = s.top();
        // 然后出栈
        s.pop();
        // 然后处理右子树，右子树的处理过程和左子树是一样的
        pt = pr->rchild;
    }
}

// 定义中序非递归算法
void Inorder_traversal(TreeNode* pt) {
    // 只需要在先序非递归的基础上稍加修改就OK
    stack<TreeNode*> s;
    while (!s.empty() || pt != NULL) {
        while (pt != NULL) {
            s.push(pt);
            pt = pt->lchild;
        }
        // 首先取栈顶元素
        TreeNode* pr = s.top();
        // 然后输出中间节点的值
        cout << pr->data << " ";
        // 然后出栈
        s.pop();
        // 转向处理右子树
        pt = pr->rchild;
    }
}

// 定义后序非递归算法
void Postorder_traversal(TreeNode* pt) {
    // 后序递归算法还是多少有点不一样的，需要知道什么时候遍历完节点的左子树和右子树
    // 这就需要记录下刚才指向的节点
    TreeNode* pr = NULL;
    bool flag = true;
    stack<TreeNode*> s;
    do {
        while (pt != NULL) {
            s.push(pt);
            pt = pt->lchild;
        }
        pr = NULL;    // pr指向刚才走过的节点
        flag = true;  // flag标记表示是否需要出栈节点
        while (!s.empty() && flag) {
            // 首先peek出栈顶的元素，这里一定是top而不是pop
            TreeNode* top = s.top();
            // 然后看看栈顶元素的右孩子节点是否是刚才访问过的节点或者为空
            if (top->rchild == pr) {
                // 打印信息
                cout << top->data << " ";
                // 出栈
                s.pop();
                // 更新pr
                pr = top;
            } else {
                // 如果刚才访问的节点不是栈顶节点的右孩子节点，就要转向处理右节点
                pt = top->rchild;
                flag = false;
            }
        }
    } while (!s.empty());
}