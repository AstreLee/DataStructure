#include<iostream>
using namespace std;

const int MAXD = 50;  // MAXDΪ���ؼ��ֵ�λ��
typedef struct node {
    char data[MAXD];  // Ҫ����������е��������λ�����ӵ�λ����λ�洢��data[0...MAXD-1]��
    node* next;  
} NodeType;

// r��Ҫ�������ֵĻ�����d�����λ��
void radixSort(NodeType* &p, int r, int d) {
    NodeType* head[MAXD], *tail[MAXD];  // ����ͷָ�������βָ��
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < r; ++j) {
            head[j] = tail[j] = NULL;  // ��ʼ�����ӵ��ס�βָ�� 
        }
        while (p != NULL) {
            int k = p->data[i] - '0';
            if (head[k] == NULL) {
                head[k] = p;
                tail[k] = p;
            } else {
                tail[k]->next = p;
                tail[k] = p;
            }
            p = p->next;  // ����ȡ��һ����
        }
    }
}

int main() {

}