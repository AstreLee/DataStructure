#include <iostream>
using namespace std;

// 函数声明
void InsertSort(int* arr, int n);

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
    InsertSort(arr, 8);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void InsertSort(int* arr, int n) {
    // 直接插入排序：将无序区中的元素插入到有序区里面
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            int temp = arr[i];
            int j = i - 1;
            for (; j >= 0 && temp < arr[j]; --j) {
                // 将前面的数全部移到后面
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}