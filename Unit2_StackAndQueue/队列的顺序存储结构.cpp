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
    q = (SqQueue*)malloc(sizeof(SqQueue));  // �����з����ڴ�ռ�
    q->front = q->rear = -1;  // ����ָ��Ͷ�βָ��ȫ����ʼ��Ϊ-1������Լ����βָ��ָ�����һ��Ԫ�أ�����ָ��ָ���һ��Ԫ��ǰ��һ��λ��
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
    return q->rear == MaxSize - 1;
}

// ��ȡ���еĳ���
int size(SqQueue* q) {
    return q->rear - q->front;
}

// ����
bool enQueue(SqQueue* q, ElemType e) {
    // �����ж϶����Ƿ���
    if (isFull(q))  return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

// ����
bool deQueue(SqQueue* q, ElemType& e) {
    // �����ж϶����Ƿ�Ϊ��
    if (isEmpty(q))  return false;
    q->front++;
    e = q->data[q->front];
    return true;
}