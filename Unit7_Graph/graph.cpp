#include <iostream>
#include <queue>
#include "adjlist.h"
#include "matrix.h"
using namespace std;

// ����ͼ�������㷨��ͨ���ڽӾ��󴴽��ڽӱ�
void createGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) {
    // ���ȴ���ͼG�Ĵ洢�ռ�
    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    // ��ʼ��ͷ������������еĽ���ָ����ΪNULL��ͬʱ��ʼ�����
    for (int i = 0; i < n; ++i) {
        G->adjlist[i].data = i;
        G->adjlist[i].head = NULL;
    }
    // �����ڽӾ��󣬳�ʼ��ÿ������ĵ�����
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                // ͷ�巨����������
                p->nextarc = G->adjlist[i].head;
                G->adjlist[i].head = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

// ���ͼ�������㷨
void disGraph(AdjGraph* G) {
    for (int i = 0; i < G->n; ++i) {
        ArcNode* p = G->adjlist[i].head;
        cout << i;  // �����ͷ�����Ϣ
        while (p != NULL) {
            cout << p->adjvex << p->weight << endl;
        }
        cout << endl;
    }
}

// ����ͼ���㷨
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

// �ڽӱ�ת��Ϊ�ڽӾ���
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

// �ڽӱ�DFS
int visited[MAXV];
void DFS_adjlist(AdjGraph* G, int v) {
    ArcNode* p = NULL;
    cout << v << " ";  // ������ʵĽ��
    visited[v] = 1;    // ����Ѿ����ʹ�
    p = G->adjlist[v].head;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) {
            // ���ڽӵ�ͬ������������ȱ���
            DFS_adjlist(G, p->adjvex);
        }
    }
}

// �ڽӾ���DFS
int visited1[MAXV];
void DFS_matrix(MatGraph* G, int v) {
    // ���������
    cout << v << " ";
    // ���������Ѿ����ʹ�
    visited1[v] = 1;
    // ����ÿһ�����㣬�鿴�Ƿ�Ϊv���ڽӵ㲢��û�з��ʹ���
    for (int i = 0; i < G->n; ++i) {
        if (visited1[i] == 1)
            continue;
        else {
            if (G->edges[v][i] != 0 && G->edges[v][i] != INF) {
                // �Զ���iΪ������������ȱ���
                DFS_matrix(G, i);
            }
        }
    }
}

// �ڽӱ�Ĺ�����ȱ��������ö��д洢ÿһ��Ľ��
void BFS(AdjGraph* G) {
    queue<int> q;       // �������
    int visited[G->n];  // �����������
    for (int i = 0; i < G->n; ++i) {
        visited[i] = 0;
    }                // ��ʼ����������
    visited[0] = 1;  // ����ӵ�һ�����㿪ʼ����
    cout << "0"
         << " ";
    q.push(0);            // ��ӵ�һ������
    while (!q.empty()) {  // ���в��յ�ʱ�����ѭ��
        // ����һ�����
        int temp = q.front();
        // ����������������ڽӽ��
        ArcNode* p = G->adjlist[temp].head;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {  // ��ǰ�ڽӵ�δ������
                cout << p->adjvex << " ";   // �����ǰ�ڽӵ�
                visited[p->adjvex] = 1;  // ��ǰ�ڽӵ����Ѿ����ʹ�
                q.push(p->adjvex);       // ���
            }
            p = p->nextarc;  // ����������һ���ڽӵ�
        }
    }
}