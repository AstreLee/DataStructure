#include<iostream>
#include<stack>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;  // sequential stack

// ��ʼ��ջ
void initStack(SqStack*& s) {
    s = (SqStack*)malloc(sizeof(SqStack));  // ����ջ�ռ䣬�׵�ַ����s��
    s->top = -1;  // ջ��ָ���ʼ����ָ��-1λ��
}

// ����ջ�ռ�
void destoryStack(SqStack* s) {
    free(s);
}

// �ж�ջ�ռ��Ƿ�Ϊ��
bool isEmpty(SqStack* s) {
    return s->top == -1;
}

// �ж�ջ�ռ��Ƿ���
bool isFull(SqStack* s) {
    return s->top == MaxSize - 1;
}

// ��ȡջ�ռ���Ԫ�صĸ���
int size(SqStack* s) {
    return s->top;
}

// ��ջ
bool push(SqStack* s, ElemType e) {
    // �����ж�ջ�Ƿ���
    if (isFull(s))  false;
    // ����topָ��ָ��������һ��Ԫ�أ������������Ƚ�ָ������
    s->top++;
    // Ȼ��Ҫ����Ԫ��e����ջ����ע��˳��ջԪ���Ƿ���data�����
    s->data[s->top] = e;
    return true;
}

// ��ջ
bool pop(SqStack* s, ElemType& e) {
    // �����ж�ջ�Ƿ��
    if (isEmpty(s))  return false;
    // ��ջ��Ԫ�ظ�ֵ������e
    e = s->data[s->top];
    // ָ�����ƣ��൱�ڳ�ջ����
    s->top--;
    return true;
}

// ȡջ��Ԫ��
bool getTop(SqStack* s, ElemType& e) {
    // �����ж�ջ�Ƿ�Ϊ��
    if (isEmpty(s)) return false;
    // ��ջ��Ԫ�ظ�ֵ������e
    e = s->data[s->top];
    // ���ؽ��
    return true;
}