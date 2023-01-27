#include <iostream>
#include <cstdlib>
using namespace std;

// TopK问题
// 找10亿个数中的100个最小的，构建大根堆，这样每次与根结点比较，如果比根结点还大,则不可能成为最小的100个数之一
// 找10亿个数中的100个最大的，构建小根堆，这样每次与根结点比较, 如果比根结点还要小，则不可能成为最大的100个数之一

// 函数声明
void SiftDown(int* arr, int n, int i);
void HeapSort(int* arr, int n);
void TopK(int* arr, int n, int* minArr, int minN);

int main() {
    // 声明一个长度为10000的整型数组
    int* arr = (int*)malloc(sizeof(int) * 10000);
    // 使用random函数生成10000个随机数
    for (int i = 0; i < 10000; ++i) {
        arr[i] = rand() % 10000 + 1;
    }
    // 声明一个长度为20的整型数组，存放这10000个数中的最小的20个数
    int* minArr = (int*)malloc(sizeof(int) * 20);
    // 调用TopK函数，找到这10000个数中的最小的20个数
    TopK(arr, 10000, minArr, 20);
    cout << "这10000个数中最小的20个数如下所示：" << endl;
    // 打印这20个最小的数字
    for (int i = 0; i < 20; ++i) {
        cout << minArr[i] << " ";
    }
    return 0;
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

void TopK(int* arr, int n, int* minArr, int minN) {
    // 首先将arr中的前minN个数字填充到我们的minArr中
    for (int i = 0; i < minN; ++i) {
        minArr[i] = arr[i];
    }
    // 调整我们的这20个数，使其满足最小堆的形式
    for (int i = minN / 2 - 1; i >= 0; --i) SiftDown(minArr, minN, i);
    // 然后从第minN + 1个数开始我们依次与最小堆的根结点比较
    // 如果比这20个数的最下值还要小的话，就不可能成为最大的20个数之一，就继续
    // 否则的话用这个大于最小值的数字去替换根结点，然后调整根节点使其成为最大堆
    for (int i = minN; i < n; ++i) {
        if (arr[i] <= minArr[0]) {
            minArr[0] = arr[i];
            SiftDown(minArr, minN, 0);
        }
    }
    // 最后对我们的minArr排序，使用堆排
    HeapSort(minArr, minN);
}