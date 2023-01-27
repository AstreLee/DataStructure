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
    q = (SqQueue*)malloc(sizeof(SqQueue));  // 给队列分配内存空间
    q->front = q->rear = -1;  // 队首指针和队尾指针全部初始化为-1，并且约定队尾指针指向最后一个元素，队首指针指向第一个元素前的一个位置
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
    return q->rear == MaxSize - 1;
}

// 获取队列的长度
int size(SqQueue* q) {
    return q->rear - q->front;
}

// 进队
bool enQueue(SqQueue* q, ElemType e) {
    // 首先判断队列是否满
    if (isFull(q))  return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

// 出队
bool deQueue(SqQueue* q, ElemType& e) {
    // 首先判断队列是否为空
    if (isEmpty(q))  return false;
    q->front++;
    e = q->data[q->front];
    return true;
}