#include <iostream>
using namespace std;

// 函数声明
void QuickSort(int* arr, int low, int high);

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
    QuickSort(arr, 0, 9);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void QuickSort(int* arr, int low, int high) {
    // 不要忘记递归的边界条件
    if (low >= high)  return;
    // 以左边的数为基准就必须从右边开始
    int i = low;
    int j = high;
    int privot = arr[i];
    while (i < j) {
        while (i < j && arr[j] > privot)  --j;
        arr[i] = arr[j];
        while (i < j && arr[i] <= privot)  ++i;
        arr[j] = arr[i];
    }
    arr[i] = privot;
    QuickSort(arr, low, i - 1);
    QuickSort(arr, i + 1, high);
}