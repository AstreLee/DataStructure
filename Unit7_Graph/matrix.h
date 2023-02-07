const int MAXV = 10;  // 最大顶点个数

// 定义节点类型
typedef struct {
    int no;  // 结点编号，暂定就结点就只有这一个编号性质
} VertexType;

// 定义图结构
typedef struct {
    int edges[MAXV][MAXV];  // 邻接矩阵数组
    int n;                  // 顶点总数
    int e;                  // 边总数
    VertexType vexs[MAXV];  // 完整的图的邻接矩阵类型
} MatGraph;