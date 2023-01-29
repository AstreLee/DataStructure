#include <iostream>
using namespace std;

// 函数声明
void SelectSort1(int* arr, int n);
void SelectSort2(int* arr, int n);


int main() {
   // ����һ����������
    int arr[] = {1, 3, 2, 5, 1, 5, 4, 199};
    // ��ӡ����ǰ�Ľ��
    cout << "����ǰ�Ľ��������ʾ��" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // 调用直接插入排序函数
    SelectSort2(arr, 8);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void SelectSort1(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 下面是改进版的选择排序，实际上我们不需要每次都交换，最后一次性交换就OK
void SelectSort2(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        // 如果k != i的话就交换位�?
        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}
