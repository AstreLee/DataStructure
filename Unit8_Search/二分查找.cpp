#include <iostream>
using namespace std;

// 函数声明
int BinarySearch(int* pt, int n, int target);

int main() {
    // 首先声明一个有序数组
    int arr[] = {1, 2, 3, 4, 5, 5, 5, 6, 6, 7};
    // 然后获取要查找的数，如果存在返回位置，如果不存在返回插入位置
    int target;
    cout << "请输入要查找的数：";
    cin >> target;
    // 调用函数
    cout << "结果为：" << BinarySearch(arr, 10, target) << endl;
    return 0;
}

int BinarySearch(int* pt, int n, int target) {
    // 下面是如果存在的情况下正常的二分查找
    // 这种是建立在target在数组中已经存在的情况下
    // 那么如果我们想让有这个元素就返回对应下标，没有这个元素就返回插入位置呢？
    // 看看下面的方法
    // int low = 0;
    // int high = n - 1;
    // while (low <= high) {
    //     int mid = low + (high - low) / 2;
    //     if (pt[mid] < target)  low = mid + 1;
    //     else if (pt[mid] > target)  high = mid - 1;
    //     else return mid;
    // 这种是建立在target在数组中已经存在的情况下
    // 那么如果我们想让有这个元素就返回对应下标，没有这个元素就返回插入位置呢？
    // 看看下面的方法
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (pt[mid] < target)  low = mid + 1;
        else high = mid - 1;
    }
    return low;

    // 下面想就这个等号加在low还是high的位置做一个声明
    // 循环结束一定是high在low的前面一个位置，这是由循环体的代码决定的
    // 那么high的左边包括high都是<=target的
    // low的右边包括low都是>=target的
    // 如果target不存在的话，最后就是high的左边包括high都是小于target的
    // low的右边包括low都是大于target的，那么这个时候正好插入位置就是low
    // 如果target存在而且有且仅有一个的话：
    // 1. 如果等号加在low上面的话，那么由最后high和low的位置关系可知
    // low是不会指向target的，所以high就是最终相等的位置
    // 2. 如果等号加在high上面的话，那么由最后high和low的位置关系可知
    // high是不会指向target的，所以low就是最终的位置

    // 如果target存在而且有多个的话
    // 1. 如果等号加在low上面的话，最终low就指向了target的后一个元素，high指向了target
    // 2. 如果等号加在high上面的话，最终low就指向了target的第一个元素，high指向了low前面一个元素
    // 3. 等号加在哪里和折半插入排序的稳定性有关系
}