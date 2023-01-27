#include<iostream>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];  // 采用顺序结构存放队列中的元素
    int front, rear;  // 队首、队尾指针
} SqQueue;  // 顺序队类型


// 初始化队列
void initQueue(SqQueue*& q) {
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

// 销毁队列
void destoryQueue(SqQueue* q) {
    free(q);
}

// 判断队列是否为空
bool isEmpty(SqQueue* q) {
    return q->front == q->rear;
}

// 判断队列是否满
bool isFull(SqQueue* q) {
    return (q->rear + 1) % MaxSize == q->front;
}

// 获取队列长度
int size(SqQueue* q) {
    return (q->rear - q->front + MaxSize) % MaxSize;
}

// 进队
bool enQueue(SqQueue* q, ElemType e) {
    // 首先判断队列是否满
    if (isFull(q))  return false;
    q->rear = (q->rear + 1) % MaxSize;  // 这里一定要注意循环队列要求余
    q->data[q->rear] = e;
    return true;
}

// 出队
bool deQueue(SqQueue* q, ElemType& e) {
    // 首先判断队列是否为空
    if (isEmpty(q)) return false;
    q->front = (q->front + 1) % MaxSize;  // 这里一定要注意循环队列要求余
    e = q->front;
    return true;
}