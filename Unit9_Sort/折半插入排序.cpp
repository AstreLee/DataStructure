#include <iostream>
using namespace std;

// 函数声明
void BinaryInsertSort(int* arr, int n);

int main() {
    // 声明一个乱序数组
    int arr[] = {1, 1, 3, 2, 1, 4, 5, 8};
    // 打印排序前的结果
    cout << "排序前的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // 调用直接插入排序函数
    BinaryInsertSort(arr, 8);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void BinaryInsertSort(int* arr, int n) {
    // 折半插入排序实际上知识减少了元素比较的次数，元素移动的效率并没有减少
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            int low = 0;
            int high = i - 1;
            int temp = arr[i];
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] <= temp)  low = mid + 1;
                else  high = mid - 1;
            }
            for (int j = i - 1; j >= low; --j)  arr[j + 1] = arr[j];
            arr[low] = temp;
        }
    }
}