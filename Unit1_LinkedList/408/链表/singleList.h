#include <iostream>
using namespace std;
typedef int ElemType;  // �����Ͷ����������Ҫ�������͵ĺ���

struct Lnode {
    ElemType data;       // ������
    struct Lnode* next;  // ָ����, ������ʱ�����struct����Ҫ����
};

// ��ʼ������ͷ���ĵ�����(β�巨)
Lnode* initWithoutHead(int arr[], int n) {
    Lnode* head = (Lnode*)malloc(sizeof(Lnode));
    head->data = arr[0];
    head->next = NULL;
    Lnode* tail = head;
    for (int i = 1; i < n; ++i) {
        Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
        newNode->data = arr[i];
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = NULL;
    return head;
}

// ��ʼ����ͷ���ĵ�����
Lnode* initWithHead(int arr[], int n) {
    Lnode* head = (Lnode*)malloc(sizeof(Lnode));
    Lnode* tail = head;
    for (int i = 0; i < n; ++i) {
        Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
        newNode->data = arr[i];
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = NULL;
    return head;
}

// ���������
void displayList(Lnode* L) {
    if (L == NULL) {
        return;
    }
    while (L->next != NULL) {
        cout << L->data << "->";
        L = L->next;
    }
    cout << L->data << endl;
}