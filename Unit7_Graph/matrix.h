const int MAXV = 10;  // ��󶥵����

// ����ڵ�����
typedef struct {
    int no;  // ����ţ��ݶ��ͽ���ֻ����һ���������
} VertexType;

// ����ͼ�ṹ
typedef struct {
    int edges[MAXV][MAXV];  // �ڽӾ�������
    int n;                  // ��������
    int e;                  // ������
    VertexType vexs[MAXV];  // ������ͼ���ڽӾ�������
} MatGraph;