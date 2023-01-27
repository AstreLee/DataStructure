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
void deListNode1(LinkList* L, ElemType x);
void deListNode2(LinkList* L, ElemType x);
void deListNode3(LinkList* L, ElemType x);


// ��һ��ɾ��ָ��Ԫ�صķ�ʽ�����Ǳ�������˳�������ΪX��Ԫ�����������
void deListNode1(LinkList* L, ElemType x) {
    int k = 0;  // ��¼��һ����XԪ�������λ��
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            ++k;
        }
    }
    L->length = k;
}

// �ڶ���ɾ��ָ��Ԫ�صķ�ʽ��ͬ���Ǳ�������˳����뷽��һ��ͬ���Ƿ�����ͳ�Ƶ���
// ����x��Ԫ�صĸ�������ô��ŵ�λ�þ��õ�ǰ�±�i - count��x��ָ��
void deListNode2(LinkList* L, ElemType e) {
    int k = 0;  // ��¼��ǰλ��ǰ�ж��ٸ�ֵ����x��Ԫ��
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e) {
            k++;
        } else {
            L->data[i - k] = L->data[i];
        }
    }
    L->length -= k;
}

// �����֣���ʵ����˺���Ľ������Ƶ�ǰ������˼�룬�������ַ����Ļ��Ͳ��ܱ�֤ԭ����˳����
void deListNode3(LinkList* L, ElemType x) {
    int i = 0;
    int j = L->length - 1;
    while (i < j) {
        while (i < j && L->data[j] == x)
            --j;
        while (i < j && L->data[i] != x)
            ++i;
        if (i != j) {
            ElemType temp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = temp;
        }
    }
    L->length = i + 1;
}