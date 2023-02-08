#include <iostream>
#include "matrix.h"
using namespace std;

// prim算法
// param1：因为要频繁访问一条条边的权限，所以使用邻接矩阵比较合适
// param2：v表示开始访问的顶点
void prim(MatGraph* G, int v) {
    int lowcost[MAXV];  // 集合V中的顶点到集合U的最小距离
    int closest[MAXV];  // 集合V中的顶点到集合U中的哪个顶点距离最小
    // 初始化的时候集合U中只有一个顶点v，那么集合V中所有顶点到集合
    // U的最小距离就是G->edges[v][i]，因为这个时候到集合U就只有这一条边的选择
    // V中的所有顶点到集合U的距离最小的那个顶点也只能是v
    // 集合U中的所有顶点的lowcost值都设置为0，便于和集合V区分
    for (int i = 0; i < G->n; ++i) {
        lowcost[i] = G->edges[v][i];
        closest[i] = v;
    }
    // 找出n - 1条边
    for (int i = 1; i < G->n; ++i) {
        int min = 0x3f3f3f3f;
        int k = 0;
        for (int j = 0; j < G->n; ++j) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }
        // 输出这条边
        cout << "(" << closest[k] << "," << k << ")：" << min;
        // 由于U集合中又添加了一个元素，所以我们需要更新lowcost和closest数组
        // 我们只需要比较集合V中的元素的lowcost和edges[k][i]的大小就行了，如果
        // 集合U中元素的添加会使得值变得更小我们就更新
        for (int j = 0; j < G->n; ++j) {
            if (lowcost[j] != 0 && G->edges[k][j] < lowcost[j]) {
                lowcost[j] = G->edges[k][j];
                closest[j] = k;
            }
        }
    }
}