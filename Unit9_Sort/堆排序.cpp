#include <iostream>
using namespace std;

// 函数声明
void SiftDown(int* arr, int n, int i);
void HeapSort(int* arr, int n);

int main() {
    // 声明一个乱序数组
    int arr[] = {1, 2, 1, 0, 4, 2, 11, 3, 2, 1, 1, 1};
    // 打印排序前的结果
    cout << "排序前的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // 调用直接插入排序函数
    HeapSort(arr, 12);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void SiftDown(int* arr, int n, int i) {
    bool flag = true;  // flag标志变量标志是否继续向下调整
    // 有左节点并且需要继续调整的时候继续
    while (2 * i + 1 < n && flag) {
        // 首先找出根节点和左子节点的最小值
        int max = arr[i];
        int maxPos = i;
        if (arr[i] < arr[2 * i + 1]) {
            max = arr[2 * i + 1];
            maxPos = 2 * i + 1;
        }
        // 接下来看看max是不是比右子节点还大
        if (2 * i + 2 < n) {
            if (max < arr[2 * i + 2]) {
                max = arr[2 * i + 2];
                maxPos = 2 * i + 2;
            }
        }
        // 如果maxPos不等于自己的话说明需要交换
        if (maxPos != i) {
            int temp = arr[maxPos];
            arr[maxPos] = arr[i];
            arr[i] = temp;
            // 可能还要继续调整，更新我们的i
            i = maxPos;
        } else {
            // 否则的话就说明根节点比两个子节点都要小，退出循环
            flag = false;
        } 
    }
}

void HeapSort(int* arr, int n) {
    // 首先是调整我们的大根堆
    for (int i = n / 2 - 1; i >= 0; --i) {
        SiftDown(arr, n, i);
    }
    // 堆排序是针对已经调整好的大根堆的，也就是现在arr已经是大根堆了
    // 每次出头元素，然后与最后一个元素交换，之后再调整第一个元素
    
    for (int i = n - 1; i >= 1; --i) {
        // 开始交换
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        // 然后开始调整头结点
        --n;
        SiftDown(arr, n, 0);
    }
    // 最后交换一下arr[0]和arr[1]
}