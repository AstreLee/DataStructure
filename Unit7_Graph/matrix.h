const int MAXV = 4;          // 最大顶点个数
const int INF = 0x3f3f3f3f;  // 定义最大值

// 定义节点类型
typedef struct {
    int no;  // 结点编号，暂定就结点就只有这一个编号性质
} VertexType;

// 定义图结构
typedef struct {
    int edges[MAXV][MAXV] = {{0, 4, 3, 1},
                             {4, 0, 5, INF},
                             {3, 5, 0, 2},
                             {1, INF, 2, 0}};
    ;                       // 邻接矩阵数组
    int n;                  // 顶点总数
    int e;                  // 边总数
    VertexType vexs[MAXV];  // 完整的图的邻接矩阵类型
} MatGraph;