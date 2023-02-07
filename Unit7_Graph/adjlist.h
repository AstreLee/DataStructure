const int MAXV = 10;  // 最大结点数

// 定义边结点
struct ArcNode {
    int adjvex;        // 邻接点编号
    ArcNode* nextarc;  // 下一个边结点
    int weight;        // 权重，这个在有权图中可以指定
};

// 定义头结点
struct Vnode {
    int data;       // 邻接点编号
    ArcNode* head;  // 指向单链表的头指针
};

// 定义图结构体
struct AdjGraph {
    Vnode adjlist[MAXV];
    int n;  // 顶点总数
    int e;  // 边总数
};