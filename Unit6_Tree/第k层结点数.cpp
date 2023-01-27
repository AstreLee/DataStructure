#include <iostream>
#include <queue>
using namespace std;
const int arrSize = 20;
typedef struct node {
    int data;  // ������
    int level;  // ����
    node* lchild;  // ��ָ��
    node* rchild;  // ��ָ��
} TreeNode;


// ��������
void CreateBiTree(TreeNode* &pt, int* arr, int pos, int n);
void DFS(TreeNode* pt, int h, int k, int& n);
int BFS1(TreeNode* pt, int k);
int BFS2(TreeNode* pt, int k);

int main() {
    // ����һ������
    int* arr = (int*)malloc(sizeof(int) * (arrSize + 1));
    for (int i = 0; i <= arrSize; ++i) {
        arr[i] = i;
    }
    // ����ͷ���
    TreeNode* root = NULL;
    // ���ú�������������
    CreateBiTree(root, arr, 1, arrSize);
    // ��ȡ����k
    int k;
    cout << "��������Ҫ��ȡ�ĵڼ��㣺";
    cin >> k;
    // DFS��ȡ������Ľ����
    int n = 0;
    DFS(root, 1, k, n);
    cout << "�ݹ��õ�3��Ľ����Ϊ��" << n << endl;
    // BFS1��ȡ������Ľ����
    cout << "����BFS1��ȡ��3��Ľ����Ϊ��" << BFS1(root, k) << endl;
    // BFS2��ȡ������Ľ����
    cout << "����BFS2��ȡ��3��Ľ����Ϊ��" << BFS2(root, k) << endl;

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
    // ���õݹ��������
    if (pt == NULL)  return;
    if (h == k) {
        ++n;  // ���h����k��ʱ��˵���ǵ�k��Ľ��. �����ͱ���n����
        return;  // û��Ҫ������������
    } else {
        // �ݹ�Ѱ��������
        DFS(pt->lchild, h + 1, k, n);
        // �ݹ�Ѱ��������
        DFS(pt->rchild, h + 1, k, n);
    }
}

int BFS1(TreeNode* pt, int k) {
    // BFS1����һ���Գ�һ����ķ�ʽ
    // ��������
    queue<TreeNode*> q;
    // ���ͷ�ڵ�
    q.push(pt);
    // ��������h��¼��ǰ�Ĳ�����ʵ����Ҳ���ǳ����˶��ٴ�
    int h = 1;
    while (! q.empty()) {
        // ��ȡ��ǰ���еĳ���
        int currentSize = q.size();
        // �����ǰh�Ѿ����˵�k��
        if (h == k)  return currentSize;
        // ����ǰ��Ľ��ȫ�����ӣ��Ա���һ����ȫ�����
        for (int i = 0; i < currentSize; ++i) {
            // ��ȡ��ͷ���
            TreeNode* front = q.front();
            // ����
            q.pop();
            // ��������ӽڵ㲻Ϊ�յĻ��ͽ����ҽ�����
            if (front->lchild != NULL)  q.push(front->lchild);
            if (front->rchild != NULL)  q.push(front->rchild);
        }
        ++h;  // h����
    }
    return 0;
}

int BFS2(TreeNode* pt, int k) {
    // BFS2���ý���е�level����
    // ���Ȼ��Ǵ�������
    queue<TreeNode*> q;
    // ��ͷ����level�޸�Ϊ1�������
    pt->level = 1;
    q.push(pt);
    // ��������count��¼�µ�k��Ľڵ���
    int count = 0;
    while (! q.empty()) {
        // ����
        TreeNode* front = q.front();
        q.pop();
        // Ȼ�����front.level == k��˵���ڵ�k��
        if (front->level == k) {
            ++count;
            continue;  // ��Ȼ�Ѿ��ǵ�k��Ľ���ˣ���û�б�Ҫ�������k + 1�����
        }
        // ����Ļ�����������������յ�����£�
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