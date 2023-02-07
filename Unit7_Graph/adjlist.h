const int MAXV = 10;         // �������
const int INF = 0x3f3f3f3f;  // �������ֵ

// ����߽��
struct ArcNode {
    int adjvex;        // �ڽӵ���
    ArcNode* nextarc;  // ��һ���߽��
    int weight;        // Ȩ�أ��������Ȩͼ�п���ָ��
};

// ����ͷ���
struct Vnode {
    int data;       // ������
    ArcNode* head;  // ָ�������ͷָ��
};

// ����ͼ�ṹ��
struct AdjGraph {
    Vnode adjlist
        [MAXV];  // ���ǽ�ͷ�����飬���ʽṹ�������ʱ��ͨ��.��Ա������ʷ�����
    int n;       // ��������
    int e;       // ������
};