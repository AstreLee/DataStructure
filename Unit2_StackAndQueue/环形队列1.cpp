#include<iostream>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];  // ����˳��ṹ��Ŷ����е�Ԫ��
    int front;  // ����ָ��
    int count;  // Ԫ���������������ǾͿ���ͨ��conut�ж϶ӿջ��Ƕ���
} QuType;  // ˳�������

// ��ʼ������
void initQueue(QuType*& q) {
    q = (QuType*)malloc(sizeof(QuType));
    q->front = q->count = 0;
}

// ���ٶ���
void destoryQueue(QuType* q) {
    free(q);
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(QuType* q) {
    return q->count == 0;
}

// �ж϶����Ƿ���
bool isFull(QuType* q) {
    return q->count == MaxSize;
}

// ��ȡ���г���
int size(QuType* q) {
    return q->count;
}

// ����
bool enQueue(QuType* q, ElemType e) {
    // �����ж϶����Ƿ���
    if (isFull(q))  return false;
    // ����front��count��ȡ��βλ��
    int rear = (q->front + q->count) % MaxSize;
    // rear++
    rear = (rear + 1) % MaxSize;
    // ����Ӧ��Ԫ�ظ�ֵ��rear
    q->data[rear] = e;
    // �ǵ�count++
    q->count++;
    return true;
}

// ����
bool deQueue(QuType* q, ElemType& e) {
    // �����ж϶����Ƿ�Ϊ��
    if (isEmpty(q)) return false;
    // frontǰ��
    q->front = (q->front + 1) % MaxSize;
    // ��ֵe
    e = q->data[q->front];
    // count--
    q->count--;
    return true;
}