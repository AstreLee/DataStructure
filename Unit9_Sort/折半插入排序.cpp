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
            // 最终退出循环的结果就是high在low的前面
            // 也就是说[low, ..)的右边包括low都是>=temp的, (..., high]high的左边都是<=temp的
            // 如果没有等于的话，就说明了high包括high左边都是小于val的
            // low包括low的右边都是大于val的，那么插入位置就是low
            // 如果有等于的话，为了使得我们的折半插入排序稳定，等于号就要加在low上
            
            // 但是如果是二分查找的话，如果没有相等的元素的话，不管等号加在哪里，最后
            // 插入位置就是low, 但是如果有相等的元素的话，而且有且只有一个,
            // 那么等号加在low的位置，最终相等的位置就是high
            // 等号加在high的位置，最终相等的位置就是low
            // 那么就说明low就是插入的位置，实际上这也是二分寻找插入位置的方法
            for (int j = i - 1; j >= low; --j)  arr[j + 1] = arr[j];
            arr[low] = temp;
            
            // 对于这个折半插入排序来说，因为是插入位置，所以等号加在哪里其实无所谓
            // 但是想要稳定性的话只能加在low的位置
        }
    }
}