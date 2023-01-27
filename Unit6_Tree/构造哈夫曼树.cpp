#include <iostream>
using namespace std;

const int N = 50;
typedef struct {
    char data;  // 数据域
    double weight;  // 结点权重
    int parent;  // 双亲结点位置
    int lchild;  // 左孩子结点位置
    int rchild;  // 右孩子结点位置
} HTNode;

typedef struct {  // 实际上这个用vector可能更好一点，因为有多少个结点事先不确定
    char cd[N];  // 存放当前结点的哈夫曼编码值
    int start;  // cd[start...n]部分都是哈夫曼值 
} HCode;

// 创建哈夫曼树
// ht是HTNode结构体数组，数组中的每个元素都是一个结构体变量，可以通过成员访问运算法.来访问
// n是叶子结点的个数
void createHt(HTNode ht[], int n) {
    // 首先将2n - 1个结点的parent,lchild,rchild全部置-1
    for (int i = 0; i < 2 * n - 1; ++i) {
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    // 然后从位置n开始，从前面没有双亲结点的结点中寻找权值最小的两个结点
    for (int i = n; i < 2 * n - 1; ++i) {
        int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;  // min1为最小值，min2为次小值
        int lnode, rnode = -1;  // lnode是最小的, rnode是次小的
        for (int k = 0; k < i; ++k) {
            // 注意只寻找没有双亲结点的结点
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = ht[rnode].parent = i;
    }
}


void createHCode(HTNode ht[], HCode hcd[], int n) {
    HCode hc;
    for (int i = 0; i < n; ++i) {
        hc.start = n;
        int f = ht[i].parent;
        int c = i;
        while (f != -1) {  // 双亲结点存在就继续循环
            if (ht[f].lchild == c) {
                hc.cd[hc.start--] = '0';
            } else {
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;  // 结构体数组元素赋值
    }
}