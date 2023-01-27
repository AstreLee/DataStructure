#include<iostream>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];  // 采用顺序结构存放队列中的元素
    int front;  // 队首指针
    int count;  // 元素数量，这样我们就可以通过conut判断队空还是队满
} QuType;  // 顺序队类型

// 初始化队列
void initQueue(QuType*& q) {
    q = (QuType*)malloc(sizeof(QuType));
    q->front = q->count = 0;
}

// 销毁队列
void destoryQueue(QuType* q) {
    free(q);
}

// 判断队列是否为空
bool isEmpty(QuType* q) {
    return q->count == 0;
}

// 判断队列是否满
bool isFull(QuType* q) {
    return q->count == MaxSize;
}

// 获取队列长度
int size(QuType* q) {
    return q->count;
}

// 进队
bool enQueue(QuType* q, ElemType e) {
    // 首先判断队列是否满
    if (isFull(q))  return false;
    // 根据front和count获取队尾位置
    int rear = (q->front + q->count) % MaxSize;
    // rear++
    rear = (rear + 1) % MaxSize;
    // 将对应的元素赋值给rear
    q->data[rear] = e;
    // 记得count++
    q->count++;
    return true;
}

// 出队
bool deQueue(QuType* q, ElemType& e) {
    // 首先判断队列是否为空
    if (isEmpty(q)) return false;
    // front前移
    q->front = (q->front + 1) % MaxSize;
    // 赋值e
    e = q->data[q->front];
    // count--
    q->count--;
    return true;
}