#include <iostream>
#include "singleList.h"
using namespace std;

// 这里提一个小问题，递归算法删除值为x的结点的时候，带或不带头结点有什么区别
// 我个人认为这是没有什么区别的，因为就算带了头结点的话，递归算法传递参数的时候
// 还是要传递L->next也就是首结点然后开始递归
void del_x_3(Lnode*& L, ElemType x) {  // 仔细体会这里引用的作用
    // 递归出口
    if (L == NULL) {
        return;
    }
    // 如果L->data == x
    if (L->data == x) {
        Lnode* temp = L;
        L = L->next;
        free(temp);
        del_x_3(L, x);
    } else {
        // 否则的话继续下一轮循环
        del_x_3(L->next, x);
    }
}

int main() {
    // 生成测试数据
    int arr[] = {1, 1, 1, 2, 3, 2, 3, 9, 1};
    // 生成链表
    Lnode* L = initWithoutHead(arr, 9);
    // 原始输出
    displayList(L);
    // 递归删除
    del_x_3(L, 1);
    // 删除后的输出
    displayList(L);

    return 0;
}
