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
void move1(LinkList* L);  // 方法一采用的是类似于快排的思想
void move2(LinkList* L);  // 方法二采用的是移位法，记录下奇数的个数，实际上还可以记录偶数的个数
void swap(ElemType& a, ElemType& b);

// move1()函数定义
void move1(LinkList* L) {
    int i = 0;
    int j = L->length - 1;
    while (i < j) {
        while (i < j && L->data[j] % 2 == 0)
            --j;
        while (i < j && L->data[i] % 2 != 0)
            ++i;
        if (i < j)  // 这里最好加上一个判断条件，如果指针相遇就没有必要交换
            swap(L->data[i], L->data[j]);
    }
}

// move2函数定义
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

// swap函数定义
void swap(ElemType& a, ElemType& b) {
    ElemType temp = a;
    a = b;
    b = a;
}