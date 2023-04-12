#include <iostream>
#include "singleList.h"
using namespace std;

// 最应该掌握的方法
void del_x_1(Lnode* L, ElemType x) {
    Lnode* pre = L;
    Lnode* pt = L->next;
    while (pt != NULL) {
        if (pt->data == x) {
            pre->next = pt->next;
            free(pt);
            pt = pre->next;
        } else {
            pre = pt;
            pt = pt->next;
        }
    }
}

// 尾插法，实际上和顺序表中将不是x的元素移到前面有些类似，尾插法也是找不是x的元素进行插入
void del_x_2(Lnode* L, ElemType x) {
    Lnode* tail = L;
    Lnode* pt = L->next;
    Lnode* temp = NULL;
    while (pt != NULL) {
        if (pt->data != x) {
            tail->next = pt;
            tail = pt;
            pt = pt->next;
        } else {
            temp = pt;
            pt = pt->next;
            free(temp);  // 这个删除操作也不要忘了哦
        }
    }
    tail->next = NULL;
}

int main() {
    // 生成测试数据
    int arr[] = {1, 1, 1, 2, 3, 2, 3, 9, 1};
    // 生成链表
    Lnode* L = initWithHead(arr, 9);
    // 原始输出
    displayList(L->next);
    // 递归删除
    del_x_2(L, 1);
    // 删除后的输出
    displayList(L->next);
}