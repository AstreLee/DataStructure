#include<iostream>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];  // ����˳��ṹ��Ŷ����е�Ԫ��
    int front, rear;  // ���ס���βָ��
} SqQueue;  // ˳�������


// ��ʼ������
void initQueue(SqQueue*& q) {
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

// ���ٶ���
void destoryQueue(SqQueue* q) {
    free(q);
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(SqQueue* q) {
    return q->front == q->rear;
}

// �ж϶����Ƿ���
bool isFull(SqQueue* q) {
    return (q->rear + 1) % MaxSize == q->front;
}

// ��ȡ���г���
int size(SqQueue* q) {
    return (q->rear - q->front + MaxSize) % MaxSize;
}

// ����
bool enQueue(SqQueue* q, ElemType e) {
    // �����ж϶����Ƿ���
    if (isFull(q))  return false;
    q->rear = (q->rear + 1) % MaxSize;  // ����һ��Ҫע��ѭ������Ҫ����
    q->data[q->rear] = e;
    return true;
}

// ����
bool deQueue(SqQueue* q, ElemType& e) {
    // �����ж϶����Ƿ�Ϊ��
    if (isEmpty(q)) return false;
    q->front = (q->front + 1) % MaxSize;  // ����һ��Ҫע��ѭ������Ҫ����
    e = q->front;
    return true;
}