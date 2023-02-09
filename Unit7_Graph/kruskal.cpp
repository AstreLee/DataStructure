#include <iostream>
#include "matrix.h"
using namespace std;

// ����߽ṹ�壬�����ߵ���㡢�յ��Ȩ��
struct Edge {
    int from;    // ���
    int to;      // �յ�
    int weight;  // Ȩ��
};

void insertSort(Edge E[], int e) {
    for (int i = 1; i < e; ++i) {
        if (E[i].weight < E[i - 1].weight) {
            int temp = E[i].weight;
            int j = i - 1;
            for (; j >= 0 && temp < E[j].weight; --j) {
                swap(E[j + 1].weight, E[j].weight);
                swap(E[j + 1].from, E[j].from);
                swap(E[j + 1].to, E[j].to);
            }
        }
    }
}

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

// ʹ�����������鼯�Ļ������ݽṹ��Kruskal�㷨
void kruskal1(MatGraph* G) {
    int vset[MAXV];  // �������飬vset[i]��ʾ����i���ڶ��㼯vset[i]
    for (int i = 0; i < G->n; ++i) {  // �ʼ��ʱ��ÿ�����㱾�����һ�����뼯
        vset[i] = i;
    }
    // ����Kruskal�㷨�Ǵ�С����ѡȡ�߳��ģ�����������Ҫ�������еı߳�
    Edge E[G->e];
    // ����k����������E�����
    int k = 0;
    // �����ڽӾ���������Ǿ����ڽӾ����ǶԳƵģ�����������еľ��ظ���һ�飩
    for (int i = 0; i < G->n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (G->edges[i][j] != 0 && G->edges[i][j] != INF) {
                E[k].from = i;
                E[k].to = j;
                E[k].weight = G->edges[i][j];
                ++k;
            }
        }
    }
    // �Ա߳�����Ȩ�ؽ��������������ǿ���ѡ����������㷨����Ȼʱ�临�Ӷ�Խ��Խ��
    // ����ͼ����ѡ����ֱ�Ӳ�������
    insertSort(E, G->e);

    // ��ʼ������õı�������Ѱ����С��n - 1����
    int i = 0;  // i�����Ѿ��ҵ��ı���
    int j = 0;  // j����Ŀǰ������ӵ��ǵڼ�����
    while (i < G->n - 1) {
        int from = E[j].from;  // ��ȡ��k�������
        int to = E[j].to;      // ��ȡ��k�����յ�
        int sn1 = vset[from];  // ��ȡ������ڵļ���
        int sn2 = vset[to];    // ��ȡ�յ����ڵļ���
        if (sn1 !=
            sn2) {  // ����ͬһ�������о�˵������ɻ����Ϳ�����ӵ���������
            // ���������
            cout << "(" << from << "," << to << ")��" << E[j].weight << endl;
            ++i;
            // �ϲ���������
            for (int i = 0; i < G->n; ++i) {
                if (vset[i] == sn2) {  // ������sn2�ϲ�������sn1��
                    vset[i] = sn1;
                }
            }
        }
        ++j;  // ��һ����
    }
}

int main() {
    MatGraph G;
    G.n = 4;
    G.e = 5;
    kruskal1(&G);
    return 0;
}