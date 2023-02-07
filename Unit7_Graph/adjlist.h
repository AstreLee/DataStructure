const int MAXV = 10;         // 最大结点数
const int INF = 0x3f3f3f3f;  // 定义最大值

// 定义边结点
struct ArcNode {
    int adjvex;        // 邻接点编号
    ArcNode* nextarc;  // 下一个边结点
    int weight;        // 权重，这个在有权图中可以指定
};

// 定义头结点
struct Vnode {
    int data;       // 顶点编号
    ArcNode* head;  // 指向单链表的头指针
};

// 定义图结构体
struct AdjGraph {
    Vnode adjlist
        [MAXV];  // 这是接头体数组，访问结构体变量的时候通过.成员运算访问符访问
    int n;       // 顶点总数
    int e;       // 边总数
};