#include <iostream>
using namespace std;

// 定义数组中可以保存的元素的最大个数
const int MaxSize = 50;
// 定义数组中保存的元素类型别名ElemType
typedef int ElemType;
// 定义结构体LinkList(里面采用数组存放元素)
typedef struct {
    ElemType data[MaxSize];  // 采用数组的方式存放顺序表中的元素
    int length;              // length保存顺序表的实际长度
} LinkList;

// 定义函数
void InitList(LinkList*& L, ElemType a[], int n);         // 初始化线性表
void DestoryList(LinkList* L);                            // 销毁线性表(注意这里是线性存储，只需要删除这个节点就行)
bool IsListEmpty(LinkList* L);                            // 判断链表是否为空
int ListLength(LinkList* L);                              // 返回链表的长度
void DisplayList(LinkList* L);                            // 输出线性表
bool GetElemByIndex(LinkList* L, int i, ElemType& e);     // 通过下标获取对应位置的元素
bool GetIndexByElem(LinkList* L, ElemType e, int& i);     // 查找元素在线性表中是否存在
bool InsertElemByIndex(LinkList* L, int i, ElemType e);   // 在指定位置插入元素
bool DeleteElemByIndex(LinkList* L, int i, ElemType& e);  // 删除指定下标元素，并且返回这个元素

// 建立顺序表
void InitList(LinkList*& L, ElemType a[], int n) {
    // 首先创建一个LinkList结构出来，只需要创建这一个节点就OK了，因为这个数据是通过
    // 这个节点里面的数组存储的
    L = (LinkList*)malloc(sizeof(LinkList));
    for (int i = 0; i < n; ++i) {
        L->data[i] = a[i];
    }
    L->length = n;
}

// 销毁线性表
void DestoryList(LinkList* L) {
    free(L);
}

// 判断线性表是否为空
bool IsListEmpty(LinkList* L) {
    return L->length == 0;
}

// 返回线性表的长度
int ListLength(LinkList* L) {
    return L->length;
}

// 输出线性表
void DisplayList(LinkList* L) {
    for (int i = 0; i < L->length - 1; ++i) {
        cout << L->data[i] << "->";
    }
    cout << L->data[L->length - 1];
}

// 根据下标获取线性表中的元素，获取成功返回true, 否则返回false
bool GetElemByIndex(LinkList* L, int i, ElemType& e) {
    // 首先判断下标i的合法性，注意这里的i使用的逻辑下标
    if (i < 1 || i > L->length)
        return false;
    // 如果在范围内的话就首先转化为物理下标
    --i;
    e = L->data[i];
    return true;
}

// 根据元素获取对应的下标, 获取成功返回true, 否则返回false
bool GetIndexByElem(LinkList* L, ElemType e, int& i) {
    for (int k = 0; k < L->length; ++k) {
        if (L->data[k] == e) {
            i = k + 1;
            return true;
        }
    }
    return false;
}

// 根据下标插入对应位置的元素，插入成功返回true, 否则返回false
bool InsertElemByIndex(LinkList* L, int i, ElemType e) {
    // 首先看看插入的位置是否合法
    if (i < 1 || i > L->length + 1 || L->length == MaxSize)
        return false;
    // 将逻辑下标转化为物理下标
    i--;
    for (int j = L->length; j > i; --j) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;
    L->length++;  // 插入元素后记得元素个数加一
    return true;
}

// 根据下标删除元素，删除成功返回true,否则返回false
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