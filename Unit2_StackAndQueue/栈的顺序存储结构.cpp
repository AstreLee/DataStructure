#include<iostream>
#include<stack>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;  // sequential stack

// 初始化栈
void initStack(SqStack*& s) {
    s = (SqStack*)malloc(sizeof(SqStack));  // 分配栈空间，首地址放在s中
    s->top = -1;  // 栈顶指针初始化就指向-1位置
}

// 销毁栈空间
void destoryStack(SqStack* s) {
    free(s);
}

// 判断栈空间是否为空
bool isEmpty(SqStack* s) {
    return s->top == -1;
}

// 判断栈空间是否满
bool isFull(SqStack* s) {
    return s->top == MaxSize - 1;
}

// 获取栈空间中元素的个数
int size(SqStack* s) {
    return s->top;
}

// 进栈
bool push(SqStack* s, ElemType e) {
    // 首先判断栈是否满
    if (isFull(s))  false;
    // 由于top指针指向的是最后一个元素，所以我们首先将指针上移
    s->top++;
    // 然后将要插入元素e放在栈顶，注意顺序栈元素是放在data里面的
    s->data[s->top] = e;
    return true;
}

// 出栈
bool pop(SqStack* s, ElemType& e) {
    // 首先判断栈是否空
    if (isEmpty(s))  return false;
    // 将栈顶元素赋值给变量e
    e = s->data[s->top];
    // 指针下移，相当于出栈操作
    s->top--;
    return true;
}

// 取栈顶元素
bool getTop(SqStack* s, ElemType& e) {
    // 首先判断栈是否为空
    if (isEmpty(s)) return false;
    // 将栈顶元素赋值给变量e
    e = s->data[s->top];
    // 返回结果
    return true;
}