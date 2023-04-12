#include <iostream>
#include "singleList.h"
using namespace std;

// ��Ӧ�����յķ���
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

// β�巨��ʵ���Ϻ�˳����н�����x��Ԫ���Ƶ�ǰ����Щ���ƣ�β�巨Ҳ���Ҳ���x��Ԫ�ؽ��в���
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
            free(temp);  // ���ɾ������Ҳ��Ҫ����Ŷ
        }
    }
    tail->next = NULL;
}

int main() {
    // ���ɲ�������
    int arr[] = {1, 1, 1, 2, 3, 2, 3, 9, 1};
    // ��������
    Lnode* L = initWithHead(arr, 9);
    // ԭʼ���
    displayList(L->next);
    // �ݹ�ɾ��
    del_x_2(L, 1);
    // ɾ��������
    displayList(L->next);
}