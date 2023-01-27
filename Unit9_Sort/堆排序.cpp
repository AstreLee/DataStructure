#include <iostream>
using namespace std;

// 函数声明
void SiftDown(int* arr, int n, int i);
void SiftUp(int* arr, int i);
void InitHeap(int* arr, int n);
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

    return 0;
}

// 初始化堆
void InitHeap(int* arr, int n) {
    // 方式一：可以采用向下调整算法初始化
    // for (int i = n / 2 - 1; i >= 0; --i) {
    //     SiftDown(arr, n, i);
    // }
    
    // 方式二：可以采用向上调整算法初始化
    for (int i = 0; i < n; ++i) {
        SiftUp(arr, i);
    }
}

// 向上调整算法
void SiftUp(int* arr, int i) {
    int parent = (i - 1) / 2;
    while (i > 0) {
        if (arr[parent] < arr[i]) {
            int temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;
            i = parent;
            parent = (parent - 1) / 2;
        } else {
            break;
        }
    }
}

void SiftDown(int* arr, int n, int i) {
    // 有左节点并且需要继续调整的时候继续
    while (2 * i + 1 < n) {
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
            break;  // 不用继续向下调整的话就直接退出
        }
    }
}

void HeapSort(int* arr, int n) {
    // 构建大根堆
    InitHeap(arr, n);
    
    // 堆排序开始
    for (int i = n - 1; i >= 1; --i) {
        // 开始交换
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        // 然后开始调整头结点
        --n;
        SiftDown(arr, n, 0);
    }
}