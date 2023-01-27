#include <iostream>
#include <queue>
using namespace std;
const int arrSize = 20;
typedef struct node {
    int data;  // 数据域
    int level;  // 层数
    node* lchild;  // 左指针
    node* rchild;  // 右指针
} TreeNode;


// 函数声明
void CreateBiTree(TreeNode* &pt, int* arr, int pos, int n);
void DFS(TreeNode* pt, int h, int k, int& n);
int BFS1(TreeNode* pt, int k);
int BFS2(TreeNode* pt, int k);

int main() {
    // 声明一个数组
    int* arr = (int*)malloc(sizeof(int) * (arrSize + 1));
    for (int i = 0; i <= arrSize; ++i) {
        arr[i] = i;
    }
    // 创建头结点
    TreeNode* root = NULL;
    // 调用函数创建二叉树
    CreateBiTree(root, arr, 1, arrSize);
    // 获取数据k
    int k;
    cout << "请输入想要获取的第几层：";
    cin >> k;
    // DFS获取第三层的结点数
    int n = 0;
    DFS(root, 1, k, n);
    cout << "递归获得第3层的结点数为：" << n << endl;
    // BFS1获取第三层的结点数
    cout << "采用BFS1获取第3层的结点数为：" << BFS1(root, k) << endl;
    // BFS2获取第三层的结点数
    cout << "采用BFS2获取第3层的结点数为：" << BFS2(root, k) << endl;

    return 0;
}

void CreateBiTree(TreeNode* &pt, int* arr, int pos, int n) {
    if (pos <= n) {
        pt = (TreeNode*)malloc(sizeof(TreeNode*));
        pt->data = arr[pos];
        pt->level = 0;
        pt->lchild = pt->rchild = NULL;
        CreateBiTree(pt->lchild, arr, 2 * pos, n);
        CreateBiTree(pt->rchild, arr, 2 * pos + 1, n);
    }
}

void DFS(TreeNode* pt, int h, int k, int& n) {
    // 设置递归结束条件
    if (pt == NULL)  return;
    if (h == k) {
        ++n;  // 如果h等于k的时候说明是第k层的结点. 引用型变量n递增
        return;  // 没必要继续往下找了
    } else {
        // 递归寻找左子树
        DFS(pt->lchild, h + 1, k, n);
        // 递归寻找右子树
        DFS(pt->rchild, h + 1, k, n);
    }
}

int BFS1(TreeNode* pt, int k) {
    // BFS1采用一次性出一层结点的方式
    // 创建队列
    queue<TreeNode*> q;
    // 入队头节点
    q.push(pt);
    // 声明变量h记录当前的层数，实际上也就是出队了多少次
    int h = 1;
    while (! q.empty()) {
        // 获取当前队列的长度
        int currentSize = q.size();
        // 如果当前h已经到了第k层
        if (h == k)  return currentSize;
        // 将当前层的结点全部出队，以便下一层结点全部入队
        for (int i = 0; i < currentSize; ++i) {
            // 获取队头结点
            TreeNode* front = q.front();
            // 出队
            q.pop();
            // 如果左、右子节点不为空的话就将左右结点入队
            if (front->lchild != NULL)  q.push(front->lchild);
            if (front->rchild != NULL)  q.push(front->rchild);
        }
        ++h;  // h递增
    }
    return 0;
}

int BFS2(TreeNode* pt, int k) {
    // BFS2采用结点中的level属性
    // 首先还是创建队列
    queue<TreeNode*> q;
    // 将头结点的level修改为1并且入队
    pt->level = 1;
    q.push(pt);
    // 声明变量count记录下第k层的节点数
    int count = 0;
    while (! q.empty()) {
        // 出队
        TreeNode* front = q.front();
        q.pop();
        // 然后如果front.level == k，说明在第k层
        if (front->level == k) {
            ++count;
            continue;  // 既然已经是第k层的结点了，就没有必要继续添加k + 1层的了
        }
        // 否则的话添加左右子树（不空的情况下）
        if (front->lchild != NULL) {
            front->lchild->level = front->level + 1;
            q.push(front->lchild);
        }
        if (front->rchild != NULL) {
            front->rchild->level = front->level + 1;
            q.push(front->rchild);
        }
    }
    return count;
}