#include <iostream>
#include "singleList.h"
using namespace std;

// ������һ��С���⣬�ݹ��㷨ɾ��ֵΪx�Ľ���ʱ�򣬴��򲻴�ͷ�����ʲô����
// �Ҹ�����Ϊ����û��ʲô����ģ���Ϊ�������ͷ���Ļ����ݹ��㷨���ݲ�����ʱ��
// ����Ҫ����L->nextҲ�����׽��Ȼ��ʼ�ݹ�
void del_x_3(Lnode*& L, ElemType x) {  // ��ϸ����������õ�����
    // �ݹ����
    if (L == NULL) {
        return;
    }
    // ���L->data == x
    if (L->data == x) {
        Lnode* temp = L;
        L = L->next;
        free(temp);
        del_x_3(L, x);
    } else {
        // ����Ļ�������һ��ѭ��
        del_x_3(L->next, x);
    }
}

int main() {
    // ���ɲ�������
    int arr[] = {1, 1, 1, 2, 3, 2, 3, 9, 1};
    // ��������
    Lnode* L = initWithoutHead(arr, 9);
    // ԭʼ���
    displayList(L);
    // �ݹ�ɾ��
    del_x_3(L, 1);
    // ɾ��������
    displayList(L);

    return 0;
}
