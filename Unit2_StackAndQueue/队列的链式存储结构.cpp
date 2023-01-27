#include<iostream>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct node {
    ElemType data;  // ������
    struct node* next;  // ָ����
} DataNode;
typedef struct {
    DataNode* front;  // ָ����׽��
    DataNode* rear;  // ָ���β���
} LinkQuNode;

// ��ʼ������
void initQueue(LinkQuNode*& q) {
    q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
    q->front = q->rear = NULL;
}

// ��������
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

// �ж������Ƿ�Ϊ��
bool isEmpty(LinkQuNode* q) {
    return q->front == NULL;
}

// ����
void enQueue(LinkQuNode* q, ElemType e) {
    DataNode* s = (DataNode*)malloc(sizeof(DataNode));
    s->data = e;
    s->next = NULL;
    // ����Ҫ���ǲ�����ǲ��ǵ�һ��Ԫ��
    if (q->rear == NULL) {
        q->rear = q->front = s;
    } else {
        q->rear->next = s;
        q->rear = s;  // ע�����βָ��Ҳ��Ҫ�ƶ���
    }
}

// ����
void deQueue(LinkQuNode* q, ElemType& e) {
    // �����ж϶����Ƿ�Ϊ��
    if (isEmpty(q))  return;
    // ���в�Ϊ�յ�ʱ����һ�����Ͷ���������
    // ���Ƚ����׽�㱣������
    DataNode* pt = q->front;
    // ���ֻ��һ�����Ļ�
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }
    e = pt->data;
    free(pt);
}