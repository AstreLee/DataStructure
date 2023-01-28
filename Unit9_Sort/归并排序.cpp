#include <iostream>
using namespace std;

void merge(int* arr, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int* newArr = (int*)malloc(sizeof(int) * (high - low + 1));
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            newArr[k] = arr[i];
            ++i; ++k;
        } else {
            newArr[k] = arr[j];
            ++j; ++k;
        }
    }
    // 合并第一个有序表剩下的内容
    while (i <= mid) {
        newArr[k] = arr[i];
        ++i; ++k;
    }
    // 合并第二个有序表剩下的内容
    while (j <= high) {
        newArr[k] = arr[j];
        ++j; ++k;
    }
    // 将新表内容复制到arr[low...high]中
    for (int t = low; t <= high; ++t) {
        arr[t] = newArr[t - low];
    }
    free(newArr);
}

void mergePass(int* arr, int length, int n) {
    int i = 0;
    for (; i + 2 * length - 1 < n; i += 2 * length) {
        merge(arr, i, i + length - 1, i + 2 * length - 1);
    }
    // 最后需要判断一下余下的表是否需要合并
    // 这里为什么是小于n - 1，想要合并的话最后一个表必须要至少有一个元素，所以前面一个有序表的结束
    // 位置就应该在n - 1的前面
    if (i + length - 1 < n - 1) {
        merge(arr, i, i + length - 1, n - 1);
    }
}

void mergeSort(int* arr, int n) {
    for (int length = 1; length < n; length *= 2) {
        mergePass(arr, length, n);
    }
}

void mergeSortDC(int* arr, int low, int high) {
    if (low < high) {
        int mid = (high - low) / 2 + low;
        // 归并左边
        mergeSortDC(arr, low, mid);
        // 归并右边
        mergeSortDC(arr, mid + 1, high);
        // 合并两边的有序表
        merge(arr, low, mid, high);
    }
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
    mergeSortDC(arr, 0, 9);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}