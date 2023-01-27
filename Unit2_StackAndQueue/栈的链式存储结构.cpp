#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct linknode{
    ElemType data;  // 数据域
    struct linknode* next;  // 指针域 
}LinkStNode;

// 初始化栈
void initStack(LinkStNode*& s) {
    s = (LinkStNode*)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

// 销毁栈空间
void destoryStack(LinkStNode* s) {
    LinkStNode* pre = s;
    LinkStNode* pt = s->next;
    while (pt != NULL) {
        free(pre);
        pre = pt;
        pt = pt->next;
    }
    free(pre);
}

// 判断栈是否为空
bool isEmpty(LinkStNode* s) {
    return s->next == NULL;
}

// 进栈
void push(LinkStNode* s, ElemType e) {
    // 首先创建结点
    LinkStNode* pt = (LinkStNode*)malloc(sizeof(LinkStNode));
    // 给结点的数据域赋值
    pt->data = e;
    // 将结点作为头结点插入
    pt->next = s->next;
    // 让头结点指向新插入的结点
    s->next = pt;
}

// 出栈
bool pop(LinkStNode* s, ElemType& e) {
    // 链栈虽然不会满，但是有可能为空，所以这里我们需要判断一下
    if (isEmpty(s))  return false;
    e = s->next->data;
    s->next = s->next->next;
    return true;
}

// 取栈顶元素
bool getTop(LinkStNode* s, ElemType& e) {
    if (isEmpty(s))  return false;
    e = s->next->data;
    return true;
}
