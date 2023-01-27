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
void move1(LinkList* L);  // ����һ���õ��������ڿ��ŵ�˼��
void move2(LinkList* L);  // ���������õ�����λ������¼�������ĸ�����ʵ���ϻ����Լ�¼ż���ĸ���
void swap(ElemType& a, ElemType& b);

// move1()��������
void move1(LinkList* L) {
    int i = 0;
    int j = L->length - 1;
    while (i < j) {
        while (i < j && L->data[j] % 2 == 0)
            --j;
        while (i < j && L->data[i] % 2 != 0)
            ++i;
        if (i < j)  // ������ü���һ���ж����������ָ��������û�б�Ҫ����
            swap(L->data[i], L->data[j]);
    }
}

// move2��������
void move2(LinkList* L) {
    int k = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] % 2 != 0) {
            if (i != k) {
                swap(L->data[i], L->data[k]);
            }
            ++k;
        }
    }
}

// swap��������
void swap(ElemType& a, ElemType& b) {
    ElemType temp = a;
    a = b;
    b = a;
}