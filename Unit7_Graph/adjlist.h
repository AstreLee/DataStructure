const int MAXV = 10;  // �������

// ����߽��
struct ArcNode {
    int adjvex;        // �ڽӵ���
    ArcNode* nextarc;  // ��һ���߽��
    int weight;        // Ȩ�أ��������Ȩͼ�п���ָ��
};

// ����ͷ���
struct Vnode {
    int data;       // �ڽӵ���
    ArcNode* head;  // ָ�������ͷָ��
};

// ����ͼ�ṹ��
struct AdjGraph {
    Vnode adjlist[MAXV];
    int n;  // ��������
    int e;  // ������
};