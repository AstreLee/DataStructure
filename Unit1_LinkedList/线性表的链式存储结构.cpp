#include <iostream>
using namespace std;

typedef int ElemType;
struct LinkNode {
    ElemType data;          // 数据域的内容
    struct LinkNode* next;  // 指针域的内容
};

// 定义函数
void CreateListHead(LinkNode*& L, ElemType a[], int n);  // 头插法
void CreateListTail(LinkNode*& L, ElemType a[], int n);  // 尾插法
void InitList(LinkNode*& L);                             // 初始化链表
void DestoryList(LinkNode* L);                           // 销毁链表
bool IsListEmpty(LinkNode* L);  // 判断链表是否为空
int LengthOfList(LinkNode* L);  // 返回链表的长度
void Display(LinkNode* L);      // 输出线性表
bool GetElemByIndex(LinkNode* L, int i, ElemType& e);  // 根据下标返回对应元素
bool GetElem(LinkNode* L, ElemType e, int& i);  // 查找指定元素对应下标
bool InsertNodeByIndex(LinkNode* L, int i, ElemType e);  // 在指定位置处插入元素
bool DelNodeByIndex(LinkNode* L,
                    int i,
                    ElemType& e);  // 删除指定位置元素，并且获取这个元素
int LocateElem(LinkNode* L, ElemType e);  // 获取元素在链表中的对应位置
bool ListInsert(LinkNode* L, int i, ElemType e); // 插入数据元素
bool ListDelete(LinkNode* L, int i, ElemType& e);  // 删除元素



// 头插法
void CreateListHead(LinkNode*& L, ElemType a[], int n) {
    // 首先创建一个头节点
    L = (LinkNode*)malloc(sizeof(LinkNode));
    // 设置一下指针域就行了，数据域无所谓，这只是作为一个头节点，这一点很关键，不然我们的链表最后就不是NULL
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = a[i];
        // 下面两行是核心代码
        s->next = L->next;
        L->next = s;
    }
}

// 尾插法
void CreateListTail(LinkNode*& L, ElemType a[], int n) {
    // 首先创建一个头节点
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode* tail = L;
    for (int i = 0; i < n; ++i) {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = a[i];
        tail->next = s;
        // s->next = NULL; 这个操作不需要
        tail = s;
    }
    tail->next = NULL;  // 将尾节点的指针域置空
}

// 初始化链表
void InitList(LinkNode*& L) {
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
}

// 销毁链表
void DestoryList(LinkNode* L) {
    LinkNode* pre = L;  // 指针pre指向头结点
    LinkNode* pt = L->next;  // 指针pt指向首结点
    while (pt != NULL) {
        free(pre);
        pre = pt;
        pt = pt->next;
    }
    free(pre);  // 销毁尾结点
}

// 判断链表是否为空
bool IsListEmpty(LinkNode* L) {
    return L->next == NULL;
}

// 返回链表长度
int LengthOfList(LinkNode* L) {
    int count = 0;
    LinkNode* pt = L->next;
    while (pt != NULL) {
        ++count;
        pt = pt->next;
    }
    return count;
}

// 输出链表
void DisplayList(LinkNode* L) {
    LinkNode* pt = L->next;
    while (pt != NULL) {
        cout << "data: " << pt->data << endl;
        pt = pt->next;
    }
}

// 求链表中对应位置的元素值
bool GetElemByIndex(LinkNode* L, int i, ElemType& e) {
    // 由于不像顺序表那样直接保存了线性表的长度，所以我们事先并不知道，只能遍历
    if (i < 1)  return false;  // 位置异常处理
    int count = 1;  // 统计当前遍历到第几个结点
    LinkNode* pt = L->next;  // pt指针负责遍历，指向首结点
    while (count < i && pt != NULL) {  // 还没有遍历到并且链表没有断的情况下继续
        pt = pt->next;
        ++count;
    }
    // 循环结束有两种可能的情况
    // 情况一：没有遍历到位置i链表就已经断了
    if (pt == NULL)  return false;
    // 情况二：已经找到了对应位置的元素
    e = pt->data;
    return true;
}

// 寻找元素在链表中的对应位置
int LocateElem(LinkNode* L, ElemType e) {
    LinkNode* pt = L->next;
    int pos = 1;  // pos记录当前遍历到了第几个元素
    while (pt != NULL && pt->data != e) {
        pt = pt->next;
        ++pos;
    }
    // 结束同样有两种情况
    // 情况一：链表遍历结束也没找到
    if (pt == NULL)  return -1;
    // 情况二：链表遍历结束之间就已经找到了
    return pos;
}

// 插入数据元素
bool ListInsert(LinkNode* L, int i, ElemType e) {
    // 首先进行程序异常处理
    if (i < 1)  return false;
    int count = 0;  // 表示当前已经遍历过了几个结点
    LinkNode* pt = L;  // 指针pt负责遍历
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    // 遍历结束同样有两种情况
    if (pt == NULL) return false;
    else {
        LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = pt->next;
        pt->next = s;
        return true;
    }
}

// 删除数据元素
bool ListDelete(LinkNode* L, int i, ElemType& e) {
    // 删除位置异常处理
    if (i < 1)  return false;
    int count = 0;  // count记录当前遍历过的结点数
    LinkNode* pt = L;
    while (count < i - 1 && pt != NULL) {
        pt = pt->next;
        ++count;
    }
    // 结束的时候同样有两种情况
    if (pt == NULL)  return false;
    else {
        // 如果删除的位置是最后一个元素后面一个位置的话
        if (pt->next == NULL)  return false;
        // 否则的话我们就正常删除
        LinkNode* pre = pt;
        pt = pt->next;
        pre->next = pt->next;
        free(pt);
        return true;
    }
}