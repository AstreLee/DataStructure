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
void deListNode1(LinkList* L, ElemType x);
void deListNode2(LinkList* L, ElemType x);
void deListNode3(LinkList* L, ElemType x);


// 第一种删除指定元素的方式，就是遍历整个顺序表，将不为X的元素依次往后放
void deListNode1(LinkList* L, ElemType x) {
    int k = 0;  // 记录下一个非X元素填入的位置
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            ++k;
        }
    }
    L->length = k;
}

// 第二种删除指定元素的方式，同样是遍历整个顺序表，与方法一不同的是方法二统计的是
// 等于x的元素的个数，那么存放的位置就用当前下标i - count（x）指定
void deListNode2(LinkList* L, ElemType e) {
    int k = 0;  // 记录当前位置前有多少个值等于x的元素
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e) {
            k++;
        } else {
            L->data[i - k] = L->data[i];
        }
    }
    L->length -= k;
}

// 第三种，其实借鉴了后面的将奇数移到前面来的思想，不过这种方法的话就不能保证原来的顺序了
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