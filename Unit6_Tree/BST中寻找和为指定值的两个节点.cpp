#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

typedef struct node {
    int data;  // ������
    node* lchild;  // ��ָ��
    node* rchild;  // ��ָ��
} TreeNode;

// ��������
void CreateBiTree(TreeNode* &pt, int* arr, int pos, int n);
// ����һ��ʹ������ + ��ϣ��
bool DFS_Hash(TreeNode* pt, int target, set<int> &set);  
// ��������ʹ�ù��� + ��ϣ��
bool BFS_Hash(TreeNode* pt, int target, set<int> &set);
// ������������BST����ݹ���ص㣬���������arr�����У�Ȼ��ʹ��˫ָ��������
bool InorderSearch(TreeNode* pt, int target, int n);
// �����ģ�ֱ����BST������ʵ���������
bool SearchOnTheTree(TreeNode* pt, int target, int n);
// ��ָ�����
TreeNode* SiftLeft(TreeNode* pt, stack<TreeNode*> &s);
// ��ָ�����
TreeNode* SiftRight(TreeNode* pt, stack<TreeNode*> &s);

int main() {
    // ����һ������
    int arr[] = {4, 2, 6, 1, 3, 5, 7};
    // �������ڵ�
    TreeNode* root = NULL;
    // ���ú�������������
    CreateBiTree(root, arr, 0, 7);
    // ����DFS_Hash�����������Ƿ��нڵ�֮�͵���target
    set<int> s;
    cout << "������Ŀ��ֵ��";
    int target;
    cin >> target;
    if (DFS_Hash(root, target, s))  cout << "DFS: �����ҵ�" << endl;
    else cout << "DFS: �Ҳ�����" << endl;

    // ����BFS_Hahs��������
    s.clear();
    if (BFS_Hash(root, target, s))  cout << "BFS: �����ҵ�" << endl;
    else cout << "BFS: �Ҳ���" << endl;
    
    // ����InorderSearch��������
    if (InorderSearch(root, target, 7))  cout << "˫ָ�룺�����ҵ�" << endl;
    else cout << "˫ָ�룺�Ҳ���" << endl;
    
    // ����SearchOnTheTree
    if (SearchOnTheTree(root, target, 7))  cout << "ֱ���ң������ҵ�" << endl;
    else cout << "ֱ���ң��Ҳ���" << endl;
}

void CreateBiTree(TreeNode* &pt, int* arr, int pos, int n) {
    if (pos < n) {
        // ���ȴ������ڵ�
        pt = (TreeNode*)malloc(sizeof(TreeNode));
        // ��ʼ���������ָ����
        pt->data = arr[pos];
        pt->lchild = pt->rchild = NULL;
        // �ݹ���ú���������������������
        CreateBiTree(pt->lchild, arr, 2 * pos + 1, n);
        CreateBiTree(pt->rchild, arr, 2 * pos + 2, n);
    }
}

bool DFS_Hash(TreeNode* pt, int target, set<int> &set) {
    // ���ptΪNULL����false
    if (pt == NULL)  return false;
    // ���target - pt.val��ֵ������set����ͷ���true
    if (set.count(target - pt->data) != 0)  return true;
    else {
        set.insert(pt->data);  // ����Ļ��Ͳ��룬����ȥ��������������������ֻҪ��һ������1����
        return DFS_Hash(pt->lchild, target, set) || DFS_Hash(pt->rchild, target, set);
    }
}

bool BFS_Hash(TreeNode* pt, int target, set<int> &set) {
    queue<TreeNode*> q;
    q.push(pt);
    while (! q.empty()) {
        // ���Ȼ�ȡջ�����
        TreeNode* top = q.front();
        // Ȼ���ջջ�����
        q.pop();
        // ���target - top.data�ǰ�����set�еĻ����ͷ���true���������
        if (set.count(target - top->data) != 0)  return true;
        else set.insert(top->data);
        // ����Ļ�������ڵ���ҽ���Ƿ����
        if (top->lchild != NULL)  q.push(top->lchild);
        if (top->rchild != NULL)  q.push(top->rchild);
    }
    return false;
}

bool InorderSearch(TreeNode* pt, int target, int n) {
    vector<int> arr;
    // ����ʹ�÷ǵݹ��㷨����������Ľ��������arr��
    // ��������һ��ջ�ռ�
    stack<TreeNode*> s;
    while (! s.empty() || pt != NULL) {
        while (pt != NULL) {
            s.push(pt);
            pt = pt->lchild;
        }
        if (! s.empty()) {
            // ���Ȼ�ȡջ�����
            TreeNode* top = s.top();
            // Ȼ��ջ������ջ
            s.pop();
            // Ȼ��top���������ӵ�����arr��
            arr.push_back(top->data);
            // Ȼ��ת��ջ����������������
            pt = top->rchild;
        }
    }
    
    // Ȼ��ʹ��˫ָ����Ѱ��
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
    // ��ʼ����ջ����ջ
    stack<TreeNode*> lstack;
    stack<TreeNode*> rstack;
    // ��ʼ����ջ
    lstack.push(pt);
    TreeNode* lpt = pt;
    while (lpt->lchild != NULL) {
        lstack.push(lpt->lchild);
        lpt = lpt->lchild;
    }
    // ��ʼ����ջ
    rstack.push(pt);
    TreeNode* rpt = pt;
    while (rpt->rchild != NULL) {
        rstack.push(rpt->rchild);
        rpt = rpt->rchild;
    }
    // ѭ����lpt != rpt��ʱ�������ʵ������ȵ�ʱ�����������ͱ�������  
    while (lpt != rpt) {
        if (lpt->data + rpt->data < target) lpt = SiftLeft(pt, lstack);
        else if (lpt->data + rpt->data > target) rpt = SiftRight(pt, rstack);
        else return true;
    }
    return false;
}

TreeNode* SiftLeft(TreeNode* pt, stack<TreeNode*> &s) {
    // ���ȳ�ջ�����
    TreeNode* top = s.top();
    s.pop();
    // Ȼ��ת��ջ�������������������(��Ȼ�������������ڵ������)
    TreeNode* node = top->rchild;
    while (node != NULL) {
        s.push(node);
        node = node->lchild;
    }
    // ��󷵻�ջ�����
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