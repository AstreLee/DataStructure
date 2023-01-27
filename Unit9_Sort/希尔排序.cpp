#include <iostream>
using namespace std;

// 函数声明
void ShellSort(int* arr, int n);

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
    ShellSort(arr, 8);
    // 打印排序后的结果
    cout << "排序后的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void ShellSort(int* arr, int n) {
    // 希尔排序实际上就是分组插入排序
    // 正常一点的想法是从第一个元素开始，将这一组的元素全部排序完成然后再从第二个元素开始
    // 将这一组的元素全部排序完成，但实际上还可以从位置d开始将属于这一组的前面的元素全部
    // 排序好，这个有点意思，这个想法实际上就是依次隔组操作
    int d = n / 3;
    while (d > 0) {
        for (int i = d; i < n; ++i) {
            if (arr[i] < arr[i - d]) {
                int j = i - d;
                int temp = arr[i];
                for (; j >= 0 && temp < arr[j]; j -= d)  arr[j + d] = arr[j];
                arr[j + d] = temp;
            }
        }
        d /= 2;
    }
}