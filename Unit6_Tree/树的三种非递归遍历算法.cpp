#include <iostream>
#include <stack>
using namespace std;

typedef struct node {
    int data;      // ������
    node* lchild;  // ��ָ����
    node* rchild;  // ��ָ����
} TreeNode;

// ��������
void CreateBiTree(TreeNode*& pt, int* arr, int pos, int n);  // ����������
void Preorder_traversal(TreeNode* pt);   // ǰ��ǵݹ����������
void Inorder_traversal(TreeNode* pt);    // ����ǵݹ����������
void Postorder_traversal(TreeNode* pt);  // ����ǵݹ����������

int main() {
    // ����һά����
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    // �������ڵ�
    TreeNode* root = NULL;
    // ���ú�������������
    CreateBiTree(root, arr, 1, 7);
    // �ǵݹ�����
    cout << "�ǵݹ��������������ʾ��" << endl;
    Preorder_traversal(root);
    cout << endl;
    // �ǵݹ�����
    cout << "�ǵݹ��������������ʾ��" << endl;
    Inorder_traversal(root);
    cout << endl;
    // �ǵݹ����
    cout << "�ǵݹ�������������ʾ��" << endl;
    Postorder_traversal(root);
    cout << endl;

    // over
    return 0;
}

// ע���������ʹ��ָ������ã��͵ݹ��㷨�д������������㷨ע��Ա�
void CreateBiTree(TreeNode*& pt, int* arr, int pos, int n) {
    if (pos <= n) {
        // �����������ڵ����Ǿͼ���
        pt = (TreeNode*)malloc(sizeof(TreeNode));
        pt->data = arr[pos];
        pt->lchild = pt->rchild = NULL;
        // �ݹ鴴��������
        CreateBiTree(pt->lchild, arr, 2 * pos, n);
        // �ݹ鴴��������
        CreateBiTree(pt->rchild, arr, 2 * pos + 1, n);
    }
}

// ��������ǵݹ��㷨
void Preorder_traversal(TreeNode* pt) {
    // ����������Ҫ�Ӹ��ڵ㿪ʼһֱ������������Ϊ�ջ��߶�������Ϊֹ
    // ����������Ҫջ�ռ䱣���Ѿ��������Ľڵ�
    // ���ȴ���ջ�ռ�
    stack<TreeNode*> s;
    while (!s.empty() || pt != NULL) {
        // ����һֱ����������ֱ��Ϊ��
        while (pt != NULL) {
            // ��Ȼ�ڱ����Ĺ����оͿ��Դ�ӡ�ڵ�ֵ��
            cout << pt->data << " ";
            // Ȼ��pt�ڵ���ջ
            s.push(pt);
            // Ȼ�����ptָ��
            pt = pt->lchild;
        }
        // ����ȡ��ջ��Ԫ��
        TreeNode* pr = s.top();
        // Ȼ���ջ
        s.pop();
        // Ȼ�������������������Ĵ�����̺���������һ����
        pt = pr->rchild;
    }
}

// ��������ǵݹ��㷨
void Inorder_traversal(TreeNode* pt) {
    // ֻ��Ҫ������ǵݹ�Ļ������Լ��޸ľ�OK
    stack<TreeNode*> s;
    while (!s.empty() || pt != NULL) {
        while (pt != NULL) {
            s.push(pt);
            pt = pt->lchild;
        }
        // ����ȡջ��Ԫ��
        TreeNode* pr = s.top();
        // Ȼ������м�ڵ��ֵ
        cout << pr->data << " ";
        // Ȼ���ջ
        s.pop();
        // ת����������
        pt = pr->rchild;
    }
}

// �������ǵݹ��㷨
void Postorder_traversal(TreeNode* pt) {
    // ����ݹ��㷨���Ƕ����е㲻һ���ģ���Ҫ֪��ʲôʱ�������ڵ����������������
    // �����Ҫ��¼�¸ղ�ָ��Ľڵ�
    TreeNode* pr = NULL;
    bool flag = true;
    stack<TreeNode*> s;
    do {
        while (pt != NULL) {
            s.push(pt);
            pt = pt->lchild;
        }
        pr = NULL;    // prָ��ղ��߹��Ľڵ�
        flag = true;  // flag��Ǳ�ʾ�Ƿ���Ҫ��ջ�ڵ�
        while (!s.empty() && flag) {
            // ����peek��ջ����Ԫ�أ�����һ����top������pop
            TreeNode* top = s.top();
            // Ȼ�󿴿�ջ��Ԫ�ص��Һ��ӽڵ��Ƿ��Ǹղŷ��ʹ��Ľڵ����Ϊ��
            if (top->rchild == pr) {
                // ��ӡ��Ϣ
                cout << top->data << " ";
                // ��ջ
                s.pop();
                // ����pr
                pr = top;
            } else {
                // ����ղŷ��ʵĽڵ㲻��ջ���ڵ���Һ��ӽڵ㣬��Ҫת�����ҽڵ�
                pt = top->rchild;
                flag = false;
            }
        }
    } while (!s.empty());
}