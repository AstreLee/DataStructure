#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

typedef struct node {
    int data;  // 数据域
    node* lchild;  // 左指针
    node* rchild;  // 右指针
} TreeNode;

// 函数声明
void CreateBiTree(TreeNode* &pt, int* arr, int pos, int n);
// 方法一：使用深搜 + 哈希表
bool DFS_Hash(TreeNode* pt, int target, set<int> &set);  
// 方法二：使用广搜 + 哈希表
bool BFS_Hash(TreeNode* pt, int target, set<int> &set);
// 方法三：利用BST中序递归的特点，将结果放在arr数组中，然后使用双指针解决问题
bool InorderSearch(TreeNode* pt, int target, int n);
// 方法四：直接在BST树上面实现中序查找
bool SearchOnTheTree(TreeNode* pt, int target, int n);
// 左指针调整
TreeNode* SiftLeft(TreeNode* pt, stack<TreeNode*> &s);
// 右指针调整
TreeNode* SiftRight(TreeNode* pt, stack<TreeNode*> &s);

int main() {
    // 声明一个数组
    int arr[] = {4, 2, 6, 1, 3, 5, 7};
    // 创建根节点
    TreeNode* root = NULL;
    // 调用函数创建二叉树
    CreateBiTree(root, arr, 0, 7);
    // 调用DFS_Hash函数来查找是否有节点之和等于target
    set<int> s;
    cout << "请输入目标值：";
    int target;
    cin >> target;
    if (DFS_Hash(root, target, s))  cout << "DFS: 可以找到" << endl;
    else cout << "DFS: 找不到！" << endl;

    // 调用BFS_Hahs函数查找
    s.clear();
    if (BFS_Hash(root, target, s))  cout << "BFS: 可以找到" << endl;
    else cout << "BFS: 找不到" << endl;
    
    // 调用InorderSearch函数查找
    if (InorderSearch(root, target, 7))  cout << "双指针：可以找到" << endl;
    else cout << "双指针：找不到" << endl;
    
    // 调用SearchOnTheTree
    if (SearchOnTheTree(root, target, 7))  cout << "直接找：可以找到" << endl;
    else cout << "直接找：找不到" << endl;
}

void CreateBiTree(TreeNode* &pt, int* arr, int pos, int n) {
    if (pos < n) {
        // 首先创建根节点
        pt = (TreeNode*)malloc(sizeof(TreeNode));
        // 初始化数据域和指针域
        pt->data = arr[pos];
        pt->lchild = pt->rchild = NULL;
        // 递归调用函数创建左子树和右子树
        CreateBiTree(pt->lchild, arr, 2 * pos + 1, n);
        CreateBiTree(pt->rchild, arr, 2 * pos + 2, n);
    }
}

bool DFS_Hash(TreeNode* pt, int target, set<int> &set) {
    // 如果pt为NULL返回false
    if (pt == NULL)  return false;
    // 如果target - pt.val的值包含在set里面就返回true
    if (set.count(target - pt->data) != 0)  return true;
    else {
        set.insert(pt->data);  // 否则的话就插入，接着去遍历左子树和右子树，只要有一个返回1就行
        return DFS_Hash(pt->lchild, target, set) || DFS_Hash(pt->rchild, target, set);
    }
}

bool BFS_Hash(TreeNode* pt, int target, set<int> &set) {
    queue<TreeNode*> q;
    q.push(pt);
    while (! q.empty()) {
        // 首先获取栈顶结点
        TreeNode* top = q.front();
        // 然后出栈栈顶结点
        q.pop();
        // 如果target - top.data是包含在set中的话，就返回true，否则继续
        if (set.count(target - top->data) != 0)  return true;
        else set.insert(top->data);
        // 否则的话看看左节点和右结点是否入队
        if (top->lchild != NULL)  q.push(top->lchild);
        if (top->rchild != NULL)  q.push(top->rchild);
    }
    return false;
}

bool InorderSearch(TreeNode* pt, int target, int n) {
    vector<int> arr;
    // 下面使用非递归算法将中序遍历的结果保存在arr中
    // 首先声明一个栈空间
    stack<TreeNode*> s;
    while (! s.empty() || pt != NULL) {
        while (pt != NULL) {
            s.push(pt);
            pt = pt->lchild;
        }
        if (! s.empty()) {
            // 首先获取栈顶结点
            TreeNode* top = s.top();
            // 然后栈顶结点出栈
            s.pop();
            // 然后将top结点数据添加到数组arr中
            arr.push_back(top->data);
            // 然后转向栈顶结点的右子树处理
            pt = top->rchild;
        }
    }
    
    // 然后使用双指针来寻找
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] < target) ++i;
        else if (arr[i] + arr[j] > target) --j;
        else return true;
    }   
    return false;
}

bool SearchOnTheTree(TreeNode* pt, int target, int n) {
    // 初始化左栈和右栈
    stack<TreeNode*> lstack;
    stack<TreeNode*> rstack;
    // 初始化左栈
    lstack.push(pt);
    TreeNode* lpt = pt;
    while (lpt->lchild != NULL) {
        lstack.push(lpt->lchild);
        lpt = lpt->lchild;
    }
    // 初始化右栈
    rstack.push(pt);
    TreeNode* rpt = pt;
    while (rpt->rchild != NULL) {
        rstack.push(rpt->rchild);
        rpt = rpt->rchild;
    }
    // 循环当lpt != rpt的时候继续，实际上相等的时候左右子树就遍历完了  
    while (lpt != rpt) {
        if (lpt->data + rpt->data < target) lpt = SiftLeft(pt, lstack);
        else if (lpt->data + rpt->data > target) rpt = SiftRight(pt, rstack);
        else return true;
    }
    return false;
}

TreeNode* SiftLeft(TreeNode* pt, stack<TreeNode*> &s) {
    // 首先出栈顶结点
    TreeNode* top = s.top();
    s.pop();
    // 然后转向栈顶结点右子树的最左结点(当然是在右子树存在的情况下)
    TreeNode* node = top->rchild;
    while (node != NULL) {
        s.push(node);
        node = node->lchild;
    }
    // 最后返回栈顶结点
    return top;
}

TreeNode* SiftRight(TreeNode* pt, stack<TreeNode*> &s) {
    TreeNode* top = s.top();
    s.pop();
    TreeNode* node = top->lchild;
    while (node != NULL) {
        s.push(node);
        node = node->rchild;
    }
    return top;
}