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
void InitList(LinkList*& L, ElemType a[], int n);         // ��ʼ�����Ա�
void DestoryList(LinkList* L);                            // �������Ա�(ע�����������Դ洢��ֻ��Ҫɾ������ڵ����)
bool IsListEmpty(LinkList* L);                            // �ж������Ƿ�Ϊ��
int ListLength(LinkList* L);                              // ��������ĳ���
void DisplayList(LinkList* L);                            // ������Ա�
bool GetElemByIndex(LinkList* L, int i, ElemType& e);     // ͨ���±��ȡ��Ӧλ�õ�Ԫ��
bool GetIndexByElem(LinkList* L, ElemType e, int& i);     // ����Ԫ�������Ա����Ƿ����
bool InsertElemByIndex(LinkList* L, int i, ElemType e);   // ��ָ��λ�ò���Ԫ��
bool DeleteElemByIndex(LinkList* L, int i, ElemType& e);  // ɾ��ָ���±�Ԫ�أ����ҷ������Ԫ��

// ����˳���
void InitList(LinkList*& L, ElemType a[], int n) {
    // ���ȴ���һ��LinkList�ṹ������ֻ��Ҫ������һ���ڵ��OK�ˣ���Ϊ���������ͨ��
    // ����ڵ����������洢��
    L = (LinkList*)malloc(sizeof(LinkList));
    for (int i = 0; i < n; ++i) {
        L->data[i] = a[i];
    }
    L->length = n;
}

// �������Ա�
void DestoryList(LinkList* L) {
    free(L);
}

// �ж����Ա��Ƿ�Ϊ��
bool IsListEmpty(LinkList* L) {
    return L->length == 0;
}

// �������Ա�ĳ���
int ListLength(LinkList* L) {
    return L->length;
}

// ������Ա�
void DisplayList(LinkList* L) {
    for (int i = 0; i < L->length - 1; ++i) {
        cout << L->data[i] << "->";
    }
    cout << L->data[L->length - 1];
}

// �����±��ȡ���Ա��е�Ԫ�أ���ȡ�ɹ�����true, ���򷵻�false
bool GetElemByIndex(LinkList* L, int i, ElemType& e) {
    // �����ж��±�i�ĺϷ��ԣ�ע�������iʹ�õ��߼��±�
    if (i < 1 || i > L->length)
        return false;
    // ����ڷ�Χ�ڵĻ�������ת��Ϊ�����±�
    --i;
    e = L->data[i];
    return true;
}

// ����Ԫ�ػ�ȡ��Ӧ���±�, ��ȡ�ɹ�����true, ���򷵻�false
bool GetIndexByElem(LinkList* L, ElemType e, int& i) {
    for (int k = 0; k < L->length; ++k) {
        if (L->data[k] == e) {
            i = k + 1;
            return true;
        }
    }
    return false;
}

// �����±�����Ӧλ�õ�Ԫ�أ�����ɹ�����true, ���򷵻�false
bool InsertElemByIndex(LinkList* L, int i, ElemType e) {
    // ���ȿ��������λ���Ƿ�Ϸ�
    if (i < 1 || i > L->length + 1 || L->length == MaxSize)
        return false;
    // ���߼��±�ת��Ϊ�����±�
    i--;
    for (int j = L->length; j > i; --j) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;
    L->length++;  // ����Ԫ�غ�ǵ�Ԫ�ظ�����һ
    return true;
}

// �����±�ɾ��Ԫ�أ�ɾ���ɹ�����true,���򷵻�false
bool DeleteElemByIndex(LinkList* L, int i, ElemType& e) {
    if (i < 1 || i > L->length) 
        return false;
    i--;
    e = L->data[i];
    for (int j = i; j < L->length - 1; ++j) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}