#include <iostream>
#include "matrix.h"
using namespace std;

// 定义边结构体，包括边的起点、终点和权重
struct Edge {
    int from;    // 起点
    int to;      // 终点
    int weight;  // 权重
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

// 使用数组做并查集的基本数据结构的Kruskal算法
void kruskal1(MatGraph* G) {
    int vset[MAXV];  // 辅助数组，vset[i]表示顶点i属于顶点集vset[i]
    for (int i = 0; i < G->n; ++i) {  // 最开始的时候每个顶点本身就是一个分离集
        vset[i] = i;
    }
    // 由于Kruskal算法是从小到大选取边长的，所以我们需要保存所有的边长
    Edge E[G->e];
    // 变量k是用来计数E数组的
    int k = 0;
    // 遍历邻接矩阵的下三角矩阵（邻接矩阵是对称的，如果遍历所有的就重复了一遍）
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
    // 对边长按照权重进行排序，这里我们可以选择各类排序算法，当然时间复杂度越低越好
    // 这里就简单起见选用了直接插入排序
    insertSort(E, G->e);

    // 开始在排序好的边数组中寻找最小的n - 1条边
    int i = 0;  // i计数已经找到的边数
    int j = 0;  // j计数目前尝试添加的是第几条边
    while (i < G->n - 1) {
        int from = E[j].from;  // 获取第k条边起点
        int to = E[j].to;      // 获取第k条边终点
        int sn1 = vset[from];  // 获取起点所在的集合
        int sn2 = vset[to];    // 获取终点所在的集合
        if (sn1 !=
            sn2) {  // 不在同一个集合中就说明不会成环，就可以添加到生成树中
            // 输出这条边
            cout << "(" << from << "," << to << ")：" << E[j].weight << endl;
            ++i;
            // 合并两个集合
            for (int i = 0; i < G->n; ++i) {
                if (vset[i] == sn2) {  // 将集合sn2合并到集合sn1中
                    vset[i] = sn1;
                }
            }
        }
        ++j;  // 下一条边
    }
}

int main() {
    MatGraph G;
    G.n = 4;
    G.e = 5;
    kruskal1(&G);
    return 0;
}