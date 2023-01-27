#include <iostream>
using namespace std;

const int N = 50;
typedef struct {
    char data;  // ������
    double weight;  // ���Ȩ��
    int parent;  // ˫�׽��λ��
    int lchild;  // ���ӽ��λ��
    int rchild;  // �Һ��ӽ��λ��
} HTNode;

typedef struct {  // ʵ���������vector���ܸ���һ�㣬��Ϊ�ж��ٸ�������Ȳ�ȷ��
    char cd[N];  // ��ŵ�ǰ���Ĺ���������ֵ
    int start;  // cd[start...n]���ֶ��ǹ�����ֵ 
} HCode;

// ������������
// ht��HTNode�ṹ�����飬�����е�ÿ��Ԫ�ض���һ���ṹ�����������ͨ����Ա�������㷨.������
// n��Ҷ�ӽ��ĸ���
void createHt(HTNode ht[], int n) {
    // ���Ƚ�2n - 1������parent,lchild,rchildȫ����-1
    for (int i = 0; i < 2 * n - 1; ++i) {
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    // Ȼ���λ��n��ʼ����ǰ��û��˫�׽��Ľ����Ѱ��Ȩֵ��С���������
    for (int i = n; i < 2 * n - 1; ++i) {
        int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;  // min1Ϊ��Сֵ��min2Ϊ��Сֵ
        int lnode, rnode = -1;  // lnode����С��, rnode�Ǵ�С��
        for (int k = 0; k < i; ++k) {
            // ע��ֻѰ��û��˫�׽��Ľ��
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = ht[rnode].parent = i;
    }
}


void createHCode(HTNode ht[], HCode hcd[], int n) {
    HCode hc;
    for (int i = 0; i < n; ++i) {
        hc.start = n;
        int f = ht[i].parent;
        int c = i;
        while (f != -1) {  // ˫�׽����ھͼ���ѭ��
            if (ht[f].lchild == c) {
                hc.cd[hc.start--] = '0';
            } else {
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;  // �ṹ������Ԫ�ظ�ֵ
    }
}