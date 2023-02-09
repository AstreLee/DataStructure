const int MAXV = 4;          // ��󶥵����
const int INF = 0x3f3f3f3f;  // �������ֵ

// ����ڵ�����
typedef struct {
    int no;  // ����ţ��ݶ��ͽ���ֻ����һ���������
} VertexType;

// ����ͼ�ṹ
typedef struct {
    int edges[MAXV][MAXV] = {{0, 4, 3, 1},
                             {4, 0, 5, INF},
                             {3, 5, 0, 2},
                             {1, INF, 2, 0}};
    ;                       // �ڽӾ�������
    int n;                  // ��������
    int e;                  // ������
    VertexType vexs[MAXV];  // ������ͼ���ڽӾ�������
} MatGraph;