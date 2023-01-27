#include <iostream>
using namespace std;

// 函数声明
void BubbleSort(int* arr, int n);

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
    BubbleSort(arr, 8);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void BubbleSort(int* arr, int n) {
    // 冒泡排序实际上是每次将一个最大的数沉底，将两个相邻的数字进行比较,
    // 实际上有点动态规划维护两个变量的意思了
    bool isChange = false;
    for (int i = 0; i < n - 1; ++i) {
        isChange = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isChange = true;
            }
        }
        // 没有交换过就已经是有序的了
        if (! isChange)  break;
    }
}