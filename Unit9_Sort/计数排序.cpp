#include<iostream>
using namespace std;

// 定义计数排序算法(假设排序的序列就是0 ~ 9之间的数字)
void countSort(int* arr, int n) {
    int pt[10] = {0};
    // 遍历原数组，数字对应是多少，就在对应下标处加一
    for (int i = 0; i < n; ++i) {
        pt[arr[i]]++;
    }
    // 遍历pt数组，对应位置的元素为几，就表示这个数字出现了多少次，重复打印即可
    for (int i = 0; i < 10; ++i) {
        for (int j = pt[i]; j >= 1; --j) {
            cout << i << " ";
        }
    }
} 

int main() {
    // 声明一个乱序数组
    int arr[] = {2, 5, 8, 1, 1, 5, 9, 9, 3, 5};
    // 打印排序前的结果
    cout << "排序前的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // 调用直接插入排序函数
    countSort(arr, 10);
}