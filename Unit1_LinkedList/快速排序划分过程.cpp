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
void partitional_1(LinkList* L);
void partitional_2(LinkList* L);
void swap(ElemType& a, ElemType& b);

// 第一种是直接交换i和j指针指向的位置
void partitional_1(LinkList* L) {
    int i = 0;
    int j = L->length - 1;
    ElemType privot = L->data[0];  // 以第一个元素作为基准元素
    while (i < j) {
        while (i < j && L->data[j] > privot)
            --j;
        while (i < j && L->data[i] <= privot)
            ++i;
        if (i < j)  // 这里有可能i == j, 这个时候就没有必要进行交换了
            swap(L->data[i], L->data[j]);
    }
    swap(L->data[0], L->data[i]);
}

// 第二种的话是最后不断的赋值，相比交换来说效率高了不少
void partitional_2(LinkList* L) {
    int i = 0;
    int j = L->length - 1;
    ElemType privot = L->data[0];
    while (i < j) {
        while (i < j && L->data[j] > privot)
            --j;
        L->data[i] = L->data[j];
        while (i < j && L->data[i] <= privot)
            ++i;
        L->data[j] = L->data[i];
    }
    L->data[i] = privot;
}

void swap(ElemType& a, ElemType& b) {
    ElemType temp = a;
    a = b;
    b = temp;
}