#include <iostream>
using namespace std;

// 函数声明
void SelectSort1(int* arr, int n);
void SelectSort2(int* arr, int n);


int main() {
   // 声明一个乱序数组
    int arr[] = {1, 3, 2, 5, 1, 5, 4, 1};
    // 打印排序前的结果
    cout << "排序前的结果如下所示：" << endl;
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
        int temp = arr[i];
        for (int j = i + 1; j < n; ++j) {
            if (temp > arr[j]) {
                temp = arr[j];
                k = j;
            }
        }
        // 如果k != i的话就交换位置
        if (k != i) {
            int temp1 = arr[i];
            arr[i] = arr[k];
            arr[k] = temp1;
        }
    }
}