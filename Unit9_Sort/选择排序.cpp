#include <iostream>
using namespace std;

// 鍑芥暟澹版槑
void SelectSort1(int* arr, int n);
void SelectSort2(int* arr, int n);


int main() {
   // 声明一个乱序数组
    int arr[] = {1, 3, 2, 5, 1, 5, 4, 9999};
    // 打印排序前的结果
    cout << "排序前的结果如下所示：" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // 璋冪敤鐩存帴鎻掑叆鎺掑簭鍑芥暟
    SelectSort2(arr, 8);
    // 鎵撳嵃鎺掑簭鍚庣殑缁撴灉
    cout << "鎺掑簭鍚庣殑缁撴灉濡備笅鎵�绀猴細" << endl;
    for (int i : arr) {
        cout << i << " ";
    }
}

void SelectSort1(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 涓嬮潰鏄敼杩涚増鐨勯�夋嫨鎺掑簭锛屽疄闄呬笂鎴戜滑涓嶉渶瑕佹瘡娆￠兘浜ゆ崲锛屾渶鍚庝竴娆℃�т氦鎹㈠氨OK
void SelectSort2(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        // 濡傛灉k != i鐨勮瘽灏变氦鎹綅缃?
        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}
