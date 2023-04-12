#include <iostream>
using namespace std;
typedef int ElemType;  // 给类型定义别名别名要放在类型的后面

struct Lnode {
    ElemType data;       // 数据域
    struct Lnode* next;  // 指针域, 声明的时候这个struct必须要带上
};

// 初始化不带头结点的单链表(尾插法)
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

// 初始化带头结点的单链表
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

// 输出单链表
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