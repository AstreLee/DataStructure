#include<iostream>
using namespace std;

void doubleBubbleSort(int* arr, int n) {
    int i = 0;  // 左指针
    int j = n - 1;  // 右指针
    while (i < j) {
        // 首先从左往右冒泡
        bool isChange = false;
        for (int k = i; k < j; ++k) {
            if (arr[k] > arr[k + 1]) {
                swap(arr[k], arr[k + 1]);
                isChange = true;
            }
        }
        if (!isChange) {
            break;
        } else {
            --j;
        }
        // 再从右往左冒泡
        isChange = false;
        for (int k = j; k > i; --k) {
            if (arr[k] < arr[k - 1]) {
                swap(arr[k], arr[k - 1]);
                isChange = true;
            }
        }
        if (!isChange) {
            break;
        } else {
            ++i;
        }
    }
}

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    // 声明一个乱序数组
    int arr[] = {2, 5, 8, 1, 10, 5, 19, 19, 3, 5};
    // 打印排序前的结果
    cout << "排序前的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // 调用直接插入排序函数
    doubleBubbleSort(arr, 10);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}