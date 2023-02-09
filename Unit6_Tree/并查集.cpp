#include <iostream>
using namespace std;

typedef struct node {
    int data;  // 对应结点的数据域
    int rank;  // 结点的秩，实际上也就是这颗分离集合树的最大高度
    int parent;  // 此节点的双亲结点
} DsjointSet;

// 并查集的初始化
void makeDS(DsjointSet t[], int n) {
    for (int i = 0; i < n; ++i) {
        t->data =
            i;  // 结点的编号和下标是一一对应的，想要访问哪个结点只需要访问下标就行了
        t->parent = i;  // 刚开始的时候每个元素自己就是一个集合
        t->rank = 1;  // 刚开始的秩初始化为1，自己一个结点就是一个集合，高度为1
    }
}

// 并查集的查找，查找某个结点所属的集合
// 由于根结点的双亲结点指向自己，所以遍历到某个结点以及这个结点的双亲结点都指向自身的时候
// 就结束
int findDS(DsjointSet t[], int x) {
    // 由于下标和结点就是一一对应的，所以我们直接访问
    if (x != t[x].parent) {
        return findDS(t, t[x].parent);
    } else {
        return x;
    }
}

// 两个元素各自所属的集合的合并
void unionDS(DsjointSet t[], int x, int y) {
    x = findDS(t, x);
    y = findDS(t, y);
    // 两个要合并的元素x和y可能本身就在一个集合当中不需要合并
    if (x == y)
        return;
    if (t[x].rank > t[y].rank) {  // y结点的秩小于x结点的秩
        t[y].parent = x;
    } else {
        t[x].parent = y;
        if (t[x].rank == t[y].rank) {
            t[y].rank++;
        }
    }
}