#include<iostream>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct node {
    ElemType data;  // 数据域
    struct node* next;  // 指针域
} DataNode;
typedef struct {
    DataNode* front;  // 指向队首结点
    DataNode* rear;  // 指向队尾结点
} LinkQuNode;

// 初始化链队
void initQueue(LinkQuNode*& q) {
    q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
    q->front = q->rear = NULL;
}

// 销毁链队
void destoryQueue(LinkQuNode* q) {
    if (isEmpty(q))  {
        free(q);
        return;
    }
    DataNode* pre = q->front;
    DataNode* pt = pre->next;
    while (pt != NULL) {
        free(pre);
        pre = pt;
        pt = pt->next;
    }
    free(pre);
    free(q);
}

// 判断链队是否为空
bool isEmpty(LinkQuNode* q) {
    return q->front == NULL;
}

// 进队
void enQueue(LinkQuNode* q, ElemType e) {
    DataNode* s = (DataNode*)malloc(sizeof(DataNode));
    s->data = e;
    s->next = NULL;
    // 这里要考虑插入的是不是第一个元素
    if (q->rear == NULL) {
        q->rear = q->front = s;
    } else {
        q->rear->next = s;
        q->rear = s;  // 注意这个尾指针也是要移动的
    }
}

// 出队
void deQueue(LinkQuNode* q, ElemType& e) {
    // 首先判断队列是否为空
    if (isEmpty(q))  return;
    // 队列不为空的时候有一个结点和多个结点的情况
    // 首先将队首结点保存下来
    DataNode* pt = q->front;
    // 如果只有一个结点的话
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }
    e = pt->data;
    free(pt);
}