#include <iostream>
#include "matrix.h"
using namespace std;

// prim�㷨
// param1����ΪҪƵ������һ�����ߵ�Ȩ�ޣ�����ʹ���ڽӾ���ȽϺ���
// param2��v��ʾ��ʼ���ʵĶ���
void prim(MatGraph* G, int v) {
    int lowcost[MAXV];  // ����V�еĶ��㵽����U����С����
    int closest[MAXV];  // ����V�еĶ��㵽����U�е��ĸ����������С
    // ��ʼ����ʱ�򼯺�U��ֻ��һ������v����ô����V�����ж��㵽����
    // U����С�������G->edges[v][i]����Ϊ���ʱ�򵽼���U��ֻ����һ���ߵ�ѡ��
    // V�е����ж��㵽����U�ľ�����С���Ǹ�����Ҳֻ����v
    // ����U�е����ж����lowcostֵ������Ϊ0�����ںͼ���V����
    for (int i = 0; i < G->n; ++i) {
        lowcost[i] = G->edges[v][i];
        closest[i] = v;
    }
    // �ҳ�n - 1����
    for (int i = 1; i < G->n; ++i) {
        int min = 0x3f3f3f3f;
        int k = 0;
        for (int j = 0; j < G->n; ++j) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }
        // ���������
        cout << "(" << closest[k] << "," << k << ")��" << min;
        // ����U�������������һ��Ԫ�أ�����������Ҫ����lowcost��closest����
        // ����ֻ��Ҫ�Ƚϼ���V�е�Ԫ�ص�lowcost��edges[k][i]�Ĵ�С�����ˣ����
        // ����U��Ԫ�ص���ӻ�ʹ��ֵ��ø�С���Ǿ͸���
        for (int j = 0; j < G->n; ++j) {
            if (lowcost[j] != 0 && G->edges[k][j] < lowcost[j]) {
                lowcost[j] = G->edges[k][j];
                closest[j] = k;
            }
        }
    }
}