#include <iostream>
#include <queue>
#include "adjlist.h"
#include "matrix.h"
using namespace std;

// 创建图的运算算法，通过邻接矩阵创建邻接表
void createGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) {
    // 首先创建图G的存储空间
    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    // 初始化头结点数组中所有的结点的指针域为NULL，同时初始化编号
    for (int i = 0; i < n; ++i) {
        G->adjlist[i].data = i;
        G->adjlist[i].head = NULL;
    }
    // 遍历邻接矩阵，初始化每个顶点的单链表
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                // 头插法插入这个结点
                p->nextarc = G->adjlist[i].head;
                G->adjlist[i].head = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

// 输出图的运算算法
void disGraph(AdjGraph* G) {
    for (int i = 0; i < G->n; ++i) {
        ArcNode* p = G->adjlist[i].head;
        cout << i;  // 先输出头结点信息
        while (p != NULL) {
            cout << p->adjvex << p->weight << endl;
        }
        cout << endl;
    }
}

// 销毁图的算法
void destoryGraph(AdjGraph* G) {
    for (int i = 0; i < G->n; ++i) {
        ArcNode* pre = G->adjlist[i].head;
        if (pre != NULL) {
            ArcNode* p = pre->nextarc;
            while (p != NULL) {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

// 邻接表转换为邻接矩阵
void listToMat(AdjGraph* G, MatGraph& g) {
    ArcNode* p = NULL;
    for (int i = 0; i < G->n; ++i) {
        p = G->adjlist[i].head;
        while (p != NULL) {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }
    g.n = G->n;
    g.e = G->e;
}

// 邻接表DFS
int visited[MAXV];
void DFS_adjlist(AdjGraph* G, int v) {
    ArcNode* p = NULL;
    cout << v << " ";  // 输出访问的结点
    visited[v] = 1;    // 标记已经访问过
    p = G->adjlist[v].head;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) {
            // 对邻接点同样进行深度优先遍历
            DFS_adjlist(G, p->adjvex);
        }
    }
}

// 邻接矩阵DFS
int visited1[MAXV];
void DFS_matrix(MatGraph* G, int v) {
    // 输出这个结点
    cout << v << " ";
    // 标记这个点已经访问过
    visited1[v] = 1;
    // 遍历每一个顶点，查看是否为v的邻接点并且没有访问过的
    for (int i = 0; i < G->n; ++i) {
        if (visited1[i] == 1)
            continue;
        else {
            if (G->edges[v][i] != 0 && G->edges[v][i] != INF) {
                // 以顶点i为起点进行深度优先遍历
                DFS_matrix(G, i);
            }
        }
    }
}

// 邻接表的广度优先遍历，利用队列存储每一层的结点
void BFS(AdjGraph* G) {
    queue<int> q;       // 定义队列
    int visited[G->n];  // 定义访问数组
    for (int i = 0; i < G->n; ++i) {
        visited[i] = 0;
    }                // 初始化访问数组
    visited[0] = 1;  // 假设从第一个顶点开始访问
    cout << "0"
         << " ";
    q.push(0);            // 添加第一个顶点
    while (!q.empty()) {  // 队列不空的时候继续循环
        // 出队一个结点
        int temp = q.front();
        // 访问这个结点的所有邻接结点
        ArcNode* p = G->adjlist[temp].head;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {  // 当前邻接点未被访问
                cout << p->adjvex << " ";   // 输出当前邻接点
                visited[p->adjvex] = 1;  // 当前邻接点标记已经访问过
                q.push(p->adjvex);       // 入队
            }
            p = p->nextarc;  // 继续访问下一个邻接点
        }
    }
}