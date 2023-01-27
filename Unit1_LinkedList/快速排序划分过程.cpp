#include <iostream>
using namespace std;

// ���������п��Ա����Ԫ�ص�������
const int MaxSize = 50;
// ���������б����Ԫ�����ͱ���ElemType
typedef int ElemType;
// ����ṹ��LinkList(�������������Ԫ��)
typedef struct {
    ElemType data[MaxSize];  // ��������ķ�ʽ���˳����е�Ԫ��
    int length;              // length����˳����ʵ�ʳ���
} LinkList;

// ���庯��
void partitional_1(LinkList* L);
void partitional_2(LinkList* L);
void swap(ElemType& a, ElemType& b);

// ��һ����ֱ�ӽ���i��jָ��ָ���λ��
void partitional_1(LinkList* L) {
    int i = 0;
    int j = L->length - 1;
    ElemType privot = L->data[0];  // �Ե�һ��Ԫ����Ϊ��׼Ԫ��
    while (i < j) {
        while (i < j && L->data[j] > privot)
            --j;
        while (i < j && L->data[i] <= privot)
            ++i;
        if (i < j)  // �����п���i == j, ���ʱ���û�б�Ҫ���н�����
            swap(L->data[i], L->data[j]);
    }
    swap(L->data[0], L->data[i]);
}

// �ڶ��ֵĻ�����󲻶ϵĸ�ֵ����Ƚ�����˵Ч�ʸ��˲���
void partitional_2(LinkList* L) {
    int i = 0;
    int j = L->length - 1;
    ElemType privot = L->data[0];
    while (i < j) {
        while (i < j && L->data[j] > privot)
            --j;
        L->data[i] = L->data[j];
        while (i < j && L->data[i] <= privot)
            ++i;
        L->data[j] = L->data[i];
    }
    L->data[i] = privot;
}

void swap(ElemType& a, ElemType& b) {
    ElemType temp = a;
    a = b;
    b = temp;
}